import matplotlib.pyplot as plt
max_value = int(100)

f = open('D:/B.TECH/2nd YEAR(2021-22)/4th Sem/Algorithm Lab/Assignment 1/Prb1B/normal_dist.txt')
array = [float(x) for x in f.read().split('\n')[:-1]]

plt.hist(array, bins=range(max_value+1))
plt.xlabel('Values in the set')
plt.ylabel('Frequency')
plt.show()