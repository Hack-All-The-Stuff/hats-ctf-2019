#include <stdio.h>
#include <string.h>
char stack[1337] = {};
int ip = 0;
int sp = 0;
int ax = 0;
int vmstep(char op){
    switch(op | 0x20){
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            ax = (op | 0x20) - 0x30;
            break;
        case 'a':
            ax += stack[sp];
            break;
        case ' ':
        case 'e':
            return 0;
        case 'g':
            sp = ip;
            break;
        case 'j':
            ip += ax - 1;
            break;
        case 'm':
            ax *= stack[sp];
            break;
        case 'p':
            printf("%c",stack[sp]);
            break;
        case 'r':
            sp = ax;
            break;
        case 's':
            ax -= stack[sp];
            break;
        case 'u':
            stack[sp] = ax;
            break;
        case 'z':
            if(stack[sp] == 0){
                ip += ax - 1;
            }
            break;
        default:
            break;
    }
    return 1;
}
void vmexec(char* code){
    ip = 0;
    while(1){
        if(vmstep(code[ip]) == 0){
            break;
        }
        printf("code : %c\nip : %d\nax : %d\n",code[ip],ip,ax); //remove for actual chal
        ++ip;
    }
}

int main(int argc, char **argv){
    vmexec(argv[1]);
    return 0;
}
