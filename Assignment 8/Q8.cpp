#include <iostream>
#include <list>
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
class BSTMerger {
private:
    Node* root;
    void storeInorder(Node* node, list<int>& l) {
        if (!node) return;
        storeInorder(node->left, l);
        l.push_back(node->data);
        storeInorder(node->right, l);
    }
    list<int> mergeLists(list<int>& a, list<int>& b) {
        list<int> result;
        auto i = a.begin(), j = b.begin();
        while (i != a.end() && j != b.end()) {
            if (*i < *j)
                result.push_back(*i++);
            else
                result.push_back(*j++);
        }
        while (i != a.end()) result.push_back(*i++);
        while (j != b.end()) result.push_back(*j++);
        return result;
    }
    Node* sortedListToBST(list<int>& l, list<int>::iterator& it, int n) {
        if (n <= 0) return nullptr;
        Node* left = sortedListToBST(l, it, n / 2);
        Node* node = new Node(*it);
        ++it;
        node->left = left;
        node->right = sortedListToBST(l, it, n - n / 2 - 1);
        return node;
    }
public:
    BSTMerger() {
        root = nullptr;
    }
    Node* merge(Node* root1, Node* root2) {
        list<int> list1, list2;
        storeInorder(root1, list1);
        storeInorder(root2, list2);
        list<int> merged = mergeLists(list1, list2);
        auto it = merged.begin();
        root = sortedListToBST(merged, it, merged.size());
        return root;
    }
    void printInorder(Node* node) {
        if (!node) return;
        printInorder(node->left);
        cout << node->data << " ";
        printInorder(node->right);
    }
};

int main() {
    Node* root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);
    Node* root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);
    BSTMerger merger;
    Node* mergedRoot = merger.merge(root1, root2);
    cout << "Inorder Traversal of Merged Balanced BST: ";
    merger.printInorder(mergedRoot);
    cout << endl;
    return 0;
}
