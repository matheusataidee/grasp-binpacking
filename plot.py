import matplotlib.pyplot as plt
import numpy as np
import math

y = np.array([0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1])
x_nextfit = np.array([1.248120301, 1.248120301, 1.255255255, 1.256281407, 1.259398496, 1.261261261, 1.263157895, 1.272727273, 1.281407035, 1.287878788])
x_firstfit = np.array([1, 1, 1, 1, 1, 1, 1, 1, 1, 1])
x_bestfit = np.array([1, 1, 1, 1, 1, 1, 1, 1, 1, 1])
x_gurobi_ub = np.array([1, 1, 1, 1, 1, 1, 1, 1, 1, 1])

x_grasp = np.array([1, 1, 1, 1, 1, 1, 1, 1, 1, 1])
x_grasp_pop = np.array([1, 1, 1, 1, 1, 1, 1, 1, 1, 1])

plt.plot(x_nextfit, y, color='orange', label='Next fit')
plt.plot(x_firstfit, y, color='blue', label='First fit')
plt.plot(x_bestfit, y, 'r--', label='Best fit')
#plt.plot(x_gurobi_ub, y, 'r--', label='Gurobi Upper Bound')

#plt.plot(x_grasp, y, color='orange', label='GRASP default')
#plt.plot(x_grasp_pop, y, 'r--', label='GRASP with POP')


plt.legend()
plt.show()