//gcc nani.c -fno-stack-protector -o nani
#include <stdio.h>
#include <stdlib.h>


void special(){
    system("/bin/sh");
}

int main(){
    char string[0x400];
    int c;

    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
    printf("Welcome to Nani!\n");
    printf("1: Add String\n");
    printf("2: Exit\n");

    while(1){
        printf("Enter your option> \n");
        scanf("%d", &c);
        switch(c){
            case 1:
                read(0, string, 0x4000);
                break;
            case 2:
                return 0;
            case 1337:
                printf("%p\n", special);
                break;
            default: printf("Wat u tryin do\n");
        }
    }
}
