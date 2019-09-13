#include <stdio.h>

int ip = 0;
int sp = 0;
int ax = 0;
int vmstep(char op,char* stack){
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
        case 'd':
            --ax;
            break;
        case ' ':
        case 'e':
            return 0;
        case 'i':
            ++ax;
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
void vmexec(char* code, char* stack){
    ip = 0;
    while(1){
        //printf("code : %c\nip : %d\n",code[ip],ip); //remove for actual chal
        if(vmstep(code[ip],stack) == 0){
            break;
        }
        //printf("ax : %d , stack[%d] = %x\n",ax,sp,stack[sp]);
        ++ip;
    }
}

int main(){
    char key[101]={},
         stack[101]={},
         input[1337]={},
         code1[] = "2u4mmimmiup2u6mimimimup2u7mmimmup2u6mmimmiup2u7mmmimup2u4mmmup2u7mmimmup2u6mimmmup2u6mmimmiup2u4mmmup2u6mimmimiup2u6mmimmiup2u7mimmmiup2u5mup",
         code2[] = "2u5mmimimup2u6mmimmiup2u7mmmimup2u6mimmmiup2u6mmimimup2u7mimmmiup2u6mimmmiup2u6mimimimup2u6mmimimiup2u5mup",
         code3[] = "0r2u6mmr2u6mmimmiu0r2u5mimir2u5mmmu0r2u5mimr2u4mmmiu0r2u5mmir2u5mmmimiu0r2u5mmr2u4mimmiu0r2u4mimir2u7mimu0r2u4mimr2u6mmmmu0r2u4mmir2u4mimimimu0r2u4mmr2u5mimimimu0r2u7mir2u6mmimimu0r2u7mr2u5mimmmu0r2u6mir2u5mmmimu0r2u6mr2u5mmmiu0r2u5mir2u4mimimu0r2u5mr2u5mmimmiu9r2u5mmimu8r2u6mimmimu7r2u5mimmmu6r2u6mmimimiu5r2u7mmmmiu4r2u7mmimimiu3r2u5mmmmu2r2u5mmmimu1r2u4mmmmu0r2u4mimmmu",
         code4[] = "2u5mmimimiup2u7mmmimup2u6mimimimiup2u6mimimimup2u6mmimimiup2u4mmmup2u6mimmimiup2u6mmimmiup2u7mimmmiup2u4mmmiup2u5mup",
         code5[] = "2u4mmimimup2u6mimimmup2u6mmmmiup2u6mmimimiup2u4mmmup2u7mmimup2u4mmmup";
    int i;
    vmexec(code1,stack);
    scanf("%1337s", &input);
    vmexec(code2,stack);
    vmexec(input,key);
    vmexec(code3,stack);
    for(i=0;i<100;++i){
        if(key[i] == '\x00' && stack[i] == '\x00'){
            i = -1;
            break;
        }
        if(key[i] != stack[i] + i){
            break;
        }
    }
    if(i != -1){
        vmexec(code4,stack);
        return 0;
    }
    vmexec(code5,stack);
    printf("%s\n", key);
    return 0;
}
