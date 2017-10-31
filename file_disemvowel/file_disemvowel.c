#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BUFFER 1024
/*Creats an true false statement*/

bool is_vowel(char letter){
	const char* vowels ="aAEeiIOoUu";
	if(strchr(vowels,letter)!='\0'){
		return true;
		}
		return false;
		}

int NoGO(int chars, char* NoGobuff, char* DisOne){
	int i,h=0;
	for(i=0;i<chars;i++){
		if(!is_vowel(NoGobuff[i])){
			DisOne[h] = NoGobuff[i];
			h++;
		}
	}
	DisOne[h] = '\0';
	return h;
}
// All of the NoGo's get kickoff in the end
void remove_vowel(FILE* main_file, FILE* another_file){
	char* in_buffer = (char*) calloc(BUFFER + 1,sizeof(char));
	char* out_buffer = (char*) calloc(BUFFER+1,sizeof(char));
	int amountRead=0, Number_NoGO;
	bool running = true;
	//while we have not reached the end of the file keep reading from it and copying the non-vowels
	while(running){
		amountRead = (int)fread(in_buffer,sizeof(char),BUFFER,main_file);
		if(!amountRead){
			break;
		}
		in_buffer[amountRead]='\0';
		Number_NoGO = NoGO(amountRead,in_buffer,out_buffer);
		fwrite(out_buffer,sizeof(char),Number_NoGO,another_file);
	}
	//close the files we are reading from and free allocated memory
	fclose(another_file);
	fclose(main_file);
	free(in_buffer);
	free(out_buffer);
}

//handles what happens with different numbers of arguments, if none, run from stdin and stdout
//if 1 expect that to be the path to an input file
//if 2 expect the first argument to be the path to an input file and the second to be output file
int main(int argc, char *argv[]){
	FILE *file;
	FILE *another_file;
	switch (argc){
		case 1:
			file = stdin;
			another_file = stdout;
			remove_vowel(file,another_file);
			return 0;
			break;
		case 2 :
			file = fopen(argv[1],"r");
			another_file = stdout;
			remove_vowel(file,another_file);
			return 0;
			break;
		case 3:
			file = fopen(argv[1],"r");
			another_file = fopen(argv[2],"w");
			remove_vowel(file,another_file);
			return 0;
			break;
		default:
			printf("Invalid Number of Arguments");
			exit(0);
			break;
}
}
