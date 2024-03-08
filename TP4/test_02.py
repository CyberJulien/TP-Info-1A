import verlet
from random import random
from time import time
import numpy as np
size = 10000000
a = [random() for i in range(size)]
b = [random() for i in range(size)]
npa = np.array(a)
npb = np.array(b)
t1 = time()
out = [0] * len(a)
for i in range(len(a)):
    out[i] = a[i] + b[i]
t2 = time()
out2 = verlet.sum_lists(a,b)
t3 = time()
out3 = np.array(a) + np.array(b)
t4 = time()
out4 = npa + npb
t5 = time()
print("sums : python:", t2-t1,"c: " ,  t3-t2, "numpy", t4 - t3, "cached numpy", t5 - t4)
t1 = time()
out = [0] * len(a)
for i in range(len(a)):
    out[i] = a[i] - b[i]
t2 = time()
out2 = verlet.sub_lists(a,b)
t3 = time()
out3 = np.array(a) - np.array(b)
t4 = time()
out4 = npa - npb
t5 = time()
print("subs : python:", t2-t1,"c: " ,  t3-t2, "numpy", t4 - t3, "cached numpy", t5 - t4)