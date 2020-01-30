#include "huffman.h"

void Huffman :: createTree(){
	minHeapNode *first, *second;
	while(head != root){
		first = pop();
		second = pop();
		push(first->freq+second->	freq, first, second);
	}
}