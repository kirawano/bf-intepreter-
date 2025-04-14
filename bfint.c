#include <stdio.h>
#include <string.h>
int strcount (char* str, char c) {
	int total = 0;
	for (int i = 0; i < strlen(str); i++){
		if (str[i] == c) {
			total++;
		}
	}
	return total;
}

int evaluate (char* code, int mem[], int memlength) {
	int dp = 0;
	int c;
	int stack[256] = {0};
	char substr[256];
	int sp = 0;

	int mark = 0;
	for (int i = 0; i < strlen(code); i++) {
		c = code[i];
		switch(c){
			case '>':
				if (dp < memlength)
					dp++;
				else{
					printf("Too high");
					return 1;
				}
				break;
			case '<':
				if (dp <= 0){
					printf("Too low");
					return 1;
				}
				dp--;
			case '.':
				printf("%i", mem[dp]);
				break;
			case '+':
				mem[dp]++;
				break;
			case '-':
				mem[dp]--;
				break;
			case '[':
				stack[++sp] = i;
				break;
			case ']':
				strncpy(substr, code + stack[sp] + 1, i-stack[sp]-1);
				substr[i-stack[sp]] = '\0';
				while(mem[dp] != 0){
					evaluate(substr, mem, memlength);
				}
				break;
				sp--;

			default:
				continue;
				break;

		}		
	}
	return 0;
}

int
main (int argc, char* argv[]) {

	int mem[256] = {0};
	char *f = argv[argc-1]; 
	FILE *bf = fopen(f, "r");
	char code[256];

	fscanf(bf,"%s", code);
	
	if (strcount(code, '[') != strcount(code, ']')) 
		return 1;
	
	evaluate(code, mem, 256);
}
