from secret import flag
from random import randint
from gmpy2 import next_prime

p = next_prime(randint(0, 2**1024))
q = next_prime(randint(0, 2**1024))
n = p*q
ep = [next_prime(randint(1,2**20)) for _ in range(20)]
em = reduce(lambda x, y: x*y, ep)
e = [em/i for i in ep]
m = int(flag.encode('hex'), 16)
c = [pow(m, i, n) for i in e]

f = open('data', 'w')
f.write(str(n) + '\n')
for i in range(len(e)):
    f.write(str(e[i]) + '\n')
    f.write(str(c[i]) + '\n')
