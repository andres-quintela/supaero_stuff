from common import commentjson
from pprint import pprint



class ProductionLevel:
    def __init__(self, power):
        self.power = power
    def __repr__(self):
        return str(self.power) + "MW"
    def __lt__(self, other):
        return self.power < other.power

class MandatoryShutdown:
    def __init__(self,  data):
        self.start_date = data["start_date"]
        self.end_date = data["end_date"]

class ThermalPlant:
    def __init__(self, id, data):
        self.id = id
        self.name = data["name"]
        self.offline_production_level = ProductionLevel( 0)
        self.production_levels = [ ProductionLevel(power)  for power in data["production_levels"] ]
        self.proportionnal_cost = data["proportionnal_cost"]
        self.quadratic_cost = data.get( "quadratic_cost", 0)
        self.startup_cost = data.get("startup_cost", 0)
        self.maximum_increase_rate = data.get("maximum_increase_rate", None)
        self.maximum_decrease_rate = data.get("maximum_decrease_rate", None)
        self.minimum_online_duration = data.get("minimum_online_duration", None)
        self.maximum_number_of_startups = data.get("maximum_number_of_startups", None)

        self.mandatory_shutdowns = [ MandatoryShutdown( d)
                                for d in data.get("mandatory_shutdowns", [] ) ]



class Reservoir:
    def __init__(self, id, data) :
        self.id = id
        self.name  = data["name"]
        self.initial_volume = data["initial_volume"]
        self.inflows = data["inflows"]
        self.maximum_volumes = data["maximum_volumes"]
        self.minmum_volumes = data["minimum_volumes"]
        self.water_value = data.get("water_value", None)

class HydroOperatingLevel:
    def __init__(self, id, data):
        self.id = id
        self.power = data["power"]
        self.flow = data["flow"]

class HydroPlant:
    def __init__(self, id, data):
        self.id = id
        self.name = data["name"]
        self.upstream_reservoir_name = data["upstream_reservoir_name"]
        self.downstream_reservoir_name =  data.get( "downstream_reservoir_name", None)
        self.downstream_delay =  data.get( "downstream_delay", None)
        self.maximum_increase_rate = data["maximum_increase_rate"]
        self.maximum_decrease_rate = data["maximum_decrease_rate"]
        self.operating_levels = [ HydroOperatingLevel(i, d) for i,d in enumerate(data["operating_levels"])]

class Valley:
    def __init__(self, id, data):
        self.id = id
        self.reservoirs = [Reservoir(i, d) for i, d in enumerate(data["reservoirs"]) ]
        self.hydro_plants = [ HydroPlant(i, d) for i, d in enumerate(data["hydro_plants"]) ]


class UnitCommitmentProblem:
    def __init__(self, data):

        self.number_of_time_steps= data["number_of_time_steps"]
        self.time_step_duration= data["time_step_duration"]
        self.time_steps = range(self.number_of_time_steps)

        self.thermal_plants = [ThermalPlant(i, d) for i, d in enumerate(data.get("thermal_plants", [] ))]
        self.valleys = [Valley(i, d) for i,d in enumerate(data.get("valleys", []))]


        self.demand = data.get("demand", [ 0. for t in self.time_steps])

        self.maximum_over_production = data.get("maximum_over_production", None)
        self.maximum_under_production = data.get( "maximum_under_production", None)
        self.over_production_penalty = data.get( "over_production_penalty", None)
        self.under_production_penalty = data.get( "under_production_penalty", None)


        self.electricity_prices = data.get("electricity_prices",  [0. for t in self.time_steps])

        if len(self.demand) < self.number_of_time_steps :
            print("Demand vector is shorter than the number of time steps : ",
                                                                           len(self.demand)," values for ",
                                                                              self.number_of_time_steps, " time steps.")
            last_val = self.demand[-1]
            print("Missing time steps filled with the last provided value of ", last_val, " MW.")
            self.demand += [ last_val for t in range( self.number_of_time_steps - len(self.demand))]

        if len(self.electricity_prices) < self.number_of_time_steps :
            print("Electricity prices vector is shorter than the number of time steps : ",
                                                                           len(self.electricity_prices)," values for ",
                                                                              self.number_of_time_steps, " time steps.")
            last_val = self.electricity_prices[-1]
            print("Missing time steps filled the last provided value of ", last_val, " euros")
            self.electricity_prices+= [ last_val for t in range( self.number_of_time_steps - len(self.electricity_prices))]

    def start_date(self, time_step) :
        return time_step * self.time_step_duration

    def end_date(self, time_step) :
        return (time_step + 1) * self.time_step_duration

    def time_step_to_string(self, time_step):
        start_date = self.start_date(time_step)
        hours = int( start_date/60)
        minutes = int( start_date % 60)
        if(hours <=24):
            return str(hours) + "h" + str("{:02}").format(minutes)
        days = int(hours/24)
        hours_in_last_day = int( hours % 24)
        return ( str(days) + "d" + str("{:02}h").format(hours_in_last_day)
                        + str("{:02}").format(minutes) )

def test():
    with open('data.json') as data_file:
        data = commentjson.load(data_file)

    pb = UnitCommitmentProblem(data)

    return pb

def build_from_data(name="data"):
    print( "Reading data from file : ", name)
    with open(name) as data_file:
        data = commentjson.load(data_file)
    pb = UnitCommitmentProblem(data)
    return pb
