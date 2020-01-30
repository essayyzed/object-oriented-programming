#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include "technique.h"
using namespace std;

#ifndef _huffman_rle_
#define _huffman_rle_

class RunLength : public Technique
{
	public:
		
		void compress(string sourceFile, string destinationFile);
		void decompress(string sourceFile, string destinationFile);
		
};

#endif