#include "huffman.h"

void Huffman :: push(int freq, minHeapNode *left, minHeapNode *right)
{ 
    minHeapNode *temp = new minHeapNode; 
    temp->ch = ' ';
    temp->freq = freq;
    temp->leftchild = left;
	temp->rightchild = right;
	temp->next = NULL; 
	root = temp;

    if (head == NULL) {         
        head = temp; 
        last = temp; 
    } 
    else if(head->next == NULL){
		if(temp->freq < head->freq){
			temp->next = head;
			head = temp;
		}
		else{
			head->next = temp;
			last = temp;
		}
	}
	else {                    
        
		minHeapNode *current = head;
		while(current->next != NULL ){		
		
			if(temp->freq < current->next->freq){
	
				break;
			}
			current = current->next;
		}
	
		if(head->freq > temp->freq){
			temp->next = head;
			head = temp;
		}
		else{
			temp->next = current->next;
			current->next = temp;
	
			
		}
    } 
}


void Huffman::push(char ch, int freq) { 
    minHeapNode *temp = new minHeapNode; 
    temp->ch = ch;
    temp->freq = freq;
    temp->leftchild = temp->rightchild = temp->next = NULL; 

    if (head == NULL) {         
        head = temp; 
        last = temp; 
    } 
    else if(head->next == NULL){
		if(temp->freq < head->freq){
			temp->next = head;
			head = temp;
		}
		else{
			head->next = temp;
			last = temp;
		}
	}
	else {                    // for all other cases 
        
		minHeapNode *current = head;
		while(current->next != NULL ){		
		
			if(temp->freq < current->next->freq){
	
				break;
			}
			current = current->next;
		}
	
		if(head->freq > temp->freq){
			temp->next = head;
			head = temp;
		}
		else{
			temp->next = current->next;
			current->next = temp;
	
			
		}
    } 
}