#include <iostream>
#include "technique.h"
#include "rle.h"
#include "huffman.h"
using namespace std;

 Technique * selectTechnique(); 	

int main(){
	Technique *t;
	t = selectTechnique();
	char opt;
	
	cout<<"Do you want to Compress or Decompress the File... select (C/D): ";
	cin>>opt;
	if(opt == 'C'){
		
		t->compress("sample1.txt", "ecryptedfile.txt");
	}
	else{
		t->decompress("ecryptedfile.txt", "Huffman.txt");
	}
	return 0;
}

/**************************************************************************************************************************/

			//DEFINATION OF SELECT_TECHNIQUE FUNTION

Technique * selectTechnique() { 
    string Technique_name; 
	cout<<"Which Technique you want to use (Huffman/Runlength)....??? ";
	cin>>Technique_name;
    Technique *t; 
    if ((Technique_name == "Huffman") or (Technique_name == "huffman"))
    	t = new Huffman;
	
        
    else 
        t = new RunLength; 
        
    return t; 
}