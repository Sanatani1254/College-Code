
#include <iostream>
#include <vector>
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
vector<int> sortedValues;

Node* insert(Node* root, int x) {
    if (!root)
        return new Node(x);

    if (x < root->data) {
        if (!root->lthread)
            root->left = insert(root->left, x);
        else {
            Node* temp = new Node(x);
            temp->left = root->left;
            temp->right = root;
            temp->lthread = true;
            temp->rthread = true;
            root->left = temp;
            root->lthread = false;
        }
    }
    else if (x > root->data) {
        if (!root->rthread)
            root->right = insert(root->right, x);
        else {
            Node* temp = new Node(x);
            temp->right = root->right;
            temp->left = root;
            temp->lthread = true;
            temp->rthread = true;
            root->right = temp;
            root->rthread = false;
        }
    }

    return root;
}

void convert(Node* root) {
    if (!root) return;

    if (!root->lthread)
        convert(root->left);

    if (!root->left) {
        root->left = prevNode;
        root->lthread = true;
    }

    if (prevNode && !prevNode->right) {
        prevNode->right = root;
        prevNode->rthread = true;
    }

    prevNode = root;

    if (!root->rthread)
        convert(root->right);
}

Node* first(Node* root) {
    if (!root) return nullptr;

    while (!root->lthread)
        root = root->left;

    return root;
}

Node* search(Node* root, int x) {
    while (root) {
        if (x == root->data)
            return root;

        if (x < root->data) {
            if (root->lthread) return nullptr;
            root = root->left;
        }
        else {
            if (root->rthread) return nullptr;
            root = root->right;
        }
    }

    return nullptr;
}

Node* successor(Node* p) {
    if (!p) return nullptr;

    if (p->rthread)
        return p->right;

    return first(p->right);
}

Node* predecessor(Node* p) {
    if (!p) return nullptr;

    if (p->lthread)
        return p->left;

    p = p->left;

    while (!p->rthread)
        p = p->right;

    return p;
}

void rangeQuery(Node* root, int L, int R) {
    Node* curr = nullptr;

    while (root) {
        if (root->data >= L) {
            curr = root;
            if (root->lthread) break;
            root = root->left;
        }
        else {
            if (root->rthread) {
                root = nullptr;
                break;
            }
            root = root->right;
        }
    }

    while (curr && curr->data <= R) {
        cout << curr->data << " ";
        curr = successor(curr);
    }
}

void inorder(Node* root) {
    Node* curr = first(root);

    while (curr) {
        sortedValues.push_back(curr->data);
        curr = successor(curr);
    }
}

int main() {
    Node* root = nullptr;

    int a[] = {40, 20, 60, 10, 30, 50, 70};

    for (int x : a)
        root = insert(root, x);

    convert(root);

    if (prevNode) {
        prevNode->right = nullptr;
        prevNode->rthread = true;
    }

    inorder(root);

    int choice, x, L, R, k;

    cout << "1.NEXT 2.PREV 3.RANGE 4.KTH 5.EXIT\n";

    while (true) {
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cin >> x;
            Node* p = successor(search(root, x));
            if (p) cout << p->data;
            else cout << "NULL";
        }
        else if (choice == 2) {
            cin >> x;
            Node* p = predecessor(search(root, x));
            if (p) cout << p->data;
            else cout << "NULL";
        }
        else if (choice == 3) {
            cin >> L >> R;
            rangeQuery(root, L, R);
        }
        else if (choice == 4) {
            cin >> k;
            if (k < 1 || k > sortedValues.size())
                cout << "NULL";
            else
                cout << sortedValues[k - 1];
        }
        else if (choice == 5) {
            break;
        }
    }

    cout<<endl;

    return 0;
}
