#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include "dictionary.cpp"

using namespace std;
using std::string;

#define MAX 100

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


DICT dictionary;  //your dictionary 
WORD word;        // 
int count[MAX];   //tracks word frequencies
int NEXT = 0;	// points to next available spot in the dictionary



int main (void) {
    int pos;

    while (1) {
       word = GetNextWord();
       if ( 0 == word )  {
           DumpDictionary(dictionary,count);
           break;
       }
       if ((pos = LocateWord(dictionary,word)) >=  0 ) 
           count[pos]++;
       else
           if (!InsertWord(dictionary,word)) cout << "dictionary full " << word << " cannot be added\n";
    }
    return 0;
}

