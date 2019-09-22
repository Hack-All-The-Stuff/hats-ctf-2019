#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/*
	gcc shop.c -o shop
*/

int isformatspec(char a){
	return (a == 'd' || a == 'i' || a == 'u' || a == 'f' || a == 'F' || a == 'e' || a == 'E' || a == 'g' || a == 'G' || a == 'x' || a == 'X' || a == 'o' || a == 's' || a == 'c' || a == 'p' || a == 'a' || a == 'A' || a == 'n');
}

int calculateCost(char fmt[]){

	int cost = 0;
	int reading = 0;
	int tempprog = 0;
	char temp[100];

	for(int i = 0; i < 100; i++){
		if( fmt[i] == '\n' ) break;
		if( fmt[i] == '.'){
			printf("I don't accept coins!\n");
			exit(-1);
		}
		// if there is a width specifier, read it to temp
		if( fmt[i] == '%' && !isformatspec(fmt[i+1]) ){
			reading = 1;
			tempprog = 0;
			continue;
		}
		// start reading characters into buffer
		if( reading ){
			temp[tempprog++] = fmt[i];
		}
		// if accidentally read the position specifier, clean out temp
		if( fmt[i] == '$' ){
			temp[tempprog] = '\x00';
			tempprog = 0;
			temp[tempprog] = '\x00';
		}
		// if u hit the end, check the width
		if( reading && isformatspec(fmt[i]) ){
			reading = 0;
			temp[tempprog] = '\x00';
			if(tempprog > 9){
				printf("There's no way you could carry enough money to afford this!\n");
				exit(-1);
			}
			int width = atoi(temp);
			// calculate cost
			if(width > 0xffff){ // prevent int overflow
				printf("There's no way you could carry enough money to afford this!\n");
				exit(-1);
			}
			cost += width;
		}
	}
	return cost;	
}

int setup(){
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	return 1; 
}

int win(){
	system("cat flag");
}

const char BANNER[] = "\
###################################\n\
# Welcome to Format String Shop!  #\n\
# Please spend your money wisely! #\n\
###################################\n";

int main(){
	char buf[100];
	int budget = 0x50;
	memset(buf, 0, 100);

	setup();
	memset(buf, '\x00', 100);

	printf(BANNER);
	while(budget > 0){
		printf("You currently have: $%d\n", budget);
		printf("Input your format string. Watch your budget!\n");
		read(STDIN_FILENO, buf, 99);
		if(!strncmp(buf, "exit", 4)) break; // early exit
		int cost = calculateCost(buf);
		if(cost > budget){
			printf("You cannot afford this, come back after you've earned more cash.\n");
		}
		else{
			budget -= cost;
			printf("Here you go sir.\n");
			printf("That'll cost you $%d\n", cost);
			printf(buf);
			putchar('\n');
		}
	}
	
	exit(0);	
}

