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
    int size;
    cout<<"Enter size of queue: ";
    cin>>size;
    Queue Q1(size);
    int option = 0;
    cout<<"1. Insert element into queue\n";
    cout<<"2. Delete element from queue\n";
    cout<<"3. Check if queue is empty\n";
    cout<<"4. Check if queue is full\n";
    cout<<"5. Display whole queue\n";
    cout<<"6. Peek at the queue\n";
    cout<<"7. Exit\n";
    while(option!= 7){
        cout<<"Please choose an option: ";
        cin>>option;
        if(option == 1){
            int value;
            cout<<"Enter value to be entered into the queue:    ";
            cin>>value;
            Q1.enqueue(value);
        }
        else if(option == 2){
            int ele = Q1.dequeue();
            if(ele == -1){
                cout<<"Underflow"<<"\n";
            }
            else{
                cout<<ele<<"\n";
            }
        }
        else if(option == 3){
            if(Q1.isEmpty()){
                cout<<"The queue is empty\n";
            }
            else{
                cout<<"The queue is not empty\n";
            }
        }
        else if(option == 4){
            if(Q1.isFull()){
                cout<<"The queue is full\n";
            }
            else{
                cout<<"The queue is not full\n";
            }
        }
        else if(option == 5) Q1.display();
        else if(option == 6){
            int ele = Q1.peek();
            if(ele == -1){
                cout<<"The queue is empty"<<"\n";
            }
            else{
                cout<<ele<<"\n";
            }
        }
    }
}