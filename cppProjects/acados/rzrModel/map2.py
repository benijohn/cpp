import matplotlib.pyplot as plt
import numpy as np
import time

rng = np.random.default_rng()
# map dimensions in meters
mapLength = 80
mapHeight = 60
gridSize = 0.1

t = time.time()
x = np.arange(0,mapLength,gridSize)
y = np.arange(0,mapHeight,gridSize)
# # interpolation coordinates for map grid
x_coordinates, y_coordinates = np.meshgrid(x,y) 

print(time.time()-t)

t = time.time()
mapDense = np.zeros([y.size, x.size])
print(time.time()-t)

 # random obstacles
num_obstacles = 200
obx = np.random.uniform(0,mapLength,num_obstacles)
oby = np.random.uniform(0,mapHeight,num_obstacles)
obr = np.random.uniform(0,1.5,num_obstacles)

# explicitly defined obstacles
# obx = np.array([45,60,180,200,270,170,135,20,220,240,40,100,215,80,280,260,48,170])
# oby = np.array([30,70,70,64,58,58,70,68,72,48,72,35,30,50,60,65,74,37])
# obr = np.array([20,7,9,5,4,9,19,7,3,9,3,8,20,5,5,5,2,6])
# num_obstacles = obx.size

t = time.time()
for i in range(num_obstacles):
    N = np.sqrt(np.square(obx[i]-x_coordinates) + np.square(oby[i]-y_coordinates))
    mapDense[N<obr[i]] = 100


np.save("mapSmallObst.npy", mapDense)


plt.pcolor(x_coordinates, y_coordinates, mapDense)
plt.show()