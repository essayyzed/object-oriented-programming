#include "rle.h"



void RunLength :: compress(string sourceFile, string destinationFile){
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