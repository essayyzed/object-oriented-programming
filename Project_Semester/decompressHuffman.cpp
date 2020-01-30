#include "huffman.h"

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