import numpy as np
from mppiPlanner import planTrajectory
import time
import matplotlib.pyplot as plt

X0 = np.array([10.0, 0.0, 0.0, 10.0, 45.0, 0.0])  # Intitalize the states [x,y,v,th,th_d]
N_horizon = 20  # Define the number of discretization steps
T_horizon = 1.0  # Define the prediction horizon
dt = T_horizon/N_horizon

sizeElite = 100
map = np.genfromtxt("map.csv", delimiter=',')

mapLength = 300
mapHeight = 120
gridSize = 0.1

x = np.arange(0,mapLength,gridSize)
y = np.arange(0,mapHeight,gridSize)

x_coordinates, y_coordinates = np.meshgrid(x,y)
fig1 = plt.figure()
plt.pcolor(x_coordinates, y_coordinates, map)


XG = 250
YG = 60

N=200
plan = np.ndarray([6,N+1])
print(plan)
plan[:,0] = X0
for i in range(N):
    ref_traj = planTrajectory(x0=X0, preview=3*T_horizon, dt=dt, num_samples=6000, map=map, x=x, y=y, XG=XG, YG=YG, sizeElite=sizeElite, plot=False)
    X0 = ref_traj[:,1]
    # print(X0.shape)
    # print(ref_traj.shape)
    plan[:,i+1] = X0
    
print(plan[3,:])
print(plan[4,:])
print(plan[0,:])
plt.plot(plan[3,:],plan[4,:],color='g',linewidth=3)
plt.show()    