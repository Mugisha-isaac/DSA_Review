#include<iostream>
#include<stdlib.h>

using namespace std;

#define MAx 10
int size = 0;


// creating a stack
struct Stack{
    int items[MAx];
    int top;
};

typedef struct Stack st;

void createStack(st *s){
    s->top = -1;
}

int isEmpty(st *s){
    if(s->top == -1){
        return -1;
    }
    return 0;
}

int isFull(st *s){
    if(s->top == MAx -1){
       return 1;
    }
    return -1;
}

void push(st *s, int item){
    int status =  isFull(s);
    if(status == 1){
        cout<<"stack overflow"<<endl;
    }
    int top = s->top++;
    s->items[top];
    size++;
}

void pop(st *s){
    if(isEmpty(s)==-1){
        cout<<"stack underflow"<<endl;
    }
    s->top--;
    size--;
}

void printStack(st *s){
    cout<<"printing stack"<<endl;
    cout<<"--------------"<<endl;
    for(int i=0;i<size;i++){
        cout<<s->items[i]<<" ";
    }
}


int main(){
    int ch;
    st *s = (st *) malloc(sizeof(st));
    createStack(s);
    push(s,1); 
    push(s,2); 
    push(s,3); 
    push(s,4); 
    push(s,5); 
    printStack(s);
    pop(s);
    printStack(s);

    return 0;
}

