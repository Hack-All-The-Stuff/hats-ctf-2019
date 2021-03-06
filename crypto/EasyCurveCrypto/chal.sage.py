

# This file was *autogenerated* from the file chal.sage
from sage.all_cmdline import *   # import sage library

_sage_const_3 = Integer(3); _sage_const_2 = Integer(2); _sage_const_1 = Integer(1); _sage_const_0 = Integer(0); _sage_const_4 = Integer(4); _sage_const_3222648157761763022765666627526081771965464654735271102975016411514968380582603473685327245591880615139230739580267468459750307042925863983751432626117 = Integer(3222648157761763022765666627526081771965464654735271102975016411514968380582603473685327245591880615139230739580267468459750307042925863983751432626117)
from secret import flag

p = _sage_const_3222648157761763022765666627526081771965464654735271102975016411514968380582603473685327245591880615139230739580267468459750307042925863983751432626117 
F = Integers(p)

a = F(randint(_sage_const_0 ,p))
b = -F(randint(_sage_const_0 ,p))**_sage_const_2 

def add(P,Q):
    if P == O:
        return Q
    if Q == O:
        return P
    if P[_sage_const_0 ]==Q[_sage_const_0 ] and P[_sage_const_1 ]==Q[_sage_const_1 ]:
        l = (_sage_const_3 *P[_sage_const_0 ]**_sage_const_2  + _sage_const_4 *b*P[_sage_const_0 ] + b**_sage_const_2 )/(_sage_const_2 *P[_sage_const_1 ] + _sage_const_2 *a)
    elif P[_sage_const_0 ]==Q[_sage_const_0 ]:
        return O
    else:
        l = (P[_sage_const_1 ] - Q[_sage_const_1 ])/(P[_sage_const_0 ] - Q[_sage_const_0 ])
    x = l**_sage_const_2  - _sage_const_2 *b - P[_sage_const_0 ] - Q[_sage_const_0 ]
    y = l*P[_sage_const_0 ] - _sage_const_2 *a - l*x - P[_sage_const_1 ]
    return (x,y)

def mul(P, n):
    if n == _sage_const_0 :
        return O
    if n == _sage_const_1 :
        return P
    if n%_sage_const_2  == _sage_const_0 :
        P = mul(P, n/_sage_const_2 )
        return add(P, P)
    return add(mul(P, n-_sage_const_1 ), P)

def genpt():
    while True:
        x = randint(_sage_const_0 ,p)
        k = (x+b)**_sage_const_2 *x
        y = k.sqrt()
        try:
            y = int(y)
        except:
            x += _sage_const_1 
            continue
        y -= a
        break
    return (x, y)

G = genpt()

C = mul(G,flag)

print "a = ",a
print "b = ",b
print "G = ",G
print "C = ",C

