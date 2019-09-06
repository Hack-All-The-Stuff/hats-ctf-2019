c = [194, 203, 222, 221, 53, 44, 254, 255, 251, 45, 41, 45, 60, 51, 58, 241, 254, 56, 254, 38, 51, 255, 251, 255, 55]
pt = [ord(i) for i in 'HATS{']
for k1 in range(128):
    k2 = c[0]^(pt[0]+k1)
    for i in range(1,5):
        if (pt[i]+k1)^k2 != c[i]:
            break
        if i==4:
            sol = ''
            for j in range(len(c)):
                sol += chr((c[j]^k2)-k1)
            print sol
