#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(){
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

int getLength(Node* head){
    int length = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        length++;
    }
    return length;
}

void print(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<"<->";
        temp = temp->next;
    }

}

void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data){
    if(tail == NULL){
        Node *newNode = new Node(data);
        tail = newNode;
        head = newNode;
    }
    else{
        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    
}

void insertATpos(Node* &head, Node* &tail, int data, int pos){
    if(pos<1){
        cout<<"Invalid Position";
        return;
    }
    if(pos == 1){
        insertAtHead(head,tail,data);
    }
    int len = getLength(head);
    if(pos > len){
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
       newNode->prev = prev;
       newNode->next = curr;
       curr->prev = newNode;


    }
}

void deleteAtHead (Node* &head, Node* &tail){
    if(head == NULL){
        cout<<"List is Empty";
        return;
    }
    else if(head->next == NULL){
        delete head;
        head = NULL;
        tail = NULL;
    }
    else{
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;

    }
}

void deleteAtTail(Node* &head, Node* &tail){
    if(tail == NULL){
        cout<<"List is Empty";
        return;
    } 
    else if(tail->prev == NULL){
        delete tail;
        head = NULL;
        tail = NULL;
    }
    else{
        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;

    }
}

void deleteAtPos(Node* &head, Node* &tail, int pos){
    if(head == NULL){
        cout<<"List is Empty";
        return;
    }
    if(pos <= 1){
        deleteAtHead(head,tail);
    }
    int len = getLength(head);
    if(pos > len){
        deleteAtTail(head,tail);
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
        curr->next->prev = prev;
        curr->next = NULL;
        curr->prev = NULL;
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
    insertATpos(head,tail,25,3);
    print(head);
    cout<<endl;
    deleteAtHead(head,tail);
    deleteAtTail(head,tail);
    deleteAtPos(head,tail,4);
    print(head);
    return 0;
}