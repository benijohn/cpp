
import numpy as np
import matplotlib.pyplot as plt
import scipy
import time
# np.random.seed(1)

# t = time.time()
# map = np.genfromtxt("map.csv", delimiter=',')
# print(map.shape)

# mapLength = 300
# mapHeight = 120
# gridSize = 0.1

# x = np.arange(0,mapLength,gridSize)
# y = np.arange(0,mapHeight,gridSize)

# v_0 = 0
# r_0 = 0
# V_0 = 10
# X_0 = 10
# Y_0 = 55
# Psi_0 = 0

# x0 = np.array([V_0, v_0, r_0, X_0, Y_0, Psi_0])

# num_samples = 6000
# sizeElite = 100
# dt = 0.05
# preview = 3

# print(time.time()-t)

def eliteSet(X,Y,V,r,map,x,y,XG,YG,sizeElite):
    totalCost = getTrajectoryCost(X,Y,V,r,map,x,y,XG,YG)
    eliteIdx = totalCost.argsort()[:sizeElite]
    return eliteIdx

def getTrajectoryCost(X,Y,V,r,map,x,y,XG,YG):
    # trajCost = np.cumsum(scipy.interpolate.interpn((y,x),map,(Y,X),bounds_error=False,fill_value=5000),axis=0)

    # trajCost = np.cumsum(scipy.interpolate.interpn((y,x),map,(Y,X),bounds_error=False,fill_value=5000),axis=0)
    trajCost = scipy.interpolate.interpn((y,x),map,(Y,X),bounds_error=False,fill_value=5000)


    # print(trajCost)
    # timeToGoal = np.divide(np.sqrt(np.square(X[-1]-300)+np.square(Y[-1]-50)),V[-1])
    # timeToGoal[timeToGoal<0] = 1000
    #distanceToGoal = np.sqrt(np.square(X[-1]-XG)+np.square(Y[-1]-YG))
    distanceToGoal = np.sqrt(np.square(X-XG)+np.square(Y-YG))

    # print(distanceToGoal.min())
    cost = 2*trajCost + 0.05*np.square(np.multiply(V,r)) + 5000*np.exp(-V) + 3*distanceToGoal
    #cost = trajCost
    # am I summing the trajectory cost twice? It looks like yes I am summing cumsum
    intCost = np.sum(cost,axis=0)
    #totalCost = 500*distanceToGoal + intCost
    totalCost = intCost
    return totalCost    


def planTrajectory(x0, preview, dt, num_samples, map, x, y, XG, YG, sizeElite, plot=False):
    num_points = int(preview/dt)
    beta = 30 # weighting term to change amount of soft maxxing
    d_r = 2
    d_V = 10
    d_v = 2

    # generate samples
    v_dot = np.random.uniform(-dt*d_v, dt*d_v, [num_points, num_samples])
    r_dot = np.random.uniform(-dt*d_r, dt*d_r, [num_points, num_samples])
    #V_dot = np.random.uniform(-dt*d_V, dt*d_V, [num_points, num_samples])

    V_0 = x0[0]
    v_0 = x0[1]
    r_0 = x0[2]
    X_0 = x0[3]
    Y_0 = x0[4]
    Psi_0 = x0[5]

    Vu = 12
    Vl = 3
    Vdiff = Vu-Vl

    # testing a sampling bounds scheme
    # V_star = (V_0-14)/22
    V_star = (V_0-Vl-Vdiff/2)/Vdiff
    V_ub = dt*d_V - np.tanh(V_star)*dt*d_V
    V_lb = -dt*d_V - np.tanh(V_star)*dt*d_V
    V_dot = np.random.uniform(V_lb, V_ub, [num_points, num_samples])

    # simple cumsum "dynamics"
    v = np.concatenate((v_0*np.ones([1,num_samples]), v_0 + np.cumsum(v_dot,axis=0)),axis=0)
    r = np.concatenate((r_0*np.ones([1,num_samples]), r_0 + np.cumsum(r_dot,axis=0)),axis=0)
    V = np.concatenate((V_0*np.ones([1,num_samples]), V_0 + np.cumsum(V_dot,axis=0)),axis=0)
    Psi = Psi_0 + dt*np.cumsum(r,axis=0)

    X_dot = np.multiply(np.cos(Psi),V) - np.multiply(np.sin(Psi),v)
    Y_dot = np.multiply(np.sin(Psi),V) + np.multiply(np.cos(Psi),v)

    X = X_0 + dt*np.cumsum(X_dot,axis=0)
    Y = Y_0 + dt*np.cumsum(Y_dot,axis=0)

    eliteIdx = eliteSet(X,Y,V,r,map,x,y,XG,YG,sizeElite)

    Xe = X[:,eliteIdx] 
    Ye = Y[:,eliteIdx]
    Ve = V[:,eliteIdx]
    re = r[:,eliteIdx]
    ve = v[:,eliteIdx]
    Psie = Psi[:,eliteIdx]

    totalCost = getTrajectoryCost(Xe,Ye,Ve,re, map, x, y, XG, YG)
    minCost = totalCost.min()
    adjustedCost = totalCost - minCost
    expCost = np.exp(-adjustedCost/beta)
    weights = np.divide(expCost,np.sum(expCost))
    # print(weights)

    # best trajectory -> REFERENCE TRAJECTORY
    bestX = np.sum(np.multiply(Xe,weights),axis=1)
    bestY = np.sum(np.multiply(Ye,weights),axis=1)
    bestr = np.sum(np.multiply(re,weights),axis=1)
    bestV = np.sum(np.multiply(Ve,weights),axis=1)
    bestv = np.sum(np.multiply(ve,weights),axis=1)
    bestPsi = np.sum(np.multiply(Psie,weights),axis=1)

    if plot:
        # x_coordinates, y_coordinates = np.meshgrid(x,y)
        # fig = plt.figure()
        # plt.pcolor(x_coordinates, y_coordinates, map)
        plt.plot(X[:,:100],Y[:,:100],color='k',alpha= 0.05)
        plt.plot(Xe,Ye,color='r',alpha=0.2)
        plt.plot(bestX,bestY,color='b')
        # print(bestV.shape)

        # fig = plt.figure()
        # plt.plot(V[:,eliteIdx])

        # fig = plt.figure()
        # plt.plot(np.multiply(V[:,eliteIdx],r[:,eliteIdx]))

        # plt.show()
    bestTrajectory = np.array([bestV, bestv, bestr, bestX, bestY, bestPsi])
    return bestTrajectory

# t = time.time()
# planTrajectory(x0, preview, dt, num_samples, map, x, y, sizeElite=sizeElite, plot=True)
# #planTrajectory(x0, preview, dt, num_samples, map, x, y)
# print(time.time()-t)
# This function was intended to be used to feed multiple trajectories to the NLMPC right now we are only taking one, but we can eventually 
# make this one to return multiple candidate trajectories

# function eliteSet = findEliteSet(X, Y, r, V, sizeElite, map, x1, y1)
    
#     trajCost = cumsum(interp2(x1,y1,map,X,Y));

#     ay = V.*r;
#     timeToGoal = sqrt((X(end,:)-300).^2 + (Y(end,:) - 200).^2)./V(end);
#     cost = trajCost + 0.1*ay.^2;
#     intCost = sum(cost);

#     totalCost = 5*timeToGoal + intCost;
#     [~, eliteSet] = mink(totalCost, sizeElite);
# end

