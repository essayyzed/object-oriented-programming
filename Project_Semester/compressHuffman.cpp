#include "huffman.h"


void Huffman::compress(string sourceFile, string destinationFile)
{
	cout<<"Compress Function of Huffman class is called."<<endl;
	map<char, int> *name_map = new map<char, int>;
	 
	ofstream fout;
	ifstream fin;
	fin.open(sourceFile);				// File name which you want to compress//
	char ch;
	while(fin.get(ch))
	{
		if(ch == '\n')
		{
			(*name_map)['~'] = (*name_map)['~'] + 1;
		}
		else{
			(*name_map)[ch] = (*name_map)[ch] + 1;
		}
	}
	fin.close();
	
	for(map<char, int>::iterator it = (*name_map).begin();it != (*name_map).end(); it++)
	{
		push(it->first, it->second);
	}
	delete name_map;
	map<char, string> *table1 = new map<char, string>;	
	print_list();
	
	createTree();

	inorder(root, table1);
	for(map<char, string>::iterator it = (*table1).begin();it != (*table1).end(); it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}	
				
	fin.open(sourceFile);

	while(fin.get(ch))
	{

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