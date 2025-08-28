#include <iostream>
using namespace std;
bool isFull(int count,int size){
    if(count == size){
        return true;
    }
    return false;
}
bool isEmpty(int count){
    if(count == 0){
        return true;
    }
    return false;
}
void push(int arr[],int *count,int size){
    if(isFull(*count,size) == true){
        cout<<"Cannot enter element as stack is full\n";
        return;
    }
    int ele;
    cout<<"Please enter the element to be entered into the stack:   ";
    cin>>ele;
    arr[*count] = ele;
    *count += 1;
    return;
}
void pop(int arr[],int *count){
    if(isEmpty(*count) == true){
        cout<<"Cannot pop as stack is empty\n";
        return;
    }
    cout<<"Element popped:  "<<arr[(*count)-1]<<"\n";
    (*count) --;
    return;
}
void display(int arr[],int count){
    cout<<"The stack is as follows\n";
    for(int i = 0;i<count;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return;
}
void peek(int arr[],int count){
    if(isEmpty(count)){
        cout<<"Cannot peek as stack is empty\n";
        return;
    }
    cout<<"The element at top:  "<<arr[count-1]<<"\n";
    return;
}
int main(){
    int num;
    cout<<"Please enter the size of the stack:  ";
    cin>>num;
    int stack[num];
    int count = 0;
    int option;
    while(true){
        cout<<"Please enter a number to choose a functionality:\n";
        cout<<"1. Adding an element to the stack\n";
        cout<<"2. Deleting an element from the stack\n";
        cout<<"3. To check if the stack is empty\n";
        cout<<"4. To check if the element is full\n";
        cout<<"5. To see the stack\n";
        cout<<"6. To peek at the stack\n";
        cout<<"7. Exit\n";
        cin>>option;
        if(option == 1) push(stack,&count,num);
        else if(option == 2) pop(stack,&count);
        else if(option == 3){
            if (isEmpty(count)){
                cout<<"The stack is empty\n";
            }
            else{
                cout<<"The stack is not empty\n";
            }
        }
        else if(option == 4){
            if (isFull(count,num)){
                cout<<"The stack is full\n";
            }
            else{
                cout<<"The stack is not full\n";
            }
        }
        else if(option == 5) display(stack,count);
        else if(option == 6) peek(stack,count);
        else if(option == 7) break;
        else cout<<"Invalid input\n";
    }
}