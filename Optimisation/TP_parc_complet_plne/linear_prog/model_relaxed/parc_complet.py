import sys
import os
import pulp

sys.path.append(os.getcwd()+'/../../')
from common import parc
from linear_prog.pulp_utils import *
import common.charts
import subprocess
import matplotlib.pyplot as plt

def create_unitcommitment_lp( pb,name):

    lp = pulp.LpProblem(name+".lp", pulp.LpMinimize)
    lp.setSolver()
    prod_vars = {}
    volume_res={}
    M ={}
    D={}
    over_production={}
    under_production={}
    time_step_in_minutes=pb.time_step_duration
    #Variables de surproduction et de sousproduction
    for t in pb.time_steps:
        varname="under_production_"+str(t)
        under_production[t]=pulp.LpVariable(varname, 0.0, pb.maximum_under_production)
        varname="over_production_"+str(t)
        over_production[t]=pulp.LpVariable(varname, 0.0, pb.maximum_over_production)
    
    #Variables creation for thermal power plants
    for t in pb.time_steps:
        prod_vars[t] = {}
        M[t] = {}
        D[t] = {}

        for thermal_plant in pb.thermal_plants :
            var_name = "prod_"+str(t)+"_"+str(thermal_plant.name)
            prod_vars[t][thermal_plant] = pulp.LpVariable(var_name, 0.0, thermal_plant.pmax(t))

            var_name = "M_"+str(t)+"_"+str(thermal_plant.name)
            M[t][thermal_plant] = pulp.LpVariable(var_name, 0,1)

            var_name = "D_"+str(t)+"_"+str(thermal_plant.name)
            D[t][thermal_plant] = pulp.LpVariable(var_name, 0,1)

            
            
    #Variables creation for hydro plants
    debit={}
    e={}
    ecart_plus={}
    ecart_moins={}
    for t in pb.time_steps:
        debit[t]={}
        e[t]={}
        volume_res[t]={}
        ecart_plus[t]={}
        ecart_moins[t]={}
        for usine in pb.hydro_plants :
            var_name = "prod_"+str(t)+"_hydro_"+str(usine.id)
            prod_vars[t][usine] = pulp.LpVariable(var_name, None, None)
            var_name = "debit_"+str(t)+"_"+str(usine.id)
            debit[t][usine] = pulp.LpVariable(var_name, None, None)
            e[t][usine]={}
            for pdf in usine.operating_levels:
                var_name = "e_"+str(t)+"_"+str(usine.id)+"_"+str(pdf.id)
                e[t][usine][pdf]= pulp.LpVariable(var_name, 0,1)
                #e[t][usine][pdf]= pulp.LpVariable(var_name, 0,1)
        for reservoir in pb.reservoirs:
            var_name= "volumeRes_"+str(t)+"_"+str(reservoir.id)
            volume_res[t][reservoir]=pulp.LpVariable(var_name,None,None, None)
            var_name= "ecart_plus_"+str(t)+"_res_"+str(reservoir.id)
            ecart_plus[t][reservoir]=pulp.LpVariable(var_name, 0,reservoir.maximum_volume*0.1, None)
            var_name= "ecart_moins_"+str(t)+"_res_"+str(reservoir.id)
            ecart_moins[t][reservoir]=pulp.LpVariable(var_name, 0,reservoir.maximum_volume*0.1, None)
    
    
    #Constraints creation for hydro plants        
    for t in pb.time_steps:
        for usine in pb.hydro_plants :
            constraint_name = "prod_"+str(t)+"_hydro_"+str(usine.id)
            lp+=debit[t][usine]==pulp.lpSum([ e[t][usine][pdf] *pdf.flow  for pdf in usine.operating_levels ]),constraint_name
            constraint_name = "debit_"+str(t)+"_hydro_"+str(usine.id)
            lp+=prod_vars[t][usine]==pulp.lpSum([ e[t][usine][pdf] *pdf.power  for pdf in usine.operating_levels ]),constraint_name
    
            if(t>0):
                constraint_name = "gradHydHausse_"+str(t)+"_"+str(usine.id)
                lp+=debit[t][usine]-debit[t-1][usine]<=usine.maximum_increase_rate*  pb.time_step_duration,constraint_name
                constraint_name = "gradHydBaisse_"+str(t)+"_"+str(usine.id)
                lp+=debit[t][usine]-debit[t-1][usine]>=-usine.maximum_decrease_rate*  pb.time_step_duration,constraint_name
            
            for pdf in usine.operating_levels : 
                if (pdf.id<len(usine.operating_levels)-1):
                    pdfSupp=usine.operating_levels[pdf.id+1]
                    constraint_name = "ordrePdf_"+str(t)+"_hydro_"+str(usine.id)+"_"+str(pdf.id)
                    lp+=e[t][usine][pdf]>=e[t][usine][pdfSupp],constraint_name
                
                if(t>0 and t<len(pb.time_steps)-1):
                   constraint_name = "interditCreux_"+str(t)+"_hydro_"+str(usine.id)+"_"+str(pdf.id)
                   lp+=e[t][usine][pdf]>=-1+e[t-1][usine][pdf]+e[t+1][usine][pdf],constraint_name
                   constraint_name = "interditPic_"+str(t)+"_hydro_"+str(usine.id)+"_"+str(pdf.id)
                   lp+=e[t][usine][pdf]<= e[t-1][usine][pdf]+e[t+1][usine][pdf],constraint_name
    
    
    
    #Constraint creation for hydro reservoir
    for t in pb.time_steps:
        for reservoir in pb.reservoirs :
             constraint_name = "volume_min_"+str(t)+"_"+str(reservoir.id)  
             lp+=volume_res[t][reservoir]>=reservoir.minimum_volume-ecart_moins[t][reservoir],constraint_name
             
             constraint_name = "volume_max_"+str(t)+"_"+str(reservoir.id)  
             lp+=volume_res[t][reservoir]<=reservoir.maximum_volume+ecart_plus[t][reservoir],constraint_name
       
             coeffDebit=pb.time_step_duration*60
             constraint_name = "volume_"+str(t)+"_"+str(reservoir.id)  
             sumDebit=pulp.lpSum([coeffDebit*debit[t-pb.hydro_plants[id].downstream_delay][pb.hydro_plants[id]] for id in filter(lambda idk:t-pb.hydro_plants[idk].downstream_delay>=0,  reservoir.upstream_hydro_plants_ids)])
             sumDebit-=pulp.lpSum([coeffDebit*debit[t][pb.hydro_plants[id]] for id in reservoir.downstream_hydro_plants_ids])
             sumDebit+=reservoir.inflows  *coeffDebit
             
             
             if(t==0):
                 lp+=volume_res[t][reservoir]==reservoir.initial_volume+sumDebit,constraint_name
             else:
                 lp+=volume_res[t][reservoir]==volume_res[t-1][reservoir]+sumDebit,constraint_name
                
    for t in pb.time_steps:
        for step in pb.steps:
            #contrainte d'interdiction de pompage/turbinage simultane
            constraint_name="intTurbinePompe_"+str(t)+"_"+str(step.id_turb)+"_"+str(step.id_pump)
            turbine=pb.hydro_plants[step.id_turb]
            pompe=pb.hydro_plants[step.id_pump]
            lp+=e[t][turbine][turbine.operating_levels[0]]+e[t][pompe][pompe.operating_levels[0]]<=1,constraint_name
        
            if(t>0):
                #contrainte d'interdiction de pompage/turbinage simultanes
                constraint_name="delaiTurbinePompe_"+str(t)+"_"+str(step.id_turb)+"_"+str(step.id_pump)
                lp+=e[t][turbine][turbine.operating_levels[0]]+e[t-1][pompe][pompe.operating_levels[0]]<=1,constraint_name
                constraint_name="delaiPompeTurbine_"+str(t)+"_"+str(step.id_turb)+"_"+str(step.id_pump)
                lp+=e[t-1][turbine][turbine.operating_levels[0]]+e[t][pompe][pompe.operating_levels[0]]<=1,constraint_name
 

    #Thermal plants constraints
    
    for t in pb.time_steps :
        constraint_name = "production"+str(t)
        lp+=pb.demand[t] + over_production[t] - under_production[t]==pulp.lpSum([prod_vars[t][usine] for usine in pb.hydro_plants])+pulp.lpSum([prod_vars[t][thermal_plant] for thermal_plant in pb.thermal_plants]),constraint_name 
        for thermal_plant in pb.thermal_plants :   
            constraint_name = "prod_max"+str(t)+"_thermal_"+str(thermal_plant.id)
            lp+=prod_vars[t][thermal_plant] <=thermal_plant.pmax(t) * M[t][thermal_plant],constraint_name
            constraint_name = "prod_min"+str(t)+"_thermal_"+str(thermal_plant.id)
            lp+=prod_vars[t][thermal_plant] >=thermal_plant.pmin(t) * M[t][thermal_plant],constraint_name
            if t > 0:
                constraint_name = "demarrage_cas1"+str(t)+"_thermal_"+str(thermal_plant.id)
                lp+=M[t-1][thermal_plant] + (1-M[t][thermal_plant]) +  D[t][thermal_plant]>= 1,constraint_name
                
                constraint_name = "demarrage_cas2"+str(t)+"_thermal_"+str(thermal_plant.id)
                lp+=D[t][thermal_plant]<= 1 - M[t-1][thermal_plant],constraint_name
                
                constraint_name = "MaxHausse"+str(t)+"_thermal_"+str(thermal_plant.id)
                lp+=(prod_vars[t][thermal_plant]-prod_vars[t-1][thermal_plant])/time_step_in_minutes<=thermal_plant.maximum_increase_rate,constraint_name
                constraint_name = "MaxBaisse"+str(t)+"_thermal_"+str(thermal_plant.id)
                lp+=(prod_vars[t][thermal_plant]-prod_vars[t-1][thermal_plant])/time_step_in_minutes>=-thermal_plant.maximum_decrease_rate,constraint_name
            
            constraint_name = "demarrage_cas3"+str(t)+"_thermal_"+str(thermal_plant.id)
            lp+=D[t][thermal_plant]<= M[t][thermal_plant] ,constraint_name
            
            for k in range(t+1,t+int(thermal_plant.minimum_online_duration/time_step_in_minutes)+1):
                if t< pb.number_of_time_steps - int(thermal_plant.minimum_online_duration/time_step_in_minutes):
                    constraint_name = "minimum_duration_"+str(t)+"_thermal_"+str(thermal_plant.id)+"_"+str(k)
                    lp+=D[t][thermal_plant]<= M[k][thermal_plant] ,constraint_name
            
    for thermal_plant in pb.thermal_plants:
        constraint_name = "nb_demarrage_max_permier_jour"+"_thermal_"+str(thermal_plant.id)
        lp+=pulp.lpSum([D[t][thermal_plant] for t in range(0, int(pb.number_of_time_steps/2))])<=thermal_plant.maximum_number_of_startups,constraint_name
        constraint_name = "nb_demarrage_max_deuxieme_jour"+"_thermal_"+str(thermal_plant.id)
        lp+=pulp.lpSum([D[t][thermal_plant] for t in range(int(pb.number_of_time_steps/2), int(pb.number_of_time_steps))])<=thermal_plant.maximum_number_of_startups,constraint_name
        
        
            
           
    #TODO
    #EOD Constraints
    #TODO
    
    #objective function

    #thermal part just an example to complete
    lp.objective=pulp.lpSum([prod_vars[t][thermal_plant]*thermal_plant.proportionnal_cost*time_step_in_minutes/60 for thermal_plant in pb.thermal_plants for t in pb.time_steps])
    lp.objective+=pulp.lpSum([D[t][thermal_plant]*thermal_plant.startup_cost for thermal_plant in pb.thermal_plants for t in pb.time_steps]) 
    lp.objective+=pulp.lpSum([over_production[t]* pb.over_production_penalty*time_step_in_minutes/60 for t in pb.time_steps])
    lp.objective+=pulp.lpSum([under_production[t]* pb.under_production_penalty*time_step_in_minutes/60 for t in pb.time_steps])
    
    #hydro part
    T=len(pb.time_steps)-1
    lp.objective-=pulp.lpSum([(volume_res[T][reservoir]-reservoir.initial_volume) *reservoir.water_value for reservoir in pb.reservoirs])
    lp.objective+=pulp.lpSum([  (ecart_plus[t][reservoir]+ecart_moins[t][reservoir])*10.0 for reservoir in pb.reservoirs for t in pb.time_steps] )
    
    model=Model(lp,prod_vars,volume_res)

    return model



