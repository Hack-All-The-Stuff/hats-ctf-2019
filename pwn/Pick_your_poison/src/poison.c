#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
	gcc poison.c -o poison -fno-stack-protector -Wl,-Ttext-segment=0x401000
*/
int choice = -1;

void banner(){
	alarm(60);
	setvbuf(stdin, 0LL, 2, 0LL);
	setvbuf(stdout, 0LL, 2, 0LL);
	setvbuf(stderr, 0LL, 2, 0LL);
	puts("______ _      _                                           _                 \n| ___ (_)    | |                                         (_)                \n| |_/ /_  ___| | __  _   _  ___  _   _ _ __   _ __   ___  _ ___  ___  _ __  \n|  __/| |/ __| |/ / | | | |/ _ \\| | | | '__| | '_ \\ / _ \\| / __|/ _ \\| '_ \\ \n| |   | | (__|   <  | |_| | (_) | |_| | |    | |_) | (_) | \\__ \\ (_) | | | |\n\\_|   |_|\\___|_|\\_\\  \\__, |\\___/ \\__,_|_|    | .__/ \\___/|_|___/\\___/|_| |_|\n                      __/ |                  | |                            \n                     |___/                   |_|                            ");
	puts("");
}

int read_int(){
	char buf[40];
	read(0, buf, 30);
	return atoi(buf);
}

int menu(){
	puts("+------------+---------------------+\n| > Poison   |   0. Old Man Gets   |\n|   Exit     |   1. Sir Ken F      |\n|            |   2. St. R. Copy    |\n+------------+---------------------+");
	printf("Choice> ");
	return read_int();
}

void choice_0(){ /* gets */
	char buf[100];
	puts("Back in my day, everybody used `gets`.\nBut nowadays everybody says to \e[4mNever\e[0m \e[4muse\e[0m \e[4mthis\e[0m \e[4mfunction\e[0m.\nI don't see why that's the case ¯\\_(ツ)_/¯.\n\nBut enough about me, what have you been up to young man?");
	printf("Say> \"");
	gets(buf);
	printf("\e[s\e[1A\e[%luC\"\e[u", strlen(buf)+6);
}

void choice_1(){ /* scanf */
	char buf[100];
	puts("Whomst'd've goes there? Speak!");
	printf("Say> \"");
	scanf("%s", buf);
	printf("\e[s\e[1A\e[%luC\"\e[u", strlen(buf)+6); }

char answer[32];
char contact[128];
void choice_2(){ /* strcpy */
	char buf[0xa8];
	puts("Excuse me sir, do you have a moment to talk about the Church of Pope Pope Ret?");
	printf("Say> \"");
	read(0, answer, 32);
	printf("\e[s\e[1A\e[%luC\"\e[u", strlen(answer)-1+6);
	if(!strncmp(answer, "yes", 3)){
		puts("That's great!\nCome here for a moment...");
	}
	else if(!strncmp(answer, "no", 2)){
		puts("Well that's a pity. Could you leave your contact information instead?");
		printf("Say> \"");
		read(0, contact, 128);
		printf("\e[s\e[1A\e[%luC\"\e[u", strlen(answer)+6);

		strcpy(buf, "Wonderful! I shall contact you soon at: ");
		strcpy(&buf[40], contact);
		puts(buf);
	}
	else{
		puts("Nani");
	}
}

int main(){
	banner();
	choice = menu();
	switch(choice){
		case 0:
			choice_0();
			goto exit;
		case 1:
			choice_1();
			goto exit;
		case 2:
			choice_2();
			break;
		default:
			puts("Invalid poison!");
			exit:
			puts("+------------+---------------------+\n|   Poison   |   0. Old Man Gets   |\n| > Exit     |   1. Sir Ken F      |\n|            |   2. St. R. Copy    |\n+------------+---------------------+");
			puts("Exiting ...");
			exit(0);
	}
}

void win(){
	char flag[11];
	memset(flag, '\x00', 11);
	int fd = open("./flag", O_RDONLY);
	if( choice >= 0 && choice <= 2 ){
		lseek(fd, choice*10, SEEK_SET);
		read(fd, flag, 10);
		printf("Here you go! %s", flag);
	}
	else{
		puts("How did you even get here?");
		return;
	}
	close(fd);
}
