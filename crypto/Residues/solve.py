from pwn import *
from gmpy2 import gcd,iroot,invert

def enc(r, x):
    r.sendline(hex(x)[2:].rstrip('L'))
    r.recvuntil('her: ')
    return int(r.recvline().strip(),16)

def fermat(n, verbose=True):
    a = iroot(n,2)[0]+1
    b = a*a - n
    while not iroot(b,2)[1]:
        a = a + 1
        b = a*a - n
    b = iroot(b,2)[0]
    p = a + b
    q = a - b
    return p, q

def crt(mp, mq, p, q):
    s = mp*invert(q,p)*q+mq*invert(p,q)*p
    return s % (p*q)

if args.REMOTE:
    r = remote('localhost', 1400)
else:
    r = process(['python2','./chal.py'])
r.recvuntil('Here is the encrypted flag: ')
c = int(r.recvline().strip(),16)
cl = [enc(r,2),enc(r,4)]
n = cl[0]**2-cl[1]
np = 0
i = 2
while np != n:
    np = n
    i+=1
    cl.append(enc(r,2**i))
    n = gcd(n,cl[0]*cl[-2]-cl[-1])

#print "n = %d"%n

p, q = fermat(n)

#print "p = %d"%p
#print "q = %d"%q

if p%4==1 or q%4==1:
    print "I'm lazy just rerun"
    exit()

e = 65537
d = invert(e, (p-1)*(q-1))
f2 = pow(c, d, n)
fp = pow(f2%p, (p+1)/4, p)
fq = pow(f2%q, (q+1)/4, q)

f = [
        crt(fp,fq,p,q),
        crt(-fp,fq,p,q),
        crt(fp,-fq,p,q),
        crt(-fp,-fq,p,q)
        ]
for i in f:
    try:
        pt = hex(i)[2:].rstrip('L')
        pt = '0'*(len(pt)%2)+pt
        pt = pt.decode('hex')
    except:
        continue
    if('HATS' in pt):
        print pt

