//Author: Frankie Gauthier
//Class:  CS2010
//Assign2

//This file contains the main function of the dictionary program



#include "dictionary.cpp"

int main (void) {

int pos = 0;

    while (1) {
       word = GetNextWord();

       if ( 0 == word.length()){


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

