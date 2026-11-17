
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

void buildParent(Node* root, Node* parent,
                 unordered_map<Node*, Node*>& par,
                 Node*& target, int s) {
    if (!root) return;

    par[root] = parent;

    if (root->data == s)
        target = root;

    buildParent(root->left, root, par, target, s);
    buildParent(root->right, root, par, target, s);
}

vector<int> distanceK(Node* root, int s, int k) {
    unordered_map<Node*, Node*> par;
    Node* target = nullptr;

    buildParent(root, nullptr, par, target, s);

    vector<int> ans;
    queue<Node*> q;
    unordered_map<Node*, bool> visited;

    q.push(target);
    visited[target] = true;

    int dist = 0;

    while (!q.empty()) {
        int sz = q.size();

        if (dist == k) {
            while (!q.empty()) {
                ans.push_back(q.front()->data);
                q.pop();
            }
            break;
        }

        while (sz--) {
            Node* curr = q.front();
            q.pop();

            Node* next[] = {
                curr->left,
                curr->right,
                par[curr]
            };

            for (Node* x : next) {
                if (x && !visited[x]) {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }

        dist++;
    }

    return ans;
}

int main() {
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    int s = 5, k = 2;

    vector<int> ans = distanceK(root, s, k);

    cout << "Nodes at distance " << k << ": ";
    for (int x : ans)
        cout << x << " ";

    cout<<endl;
    return 0;
}
