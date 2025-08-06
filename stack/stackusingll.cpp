#include <iostream>
using namespace std;



class Stack{
    Stack *top;
    int data;
    public:
    Stack(){
        top = NULL;
    }
    Stack(int data){
        this->data = data;
        top = NULL;
        
    }
    void push(int x){
        Stack *temp = new Stack();
    }
}