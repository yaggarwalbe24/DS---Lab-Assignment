#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};
class LinkedList{
    Node* head;
    public:
    LinkedList(){
        head = nullptr;
    }
    void insertAtBeginning(int val){
    Node *newNode = new Node(val);
    newNode -> next = head;
    head = newNode;
    }
    void insertAtEnd(int val){
        Node *newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
        }
        else{
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void insertAfterValue(int val,int value){
        Node *newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
        }
        else{
            Node *temp = head;
            while(temp != nullptr && temp->data != value){
                temp = temp->next;
            }
            if(temp == nullptr){
                cout<<"Element not found \n";
            }
            else{
                newNode->next = temp -> next;
                temp -> next = newNode;
            }
        }
    }
    void deleteFromBeginning(){
        if(head == nullptr){
            cout<<"Cannot delete as a linked list is empty\n";
        }
        else{
            Node*temp = head;
            head = head->next;
            delete temp;
        }
    }
    void deleteFromEnd(){
        if(head == nullptr){
            cout<<"Cannot delete as a linked list is empty\n";
        }
        else if(head->next == nullptr){
            Node*temp = head;
            head = nullptr;
            delete temp;
        }
        else{
            Node *prev = head;
            Node *after = head->next;
            while(after->next != nullptr){
                prev = prev->next;
                after = after->next;
            }
            prev->next = nullptr;
            delete after;
        }
    }
    void deleteElement(int val){
        if(head==nullptr){
            cout<<"Cannot delete as linked list is empty\n";
        }        
        else if(head->data == val){
            deleteFromBeginning();
        }
        else{
            Node *prev = head;
            Node *after = head->next;
            while(after != nullptr && after->data != val){
                prev = prev->next;
                after = after->next;
            }
            if(after == nullptr){
                cout<<"Element not found in the linked list\n";
            }
            else{
                prev->next = after->next;
                delete after;
            }
        }
    }
    void search(int val){
        Node *temp = head;
        int count = 0;
        while(temp!= nullptr){
            if(temp->data == val){
                cout<<"The element was found at "<<count<<" position from the head\n";
                break;
            }
            temp = temp->next;
            count += 1; 
        }
        if(temp == nullptr){
            cout<<"The element is not present in the linked list\n";
        }
    }
    void display(){
        Node * temp = head;
        while(temp != nullptr){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"nullptr"<<"\n";
    }
    void count(int val){
        Node *temp = head;
        int count = 0;
        while(temp!= nullptr){
            if(temp->data == val){
                count += 1;
            }
            temp = temp->next;
        }
        cout<<"The element "<<val<<" occurs "<<count<<" times.\n";
        for(int i=0;i<count;i++){
            deleteElement(val);
        }
    }
    void middle(){
        Node *slow = head;
        Node *fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        cout<<"The middle element is:   "<<slow->data<<"\n"; 
    }
    void reverse(){
        Node *prev = nullptr;
        Node *temp = head;
        Node *next = nullptr;
        while(temp != nullptr){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        head = prev;
    }
};
int main(){
    LinkedList myList;
    int option = 0;
    cout<<"1. Insertion at the beginning\n";
    cout<<"2. Insertion at the end\n";
    cout<<"3. Insertion after a specific value\n";
    cout<<"4. Delete from the beginning\n";
    cout<<"5. Delete from the end\n";
    cout<<"6. Delete a specific node\n";
    cout<<"7. Search for a node\n";
    cout<<"8. Display all nodes\n";
    cout<<"9. Count occurences of an element and then delete all occurences\n";
    cout<<"10. Find the middle element of the list\n";
    cout<<"11. Reverse the list\n";
    cout<<"12. Exit\n";
    while(option != 12){
        cout<<"Please choose an option: ";
        cin>>option;
        if(option == 1){
            int value;
            cout<<"Please enter value of node to be entered: ";
            cin>>value;
            myList.insertAtBeginning(value);
        }
        else if(option == 2){
            int value;
            cout<<"Please enter value of node to be entered: ";
            cin>>value;
            myList.insertAtEnd(value);
        }
        else if(option == 3){
            int value,element;
            cout<<"Please enter value of node to be entered: ";
            cin>>value;
            cout<<"Please enter element after which node has to be entered: ";
            cin>>element;
            myList.insertAfterValue(value,element);
        }
        else if(option == 4) myList.deleteFromBeginning();
        else if(option == 5) myList.deleteFromEnd();
        else if(option == 6){
            int value;
            cout<<"Please enter value of node to be deleted: ";
            cin>>value;
            myList.deleteElement(value);
        }
        else if(option == 7){
            int value;
            cout<<"Please enter value of node to be searched: ";
            cin>>value;
            myList.search(value);
        }
        else if(option == 8) myList.display();
        else if(option == 9){
            int value;
            cout<<"Enter the element to be counted and deleted: ";
            cin>>value;
            myList.count(value);
        }
        else if(option == 10) myList.middle();
        else if(option == 11) myList.reverse();
    }
}