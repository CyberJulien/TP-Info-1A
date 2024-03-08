import verlet
from dataclasses import dataclass
from time import sleep
from random import random
MODE = "input"
FILE="out.csv"

@dataclass(repr=True)
class Point():
    x: float
    xprec : float
    y : float
    yprec : float
    m : float
    r : float
    colorR : int
    colorG : int
    colorB : int
    _id : int

p = Point(0.65,3.45,0.0,0.0,0.0,0.0,255,255,0,0)

test = verlet.Test_Verlet(p)
print(test)

tab = verlet.Test_Listes([1,2,3,4.21,5.87])
print(tab)