#include <iostream>
#include <stack>
#include <climits>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
class BST{
    public:
    Node *root;
    BST(){
        root = nullptr;
    }
    void PreOrder(Node *temp){
        if(temp != nullptr){
            cout<<temp->data<<" ";
            PreOrder(temp->left);
            PreOrder(temp->right);
        }
    }
    void InOrder(Node *temp){
        if(temp != nullptr){
            InOrder(temp->left);
            cout<<temp->data<<" ";
            InOrder(temp->right);
        }
    }
    void PostOrder(Node *temp){
        if(temp != nullptr){
            PostOrder(temp->left);
            PostOrder(temp->right);
            cout<<temp->data<<" ";
        }
    }
    void PreOrder(){
        PreOrder(root);
    }
    void InOrder(){
        InOrder(root);
    }
    void PostOrder(){
        PostOrder(root);
    }
    Node* search_nonRecursive(int ele){
        Node *temp = root;
        while(temp != nullptr && temp->data != ele){
            if(ele<temp->data){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
        return temp;
    }
    Node* search_recursive(Node *temp,int ele){
        if(temp == nullptr || temp->data == ele){
            return temp;
        }
        if(ele<temp->data){
            return search_recursive(temp->left,ele);
        }
        else{
            return search_recursive(temp->right,ele);
        }
    }
    Node* findMaximum(Node *temp){
        while(temp->right != nullptr){
            temp = temp->right;
        }
        return temp;
    }
    Node* findMinimum(Node *temp){
        while(temp->left != nullptr){
            temp = temp->left;
        }
        return temp;
    }
    Node* successor(Node *temp,Node * target){
        if(target->right != nullptr){
            return findMinimum(target->right);
        }
        Node *succ = nullptr;
        while(true){
            if(target->data<temp->data){
                succ = temp;
                temp = temp->left;
            }
            else if(target->data>temp->data){
                temp = temp->right;
            }
            else{
                break;
            }
        }
        return succ;
    }
    Node* predecessor(Node* temp, Node* target){
        if(target->left != nullptr){
            return findMaximum(target->left);
        }
        Node *prev = nullptr;
        while(true){
            if(target->data>temp->data){
                prev = temp;
                temp = temp->right;
            }
            else if(target->data<temp->data){
                temp = temp->left;
            }
            else{
                break;
            }
        }
        return prev;
    }
    Node* insert(Node *temp, int val){
        if(temp == nullptr){
            return new Node(val);
        }
        if(val<temp->data){
            temp->left = insert(temp->left,val);
        }
        else if(val>temp->data){
            temp->right = insert(temp->right,val);
        }
        return temp;
    }
    Node* deleteNode(Node *temp, int val)
    {
        if (temp == nullptr){
            return temp;
        }
        if (val<temp->data){
            temp->left = deleteNode(temp->left,val);
        }
        else if(val>temp->data){
            temp->right = deleteNode(temp->right,val);
        }
        else{
            if(temp->left == nullptr){
                return temp->right;
            }
            else if(temp->right == nullptr){
                return temp->left;
            }
            Node *curr = findMinimum(temp->right);
            temp->data = curr->data;
            temp->right = deleteNode(temp->right,curr->data);

        }
        return temp;
    }
    int maxDepth(Node *temp){
        if(temp == nullptr){
            return 0;
        }
        int leftDepth = maxDepth(temp->left);
        int rightDepth = maxDepth(temp->right);
        return 1+max(leftDepth,rightDepth);
    }
    int minDepth(Node *temp){
        if(temp == nullptr){
            return 0;
        }
        if(temp->left == nullptr && temp->right == nullptr){
            return 1;
        }
        if(temp->left == nullptr){
            return 1+minDepth(temp->right);
        }
        if(temp->right == nullptr){
            return 1+minDepth(temp->left);
        }
        return 1+min(minDepth(temp->left),minDepth(temp->right));
    }
    bool isBSTUtil(Node* temp, int minVal, int maxVal) {
        if (temp == nullptr){
            return true;
        }
        if (temp->data <= minVal || temp->data >= maxVal){
            return false;
        }
        return isBSTUtil(temp->left, minVal, temp->data) && isBSTUtil(temp->right, temp->data, maxVal);
    }
    bool isBST(Node* root) {
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }
    void inorderNonRecursive(Node* root) {
        stack<Node*> st;
        Node* current = root;
        while (current != nullptr || !st.empty()) {
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }
            current = st.top();
            st.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }


};