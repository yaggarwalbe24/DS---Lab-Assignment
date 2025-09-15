#include <iostream>
using namespace std;
class Queue{
    int front,rear,size;
    int *arr;
    public:
    Queue(int capacity){
        size = capacity;
        arr = new int[size];
        front = rear = -1;
    }
    bool isEmpty(){
        if(front == -1 || front>rear) return true;
        return false;
    }
    bool isFull(){
        if(rear == size-1) return true;
        return false;
    }
    void enqueue(int val){
        if(isFull()){
            cout<<"Cannot enter element as queue is full\n";
            return;
        }
        if(isEmpty()) front=rear=0;
        else rear +=1;
        arr[rear] = val;
    }
    int dequeue(){
        if(isEmpty()){
            return -1;
        } 
        else{
            int val = arr[front];
            front += 1;
            if(front>rear) front=rear=-1;
            return val;
        }
    }
    int peek(){
        if(isEmpty()){
            return -1;
        }
        else{
            return arr[front];            
        }
        
    }
    int count(){
        return rear-front+1;
    }
    void display(){
        if(isEmpty()){
            cout<<"Queue is empty\n";
        }
        else{
            for(int i=front;i<=rear;i++){
                cout<<arr[i]<<"\t";
            }
        }
    }
};
class StackUsingOneQueue{
    Queue q1(100);
    public:
    void push(int val){
        int count = q1.count();
        q1.enqueue(val);
        for(int i=0;i<count;i++){
            int temp = q1.dequeue();
            q1.enqueue(temp);
        }
        
    }
    void pop(){
        if(q1.isEmpty()){
            cout<<"Cannot pop as stack is empty\n";
        }
        else{
            cout<<q1.dequeue();
        }
    }
    void display(){
        q1.display();
    }
    void peek(){
        cout<<q1.peek()<<"\n";
    }
};
int main(){
    StackUsingOneQueue s1;
    s1.push(12);
    s1.push(64);
    s1.peek();
    s1.pop();
    s1.display();

}