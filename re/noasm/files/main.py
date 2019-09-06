import binascii
import base64
import sys
import hashlib
import random

if __name__ == "__main__":
    sys.stdout.write("Tell me the flag and I will let you know if you are right: ")

    pw = raw_input()

    if len(pw) != 19:
        print("WRONG")
        exit(0)

    p = binascii.hexlify(pw[0:5])
    if int(b"0x" + p, 0) != 0x666c61677b:
        print("WRONG1")
        exit(0)

    b = base64.b64encode(pw[5:9])
    if b != ''.join(map(chr, [89, 88, 78, 116, 88, 119, 61, 61])):
        print("WRONG2")
        exit(0)

    h = hashlib.md5(pw[9:13]).hexdigest()
    if h != "109dd7decb2e3a3658db75dcad688658":
        print("WRONG3")
        exit(0)

    rs = [87, 16, 33, 1, 56, 73]
    for i, r in zip(range(13, 19), rs):
        c = pw[i]
        random.seed(c)
        if r != random.randint(0, 100):
            print("WRONG4")
            exit(0)

    print("That's the flag, go submit it.")
    
