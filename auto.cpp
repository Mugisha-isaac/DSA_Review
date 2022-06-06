#include<bits/stdc++.h>
using namespace std;

int main(){
    auto x=4;
    auto y=3.37;
    auto ptr = &x;


    cout<<typeid(x).name()<<endl;
    cout<<typeid(y).name()<<endl;
    cout<<typeid(ptr).name()<<endl;


    return 0;
}