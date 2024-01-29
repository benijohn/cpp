import matplotlib.pyplot as plt
import numpy as np
import time
# import map
rng = np.random.default_rng()
mapLength = 300
mapHeight = 120
gridSize = 0.1

t = time.time()
x = np.arange(0,mapLength,gridSize)
y = np.arange(0,mapHeight,gridSize)
# # interpolation coordinates for map grid
x_coordinates, y_coordinates = np.meshgrid(x,y) 

print(time.time()-t)

# mapDense = map.buildMap()
# blank map

t = time.time()
mapDense = np.zeros([y.size, x.size])
print(time.time()-t)



num_obstacles = 20
obx = np.random.uniform(0,mapLength,num_obstacles)
oby = np.random.uniform(0,mapHeight,num_obstacles)
obr = np.random.uniform(0,30,num_obstacles)

obx = np.array([45,60,180,200,270,170,135,20,220,240,40,100,215,80,280,260,48,170])
oby = np.array([30,70,70,64,58,58,70,68,72,48,72,35,30,50,60,65,74,37])
obr = np.array([20,7,9,5,4,9,19,7,3,9,3,8,20,5,5,5,2,6])
num_obstacles = obx.size

t = time.time()
for i in range(num_obstacles):
    N = np.sqrt(np.square(obx[i]-x_coordinates) + np.square(oby[i]-y_coordinates))
    mapDense[N<obr[i]] = 100

# N1 = np.sqrt(np.square(45-x_coordinates) + np.square(30-y_coordinates))
# np.savetxt("map.csv", mapDense, delimiter=",")
# np.savetxt("x_coord.csv", x_coordinates, delimiter=',')
# np.savetxt("y_coord.csv", y_coordinates, delimiter=',')
np.save("map.npy", mapDense)
print(time.time()-t)
# t = time.time()
# #mapDense[np.where(N1<27)] = 1
# mapDense[N1<27] = 1
# print(time.time()-t)


# norm = np.linalg.norm

# it = np.nditer([x_coordinates, y_coordinates])

# for x,y in it:
#     # print(x)
#     # print(y)
#     if (norm([450-x,300-y]) < 270 or norm([1350-x, 700-y]) < 290 or norm([2150-x, 300-y]) < 270
#         or norm([600-x, 700-y])<70 or norm([200-x, 680-y])<70 or norm([800-x, 500-y])<50
#         or norm([1800-x, 700-y])<90 or norm([2200-x, 720-y])<30 or norm([2800-x, 600-y])<50
#         or norm([2000-x, 640-y])<50 or norm([2400-x, 480-y])<90 or norm([2600-x, 650-y])<50
#         or norm([2700-x, 580-y])<40 or norm([400-x, 720-y])<30 or norm([480-x, 740-y])<20
#         or norm([1700-x, 580-y])<90 or norm([1000-x, 350-y])<80 or norm([1700-x, 370-y])<60):
#         mapDense[y,x] = 100

# for i in range(y.size):
#     for j in range(x.size):
#         # if (np.linalg.norm([450-j,100-i]) < 280 or norm([1350-j, 500-i]) < 300 or norm([2150-j, 100-i]) < 280): # or,
#         #         # norm([600-j, 500-i])<80 or norm([200-j, 480-i])<80 or norm([800-j, 300-i])<60 ,
#         #         # or norm([1800-j, 500-i])<100 or norm([2200-j, 520-i])<40 or norm([2800-j, 400-i])<60 ,
#         #         # or norm([2000-j, 440-i])<40 or norm([2400-j, 280-i])<100 or norm([2600-j, 450-i])<60 ,
#         #         # or norm([2700-j, 380-i])<50 or norm([400-j, 520-i])<40 or norm([480-j, 540-i])<30)
#         #     mapDense[i,j] = 60

        # if (norm([450-j,300-i]) < 270 or norm([1350-j, 700-i]) < 290 or norm([2150-j, 300-i]) < 270
        #         or norm([600-j, 700-i])<70 or norm([200-j, 680-i])<70 or norm([800-j, 500-i])<50
        #         or norm([1800-j, 700-i])<90 or norm([2200-j, 720-i])<30 or norm([2800-j, 600-i])<50
        #         or norm([2000-j, 640-i])<50 or norm([2400-j, 480-i])<90 or norm([2600-j, 650-i])<50
        #         or norm([2700-j, 580-i])<40 or norm([400-j, 720-i])<30 or norm([480-j, 740-i])<20
        #         or norm([1700-j, 580-i])<90 or norm([1000-j, 350-i])<80 or norm([1700-j, 370-i])<60):
        #     mapDense[i,j] = 100






plt.pcolor(x_coordinates, y_coordinates, mapDense)
plt.show()