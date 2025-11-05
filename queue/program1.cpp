#include <iostream>
using namespace std;

class Queue{
    private:
        int rear;
        int front;
        int* arr;
        int size;
    public:
        Queue(int size){
            arr = new int[size];
            rear = -1;
            front = -1;
            this->size = size;
        }
        ~Queue(){
            delete arr;
        }

        void enqueue(int x){
            if(rear == size-1){
                cout<<"queue is full\n";
                return;
            }
            if(front == -1){
                rear = front = 0;
                arr[rear] = x;
                return;
            }
            rear++;
            arr[rear] = x;
            return;
        }

        void dequeue(){
            if(front == -1){
                cout<<"queue is already empty"<<endl;
                return;
            }
            if(front == rear){
                front = rear = -1;
                return;
            }
            front++;
            return;
        }

        void print(){
            if(front == -1){
                cout<<"queue is empty"<<endl;
                return;
            }
            for(int i=front;i<=rear;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            return;
        }

};

int main(){

    Queue q = Queue(5);

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