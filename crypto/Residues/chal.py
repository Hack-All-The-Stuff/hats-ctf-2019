from secret import flag
from random import randint
from gmpy2 import gcd, next_prime

def genrsa(s):
    e = 65537
    while True:
        r = randint(0, 4**s)
        p = next_prime(r)
        q = next_prime(r + randint(1, 2**s))
        if gcd(p-1, e) == gcd(q-1, e) == 1:
            return p * q, 2*e

def enc(m, e, n):
    c = hex(pow(m, e, n))[2:].rstrip('L')
    return c

def main():
    n, e = genrsa(512)
    print '''--------*Residue*-------
The modulus is hidden
You only have 6 encryptions, use them wisely
Here is the encrypted flag: ''' + enc(flag, e, n)
    for _ in range(6): # fix bound later
        print "Enter a value to be encrypted:"
        try:
            m = int(raw_input(),16)
        except:
            print "Nope"
            return -1
        c = enc(m, e, n)
        print "Cipher: " + c

if __name__ == '__main__':
    main()
