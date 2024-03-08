import verlet
from random import random
a = 2#random()
b = 1#random()
print(a)
print(b)
if (verlet.sum_two_numbers(a, b) == a + b):
    print("Successfull!")
else:print("error")
print(verlet.sum_two_numbers(a, b))
print(a+b)