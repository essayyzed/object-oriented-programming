#include<iostream>
#include<string>
#include<fstream>
#include<map>
using namespace std;

/*************************************** TECHNIQUE VIRTUAL CLASS HAVING TWO PURE VIRTUAL FUNCTIONS **********************************/
#ifndef _Huffman_Technique_
#define  _Huffman_Technique_

class Technique
{
	public:
	virtual void compress(string sourceFile, string destinationFile) = 0; 
	virtual void decompress(string sourceFile, string destinationFile) = 0; 
};

// Technique * selectTechnique();

#endif