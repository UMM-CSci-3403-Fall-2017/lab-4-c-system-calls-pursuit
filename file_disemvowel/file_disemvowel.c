#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER 16

bool is_vowel(char letter){
    if(letter == 'a' || letter == 'A' || letter == 'e' || letter == 'E' || letter == 'i' || letter == 'I' 
    || letter == 'o' || letter == 'O' || letter == 'u' || letter == 'U'){
        return true;
    }
    else{
        return 	false;
    }
}

int NoGO(int num_chars, char* in_buf, char* out_buf){
	int i, j=0;
	for(i = 0; i < num_chars;i++){
		if(!is_vowel(in_buf[i])){
			out_buf[j] = in_buf[i];
			j++;
		}
	}
	out_buf[j] = '\0';
	return j;
}
