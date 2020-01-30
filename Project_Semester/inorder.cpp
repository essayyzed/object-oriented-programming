#include "huffman.h"

void Huffman :: inorder(minHeapNode* temp, map<char, string> *table){
	static string code = "";
	if(temp==NULL){
		return ;
	}
	
	if(temp->leftchild != NULL){
	
		code += '0';
		inorder(temp->leftchild, table);
		code.erase(code.size()-1, 1);
	
	}
	if((temp->leftchild == NULL) and (temp->rightchild == NULL)){
	
	
		if(code != ""){
			(*table)[temp->ch] =  code ;
		//	cout<<temp->ch<<" : "<<code<<endl;	
		}
		
	
	}
	cout<<temp->freq<<" ";

	if(temp->rightchild != NULL){

		code +='1';
		inorder(temp->rightchild, table);

		code.erase(code.size()-1, 1);
	}
}