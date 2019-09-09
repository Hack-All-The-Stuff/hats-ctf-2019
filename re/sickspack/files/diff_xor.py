from pwn import *

target =    "488d0549082000488945f8488b4de0488b55e8488b45f84889ce4889d7ffd090c9c3".decode("hex")
original =  "488d3d71010000e834feffff488d3d6b010000e828feffff488d3d75010000e81cfe".decode("hex")

open("diff.bytes", "w").write(xor(target, original).encode("hex"))