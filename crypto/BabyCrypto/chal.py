from secret import flag
from os import urandom
k1 = ord(urandom(1))
k2 = ord(urandom(1))%0x80
c = []
for i in flag:
    c.append(ord(i) + k2)
    c[-1] ^= k1
print c
'''
[194, 203, 222, 221, 53, 44, 254, 255, 251, 45, 41, 45, 60, 51, 58, 241, 254, 56, 254, 38, 51, 255, 251, 255, 55]
'''
