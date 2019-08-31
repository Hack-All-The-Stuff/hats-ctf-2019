//gcc ezprintf.c -no-pie -o ezprintf
#include <stdio.h>

int magic;

int main(){
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
    magic = 0;
    char buf[0x400];
    read(0, buf, 0x400);
    printf(buf);

    if(magic) system("/bin/sh");
}

