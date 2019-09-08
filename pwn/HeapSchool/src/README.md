# HeapSchool
No solution script coz it's a quiz like challenge.

One way to solve this relatively easily is to throw [malloc\_playground](https://github.com/shellphish/how2heap/blob/master/malloc_playground.c) into gdb and inspect memory while performing the same actions given by the binary.

It would help to open a python interpreter in another window alongside the challenge. I used the following lambda function to calculate chunk sizes.
```Python
f = lambda x : max(int(ceil(max(x-8, 0)/16.0)*0x10), 0x10)+0x10
```

Here is a sample run through.
```
lord_idiot:~/Projects/Challenges/HeapSchool/src$ nc challs.hats.sg 1305
▄███   ▄███ ▄█████████▄ ▄█████████▄ ▄█████████▄ 
████   ████ ████▀▀▀▀▀▀▀ ████▀▀▀████ ████▀▀▀████
████▄▄▄████ ████▄▄▄▄▄▄▄ ████▄▄▄████ ████▄▄▄████ 
███████████ ███████████ ███████████ ██████████▀ 
████▀▀▀████ ████        ████▀▀▀████ ████▀▀▀▀▀▀  
████   ████ ███████████ ████   ████ ████        
▀▀▀▀   ▀▀▀▀ ▀▀▀▀▀▀▀▀▀▀▀ ▀▀▀▀   ▀▀▀▀ ▀▀▀▀        
▄█████████▄ ▄██████████▄ ▄███   ▄███ ▄█████████▄ ▄█████████▄ ▄███
████▀▀▀▀▀▀▀ ████▀▀▀▀▀███ ████   ████ ████▀▀▀████ ████▀▀▀████ ████
████▄▄▄▄▄▄  ███          ████▄▄▄████ ████   ████ ████   ████ ████
███████████ ███          ███████████ ████   ████ ████   ████ ████
      ▀████ ███▄     ▄▄▄ ████▀▀▀████ ████   ████ ████   ████ ████
███████████ ████████████ ████   ████ ███████████ ███████████ ██████████
 ▀▀▀▀▀▀▀▀▀   ▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀   ▀▀▀▀  ▀▀▀▀▀▀▀▀▀   ▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀


Welcome to Heap School!
We'll be starting class with a pop quiz!
Note: This challenge is based on the Ubuntu 16.04 [64-bit] ptmalloc allocator (Ubuntu GLIBC 2.23-0ubuntu11)

##################### SECTION A #####################
Q1: I call malloc(53),
What is the actual chunk size, including chunk metadata?
(e.g. 1337): 64
Correct! ✓

Q2: I call malloc(78),
What is the actual chunk size, including chunk metadata?
(e.g. 1337): 96
Correct! ✓

Q3: I call malloc(58),
What is the actual chunk size, including chunk metadata?
(e.g. 1337): 80
Correct! ✓

Congrats! You have completed [SECTION A]
################# END OF SECTION A ##################

##################### SECTION B #####################
Heap base is current at: 0x00005566f7798000
malloc(409) = 0x00005566f7798010
malloc(489) = 0x00005566f77981c0
malloc(396) = 0x00005566f77983c0
free(0x00005566f77981c0)

Q1: What is the QWORD value at 0x00005566f7798008?
(e.g. 0xdeadbeef): 0x1b1
Correct! ✓

Q1: What is the QWORD value at 0x00005566f77983b0?
(e.g. 0xdeadbeef): 0x200
Correct! ✓

Congrats! You have completed [SECTION B]
################# END OF SECTION B ##################

Congrats! Here is your flag: HATS{You_get_an_A!}
```
