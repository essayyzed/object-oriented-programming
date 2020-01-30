#include <iostream> 
#include <fstream>
using namespace std; 

#define SIZE 4

// stuff from Queue lecture goes here ... then apply template on it 
void pause(){
    getchar();
}

template <class T>
class Queue {
    private:
    T q[SIZE];
    int in,out;
    bool is_empty, is_full;

    int inc(int value_to_increment);

    public:
    Queue();
    
    void enqueue(T val);
    T dequeue();
    bool tell_is_empty();
    bool tell_is_full();
    void print_queue();
};

template <class T>
Queue<T>::Queue() {
    in = out = 0;
    is_empty = true;
    is_full = false;
}

template <class T>
int Queue<T>::inc(int value_to_increment) {
    if ( value_to_increment + 1 == SIZE )
        value_to_increment = 0;
    else 
        value_to_increment = value_to_increment + 1;
    return value_to_increment;
}

template <class T>
void Queue<T>::enqueue(T val) {
    if (is_full){
        throw "Mr.Queue is full...";
    }

    q[in] = val;
    in = inc(in);

    if (in == out)
        is_full = true;

    is_empty = false;
}

template <class T>
T Queue<T>::dequeue(){
    if (is_empty)
        throw "Mr.Queue is empty...";

    T returning_value = q[out];
    out = inc(out);

    if (out == in)
        is_empty = true;

    is_full = false;
    return returning_value;
}

template <class T>
bool Queue<T>::tell_is_empty() {
    return is_empty;
}

template <class T>
bool Queue<T>::tell_is_full() {
    return is_full;
}

template <class T>
void Queue<T>::print_queue() {
    cout << "[\t";
    for ( int i =0; i < SIZE; i++ )
        cout << q[i] << "\t";
    cout << "]" << endl;

    cout << " \t";
    for ( int i = 0; i < SIZE; i++ )
        cout << i << "\t";
    cout << " " << endl;

    cout << " ";
    for ( int i = 0; i < SIZE; i++ )
        cout << "\t";
    cout << "^in" << endl;

    cout << " ";
    for ( int i = 0; i < SIZE; i++ )
        cout << "\t";
    cout << "^out" << endl;

    pause();
}

class Writer { 
    // fill stuff here 
    public:
    void process_file(string filename, Queue <string> * q);
}; 
// method definitions for Writer class here 
void Writer::process_file(string filename, Queue <string> * q){
    string line;
    ifstream fin;

    fin.open(filename);
    while ( !fin.eof() ){
        getline(fin,line);
        try{
            if (q->tell_is_full() == true)
                break;
            q->enqueue(line);
        }
        catch(const char * message) {
            cout << message << endl;
        }  
    }
    fin.close();
}


class Reader { 
    // fill stuff  here 
    public:
    void process_queue(Queue <string> * q);
};
// method definitions for Reader class here 
void Reader::process_queue(Queue <string> * q){
    string line;
    while ( q->tell_is_empty() != true ){
        try{
            line = q->dequeue();
            cout << "String:  " << " [" << line << "] " << " has length:  " << line.length() << endl;
            pause();
        }
        catch(const char * message) {
            cout << message << endl;
        }
    }
}


int main() { 
    Queue<string> *que; 
    que = new Queue<string>; 

    string filename = "string-collection.txt"; 

    Writer first_writer; 
    Reader first_reader; 

    first_writer.process_file(filename, que); 
    first_reader.process_queue(que); 

    return 0; 
}



