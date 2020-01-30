#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include "technique.h"
using namespace std;

#ifndef _Huffman_Huffman
#define  _Huffman_Huffman



class Huffman : public Technique
{
	private:
		struct minHeapNode 
        { 
		char ch;
		int freq; 
	    minHeapNode *leftchild, *rightchild, *next; 
		};
	
		minHeapNode *root, *head, *last;
	
	public:
		Huffman();
		void compress(string sourceFile, string destinationFile);
		void decompress(string sourceFile, string destinationFile);
		void push(char ch, int freq);
		void push(int freq, minHeapNode *left, minHeapNode *right);
		void print_list();
		void createTree();
		void inorder(minHeapNode* temp, map<char, string> *table);
		~Huffman();
		
		minHeapNode *pop()
        {						//POP FUNCTION WHICH RETURN THE ADDRESS OF MINIMUM FREQUENCY NODE AND UN LINK IT FROM THE LIST
			minHeapNode *popValue;
		    if (head->next == NULL)
            {       
		        popValue = last;            
		        head = NULL;                
		        last = NULL; 
		    } 
            else
            {
				popValue = head;
				head = head->next;          
		      
		    } 
			popValue->next = NULL;
			return popValue; 
		}
		
};


#endif // !_Huffman_Huffman