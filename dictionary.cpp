//Author: Frankie Gauthier
//Class:  CS2010
//Assign2

// this file provides the functions and declarations necessary for the dictionary



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
//#include "dictionary.cpp"

using namespace std;
using std::string;



// max number of words for the dictionary type
#define MAX 20


//define a bool type a word type and a DICT type
typedef int BOOL;
typedef string WORD;
typedef WORD DICT[MAX];


// function prototypes
int LocateWord(DICT, WORD);
BOOL FullDictionary(DICT);
BOOL InsertWord(DICT,WORD);
WORD GetNextWord(void);
void DumpDictionary(DICT ,int[]);
BOOL wordCompare(WORD first,WORD second);
void quickSort(DICT, int, int);
void sortDict(DICT);

DICT dictionary;  //your dictionary 
WORD word;        // 
int count[MAX];   //tracks word frequencies
int NEXT = 0;	// points to next available spot in the dictionary




//****  dictionary functions  ****


// -inserts a word at the next available location in the dictionary
// -takes the dictionary to insert the word into and the word to be inserted as params
// -returns a bool indicating the success of the insert
BOOL InsertWord(DICT dict, WORD word){

        if (!FullDictionary(dict)){
                count[NEXT]++;
		dict[NEXT] = word;
                
		NEXT++;
		return true;
        }
return false;

}


// -prints the words in the dictionary and prints the frequency at which they occur 
// -takes the dictionary to print as a param and the frequency array to print
// -returns nothing
void DumpDictionary(DICT dict, int count[]) {

	sortDict(dict);
	cout << "\nWord\t\tFrequency\n--------------------------\n";	 
	for (int i = 0; i<(NEXT); i++ ){
                cout << dict[i]  << "\t\t\t" << count[i] << endl;
        }
	cout << endl;
}


// -reads characters from the input stream until a non-letter character is read
// -returns the characters read as a word value
WORD GetNextWord(void){
        
	WORD tmpword = "";
	char ch;
        int newWord = 0;
	
        // if the input is not null             
        while(cin.good()){
                ch = tolower(cin.get());
		// check if it is a letter character
                if(isalpha(ch)){

                tmpword += ch;
                newWord = 1;

                }else{
                        if(newWord){
                         
				 return tmpword;
                        }
                }

        }
return tmpword;
}


// -returns if the last entry in the dictionary is occupied (aka its full)
// -takes the dictionary as a parameter
// -takes an array of words as a parameter and returns a boolean
BOOL FullDictionary(DICT dict) {

        if( (MAX) ==  NEXT){
                return true;
        }

return false;

}


// -searches the dictionary passed to it for the word that is passed to it and returns
// -returns an int (the words index in the dict) or -1 if not
int LocateWord(DICT dict, WORD word) {

	

        for(int i = 0; i<NEXT;i++){
                if(wordCompare(word, dict[i])) return i;
        }
        return -1;
}


// compares two WORDSs letter for letter and returns true if they are the same otherwise returns false
// takes two WORDS as parameters and returns a BOOL
BOOL wordCompare(WORD first,WORD second){

	if (first.length() != second.length()) return false;

	for(int i=0; i< first.length(); i++){
		if (first[i] != second[i]){
			return false;
		}
	}

return true;
}


// -sorts the existing entries in the dictionary by calling quickSort
// -this function takes the dictionary to be sorted as a parameter
// -returns nothing 
void sortDict(DICT dict){
	
	quickSort(dict,0,NEXT-1);
}



// -recursively quicksorts the dictionary
// -takes the dictionary as a param as well as two ints holding the left and right locations of the partition
// -returns nothing
void quickSort(DICT dict, int left, int right){

	int lPtr = left; int rPtr = right; int pivotLoc = (lPtr + rPtr)/2;
	int tmpCount = 0;
	WORD tmpWord;
	WORD pivot = dict[pivotLoc];
	
	while(lPtr < rPtr){

		// move left and right pointers until a value is found on the wrong side of the pivot
		while(dict[lPtr] < pivot) lPtr++;
		while(dict[rPtr] > pivot) rPtr--;

		// swap the left and right pointers values
		if(lPtr <= rPtr){
			
			// swap the dictionary entries
			tmpWord = dict[lPtr];
			dict[lPtr] = dict[rPtr];
			dict[rPtr] = tmpWord;
			
			// swap the corresponding frequencies
			tmpCount = count[lPtr];
			count[lPtr] = count[rPtr];
			count[rPtr] = tmpCount;

			
			lPtr++;
			rPtr--;	
		}
			
		// recursively call quicksort on the left and right
		if(left < rPtr) quickSort( dict, left, rPtr );	
		if(right > lPtr) quickSort( dict, right,lPtr );
	}

}
	
















