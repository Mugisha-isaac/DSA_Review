#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

class account
{
    int acno;
    char name[50];
    int deposit;
    char type;

public:
    void create_account();
    void show_account();
    void modify();
    void dep(int);
    void draw(int);
    void report() const;
    int racno() const;
    int redeposit() const;
    char rettype() const;
    bool isDepositCorrect(int deposit, char type);
};

void account::create_account()
{
    cout << "Enter account No" << endl;
    cin >> acno;
    cout << "Enter the name of account holder" << endl;
    cin >> name;
    cout << "Enter the type of account (C(current)/S(saving))" << endl;
    cin >> type;
    type = toupper(type);
    cout << "Enter initial amount (>=500 for saving and >=1000 for current)" << endl;
    cin >> deposit;
    bool status = isDepositCorrect(deposit,type);
    
}

bool account::isDepositCorrect(int deposit, char type)
{
    switch (type)
    {
    case 'C':
        if (deposit <= 1000)
        {
            return false;
        }
        else
        {
            return true;
        }
    case 'S':

    if(deposit<=500){
        return false;
    }
    else{
        return true;
    }

    default:
       cout<<"Invalid choice";    
    }
}