#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
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

//Transverse/printing
void printlist(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
//insertation at head
void insertathead(Node *&head, int d)
{

    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
//insertation at tail
void insertatTail(Node* &tail,int d) {

    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}
//insertation at a position
void insertatposition(Node* &head,Node* &tail, int position, int d)
{   
    //insert at start
    if(position == 1) {
        insertathead(head,d);
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
        insertatTail(tail,d);
        return;
    }

    // creating a node for d
    Node* nodetoinsert = new Node(d);
    nodetoinsert -> next = temp -> next;
    temp -> next = nodetoinsert;
}

void deleteNode(Node* &head,Node* &tail,int position) {
    //deleting from start
    if(position==1) {
        Node* temp = head;
        head = head -> next;
        //freeing memory
        temp -> next = NULL;
        delete temp;
    }
    //deleting at middle
    else {
        Node* cur = head;
        Node* pre = NULL;
        int cnt =1;

        while(cnt<position) {
            pre  = cur;
            cur  = cur -> next;
            cnt++;
        }

        pre -> next = cur -> next;
        cur -> next = NULL;
        if(pre->next==NULL){
        tail =pre;
        }
        delete cur;
    }
}

//reverse
Node* reverseLL(Node* &head) {
    if(head==NULL || head -> next == NULL) {
        return head;
    }
    Node* prev = NULL;
    Node* cur = head;
    Node* forward = NULL;
    
    while(cur != NULL){
        forward = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = forward;
    }
    head = prev;
    return head;
}

    void Sort(Node* &head) {
        if (head == nullptr || head->next == nullptr) {
            return; // List is already sorted
        }

        Node* current = head;

            while (current->next != NULL) {
                if (current->data > current->next->data) {
                    // Swap data of the two nodes
                    int temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                }
                current = current->next;
            }
        }

int main()
{ // create a new node
    Node *node1 = new Node(10);

    // pointing head at the node
    Node* head = node1;
    Node* tail = node1;

    printlist(head);
    insertathead(head, 12);
    printlist(head);

    insertathead(head, 15);
    printlist(head);

    insertatTail(tail, 9);
    printlist(head);

    insertatTail(tail, 8);
    printlist(head);

    insertatposition(head,tail,6, 22);
    printlist(head);
    
    cout<<"head "<<head -> data<<endl;
    cout<<"tail "<<tail -> data<<endl;

    deleteNode(head,tail, 5);
    printlist(head);
    cout<<"head "<<head -> data<<endl;
    cout<<"tail "<<tail -> data<<endl;

    reverseLL(head);
    printlist(head);

    Sort(head);
    printlist(head);
    return 0;
}