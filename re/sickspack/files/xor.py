import sys
code = open(sys.argv[1]).read()
open(sys.argv[1] + ".xor", "w").write(''.join([chr(ord(c) ^ 0x55) for c in code]))