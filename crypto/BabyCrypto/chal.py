from secret import flag
from os import urandom
k1 = ord(urandom(1))
k2 = ord(urandom(1))%0x80
c = []
for i in flag:
    c.append(ord(i) + k2)
    c[-1] ^= k1
print c
