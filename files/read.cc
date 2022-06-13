#include<iostream>
#include<fstream>

using namespace std;

int main(){

    fstream my_file;
    my_file.open("my_file.txt", ios::in);
    if(!my_file){
        cout<<" File doesn't exist"<<endl;
    }
    else{
        char ch;
        while(1){
            my_file>>ch;
            
            if(my_file.eof()){

                // file.eof() check the end of the file.
              break;

              cout<<ch;
            }
        }
    }

     my_file.close();
    return 0;
}