#include <iostream>
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
//traversing a doubly linked list forward
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data<<" ";
        temp = temp->next;
    }
    cout << endl;
}
//traversing a doubly linked list backward
void printb(Node *tail) 
{
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->data<<" ";
        temp = temp->prev;
    }
    cout << endl;
}

//gives length of doubly linked list
int getlength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void insertAtHead(Node* &head,Node* &tail,int d) {
    //if list is empty
    if(head==NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else {
    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
    }

}
void insertAtTail(Node* &head,Node* &tail,int d){
    //if list is empty
    if(tail==NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else {
    Node* temp = new Node(d);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
    }
}
void insertAtPosition(Node* &head,Node* &tail,int position,int d) {
    //insert at start
    if(position == 1) {
        insertAtHead(head,tail,d);
        return;
    }
    //transversing to position
    Node *temp = head;
    int c = 1;
    while (c < position - 1) {
        temp = temp -> next;
        c++;
    }
    //insert at tail
    if(temp -> next == NULL) {
        insertAtTail(head,tail,d);
        return;
    }

    // creating a node for d
    Node* nodetoinsert = new Node(d);
    temp -> next -> prev = nodetoinsert; 
    nodetoinsert -> next = temp -> next;
    temp -> next = nodetoinsert;
    nodetoinsert -> prev = temp;
}
void deleteNode(Node* &head,Node* &tail,int position) {
    //deleting from start
    if(position==1) {
        Node* temp = head;
        head = head -> next;
        head ->prev = NULL;
        //freeing memory
        temp -> next = NULL;
        delete temp;
    }
    //deleting at middle
    else {
        Node* cur = head;
        Node* prev = NULL;
        int cnt =1;

        while(cnt<position) {
            prev  = cur;
            cur  = cur -> next;
            cnt++;
        }

        cur -> prev =NULL;
        prev -> next = cur -> next;
        cur -> next -> prev = prev;
        cur -> next = NULL;
        if(prev->next==NULL){
        tail =prev;
        }
        delete cur;
    }
}
int main()
{
    // Node *node1 = new Node(10);
    Node *head = NULL;
    Node *tail = NULL;
    print(head);
    cout<<getlength(head)<<endl;
    insertAtHead(head,tail,12);
    print(head);
    insertAtHead(head,tail,13);
    print(head);
    insertAtHead(head,tail,14);
    print(head);
    insertAtTail(head,tail,17);
    print(head);

    insertAtPosition(head, tail, 2, 31);
    print(head);
    insertAtPosition(head, tail, 1, 101);
    print(head);
    insertAtPosition(head, tail, 7, 100);
    print(head);
    printb(tail);
    cout<<"head "<<head -> data<<endl;
    cout<<"tail "<<tail -> data<<endl;
    deleteNode(head, tail, 5);
    print(head);
    cout<<"head "<<head -> data<<endl;
    cout<<"tail "<<tail -> data<<endl;
    printb(tail);
    return 0;
}