import sys
import os
import pulp

sys.path.append(os.getcwd()+'/../../')
from common import parc
from linear_prog.pulp_utils import *
import common.charts
import subprocess


def create_marginal_cost_lp( pb,name):

	lp = pulp.LpProblem(name+".lp", pulp.LpMaximize)
	lp.setSolver()
	prod_vars = {}
	volume_res={}
	
	time_step_in_minutes=pb.time_step_duration

			
	#Variables creation for hydro plants
	debit_vars={}
	e={}
	ecart_plus={}
	ecart_moins={}
	for t in pb.time_steps:
		
		debit_vars[t]={}
		e[t]={}
		volume_res[t]={}
		ecart_plus[t]={}
		ecart_moins[t]={}
		prod_vars[t]={}
		
		for usine in pb.hydro_plants :
			var_name = "prod_"+str(t)+"_hydro_"+str(usine.id)
			prod_vars[t][usine] = pulp.LpVariable(var_name, -10000, 10000)
			var_name = "debit_"+str(t)+"_"+str(usine.id)
			debit_vars[t][usine] = pulp.LpVariable(var_name, -10000, 100000)
			e[t][usine]={}
			for pdf in usine.operating_levels:
				var_name = "e_"+str(t)+"_"+str(usine.id)+"_"+str(pdf.id)
				e[t][usine][pdf]= pulp.LpVariable(var_name, cat="Binary")
		for reservoir in pb.reservoirs:
			var_name= "volumeRes_"+str(t)+"_"+str(reservoir.id)
			volume_res[t][reservoir]=pulp.LpVariable(var_name,reservoir.minimum_volume,reservoir.maximum_volume, None)
			
			
	#Constraints creation for hydro plants        
	for t in pb.time_steps:
		
		for usine in pb.hydro_plants :
			#Production constraints
			constraint_name = "prod_"+str(t)+"_hydro_"+str(usine.id)
			lp+=prod_vars[t][usine]==pulp.lpSum([ e[t][usine][pdf] *pdf.power  for pdf in usine.operating_levels ]),constraint_name
			
			#debit at u at time t
			constraint_name = "debit_"+str(t)+"_hydro_"+str(usine.id)
			lp+=debit_vars[t][usine]==pulp.lpSum([ e[t][usine][pdf] *pdf.flow  for pdf in usine.operating_levels ]),constraint_name
			
			
			#flow gradient constraint
			if t<pb.time_steps[-1]:
				constraint_name = "debit_gradient_max"+str(t)+"_hydro_"+str(usine.id)
				lp+= usine.maximum_increase_rate >= (debit_vars[t+1][usine]-debit_vars[t][usine])/pb.time_step_duration , constraint_name
			
				constraint_name = "debit_gradient_min"+str(t)+"_hydro_"+str(usine.id)
				lp+= usine.maximum_decrease_rate >= -(debit_vars[t+1][usine]-debit_vars[t][usine])/pb.time_step_duration >= -usine.maximum_decrease_rate, constraint_name
			
			#preserve the startup order
			pdf_previous=usine.operating_levels[0]
			for pdf in usine.operating_levels:
				constraint_name = "level_"+str(t)+"_hydro_"+str(usine.id)+"_level_"+str(pdf.id)
				lp+=e[t][usine][pdf]<=e[t][usine][pdf_previous], constraint_name
				pdf_previous=pdf
				
				#do not produce peaks
				if (t>0) and (t<pb.time_steps[-1]):
						constraint_name = "peaks1_"+str(t)+"_hydro_"+str(usine.id)+"_level_"+str(pdf.id)
						lp+=e[t][usine][pdf]>=e[t-1][usine][pdf]+e[t+1][usine][pdf]-1, constraint_name
						
						constraint_name = "peaks2_"+str(t)+"_hydro_"+str(usine.id)+"_level_"+str(pdf.id)
						lp+=e[t][usine][pdf]<=e[t-1][usine][pdf]+e[t+1][usine][pdf],constraint_name
			
			
		for reservoir in pb.reservoirs :	
			#volume update
			if t==0:
				constraint_name = "volume_"+str(t)+"_reservoir_"+str(reservoir.id)
				lp+=volume_res[t][reservoir]==reservoir.initial_volume, constraint_name
			else:
				constraint_name = "volume_"+str(t)+"_reservoir_"+str(reservoir.id)
				lp+=volume_res[t][reservoir]==volume_res[t-1][reservoir] + pulp.lpSum([1800*debit_vars[t-pb.hydro_plants[usine].downstream_delay][pb.hydro_plants[usine]] for usine in reservoir.upstream_hydro_plants_ids]) - pulp.lpSum([1800*debit_vars[t][pb.hydro_plants[usine]] for usine in reservoir.downstream_hydro_plants_ids]) + 1800*reservoir.inflows , constraint_name
			
			##max and min volumes
			constraint_name = "volume_max"+str(t)+"_reservoir_"+str(reservoir.id)
			lp+=volume_res[t][reservoir]<=reservoir.maximum_volume, constraint_name
			
			constraint_name = "volume_min"+str(t)+"_reservoir_"+str(reservoir.id)
			lp+=volume_res[t][reservoir]>=reservoir.minimum_volume, constraint_name
			
	#objective function
	lp.objective=pulp.lpSum([pulp.lpSum([prod_vars[t][usine]*0.5*pb.electricity_prices[t] for t in pb.time_steps]) for usine in pb.hydro_plants]) - pulp.lpSum([reservoir.water_value * (reservoir.initial_volume-volume_res[pb.time_steps[-1]][reservoir]) for reservoir in pb.reservoirs])
	model=Model(lp,prod_vars,volume_res)

	return model



def run():
	pb_name = "vallee_hydraulique"
	pb = parc.build_from_data(pb_name+".json")
	subprocess.call(["rm", "cplex.log"])

	print ("Creating Model " + pb_name)
	model = create_marginal_cost_lp(pb, pb_name)   
		
	print ("Solving Model")
	solve(model, pb_name)
		
	print ("Post Treatment")
	
	results=getResultsModel(pb, model, pb_name)
	printResults(pb,model,pb_name,pb.electricity_prices,results)
	


if __name__ == '__main__':
	
	run()

