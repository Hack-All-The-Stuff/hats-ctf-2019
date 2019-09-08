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
        //printf("code : %c\nip : %d\n",code[ip],ip); //remove for actual chal
        if(vmstep(code[ip]) == 0){
            break;
        }
        //printf("ax : %d\n",ax);
        ++ip;
    }
}

int main(){
    char key[101]={},
         input[1337]={},
         code1[] = "0u7au9mu6aup0u1au9mu3au9mu2aup0u1au9mu3au9mu8aup0u1au9mu2au9mu2aup0u1au9mu3au9mu6aup0u3au9mu5aup0u1au9mu3au9mu8aup0u1au9mu2au9mu5aup0u1au9mu2au9mu2aup0u3au9mu5aup0u1au9mu2au9mu8aup0u1au9mu2au9mu2aup0u1au9mu4au9mu4aup0u1au9mu1aup",
         code2[] = "0u1au9mu0au9mu5aup0u1au9mu2au9mu2aup0u1au9mu3au9mu6aup0u1au9mu2au9mu6aup0u1au9mu2au9mu3aup0u1au9mu4au9mu4aup0u1au9mu2au9mu6aup0u1au9mu3au9mu2aup0u1au9mu2au9mu4aup0u1au9mu1aup",
         code3[] = "0r0u2au9mu6ar0u1au9mu2au9mu2au0r0u2au9mu5ar0u4au9mu4au0r0u2au9mu4ar0u3au9mu6au0r0u2au9mu3ar0u1au9mu0au9mu2au0r0u2au9mu2ar0u4au9mu1au0r0u2au9mu1ar0u3au9mu3au0r0u2au9mu0ar0u1au9mu1au9mu6au0r0u1au9mu8ar0u8au9mu6au0r0u1au9mu7ar0u1au9mu1au9mu4au0r0u1au9mu6ar0u1au9mu2au9mu3au0r0u1au9mu5ar0u1au9mu0au9mu7au0r0u1au9mu4ar0u1au9mu0au9mu1au0r0u1au9mu3ar0u4au9mu5au0r0u1au9mu2ar0u4au9mu2au0r0u1au9mu1ar0u1au9mu0au9mu4au0r0u9r0u4au9mu6au0r0u8r0u1au9mu2au9mu7au0r0u7r0u1au9mu0au9mu7au0r0u6r0u1au9mu2au9mu4au0r0u5r0u1au9mu3au9mu5au0r0u4r0u1au9mu4au9mu2au0r0u3r0u8au9mu8au0r0u2r0u1au9mu0au9mu1au0r0u1r0u7au9mu1au0r0u0r0u8au9mu0au",
         code4[] = "0u1au9mu0au9mu6aup0u1au9mu3au9mu6aup0u1au9mu3au9mu3aup0u1au9mu3au9mu2aup0u1au9mu2au9mu4aup0u3au9mu5aup0u1au9mu2au9mu8aup0u1au9mu2au9mu2aup0u1au9mu4au9mu4aup0u3au9mu6aup0u1au9mu1aup",
         code5[] = "0u7au9mu7aup0u1au9mu3au9mu0aup0u1au9mu1au9mu7aup0u1au9mu2au9mu4aup0u3au9mu5aup0u6au9mu4aup0u3au9mu5aup";
    int i;
    vmexec(code1);
    scanf("%1337s", &input);
    vmexec(code2);
    vmexec(input);
    for(i=0;i<100;++i){
        key[i] = stack[i];
        if(key[i] == '\x00'){
            break;
        }
    }
    vmexec(code3);
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
        vmexec(code4);
        return 0;
    }
    vmexec(code5);
    printf("%s\n", key);
    return 0;
}
