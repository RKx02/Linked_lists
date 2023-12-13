#include<iostream>
using namespace std;

class Node
{
public:
       int data;
    Node *prev;
    Node *next;
    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    //destructor
    ~Node() {
        int value = this -> data;
         //memory free
        if(this->next != NULL) {
            delete next;
            this-> next = NULL;
        }
        cout<<"Memory is free for "<<value<<endl;
    }
};
void insertNode(Node* &tail,int element,int d) {
    if(tail==NULL) {
        Node* temp = new Node(d);
        tail = temp;
        temp -> next = temp;
        temp -> prev = temp;
    }
    else {
        Node* cur = tail;
        while(cur -> data != element) {
            cur = cur -> next;
        }
        Node* Node1 = new Node(d);
        Node1 -> next = cur -> next;
        cur -> next -> prev = Node1;
        cur -> next = Node1;
        Node1 -> prev = cur;
    }
}

void deleteNode(Node* &tail,int value) {
    //if list is empty
    if(tail == NULL) {
        cout<<"List is empty, Please check again";
        return;
    }
    else {
        //list is non empty
        Node* prev = tail;
        Node* cur = prev -> next;
        while(cur -> data != value){
            prev = cur;
            cur = cur -> next;
        }
        prev -> next = cur -> next;
        cur -> next -> prev = prev;
        //1 node linked list
        if(cur==prev) {
            tail = NULL;
        }
        //>2 linked list
        else if(tail==cur){
            tail = prev;
        }
        cur -> next = NULL;
        delete cur;
    }
}
int getlength(Node* tail) {
    int c=1;
    Node* temp =tail -> next;
    while(temp!=tail){
        c++;
        temp = temp -> next;
    }
    return c;
}

void printNode(Node* tail) {
    Node* temp = tail;
     if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    do {
        cout<<tail -> data <<" ";
         tail = tail -> next;
    }
    while(tail != temp);
    cout<<endl;
}

int main() {
Node* tail = NULL;
insertNode(tail,3,5);
printNode(tail);

insertNode(tail,5,10);
printNode(tail);

insertNode(tail,10,7);
printNode(tail);

insertNode(tail,10,244);
printNode(tail);
cout<<"number of node: "<<getlength(tail)<<endl;
deleteNode(tail,5);
printNode(tail);
return 0;
}