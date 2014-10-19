#ifndef DICT_H

#define DICT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>


#ifndef types
#define types

typedef int BOOL;
typedef string WORD;
typedef WORD DICT[MAX];

int LocateWord(DICT, WORD);
BOOL FullDictionary(DICT);
BOOL InsertWord(DICT,WORD);
WORD GetNextWord(void);
void DumpDictionary(DICT ,int[]);

#endif




BOOL InsertWord(DICT dict, WORD word){
	
	if (!FullDictionary(dict)){
		dict[NEXT++] = word;
		return true;	
	}
return false;

}



void DumpDictionary(DICT dict, int count[]) {
	
	int i =0;
	while(dict[i] != null){
		cout << dict[i]  << "\t" << count[i]<< endl;
		i++;
	}

}



WORD GetNextWord(void){
	Word tmpword;
	char ch;
	int ptr = 0; 
	in newWord = 0;

	// if the input is not null		
	while(cin.good()){
		ch = tolower(cin.get());
		
		if(isalpha(ch)){

		tmpword[ptr++] = ch;
		newWord = 1;

		}else{
			if(newWord){
				return tmpword;
			}
		}
	
	}
return NULL;
}



BOOL FullDictionary(DICT dict) {
	
	if(dict[MAX-1] != 0){
		return true;
	}
	
return false;

}



int LocateWord(DICT dict, WORD word) {

	for(int i = 0; i<MAX;i++){
		if(strcmp(word,dict[i])) return i;
	}
	return 0;
}



#endif
