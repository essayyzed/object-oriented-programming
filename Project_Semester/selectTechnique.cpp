// #include "technique.h"
#include "rle.h"
#include "huffman.h"

inline Technique * selectTechnique();

inline Technique * selectTechnique()
{ 
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