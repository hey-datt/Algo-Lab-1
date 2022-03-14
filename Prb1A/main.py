import numpy as np  
import csv  
import matplotlib.pyplot as plt  


random_num = np.zeros(int(10e6),dtype=int)

y=range(101)


with open('D:/B.TECH/2nd YEAR(2021-22)/4th Sem/Algorithm Lab/Assignment 1/Prb1A/uniform_dist.csv') as csv_file:  
    csvreader = csv.reader(csv_file, delimiter=',')  
    count = 0  
    for row in csvreader:  
        
        random_num[count] = row[0]
        count = count + 1
        
    

plt.figure("Histogram of Uniform Distribution Dataset")
plt.title("Histogram of Uniform Distribution Dataset")
plt.xlabel("Number")
plt.ylabel("Frequency")
plt.hist(random_num,y) 
plt.show()
