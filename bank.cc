#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>


using namespace std;

class account{
    int acno;
    char name[50];
    int deposit;
    char type;

    public: 

    void create_account();
    void show_account() const;
    void modify();
    void dep(int);
    void draw(int);
    void report() const;
    int racno() const;
    int redeposit() const;
    char rettype() const;
};


void account::create_account(){
    cout <<"Enter account No"<<endl;
    cin>>acno;
    cout<<"Enter the name of account holder"<<endl;
    cin>>name;
    cout<<"Enter the type of account (C(current)/S(saving))"<<endl;
    cin>>type;
    type = toupper(type);
    cout<<"Enter initial amount (>=500 for saving and >=1000 for current)"<<endl;
    cin>>deposit;
    cout<<"Account Created"<<endl;
}


void account::show_account() const {
   cout<<"Account No: "<<acno<<endl;
   cout<<"Account Holder: "<<name<<endl;
   cout<<"Type Of Account "<<type<<endl;
   cout<<"Balance Amount: "<<deposit<<endl;
}


void account::modify(){
    cout<<"Account No: "<<acno<<endl;
    cout<<"Modify Account Holder Name"<<endl;
    cin>>name;
    cout<<"Modify Account Type "<<endl;
    cin>>type;
    type = toupper(type);
    cout<<"Modify Balance Account "<<endl;
    cin>>deposit;
}

void account::dep(int x){
    deposit = deposit + x;
}

void account::draw(int x){
    deposit = deposit -x;
}

void account::report() const{
    cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<deposit<<endl;    
}

int account::racno()const{
    return acno;
}

int account::redeposit() const {
    return deposit;
}

char account::rettype() const {
    return type;
}


void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_all();
void deposit_withdraw(int,int);
void intro();