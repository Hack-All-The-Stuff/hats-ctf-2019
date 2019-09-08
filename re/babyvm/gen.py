def pushnum(n):
    n=int(n)
    s=''
    t=0
    if(n<0):
        n=-n
        t=1
    if(n<=9):
        return str(n)+'u0s' if t==1 else str(n)
    narr=[]
    while n>0:
        narr=[n%9]+narr
        n/=9
    for i in narr:
        s=s+'u9mu'+str(i)+'a'
    return s[4:]+'u0s' if t==1 else s[4:]

'''
flag = "HATS{vm_r3_15_fun_r19h7?}"
gens = []
s = ''
for i in range(len(flag)):
    gens.append(pushnum(ord(flag[i]) -i ))
for i in range(len(gens),0,-1):
    s += '0r0u' + pushnum(i-1)+'r'
    s += '0u' + gens[i-1] + 'u'
print s
'''

msg = "Flag : "
s = ''
for i in msg:
    s += '0u' + pushnum(ord(i)) + 'up'
print s
