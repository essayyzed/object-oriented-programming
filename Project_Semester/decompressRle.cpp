#include "rle.h"


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