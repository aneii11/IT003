import numpy as np

from time import time

for i in range(1,11,1):
    filename = '/home/an3ii/IT003/test_data/test '+str(i)
    with open(filename, 'r') as f:
        data = []
        raw_data = f.read()
        test = raw_data.split(' ')
        test.remove('')
        #print(test)
        for j in test:
            data.append(float(j))
        start = time()
        sorted_arr = np.sort(data)
        stop = time()
        print("Test "+str(i)+": ",round((stop-start)*1000,2), 'ms' )