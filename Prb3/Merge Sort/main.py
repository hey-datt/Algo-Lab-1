import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import math

uniform_df = pd.read_csv('D:/B.TECH/2nd YEAR(2021-22)/4th Sem/Algorithm Lab/Assignment 1/Prb3/Merge Sort/uniform_comparisons.txt')
normal_df = pd.read_csv('D:/B.TECH/2nd YEAR(2021-22)/4th Sem/Algorithm Lab/Assignment 1/Prb3/Merge Sort/normal_comparisons.txt')

n_uniform = uniform_df['num'].to_numpy()
comp_uniform = uniform_df['avg_comp'].to_numpy()
time_uniform = uniform_df['avg_time'].to_numpy()
comp_ratio_uniform = comp_uniform/(n_uniform*np.log2(n_uniform))
#comp_ratio_uniform = [(c/(n*math.log2(n))) for c, n in zip(comp_uniform ,n_uniform)]
time_ratio_uniform = time_uniform/(n_uniform*np.log2(n_uniform))
#time_ratio_uniform = [(t/(n*math.log2(n))) for t, n in zip(time_uniform ,n_uniform)]

n_normal = normal_df['num'].to_numpy()
comp_normal = normal_df['avg_comp'].to_numpy()
time_normal = normal_df['avg_time'].to_numpy()
comp_ratio_normal = comp_normal/(n_normal*np.log2(n_normal))
#comp_ratio_normal = [(c/(n*math.log2(n))) for c, n in zip(comp_normal ,n_normal)]
time_ratio_normal = time_normal/(n_normal*np.log2(n_normal))
#time_ratio_normal = [(t/(n*math.log2(n))) for t, n in zip(time_normal ,n_normal)]


fig, axis = plt.subplots(2, 1, figsize=(10, 7))

fig.suptitle('Comparision and Time Ratio')

axis[0].plot(comp_ratio_uniform, 'o-', label='Uniform')
axis[0].plot(comp_ratio_normal, 'o--', label='Normal')
axis[0].legend()
axis[0].set_ylabel(r'$\frac{comp}{n*lgn}$', rotation=0, labelpad=13)

axis[1].plot(time_ratio_uniform, 'o-', label='Uniform')
axis[1].plot(time_ratio_normal, 'o--', label = 'Normal')
axis[1].legend()
axis[1].set_ylabel(r'$\frac{time}{n*lgn}$', rotation=0, labelpad=13)

plt.xlabel(r'n [array size = $2^n$]')

plt.show()