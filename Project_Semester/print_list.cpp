#include "huffman.h"

void Huffman :: print_list() 
{ 
    minHeapNode *current = head; 
    cout << "[ " ; 
    while (current != NULL) { 
        cout << current->ch << " : "<< current->freq<<endl;; 

        current = current->next; 
    }
    cout << "]" << endl;
}