#include <iostream>
using namespace std;
class Queue{
    int front,rear,size;
    char *arr;
    public:
    Queue(int capacity){
        size = capacity;
        arr = new char[size];
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
    void enqueue(char val){
        if(isFull()){
            cout<<"Cannot enter element as queue is full\n";
            return;
        }
        if(isEmpty()) front=rear=0;
        else rear +=1;
        arr[rear] = val;
    }
    char dequeue(){
        if(isEmpty()){
            return '\0';
        } 
        else{
            char val = arr[front];
            front += 1;
            if(front>rear) front=rear=-1;
            return val;
        }
    }
    char peek(){
        if(isEmpty()){
            return '\0';
        }
        else{
            return arr[front];            
        }
        
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
void firstNonRepeating(char input[], int n){
    Queue q(n);
    int freq[256] = {0};
    for(int i=0;i<n;i++){
        char ch = input[i];
        freq[ch] += 1;
        q.enqueue(ch);
        while(q.isEmpty()!= true && freq[q.peek()]>1){
            q.dequeue();
        }
        if(q.isEmpty()!=true){
            cout<<q.peek()<<" ";
        }
        else{
            cout<<"-1"<<" ";
        }
    }
}
int main(){
    char input[] = {'a','a','b','c'};
    int n = sizeof(input)/sizeof(input[0]);
    firstNonRepeating(input,n);
}