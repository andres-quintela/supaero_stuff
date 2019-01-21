import numpy as np
import math as math
import matplotlib.pyplot as plt


#air
r=287
gamma=1.4
cp=gamma*r/(gamma-1)

#after combustion
r_2=291.6
gamma_2= 1.33
cp_2=gamma_2*r_2/(gamma_2-1)

#kerosene calorific power

P_kerosene=42800000  #J/kg


M0=0.75
alt_feet = 35000 #feet
alt = alt_feet*0.3048
p0 = 22700 #pa
t0 = 217 # K

bypass=11
psi_intake=0.97
r_comp=41
n_comp=0.9
n_fan=0.92
n_comb=0.99
psi_comb=0.95
#t_max = 1640 #kelvin
n_shaft=0.98
n_hp=0.89
n_lp=0.90
psi_nozzle=0.97
n_fan=0.92

mass_flow = 215
mass_core = mass_flow/(bypass+1)
mass_fan = mass_flow - mass_core 

counter=0
array_propu=[]
array_thermal=[]
array_specific=[]
array_t_max=[]
array_total=[]




for t_max in np.linspace(1200,2000,50):
	

	#intake
	pi0=(1+(gamma-1)*0.5*M0**2)**(gamma/(gamma-1))*p0 #total pressure before intake
	pi2=psi_intake*pi0 #total pressure after intake
	ti0=(1+0.5*(gamma-1)*M0**2)*t0 #total temperature before and after intake (isentropic)
	ti2=ti0
	a0=math.sqrt(gamma*r*t0)
	v0=a0*M0

	#compressor
	pi3=pi2*r_comp  #total pressure after compressor
	ti3=r_comp**((gamma-1)/(gamma*n_comp))*ti0  #total temperature after compressor
	w_comp=mass_core*(ti3-ti2)*cp

	#combustion chamber
	f=(cp_2*t_max-cp*ti3)/(n_comb*P_kerosene-cp_2*t_max) #fuel to air ratio
	pi4=pi3*psi_comb
	ti4=t_max

	#high pressure turbine
	w_hpturb=-w_comp/n_shaft
	ti45=w_hpturb/(mass_core*(1+f)*cp_2)+ti4
	pi45=pi4/(ti4/ti45)**(gamma_2/(n_hp*(gamma_2-1)))

	#low pressure

	M_fict=math.sqrt( ((pi45/p0)** ((gamma_2-1)/gamma_2)  -1)  *2/   (gamma_2-1))

	t_fict=ti45/(1+M_fict**2*0.5*(gamma_2-1))
	a_fict=math.sqrt(gamma_2*r_2*t_fict)
	v_fict=M_fict*a_fict
	w_fict=0.5*mass_core*(1+f)*v_fict**2-0.5*mass_core*v0**2


	w_fan=bypass/(2+bypass)*w_fict
	w_lpturb=-w_fan
	ti5=w_lpturb/(mass_core*(1+f)*cp_2)+ti45
	pi5=pi45/(ti45/ti5)**(gamma_2/(n_lp*(gamma_2-1)))

	#nozzle

	pi9=psi_nozzle*pi5
	ti9=ti5

	M9=math.sqrt( ((pi9/p0)** ((gamma_2-1)/gamma_2)  -1)  *2/   (gamma_2-1))
	t9=ti9/(1+0.5*(gamma_2-1)*M9**2)
	a9=math.sqrt(gamma_2*r_2*t9)
	v9=a9*M9

	#fan

	ti12=ti2
	pi12=pi2

	ti17=w_fan*n_shaft/((mass_fan)*cp)+ti12
	pi17=pi12*(ti17/ti12)**(gamma*n_fan/(gamma-1))
	pi19=pi17*psi_nozzle
	M19=math.sqrt( ((pi19/p0)** ((gamma-1)/gamma)  -1)  *2/   (gamma-1))
	ti19=ti17

	t19=ti17/(1+0.5*(gamma-1)*M19**2)
	a19=math.sqrt(gamma*r*t19)
	v19=a19*M19


	#efficiencies

	#variation in KE
	w_ce=0.5*mass_core*((1+f)*v9**2-v0**2)+0.5*mass_fan*(v19**2-v0**2)

	#calorific energy
	w_f=P_kerosene*f*mass_core

	#force
	Fx=mass_core*((1+f)*v9-v0)+mass_fan*(v19-v0)

	#propulsive power
	w_p=Fx*v0


	n_thermal=w_ce/w_f

	n_propu=w_p/w_ce

	n_total=n_thermal*n_propu


	#specific consumption
	c_s=mass_core*f/Fx

	#specific thrust

	F_s=Fx/mass_flow
	
	
	counter=counter+1
	array_propu.append(n_propu)
	array_total.append(n_total)
	array_thermal.append(n_thermal)
	array_specific.append(F_s)
	array_t_max.append(t_max)
	
fig, ax1 = plt.subplots()


color = 'k'


ax1.plot(array_t_max,array_propu,'b',label='Propulsif')
ax1.plot(array_t_max,array_thermal,'r',label='Thermique')
ax1.plot(array_t_max,array_total,'g',label='Total')

ax1.set_xlabel('T_max(K)')
ax1.set_ylabel('Rendements ', color=color)
ax1.tick_params(axis='y', labelcolor=color)

fig1=plt.legend(loc='center left')

ax2=ax1.twinx()

ax2.set_ylabel('Poussée specifique ', color=color)
ax2.plot(array_t_max,array_specific,'k',label='Poussé specifique')

fig1=plt.legend(loc='best')




fig.tight_layout()
plt.savefig('tmax.png')

	
	
