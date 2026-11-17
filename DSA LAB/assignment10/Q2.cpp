
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    bool lthread, rthread;

    Node(int x) {
        data = x;
        left = right = nullptr;
        lthread = rthread = false;
    }
};

Node* prevNode = nullptr;

void convert(Node* root) {
    if (!root) return;

    if (!root->lthread)
        convert(root->left);

    if (root->left == nullptr) {
        root->left = prevNode;
        root->lthread = true;
    }

    if (prevNode && prevNode->right == nullptr) {
        prevNode->right = root;
        prevNode->rthread = true;
    }

    prevNode = root;

    if (!root->rthread)
        convert(root->right);
}

void inorder(Node* root) {
    if (!root) return;

    Node* curr = root;

    while (!curr->lthread && curr->left)
        curr = curr->left;

    while (curr) {
        cout << curr->data << " ";

        if (curr->rthread)
            curr = curr->right;
        else {
            curr = curr->right;

            while (curr && !curr->lthread)
                curr = curr->left;
        }
    }
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(35);

    convert(root);

    if (prevNode) {
        prevNode->right = nullptr;
        prevNode->rthread = true;
    }

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}
