#include<iostream>
using namespace std;


class Node{
    public: 
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    Node(){
        this->next = NULL;                                                                                                                                                                                                                                  
    }
};

int getLength(Node* head) {
    int length = 0;
    Node* temp = head;
    while (temp != nullptr) {
        temp = temp->next;
        length++;
        
    }
    return length;
}

void printLL(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
}
void insertAtHead(Node* &head,Node* &tail, int data){
    if (head == NULL){
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    
}
void insertAtTail(Node* &head,Node* &tail, int data){
    if (head == NULL){
        head = new Node(data);
        tail = head;
    }
    else{
        Node *newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }   
}
void insertAtPos(Node* &head,Node* &tail, int data, int pos){
    if(pos<1){
        cout<<"Invalid Position";
        return;
    }
    if (pos == 0){
        insertAtHead(head,tail,data);
    }
    int len = getLength(head);
    if (pos == len){
        insertAtTail(head,tail,data);
    }
    else{
        Node *newNode = new Node(data);
        Node *prev = NULL;
        Node *curr = head;
        while(pos!=1){
            prev = curr;
            curr = curr->next;
            pos--;
        }
        prev->next = newNode;
        newNode->next = curr;
    }
}

void deleteAtPos(Node* &head,Node* &tail, int pos){
    int len = getLength(head);
    if (head == NULL){
        cout<<"List is Empty";
    }
    if (pos==1){
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    
    else if (pos == len){
        Node *prev = head;
        while(prev->next != tail){
            prev = prev->next;
        }
        prev->next = NULL;
        
        delete tail;
        tail = prev;
        
    }
    else{
        Node *prev = NULL;
        Node *curr = head;
        while(pos!=1){
            prev = curr;
            curr = curr->next;
            pos--;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main(){
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head,tail,50);
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,10);
    insertAtTail(head,tail,60);
    insertAtPos(head,tail,35,4);
    deleteAtPos(head,tail,1);
    deleteAtPos(head,tail,6);
    deleteAtPos(head,tail,3);
    printLL(head);
    return 0;
}