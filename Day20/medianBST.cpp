#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// Helper function to perform inorder traversal and store the result in a vector
void inorder(Node* root, vector<int>& temp) {
    if (root == nullptr) return;
    
    inorder(root->left, temp);
    temp.push_back(root->data);
    inorder(root->right, temp);
}

// Function to find the median of the values in the BST
float findMedian(Node *root) {
    vector<int> temp;
    inorder(root, temp);
    
    int n = temp.size();
    
    if (n % 2 == 1) { // Odd number of elements
        return temp[n / 2];
    } else { // Even number of elements
        return (temp[n / 2 - 1] + temp[n / 2]) / 2.0;
    }
}

// Helper function to build a tree for testing
Node* buildTree() {
    cout << "Enter node value (-1 for NULL): ";
    int value;
    cin >> value;

    if (value == -1) {
        return nullptr;
    }

    Node* node = new Node(value);
    cout << "Enter left child of " << value << endl;
    node->left = buildTree();
    cout << "Enter right child of " << value << endl;
    node->right = buildTree();

    return node;
}

int main() {
    Node* root = buildTree();

    float result = findMedian(root);

    cout << "Median of BST: " << result << endl;

    return 0;
}
