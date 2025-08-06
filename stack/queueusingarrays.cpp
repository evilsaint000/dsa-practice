#include <iostream>
using namespace std;

class queue{
    int arr[5];
    int capacity=5;
    int start,end=-1;
    int top= -1;
    int currsize=0;
    public:
    void push(int x){
        if(end==-1){
            start=0;
            end=0;
            arr[end]=x;
            currsize++;
        }
        else if(currsize == capacity){
            cout <<  "queue is full" << endl;
        }else{
            end = (end+1)%capacity;
            arr[end]=x;
            currsize++;
        }
    }
    void pop(){
        if(currsize==0){
            cout << "queue is empty"  << endl;
        }
        else if(start==end){
            start=-1;
            end=-1;
            currsize--;
        }
        else{
            start = (start+1)%capacity;
            currsize--;

        }
    }
    void show(){
        if(currsize == 0){
            cout << "queue is empty" << endl;
        } else {
            int i = start;
            while(true){
                cout << arr[i] << " ";
                if(i == end) break;
                i = (i + 1) % capacity;
            }
            cout << endl;
        }
    }
    void top1(){
        if(currsize == 0){
            cout << "queue is empty" << endl;
        } else {
            cout << arr[start] << endl;
        }
    }
    void size(){
        cout<< currsize << endl;
    }

};
int main(){
    queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);
    q.pop();
    q.top1();
    q.size();
    q.show();
    return 0;
}