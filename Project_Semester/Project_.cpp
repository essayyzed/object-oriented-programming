#include<iostream>
#include<string>
#include<fstream>
#include<map>
using namespace std;

/*************************************** TECHNIQUE VIRTUAL CLASS HAVING TWO PURE VIRTUAL FUNCTIONS **********************************/
class Technique{
	public:
	virtual void compress(string sourceFile, string destinationFile) = 0; 
	virtual void decompress(string sourceFile, string destinationFile) = 0; 
};

/***********************************************************************************************************************************/



/******************************** RUNLENGTH CLASS INHERITED FROM TECHNIQUE CLASS HAVING TWO FUNCTIONS *****************************/

class RunLength : public Technique{
	public:
		
		void compress(string sourceFile, string destinationFile);
		void decompress(string sourceFile, string destinationFile);
		
};

/**************************************************************************************************************/



/*************************************** RUNLENGTH CLASS COMPRESS FUNCTION ************************************/

void RunLength::compress(string sourceFile, string destinationFile){
	cout<<"Compress Function of RunLength class is called."<<endl;
	ifstream fin;
	ofstream fout;
	int count = 1, counter = 0;
	char ch,previous;
	fin.open(sourceFile);
	if(fin.is_open()){	
	
		while(fin.get(ch)){    
			if(ch == '\n'){
				ch ='~';
			}
			if(ch == ' '){
				ch ='`';
			}
			if (counter == 0){
				previous = ch;
				counter++;
				continue;	
			}
			
			if(ch == previous){	
				count++;
			}
			else{
				fout.open(destinationFile, ios::out | ios::app);
				fout<<count<<previous;
				
				fout.close();
				
				previous = ch;
				count = 1;
			}
		}
		fout.open(destinationFile, ios::out | ios::app);
			fout<<count<<previous;
			fout.close();
	}
	else
		cout<<"File Not Found...ERROR"<<endl;	
	fin.close();
}

/*****************************************************************************************************************/



/*************************************** RUNLENGTH CLASS DECOMPRESSING FUNCTION **********************************/

void RunLength :: decompress(string sourceFile, string destinationFile){
	cout<<"Decompress Function of RunLength class is called."<<endl;
	ifstream fin;
	ofstream fout;
	fin.open(sourceFile);
	if(fin.is_open()){	
		string line;
		char ch;
		int integer;
		while(fin >> integer >> ch){
			cout << ch << endl;
			cout <<integer<< endl;
			fout.open(destinationFile, ios::out | ios::app);
			for(int i = 0; i < integer; i++){
				if(ch == '~')
					fout << endl;
				else if(ch == '`')
					fout << " ";
				else
					fout << ch;	
			}
			fout.close();
		}	
	}
	else
		cout<<"File Not Found...ERROR"<<endl;
	
	fin.close();
}

/****************************************************************************************************************/


/********************************** HUFFMAN CLASS INHERITED FROM TECHNIQUE CLASS ********************************/
class Huffman : public Technique{
	private:
		struct minHeapNode { 
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
		
		minHeapNode *pop() {						//POP FUNCTION WHICH RETURN THE ADDRESS OF MINIMUM FREQUENCY NODE AND UN LINK IT FROM THE LIST
			minHeapNode *popValue;
		    if (head->next == NULL) {       
		        popValue = last;            
		        head = NULL;                
		        last = NULL; 
		    } else {
				popValue = head;
				head = head->next;          
		      
		    } 
			popValue->next = NULL;
			return popValue; 
		}
		
};

/***************************************************************************************************************/



/********************************************* FUNCTIONS OF HUFFMAN CLASS **************************************/



		// HUFFMAN CONSTRUCTOR IS CALLED TO INTIALIZE THE VALUES OF PRIVATE MEMBERS OF CLASS

/*********************************************************************************************************************************/
	
Huffman :: Huffman(){								
	head = last = root = NULL;
}
/*********************************************************************************************************************************/

		//PUSH FUNCTION OF HUFFMAN CLASS HAVING TWO ARGUMENTS WHICH INSERT NEW NODE ACCORDING TO ASCENDING ORDER IN THE LIST
		
/*********************************************************************************************************************************/		
		
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
/*********************************************************************************************************************************/

