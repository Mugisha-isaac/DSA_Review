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


int main(){

}

void write_account(){
    account ac;
    ofstream outFile;
    outFile.open("account.dat", ios::binary | ios::app);
    ac.create_account();
    outFile.write(reinterpret_cast<char *>(&ac), sizeof(account));
    outFile.close();
}

void display_sp(int n){
    account ac;
    bool flag = false;
    ifstream inFile;
    inFile.open("account.dat", ios::binary);
    if(!inFile){
        cout<<"File couldn't be opened !! press any key....";
        return;
    }

    cout<<"Balance Details"<<endl;
    while (inFile.read(reinterpret_cast<char *>(&ac),sizeof(account)))
    {
        if(ac.racno()==n){
            ac.show_account();
            flag = true;
        }
    }
    inFile.close();
    if(flag == false){
        cout<<"Account Number Doesn't Exist"<<endl;
    }
}

void modify_account(int n){
    bool found = false;
    account ac;
    fstream File;
    File.open("account.dat",ios::binary | ios::in | ios::out);
    if(!File){
        cout<<"File couldn't be opened !! press any key....";
        return;
    }
    while(!File.eof() && found == false){
        File.read(reinterpret_cast<char *>(&ac), sizeof(account));
        if(ac.racno()==n){
            ac.show_account();
            cout<<"Enter New Details Of Account "<<endl;
            ac.modify();
            int pos = (-1)*static_cast<int>(sizeof(account));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *>(&ac), sizeof(account));
            cout<<"Record Updated!"<<endl;
            found = true;
        }
    }
    File.close();
    if(found == false){
        cout<<"Record Not Found"<<endl;
    }
}

void delete_account(int n){
    account ac;
    ifstream inFile;
    ofstream outFile;
    
    inFile.open("account.dat",ios::binary);
    if(!inFile){
        cout<<"File couldn't be opened !! press any key....";
        return;
    }
    outFile.open("Temp.dat", ios::binary);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *>(&ac),sizeof(account))){
        if(ac.racno() != n){
            outFile.write(reinterpret_cast<char *>(&ac),sizeof(account));
        }
    }

    inFile.close();
    outFile.close();
    remove("account.dat");
    rename("Temp.dat","account.dat");
    cout<<"Record Deleted"<<endl;
}


void display_all(){
    account ac;
    ifstream inFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile){
        cout<<"File could not be open !! Press any Key...";
		return;
    }

    cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"A/c no.      NAME           Type  Balance\n";
	cout<<"====================================================\n";
    
    while(inFile.read(reinterpret_cast<char *>(&ac),sizeof(account))){
        ac.report();
    }
    inFile.close();
}


void deposit_withdraw(int n, int option){
    int amount;
    bool found = false;
    account ac;
    fstream File;
    File.open("account.dat", ios::binary | ios::in | ios::out);
    if(!File){
        cout<<"File could not be open !! Press any Key...";
		return;
    }

    while(!File.eof() &&found == false){
        File.read(reinterpret_cast<char *>(&ac),sizeof(account));
        if(ac.racno() ==n){
            ac.show_account();
            if(option ==1){
                cout<<"TO DEPOSIT AMOUNT";
                cout<<"-----------------"<<endl;
                cout<<"Enter amount to be deposited"<<endl;
                cin>>amount;
                ac.dep(amount);
            }

            if(option ==2){
                cout<<"TO WITHDRAW AMOUNT"<<endl;
                cout<<"-------------------"<<endl;
                cout<<"Enter amount to withdraw"<<endl;
                cin>>amount;
                int bal = ac.redeposit() - amount;
                if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C')){
                    cout<<">Insufficient Balance"<<endl;
                }
                else{
                    ac.draw(amount);
                }
            }
            int pos = (-1)*static_cast<int>(sizeof(account));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&ac), sizeof(account));
            cout<<"Record Updated";
            found = true;
        }
    }

    File.close();
    if(found == false){
        cout<<"Record Not Found"<<endl;
    }
}


void intro(){
    cout<<"Bank Management System"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"Made By: your name";
    cout<<"SCHOOL: your school name";
    cin.get();
}