#include <iostream>
using namespace std;
class CircularQueues{
    int front,rear,size;
    int *arr;
    public:
    CircularQueues(int capacity){
        size = capacity;
        arr = new int[size];
        front = rear = -1;
    }
    bool isEmpty(){
        if(front == rear && rear==-1) return true;
        return false;
    }
    bool isFull(){
        if(front == (rear+1)%size) return true;
        return false;
    }
    void enqueue(int val){
        if(isFull()){
            cout<<"Cannot insert element as queue is full\n";
            return;
        }
        if(isEmpty()) front=rear=0;
        else rear = (rear+1)%size;
        arr[rear] = val;
    }
    void dequeue(){
        if(isEmpty()) cout<<"Cannot delete any element as queue is empty\n";
        else{
            cout<<"The element dequeued:    "<<arr[front]<<"\n";
            if(front==rear){
                front = rear = -1;
            }
            else{
                front = (front+1)%size;
            }
        }
    }
    void peek() {
        if(isEmpty()){
            cout<<"Queue is empty\n";
        }
        else{
            cout << "Element at front: " << arr[front] << "\n";
        }
    }
    void display(){
        if(isEmpty()){
            cout<<"Queue is empty\n";
        }
        else{
            int i = front;
            while(true){
                cout<<arr[i]<<"\t";
                if(i==rear) break;
                i=(i+1)%size;
            }
            cout<<"\n";
        }
    }
};
int main(){
    int size;
    cout<<"Enter size of queue: ";
    cin>>size;
    CircularQueues Q1(size);
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
        else if(option == 2) Q1.dequeue();
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
        else if(option == 6) Q1.peek();
    }
}