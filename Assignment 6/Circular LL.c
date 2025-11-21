#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node(int val){
        data = val;;
        next = nullptr;
    }
};
class CircularLL{
    Node*head;
    public:
    CircularLL(){
        head = nullptr;
    }
    void insertAtBeginning(int val){
        Node *newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
            newNode->next = head;
            return;
        }
        Node *curr = head;
        while(curr->next != head){
            curr = curr->next;
        }
        curr->next= newNode;
        newNode-> next = head;
        head = newNode;
    }
    void insertAtEnd(int val){
        Node *newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
            newNode->next = head;
            return;
        }
        Node *curr = head;
        while(curr->next != head){
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->next = head;
    }
    void insertAfterValue(int ele,int val){
        if(head == nullptr){
            cout<<"Cannot enter as node does not exist\n";
            return;
        }
        Node *curr = head;
        do{
            if(curr->data == ele){
                break;
            }
            curr = curr->next;
        }while(curr!=head);
        if(curr->data != ele){
            cout<<"Element does not exist in the list\n";
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = curr->next;
        curr->next = newNode;
    }
    void deleteAtBeginning(){
        Node *temp = head;
        if(head == nullptr){
            cout<<"Empty list\n";
            return;
        }
        if(head->next == head){
            head = nullptr;
        }
        else{
            Node *curr = head;
            while(curr->next != head){
                curr = curr->next;
            }
            curr->next = head->next;
            head = head->next;
        }
        delete temp;
    }
    void deleteAtEnd(){
        if(head == nullptr){
            cout<<"Empty List\n";
            return;
        }
        if(head->next==head){
            delete head;
            head = nullptr;
            return;
        }
        else{
            Node *curr = head;
            while(curr->next->next != head){
                curr = curr->next;
            }
            Node *temp = curr->next;
            curr->next = head;
            delete temp;
        }
         
    }
    void deleteAtValue(int val){
        if(head == nullptr){
            cout<<"Empty list";
            return;
        }
        Node * curr = head;
        if(head->data == val){
            deleteAtBeginning();
            return;
        }
        else{
            Node *prev = head;
            curr = curr->next;
            while(curr != head && curr->data != val){
                curr = curr->next;
                prev = prev->next;
            }
            if(curr == head){
                cout<<"Element not found in list\n";
                return;
            }
            prev->next = curr->next;
            delete curr;
        }
    }
    void search(int val){
        if(head == nullptr){
            cout<<"Empty list\n";
            return;
        }
        Node *curr = head;
        int pos = 1;
        do{
            if(curr->data == val){
                cout<<"Element present at: "<<pos<<" position\n";
                return;
            }
            curr = curr->next;
            pos++;
        }while(curr!=head);
        cout<<"Element not present in the list\n";
    }
    void display(){
        if(head == nullptr){
            cout<<"Empty List\n";
            return;
        }
        Node *curr = head;
        do{
            cout<<curr->data<<" -> ";
            curr = curr->next;
        }while(curr != head);
        cout<<head->data<<"\n";
    }
    void size(){
        int size = 1;
        if(head == nullptr){
            cout<<"The size of list is zero\n";
            return;
        }
        Node *curr = head;
        while(curr->next != head){
            size+=1;
            curr=curr->next;
        }
        cout<<"Size of the list:    "<<size<<"\n";
    }
};
int main(){
    CircularLL cll;
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
        cout<<"10. Exit\n";
        cout<<"Enter choice:    ";
        cin>>choice;
        switch (choice){
            case 1:
                cout<<"Enter value of node to be inserted: ";
                cin>>val;
                cll.insertAtBeginning(val);
                break;
            case 2:
                cout<<"Enter value of node to be inserted: ";
                cin>>val;
                cll.insertAtEnd(val);
                break;
            case 3:
                cout<<"Enter the value of the node to be entered:   ";
                cin>>val;
                cout<<"Enter the value of the node after which to be entered:   ";
                cin>>ele;
                cll.insertAfterValue(ele,val);
                break;
            case 4:
                cll.deleteAtBeginning();
                break;
            case 5:
                cll.deleteAtEnd();
                break;
            case 6:
                cout<<"Enter the value of the node to be deleted:   ";
                cin>>val;
                cll.deleteAtValue(val);
                break;
            case 7:
                cll.display();
                break;
            case 8:
                cout<<"Enter the value to be searched:  ";
                cin>>val;
                cll.search(val);
                break;
            case 9:
                cll.size();
                break;
            case 10:
                break;
            default:
                cout<<"Invalid option\n";
        }
    }while(choice != 10);
}