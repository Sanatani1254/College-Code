#include <iostream>
#include <queue>
using namespace std;

struct Node 
{
    int data;
    Node *left, *right;
    Node(int val) : data(val),left(NULL),right(NULL) {}
};

void dis(Node* root,int hd,int &minhd,int &maxhd) 
{
    if (!root) return;
    if (hd<minhd) minhd = hd;
    if (hd>maxhd) maxhd = hd;
    dis(root->left,hd - 1,minhd,maxhd);
    dis(root->right,hd + 1,minhd,maxhd);
}

void topView(Node* root) {
    if (!root) return;

    int minhd = 0, maxhd = 0;
    dis(root,0,minhd,maxhd);

    int width = maxhd - minhd + 1;
    int* val = new int[width];
    bool* filled = new bool[width];
    for (int i = 0; i < width; i++) 
    {
        filled[i] = false;
    }

    queue<Node*> nodeQ;
    queue<int> hdQ;
    nodeQ.push(root);
    hdQ.push(0);

    while (!nodeQ.empty()) {
        Node* node = nodeQ.front(); 
        nodeQ.pop();
        int hd = hdQ.front();       
        hdQ.pop();

        int idx = hd - minhd;       
        if (!filled[idx]) 
        {         
            filled[idx] = true;
            val[idx] = node->data;
        }

        if (node->left)  
        {
            nodeQ.push(node->left);  
            hdQ.push(hd - 1); 
        }
        if (node->right) 
        { 
            nodeQ.push(node->right); 
            hdQ.push(hd + 1); 
        }
    }

    for (int i = 0;i<width;i++)
    {
        cout << val[i] << " ";
    
    }
    cout << endl;

    delete[] val;
    delete[] filled;
}

int main() 
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    topView(root);
    return 0;
}