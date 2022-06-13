#include<iostream>
#include<fstream>

using namespace std;

int main(){
    fstream my_file;
    my_file.open("my_file.txt",ios::out); // opening file for writing purpose

    if(!my_file){
        cout<<"File was not created"<<endl;
    }
    else{
        cout<<"File was created successfully"<<endl;
        my_file<<"Hello World!"<<endl;
        my_file.close();
    }

    return 0;
}