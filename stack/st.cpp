#include <iostream>
using namespace std;

class stack{
    int arr[10];
    int top= -1;
    public:
    void push(int x){
        if(top==9){
            cout << "stack is full" << endl;
        }else{
            top++;
            arr[top]=x;
        }
    }
    void pop(){
        if(top==-1){
            cout << "stack is empty"  << endl;

        }else{
            top --;
        }
    }
    void show(){
        for(int i=0; i<=top; i++){
            cout << arr[i] << " ";
        }

    }
    void top1(){
        cout << arr[top] << endl;
    }
    int size(){
        return top+1;
    }

};

int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    s.push(80);
    s.push(90);
    s.push(100);
   
    s.pop();
    s.show();
    return 0;
}