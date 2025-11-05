#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            next = nullptr;
        }
};

class Queue{
    Node* head;
    Node* rear;
    public:
        Queue(){
            head = nullptr;
            rear = nullptr;
        }

        void enqueue(int x){
            if(head == nullptr){
                head = new Node(x);
                rear = head;
                return;
            }
            Node* newNode = new Node(x);
            rear->next = newNode;
            rear = newNode;
            return;
        }

        void dequeue(){
            if(head == nullptr){
                cout<<"queue is already empty\n";
                return;
            }
            if(head == rear){
                Node* delNode = head;
                head = rear = nullptr;
                delete delNode;
                return;
            }
            Node* delNode = head;
            head = head->next;
            delete delNode;
        }

        void print(){
            if(head == nullptr){
                cout<<"queue is empty\n";
                return;
            }
            Node* temp = head;
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
            return;
        }
};


int main(){

    Queue q = Queue();
    
    q.print();
    
    q.dequeue();
    q.enqueue(55);
    q.enqueue(9);
    q.enqueue(4);
    q.enqueue(83);

    q.enqueue(22);
    q.enqueue(10);



    q.print();

    q.dequeue();
    q.dequeue();

    q.print();

    q.enqueue(99);
    q.print();

    return 0;
}