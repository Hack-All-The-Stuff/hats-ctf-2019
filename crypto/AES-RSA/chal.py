from secret import flag
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
from Crypto.Util.number import getPrime
from os import urandom

key = urandom(16)
while True:
    p = getPrime(512)
    q = getPrime(512)
    if(p%3==0 or q%3==0):
        continue
    break
n = p*q
e = 3

def rsaenc(m):
    m = int(m.encode('hex'),16)
    c = pow(m,e,n)
    c = hex(c)[2:].rstrip('L')
    c = ('0'*(len(c)%2)+c).decode('hex')
    return c

def encrypt(m):
    m = rsaenc(m)
    iv = urandom(16)
    c = AES.new(key, AES.MODE_CBC, iv).encrypt(pad(m, 16))
    return iv + c

def decrypt(c):
    iv = c[:16]
    c = c[16:]
    try:
        c = AES.new(key, AES.MODE_CBC, iv).decrypt(c)
        c = unpad(c, 16)
    except:
        return -1
    # todo: implement decryption
    return 0

flag = encrypt(flag)

def main():
    print '''This is a WIP cipher that combines RSA and AES
Encryption has been implemented, but I haven't figured how to decrypt yet
Here is an encrypted message using this service that I recieved:
%s
, could you help me find the message?'''% flag.encode('hex')
    for _ in xrange(0x2000):
        print '''
1. Encrypt service
2. Decrypt service
3. Quit
        '''
        inp = raw_input().strip()
        if inp == '1':
            print 'Send a message to be encrypted'
            inp = raw_input().decode('hex')
            print 'Encrypted message:'
            print encrypt(inp).encode('hex')
        elif inp == '2':
            print 'Send a message to be decrypted'
            inp = raw_input().decode('hex')
            print 'Decrypted message:'
            print decrypt(inp)
        elif inp == '3':
            return 0
    return 0

if __name__ == '__main__':
    main()
