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

p1 = Point(0.65,3.45,0.0,0.0,0.0,0.0,255,255,0,0)
p2 = Point(0.65,10.45,0.0,6.0,0.0,0.0,100,100,0,0)
p3 = Point(0,0,0.0,0.0,0.0,10.0,255,25,0,0)

test = verlet.Test_Verlet(p)
print(test)

tab = verlet.Test_Listes([p1,p2,p3])
print(tab)