from pwn import *
from gmpy2 import iroot


counter = 0
def checkpad(s,r):
    global counter
    counter += 1
    r.sendline('2')
    r.sendline(s.encode('hex'))
    r.recvuntil('Decrypted message:\n')
    return int(r.recvline().strip())+1

r = process(['python2','./chal.py'])
print r.recvuntil('I recieved:\n')
c = r.recvline().strip().decode('hex')
c = [c[i] for i in range(len(c))] # c as a string
ci = [ord(i) for i in c] # c but in integers
co = ci # original c
m = []

# determine pad length
for i in range(1,16):
    c[-17]=chr(ci[-17]^i)
    if checkpad(''.join(c),r) == 1:
        i ^= 1
        for j in range(i):
            ci[-17-j]^=i
        break

plen = i

# looping through first block special cuz got known padding alr
for j in range(plen,16):
    for k in range(j):
        c[-17-k]=chr(ci[-17-k]^(j+1))
    for k in range(256):
        c[-17-j]=chr(k)
        if checkpad(''.join(c),r) == 1:
            print hex(k ^ (j+1) ^ ci[-17-j])[2:]
            m.append(k ^ (j+1) ^ ci[-17-j])
            ci[-17-j] = k ^ (j+1)
            break

#looping through the other blocks
for _ in range(len(c)/16-2):
    c = c[:-16]
    ci = ci[:-16]
    co = co[:-16]
    for j in range(16):
        c[-1-j] = chr(co[-1-j])
    for j in range(16):
        for k in range(j):
            c[-17-k]=chr(ci[-17-k]^(j+1))
        for k in range(256):
            c[-17-j]=chr(k)
            if checkpad(''.join(c),r) == 1:
                print hex(k ^ (j+1) ^ co[-17-j])[2:]
                m.append(k ^ (j+1) ^ co[-17-j])
                ci[-17-j] = k ^ (j+1)
                break

m = ''.join(hex(i)[2:].zfill(2) for i in m[::-1])
m = hex(iroot(int(m,16),3)[0])[2:].rstrip('L').decode('hex')
print m
print counter
