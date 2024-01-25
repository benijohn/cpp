import matplotlib.pyplot as plt
import numpy as np
import map



# import numpy.linalg.norm() as norm

# cdef int mapLenth, mapHeight, gridSize
mapLength = 300
mapHeight = 100
gridSize = 0.1

x = np.arange(0,mapLength,gridSize)
y = np.arange(0,mapHeight,gridSize)
# # interpolation coordinates for map grid
x_coordinates, y_coordinates = np.meshgrid(x,y) 

mapDense = map.buildMap()
# # blank map
# mapDense = np.zeros([y.size, x.size])

# norm = np.linalg.norm

# for i in range(y.size):
#     for j in range(x.size):
#         # if (np.linalg.norm([450-j,100-i]) < 280 or norm([1350-j, 500-i]) < 300 or norm([2150-j, 100-i]) < 280): # or,
#         #         # norm([600-j, 500-i])<80 or norm([200-j, 480-i])<80 or norm([800-j, 300-i])<60 ,
#         #         # or norm([1800-j, 500-i])<100 or norm([2200-j, 520-i])<40 or norm([2800-j, 400-i])<60 ,
#         #         # or norm([2000-j, 440-i])<40 or norm([2400-j, 280-i])<100 or norm([2600-j, 450-i])<60 ,
#         #         # or norm([2700-j, 380-i])<50 or norm([400-j, 520-i])<40 or norm([480-j, 540-i])<30)
#         #     mapDense[i,j] = 60

#         if (norm([450-j,300-i]) < 270 or norm([1350-j, 700-i]) < 290 or norm([2150-j, 300-i]) < 270
#                 or norm([600-j, 700-i])<70 or norm([200-j, 680-i])<70 or norm([800-j, 500-i])<50
#                 or norm([1800-j, 700-i])<90 or norm([2200-j, 720-i])<30 or norm([2800-j, 600-i])<50
#                 or norm([2000-j, 640-i])<50 or norm([2400-j, 480-i])<90 or norm([2600-j, 650-i])<50
#                 or norm([2700-j, 580-i])<40 or norm([400-j, 720-i])<30 or norm([480-j, 740-i])<20
#                 or norm([1700-j, 580-i])<90 or norm([1000-j, 350-i])<80 or norm([1700-j, 370-i])<60):
#             mapDense[i,j] = 100





plt.pcolor(x_coordinates, y_coordinates, mapDense)
plt.show()