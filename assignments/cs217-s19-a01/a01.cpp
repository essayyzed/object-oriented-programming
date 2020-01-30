#include <iostream>
#include <string> 
using namespace std; 

// prototype go here 

int index( char * c, char ch);
int count_digits( char * c );


int main() { 
    string haystack; 
    char needle; 

    // Also try different values for the string and character
    haystack = "A quick brown fox (id: 45) jumped over a lazy dog (id: 9)"; 
    needle = 'j'; 

    int loc, count; 
    loc = index(&haystack[0], needle); 
    cout << "Loc: " << loc << endl; 

    count = count_digits(&haystack[0]); 
    cout << "Count: " << count << endl;  

    return 0; 
}

// functions go here 

int index( char * c, char ch){
    int index = 0;
    while ( *c != ch ) {
        if ( *c == '\0' )
            return -1;
        index = index + 1;
        c = c + 1;   //incrementing the address
    }
    return index;
}

int count_digits( char * c ){
    int count = 0;
    while ( *c != '\0' ){
        if ( (int)(*c) >= 48 && (int)(*c) <=57 )
            count = count +1;
        c = c + 1; //incrementing the address
    }
    return count;
}