#include <iostream>
using namespace std;
// template <typename T>


class Node{
    public:
        int data;
        Node* next;
        Node(int x){
            data = x;
            next = nullptr;
        }
};

class Stack{
    int top;
    Node* head;

    public:
        Stack(){
            top = -1;
            head = nullptr;
        }
        void push(int data){
            Node* newNode = new Node(data);
            newNode->next = head;
            head = newNode;
            return;
        }
        void pop(){
            if(head == NULL){
                cout<<"stack is empty (underflow)\n";
                return;
            }
            Node* delNode = head;
            head = head->next;
            delNode->next = nullptr;
            delete delNode;
        }
        int getTop(){
            if(head == NULL){
                cout<<"stack is empty (underflow)\n";
                return -1;
            }
            return head->data;
        }
        bool isEmpty(){
            if(head == NULL){
                return true;
            }
            return false;
        }
};


void insertBeg(int data, Node **head)
{
    Node *newNode = new Node(data);
    newNode->next = *head;
    *head = newNode;
    return;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


Node* reverseLL(Node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    Stack s = Stack();
    Node* temp = head;
    while(temp != NULL){
        s.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(!s.isEmpty()){
        temp->data = s.getTop();
        temp = temp->next;
        s.pop();
    }
    return head;
}


int main(){
    Stack s = Stack();

    cout<<s.getTop()<<endl;
    s.push(45);
    s.push(83);
    s.push(5);
    s.push(32);

    cout<<s.getTop()<<endl;

    s.pop();
    // s.pop();
    // s.pop();
    // s.pop();

    cout<<s.getTop()<<endl;

    Node* head = nullptr;
    insertBeg(5, &head);
    insertBeg(89, &head);
    insertBeg(9, &head);
    insertBeg(92, &head);

    printList(head);
    head = reverseLL(head);
    printList(head);

    return 0;
}