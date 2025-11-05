#include <iostream>
using namespace std;

// #define MAX_SIZE 10
template <typename T>

class Stack{
    private:
        T* arr;
        int top;
        int size;
    
    public:
        Stack(int size){
            arr = new T[size];
            this->size = size;
            top = -1;
        }

        ~Stack(){
            delete[] arr;
        }

        void push(T x){
            if(top >= size-1){
                cout<<"stack is full (overflow)\n";
                return;
            }
            top++;
            arr[top] = x;
        }

        void pop(){
            if(top == -1){
                cout<<"stack is empty (underflow)\n";
                return;
            }
            top--;
        }

        bool isEmpty(){
            if(top == -1){
                return true;
            }
            return false;
        }

        bool isFull(){
            if(top >= size-1){
                return true;
            }
            return false;
        }

        T getTop(){
            if(top == -1){
                cout<<"stack is empty\n";
                return T();
            }
            return arr[top];
        }

};

string revString(string s){
    int size = s.length();
    Stack s1 = Stack<char>(size);

    for(int i=0;i<size;i++){
        s1.push(s[i]);
    }

    for(int i=0;i<size;i++){
        s[i] = s1.getTop();
        s1.pop();
    }
    return s;
}

int main(){

    Stack s = Stack<int>(10);

    s.push(5);
    s.push(8);
    s.push(83);
    s.push(16);
    s.push(3);
    s.push(3);
    s.push(3);
    s.push(3);
    s.push(3);
    s.push(32);
    s.push(777);
    s.push(777);
    s.push(777);

    cout<<(s.getTop())<<endl;

    s.pop();
    cout<<(s.getTop())<<endl;
    cout<<(s.isEmpty())<<endl;

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    cout<<(s.isFull())<<endl;

    string rev = revString("pushpender singh");
    cout<<"reversed : "<<rev<<endl;

    return 0;
}