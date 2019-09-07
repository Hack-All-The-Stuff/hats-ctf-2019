// gcc bof1.c -o bof1 -fno-stack-protector -no-pie
#include <stdio.h>
#include <unistd.h>

void banner(){
    alarm(60);
    setvbuf(stdin, 0LL, 2, 0LL);
    setvbuf(stdout, 0LL, 2, 0LL);
    setvbuf(stderr, 0LL, 2, 0LL);
    printf("*** WELCOME TO %s ***\n", __FILE__);
}

int getflag() {
    printf("\nHINT: you shoudn't jump straight to getflag\n");
    printf("but instead somewhere in the middle\n\n");

    printf("This is due to the stack alignment shifting (the value of rbp now has a '8' in the units place, which system() does not like)\n");
    system("cat flag");
}

int main() {
    banner();
    char buf[0x20];
    gets(buf);
    printf("bof me daddy!  %s", buf);
}