		//OVER LOADED PUSH FUNCTION OF HUFFMAN CLASS HAVING THREE ARGUMENTS WHICH INSERT NEW NODE ACCORDING TO ASCENDING ORDER IN THE LIST

/*********************************************************************************************************************************/
		
void Huffman :: push(int freq, minHeapNode *left, minHeapNode *right) { 
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
/*********************************************************************************************************************************/

		//PRINT_LIST FUNCTION OF HUFFMAN CLASS WHICH PRINT THE CHARACTER AND FREQUENCY OF ALL THE NODES IN THE LIST
		
/*********************************************************************************************************************************/

void Huffman :: print_list() { 
    minHeapNode *current = head; 
    cout << "[ " ; 
    while (current != NULL) { 
        cout << current->ch << " : "<< current->freq<<endl;; 

        current = current->next; 
    }
    cout << "]" << endl; 
}
/*********************************************************************************************************************************/

		//CREATE_TREE FUNCTION OF HUFFMAN CLASS WHICH CREATE HUFFMAN TREE ACCORDING TO THE FREQUENCIES
		
/*********************************************************************************************************************************/

void Huffman :: createTree(){
	minHeapNode *first, *second;
	while(head != root){
		first = pop();
		second = pop();
		push(first->freq+second->	freq, first, second);
	}
}
/*********************************************************************************************************************************/

		//INORDER FUNCTION OF HUFFMAN CLASS TO TRAVERSE ON THE TREE IN INORDER AND GET THE BINARY VALUES AGAINST THE CHARACTERS OF LEAF NODES
		
/*********************************************************************************************************************************/

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

/*********************************************************************************************************************************/


/********************************************** COMPRESSING FUNCTION OF HUFFMAN CLASS **************************************/


void Huffman::compress(string sourceFile, string destinationFile){
	cout<<"Compress Function of Huffman class is called."<<endl;
	map<char, int> *name_map = new map<char, int>;
	 
	ofstream fout;
	ifstream fin;
	fin.open(sourceFile);				// File name which you want to compress//
	char ch;
	while(fin.get(ch)){
		if(ch == '\n'){
			(*name_map)['~'] = (*name_map)['~'] + 1;
		}
		else{
			(*name_map)[ch] = (*name_map)[ch] + 1;
		}
	}
	fin.close();
	
	for(map<char, int>::iterator it = (*name_map).begin();it != (*name_map).end(); it++){
		push(it->first, it->second);
	}
	delete name_map;
	map<char, string> *table1 = new map<char, string>;	
	print_list();
	
	createTree();

	inorder(root, table1);
	for(map<char, string>::iterator it = (*table1).begin();it != (*table1).end(); it++){
		cout<<it->first<<" "<<it->second<<endl;
	}	
				
	fin.open(sourceFile);

	while(fin.get(ch)){

		cout<<ch;
		fout.open(destinationFile, ios::out | ios::app);

		if(ch == '\n'){
			fout<<(*table1)['~']<<" ";
		}
		else{
			fout<<(*table1)[ch]<<" ";	
		}

		fout.close();
	}
	fin.close();
	
	ofstream fout_("tableFile.txt");
	for(map<char, string>::iterator it = (*table1).begin();it != (*table1).end(); it++){

		fout_<<it->first<<it->second<<" ";

	}
	fout_.close();
}

/*********************************************************************************************************************************/



/**************************************************  HUFFMAN DECOMPRESSING FUNTION  **********************************************/

void Huffman::decompress(string sourceFile, string destinationFile){
	cout<<"Decompress Function of Huffman class is called."<<endl;
	string codeValue;
	char ch;
	ofstream fout;
	ifstream fin;
	
	fin.open("tableFile.txt");
	map<string, char> decoder_list;
	if(fin.is_open()){
		while(fin){
			fin>>ch;
			fin>>codeValue;
			decoder_list[codeValue] = ch;
		}
	}
	else
		cout<<"File not found.....ERROR  "<<endl;
	fin.close();
	for(map<string, char>::iterator it = decoder_list.begin();it != decoder_list.end(); it++){

		cout<<it->first<<it->second<<" ";

	}			
	fin.open(sourceFile);
	if(fin.is_open()){
		while(fin>>codeValue){
			cout <<codeValue<<endl;
			fout.open(destinationFile, ios::out | ios::app);
			if(fin.is_open()){
				if(decoder_list[codeValue] == '~'){
					
					fout<<endl;
				}
		
				else{
					fout<<decoder_list[codeValue];	
				}
			}
			else
				cout<<"File not found.....ERROR3  "<<endl;
			fout.close();
		}
	}
	else
		cout<<"File not found.....ERROR2  "<<endl;
	fin.close();
}

/**************************************************************************************************************************/

Technique * selectTechnique(); 				//PROTOTYPE OF SELECT_TECHNIQUE GLOBAL FUNCTION


/*************************************************** INT MAIN STARTS FROM HERE ********************************************/

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
												
/***************************************************:-):-) END OF CODE :-) :-)********************************************/
