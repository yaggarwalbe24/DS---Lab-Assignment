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
    void interleave(){
        if(isEmpty()){
            cout<<"The queue is empty\n";
        }
        int n = rear-front+1;
        int mid = front+n/2;
        int i=front;
        int j = mid;
        while(i<mid and j<=rear){
            cout<<arr[i]<<"\t"<<arr[j]<<"\t";
            i++;
            j++;
        }
        cout<<"\n";
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
int main(){
    Queue q1(10);
    q1.enqueue(4);
    q1.enqueue(7);
    q1.enqueue(11);
    q1.enqueue(20);
    q1.enqueue(5);
    q1.enqueue(9);
    q1.interleave();

}