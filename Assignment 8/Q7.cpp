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
    Node* buildFromInPostHelper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int& postIndex) {
        if (inStart > inEnd)
            return nullptr;
        Node* node = new Node(postorder[postIndex--]);
        if (inStart == inEnd)
            return node;
        int inIndex = find(inorder.begin() + inStart, inorder.begin() + inEnd + 1, node->data) - inorder.begin();
        node->right = buildFromInPostHelper(inorder, postorder, inIndex + 1, inEnd, postIndex);
        node->left = buildFromInPostHelper(inorder, postorder, inStart, inIndex - 1, postIndex);
        return node;
    }
    void printInorderHelper(Node* node) {
        if (!node) return;
        printInorderHelper(node->left);
        cout << node->data << " ";
        printInorderHelper(node->right);
    }
    void printPostorderHelper(Node* node) {
        if (!node) return;
        printPostorderHelper(node->left);
        printPostorderHelper(node->right);
        cout << node->data << " ";
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
    void buildTreeFromInPost(vector<int>& inorder, vector<int>& postorder) {
        int postIndex = postorder.size() - 1;
        root = buildFromInPostHelper(inorder, postorder, 0, inorder.size() - 1, postIndex);
    }
    void printInorder() {
        printInorderHelper(root);
        cout << endl;
    }
    void printPostorder() {
        printPostorderHelper(root);
        cout << endl;
    }
    void printPreorder() {
        printPreorderHelper(root);
        cout << endl;
    }
};

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    BinaryTree tree;
    tree.buildTreeFromInPost(inorder, postorder);
    cout << "Inorder Traversal of Constructed Tree: ";
    tree.printInorder();
    cout << "Postorder Traversal of Constructed Tree: ";
    tree.printPostorder();
    cout << "Preorder Traversal of Constructed Tree: ";
    tree.printPreorder();
    return 0;
}
