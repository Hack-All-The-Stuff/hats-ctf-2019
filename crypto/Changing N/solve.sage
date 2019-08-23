f = open('data', 'r').read().split('\n')

c = []
n = []

for i in range(9**2):
    c.append(int(f[3*i]))
    n.append(int(f[3*i+1]))

ce = crt(c,n)

print ce.nth_root(733)