def run():
    pb_name = "parc_complet"
    pb = parc.build_from_data(pb_name+".json")
    subprocess.call(["rm", "cplex.log"])
    
    print ("Creating Model " + pb_name)
    model = create_unitcommitment_lp(pb, pb_name)
    
    print ("Solving Model")
    solve(model, pb_name)

    print ("Post Treatment")
    results=getResultsModel(pb,model,pb_name)
    

    
    marginal_costs=[0.0 for t in pb.time_steps]
    
    #decomment this part and give the right name of the EOD constraint name
    #to get the marginal cost of the demand at each time step
    dual_variables=getAllDualVariables(model)
    for t in pb.time_steps:
        marginal_costs[t]=-dual_variables["production"+str(t)]*2.0
    results.marginal_costs=marginal_costs
    
    printResults(pb, model, pb_name,marginal_costs,results)
    
    ecart=[0]*96
    sum_error=0
    for t in pb.time_steps:
            ecart[t]= results.prod_vars_solution["cumulThm"][t] + results.prod_vars_solution["cumulHydro"][t]-pb.demand[t]
            sum_error+=abs(ecart[t])
    
    average=sum_error/len(ecart)
    objective_penalty=0.0
    for t in pb.time_steps:
        if ecart[t]>0:
            objective_penalty+=ecart[t]*pb.over_production_penalty*pb.time_step_duration/60
        else:
            objective_penalty+=-ecart[t]*pb.under_production_penalty*pb.time_step_duration/60
         
    objective_production=pulp.value(model.lp.objective)-objective_penalty
    
    print("penalty objective",objective_penalty)
    print("production objective",objective_production)
    print("objective",pulp.value(model.lp.objective))
    #~ plt.title("Mean absolute error = "+ str(average)+" Production cost = "+ str(objective_production))
    #~ plt.plot(pb.time_steps,ecart)
    #~ plt.xlabel("Time step")
    #~ plt.ylabel("Error (MW)")
    #~ plt.grid(True)
    #~ plt.show()
    
    
    #~ plt.plot(pb.time_steps,marginal_costs,label="Marginal costs")
    #~ plt.plot(pb.time_steps,pb.demand,label="Demand")
    #~ plt.xlabel("Time step")
    #~ plt.show()
    
    fig, ax1 = plt.subplots()


    color = 'k'
    ax1.plot(pb.time_steps,marginal_costs,'b',label="Marginal costs")
    
    ax1.set_ylabel('Marginal costs (EUR/MWh)', color=color)
    ax1.set_xlabel('Time steps')
    ax1.tick_params(axis='y', labelcolor=color)
    fig1=plt.legend(loc='center right')

    ax2=ax1.twinx()

    ax2.set_ylabel('Demand(MW)', color=color)
    ax2.plot(pb.time_steps,pb.demand,'k',label="Demand")

    fig1=plt.legend(loc='upper right')
    plt.show()
    
if __name__ == '__main__':
    
    run()

