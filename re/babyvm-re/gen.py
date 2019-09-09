def pushnum(n):
    n=int(n)
    s=''
    t=0
    if(n<=9):
        return str(n)+'u0s' if t==1 else str(n)
    narr=[]
    while n>0:
        narr=[n%2]+narr
        n/=2
    s = '2u' + str(4*narr[0] + 2*narr[1] + narr[2])
    for i in narr[3:]:
        s += 'mi' if i==1 else 'm'
    return s


flag = "HATS{vm_r3_15_fun_r19h7?}"
gens = []
s = ''
for i in range(len(flag)):
    gens.append(pushnum(ord(flag[i]) -i+i ))
for i in range(len(gens),0,-1):
    s += '0r' + pushnum(i-1)+'r'
    s += gens[i-1] + 'u'
print s
'''

msg = "\n"
s = ''
for i in msg:
    s += pushnum(ord(i)) + 'up'
print s
'''
