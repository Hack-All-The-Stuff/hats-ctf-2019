from pwn import *

before =    "488d0599082000488945f8488b4de0488b55e8909090904889ce4889d7ffd090c9c3".decode("hex")
after =     "488d3d61010000e844feffff488d3d5b010000e838feffff488d3d65010000e82cfe".decode("hex")

open("diff.bytes", "w").write(xor(before, after).encode("hex"))