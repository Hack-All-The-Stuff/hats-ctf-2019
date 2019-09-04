from secret import flag
from random import randint
from gmpy2 import next_prime

def genrsa(m, e, l):
    p = next_prime(randint(0, 2**l))
    q = next_prime(randint(0, 2**l))
    N = p * q
    return pow(m, e, N), N

dataf = open('data','w')

e = next_prime(9**3)
m = int(flag.encode('hex'), 16)
for _ in range(9**2):
    c, N = genrsa(m, e, 1024)
    dataf.write("%d\n%d\n\n" % (c, N))

dataf.close()
