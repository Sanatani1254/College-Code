#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int x) {
    if (!root)
        return new Node(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

void inorder(Node* root, vector<int>& v) {
    if (!root) return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
    Node* root = nullptr;

    int a[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for (int x : a)
        root = insert(root, x);

    vector<int> v;
    inorder(root, v);

    int queries[] = {1, 3, 5, 8};

    for (int k : queries) {
        if (k < 1 || k > v.size())
            cout << "Invalid ";
        else
            cout << v[k - 1] << " ";
    }

    cout<<endl;

    return 0;
}
