from gmpy2 import gcd, invert

def xgcd(a, b):
    if a == 0:
        return (b, 0, 1)
    g, x, y = xgcd(b%a, a)
    return (g, y-(b/a)*x, x)

f = open('data', 'r').read().split('\n')
n = int(f[0])
e = []
c = []
for i in range(1,len(f)-1,2):
    e.append(int(f[i]))
    c.append(int(f[i+1]))

x = [1]*len(e)
g = e[0]
for i in range(1, len(e)):
    g, a, b = xgcd(g, e[i])
    for j in range(i):
        x[j] *= a
    x[i] = b

m = 1
for i in range(len(e)):
    if x[i]<0:
        m = m * invert(pow(c[i],-x[i],n),n) % n
    else:
        m = m * pow(c[i],x[i],n) % n

print hex(m)[2:].decode('hex')
