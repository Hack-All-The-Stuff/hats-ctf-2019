import sys
code = open(sys.argv[1]).read()
open(sys.argv[1] + ".formatted", "w").write(''.join(["\\x" + code[i] + code[i + 1] for i in range(0, len(code), 2)]))