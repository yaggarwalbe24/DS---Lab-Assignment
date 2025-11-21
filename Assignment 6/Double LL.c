#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int val){
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};
class doubleLL{
    Node *head;
    public:
    doubleLL(){
        head = nullptr;
    }
    void insertAtHead(int val){
        Node *newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
        }
        else{
            newNode ->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void insertAtEnd(int val){
        Node * newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
        }
        else{
            Node *curr = head;
            while(curr->next != nullptr){
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->prev = curr;
        }
    }
    void insertAfterValue(int ele, int val){
        if(head == nullptr){
            cout<<"Cannot enter as node does not exist\n";
            return;
        }
        Node *newNode = new Node(val);
        Node *curr = head;
        while(curr && curr->data != ele){
            curr = curr->next;
        }
        if(curr == nullptr){
            cout<<"Element not found\n";
            return;
        }
        newNode->next = curr->next;
        newNode->prev = curr;
        if(curr->next){
            curr->next->prev = newNode;
        }
        curr->next = newNode;
    }
    void deleteAtBeginning(){
        if(head == nullptr){
            cout<<"Cannot delete anything as list is empty\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        if(head){
            head->prev = nullptr;
        }
        delete temp;
    }
    void deleteAtEnd(){
        if(head == nullptr){
            cout<<"Cannot delete as list is empty\n";
            return;
        }
        Node * curr = head;
        while(curr->next){
            curr = curr->next;
        }
        if(curr->prev){
            curr->prev->next = nullptr;
        }
        else{
            head = nullptr;
        }
        delete curr;
    }
    void deleteAtValue(int val){
        if(head == nullptr){
            cout<<"Cannot delete as list is empty\n";
            return;
        }
        Node *curr = head;
        while(curr && curr->data != val){
            curr = curr->next;
        }
        if(curr == nullptr){
            cout<<"Element not found\n";
            return;
        }
        if(curr->prev){
            curr->prev->next = curr->next;
        }
        else{
            head = curr->next;
        }
        if(curr->next){
            curr->next->prev = curr->prev;
        }
        delete curr;
    }
    void display(){
        if(head == nullptr){
            cout<<"The list is empty\n";
            return;
        }
        Node *curr = head;
        while(curr){
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<"\n";
    }
    void search(int val){
        Node * curr = head;
        int count = 1;
        while(curr){
            if(curr->data == val){
                cout<<"The element was found at: "<<count<<" position\n";
                return;
            }
            curr = curr->next;
            count += 1;
        }
        cout<<"Value not found\n";
    }
    void size(){
        int count = 0;
        Node *curr = head;
        while(curr){
            curr = curr->next;
            count += 1;
        }
        cout<<"The size of the list is: "<<count<<"\n";
    }
    void palindrome(){
        if(head == nullptr){
            cout<<"The list is empty\n";
            return;
        }
        Node *left = head;
        Node * right = head;
        while(right->next != nullptr){
            right = right->next;
        }
        while(left != right && left->prev != right){
            if(left->data != right->data){
                cout<<"The list is not a palindrome\n";
                return;
            }
            left = left->next;
            right = right->prev;
        }
        cout<<"The list is a palindrome\n";
    }
};
int main(){
    doubleLL dll;
    int choice, val, ele;
    do{
        cout<<"1. Insert node at the beginning of the list\n";
        cout<<"2. Insert node at the end of the list\n";
        cout<<"3. Insert node after a specific node\n";
        cout<<"4. Delete from the beginning of the list\n";
        cout<<"5. Delete from the end of the list\n";
        cout<<"6. Delete a specific node\n";
        cout<<"7. Display the list\n";
        cout<<"8. Search for an element in the list\n";
        cout<<"9. Check the size of the list\n";
        cout<<"10. Check palindrome\n";
        cout<<"11. Exit\n";
        cout<<"Enter choice:    ";
        cin>>choice;
        switch (choice){
            case 1:
                cout<<"Enter value of node to be inserted: ";
                cin>>val;
                dll.insertAtHead(val);
                break;
            case 2:
                cout<<"Enter value of node to be inserted: ";
                cin>>val;
                dll.insertAtEnd(val);
                break;
            case 3:
                cout<<"Enter the value of the node to be entered:   ";
                cin>>val;
                cout<<"Enter the value of the node after which to be entered:   ";
                cin>>ele;
                dll.insertAfterValue(ele,val);
                break;
            case 4:
                dll.deleteAtBeginning();
                break;
            case 5:
                dll.deleteAtEnd();
                break;
            case 6:
                cout<<"Enter the value of the node to be deleted:   ";
                cin>>val;
                dll.deleteAtValue(val);
                break;
            case 7:
                dll.display();
                break;
            case 8:
                cout<<"Enter the value to be searched:  ";
                cin>>val;
                dll.search(val);
                break;
            case 9:
                dll.size();
                break;
            case 10:
                dll.palindrome();
                break;
            case 11:
                break;
            default:
                cout<<"Invalid option\n";
        }
    }while(choice != 11);
}