#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
class BinaryTree {
private:
    Node* root;
    Node* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd, int& preIndex) {
        if (inStart > inEnd){
            return nullptr;
        }
        Node* node = new Node(preorder[preIndex++]);
        if (inStart == inEnd)
            return node;
        int inIndex = find(inorder.begin() + inStart, inorder.begin() + inEnd + 1, node->data) - inorder.begin();
        node->left = buildTreeHelper(preorder, inorder, inStart, inIndex - 1, preIndex);
        node->right = buildTreeHelper(preorder, inorder, inIndex + 1, inEnd, preIndex);
        return node;
    }
    void printInorderHelper(Node* node) {
        if (!node) return;
        printInorderHelper(node->left);
        cout << node->data << " ";
        printInorderHelper(node->right);
    }
    void printPreorderHelper(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        printPreorderHelper(node->left);
        printPreorderHelper(node->right);
    }
public:
    BinaryTree() {
        root = nullptr;
    }
    void buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        root = buildTreeHelper(preorder, inorder, 0, inorder.size() - 1, preIndex);
    }
    void printInorder() {
        printInorderHelper(root);
        cout << endl;
    }
    void printPreorder() {
        printPreorderHelper(root);
        cout << endl;
    }
};

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    BinaryTree tree;
    tree.buildTree(preorder, inorder);
    cout << "Inorder Traversal of Constructed Tree: ";
    tree.printInorder();
    cout << "Preorder Traversal of Constructed Tree: ";
    tree.printPreorder();
    return 0;
}
