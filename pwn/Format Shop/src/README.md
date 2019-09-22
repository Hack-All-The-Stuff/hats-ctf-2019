# Printf Shop
Relatively straightforward to find the bug, a format string bug.
```C
100             printf("That'll cost you $%d\n", cost);
101             printf(buf);
102             putchar('\n');
```

Just considering this fact, you can do a quick `checksec`, to find out that there is only **Partial RELRO**. This allows us to overwrite GOT entries using our format string payload.
```Bash
lord_idiot:~/Projects/Challenges/Printf_Shop/src$ checksec ./shop
[*] '/home/lord_idiot/Projects/Challenges/Printf_Shop/src/shop'
    Arch:     amd64-64-little
    RELRO:    Partial RELRO
    Stack:    Canary found
    NX:       NX enabled
    PIE:      No PIE (0x400000)
```
The general exploit would go like this: `overwrite some libc function's GOT entry with win -> call that function`. In this case we can make use of `exit`, as it is easy to control when this function is called in this binary.

However, there is one limitation in this challenge. A format string is formatted like so:
```
%[flags][width][.precision][length]specifier 
```
But this challenge limits the `[length]` part of your format string. Each time you make use of the `[length]` specifier in your payload, that amount is deducted from your "wallet". This is very restrictive as you usually use the `[length]` portion in order to control the bytes that you are writing in the format string attack. So how can this be bypassed? Here are the three possible solutions I can think of.

## 1. Negative length specifier
Hopefully the limitation enforced by this challenge would have triggered you to read more about the `printf` specification or source code. I found this little tidbit when looking through the source code in the past. What you can find in these [lines](https://code.woboq.org/userspace/glibc/stdio-common/vfprintf-internal.c.html#1392) is that you can specify a **negative** length, which actually indicates to left justify the output instead of the default right justify. However, if you specify a negative length in this challenge, that means that it will deduct a negative amount from your wallet, adding money to your wallet instead! With this, it's a standard format string arbitrary write challenge. This is the solution I was hoping to lead solvers towards.

## 2. Optimised format string
Alternatively, you can optimse your format string payload in order to keep within the small budget provided. The idea is to do the entire write in one payload. Our win function is located at `0x400b4b`, and our budget is `$0x50 ($80)`. One way you might try to exploit this is to write each byte at a time, first 0x4b, then 0xb, then 0x40. However `0x4b + 0xb + 0x40 > 0x50`, so this fails.

If we merge all these into one payload however, we can keep within this budget. Here is the rough payload.
```Python
fmt = ""
# write 0x0b
fmt+= "%{}c".format(0xb)
fmt+= "%16$hhn".format(exit_GOT+1)
# write 0x40
fmt+= "%{}c".format(0x40-0xb) # since 0xb bytes have already been written, we only need to write the additional amount
fmt+= "%17$hhn".format(exit_GOT+2)
# write 0x4b
fmt+= "%{}c".format(0x4b-0x40) # likewise, only the additional 0xb bytes are required here
fmt+= "%18$hhn".format(exit_GOT)
```
In total, this payload will only cost as much as the highest single byte ($0x4b), which is smaller than $0x50. This is a optimisation I use frequently to keep the length of my payloads minimal.

## 3. If you are crazy
I'm not sure if this will work. But one possible way to avoid this budget is to not use format specifiers at all. Using `%s` can print out strings of various sizes, and you could hunt around the binary to find strings that have the exact length required for your writes. This will allow you to write `n` bytes without having that amount deducted from your "wallet".

I'd be interested to know if anybody actually tried this.
