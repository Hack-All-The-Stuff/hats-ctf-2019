//gcc bof.c -fno-stack-protector -no-pie -z execstack -o bof
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    char name[0x400];
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
    read(0, name, 0x800);
    return 0;
}
