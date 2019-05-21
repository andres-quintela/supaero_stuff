import sys, os
sys.path.append(os.getcwd()+'/../')
from common import parc
from timeit import default_timer as timer
import math
import matplotlib.pyplot as plt



def run(data_file):

    # read the data file, and put everything into python objects
    pb = parc.build_from_data(data_file)
    #let's consider the first thermal plant
    thermal_plant = pb.thermal_plants[0]

    #we start a timer to count how long our computations take
    start_time = timer()


    #we initialize our indices
    time_steps = pb.time_steps
    # the plant is either offline or at one of its power level
    # so our set of states for dynamic programming is the union
    #  of the offline state and the production levels
    states = [ thermal_plant.offline_production_level] + thermal_plant.production_levels

    # let's initialize our bellman values to - infinity
    bellman_values = {}
    for state in states:
        bellman_values[state] = {}
        for t in range(-1,4):
			#[value,previous state,nb of startups]
            bellman_values[state][t] = [- float("inf"),0,0]
    
  

    # initialization of the bellman values on the first time step
    # since the plant is initially offline, the bellman value for the offline state at the first time step
    # is set to 0. Since the other states are not feasible at this time step, we keep their bellman
    # values at + infinity
    initial_time_step = -1
    initial_state = thermal_plant.offline_production_level
    bellman_values[initial_state][initial_time_step][0] = 0
    

    # implement the dynamic programming algorithm here to fill all bellman_values[state][t]
    def transition_value(state,previous_state,time):
		startup=false
        transition_val=state.power*pb.electricity_prices[time]*pb.time_step_duration/60 - state.power*thermal_plant.proportionnal_cost*pb.time_step_duration/60 -  (state.power**2)*thermal_plant.quadratic_cost*pb.time_step_duration/60
        if previous_state==thermal_plant.offline_production_level and state != thermal_plant.offline_production_level:
            transition_val=transition_val-thermal_plant.startup_cost
            startup=true
        if (state.power-previous_state.power)>thermal_plant.maximum_increase_rate:
            transition_val= - float("inf")
        if (previous_state.power-state.power)>thermal_plant.maximum_decrease_rate:
            transition_val= - float("inf")
        return transition_val,startup
    
    
    max_val= - float("inf")  
    previous_state=initial_state    
    
    for t in time_steps:
        print("timestep =",t )
        for state in states:
            print("new state loop")
            for previous_state in states:
                print(state)
                print(previous_state)
                trans_val,startup=transition_value(state,previous_state,t)
                temp_val=trans_val+ bellman_values[previous_state][t-1][0]
                if temp_val >= max_val:
                    max_val=temp_val
                    next_state=state
                    p_state=previous_state
                    print("max val changed")
            bellman_values[next_state][t]=[max_val,p_state]
            max_val=- float("inf")
            temp_val=- float("inf")
      
        
             
    # what is the best value we can find at the last time step ?
    last_time_step = time_steps[-1]
    opt_value = - float("inf")
    for state in states:
        if bellman_values[state][last_time_step][0] > opt_value:
            opt_value = bellman_values[state][last_time_step][0]
            final_state=state
            
    
    # let's find the optimal production plan

    program = []
   
    previous_state=final_state
    for t1 in time_steps:
        t=len(time_steps)-t1-1
        program=[previous_state.power]+program
        temp_state=bellman_values[previous_state][t][1]
        previous_state=temp_state
        
    #add initial 0 state
    program = [thermal_plant.offline_production_level.power]+program

	
    end_time = timer()
    print("The optimal value is : ", opt_value)
    print("It was found in : {:.2E} sec".format(end_time - start_time))
	

    print("Program : ", program)
    plt.plot(program)
    plt.show()


if __name__ == '__main__':
    run("thermal_plant_toy.json")
