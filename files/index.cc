// fstream provides 3 classes to deal with files in c++

// 1. ofstream. it is used to write to a file.
// 2. ifstream. it is used to read from a file.
// 3. fstream. combines both ofstream and ifstream.

// conditions to use fstream:
// 1. you need to include <fstream>
// 2.include <iostream>

// How to open a file
//  use open(file,mode)

// mode has these values
// ios::app -> append to a file.
// ios::ate -> seek to end of file.
// ios::in -> read from a file.
// ios::out -> write to a file.
// ios::trunc -> truncate a file.

// example:

#include <iostream>
#include<fstream>

using namespace std;

int main(){
    fstream my_file;
    my_file.open("my_file.txt",ios::out);

    if(!my_file){
        cout<<"File not created !"<<endl;
    }
    else{
        cout<<"File created successfully!"<<endl;
        my_file.close();
    }

    return 0;
}
