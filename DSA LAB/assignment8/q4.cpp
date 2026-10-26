#include <iostream>
#include <vector>
using namespace std;

struct node 
{
    int val;
    node *left, *right;
    node(int k) :val(k),left(nullptr),right(nullptr) {}
};

node* insert(node* root, int val) {
    if (root == nullptr) 
    {
        return new node(val);
    }
    if (val<root->val) 
    {
        root->left  = insert(root->left, val);
    }
    else                 
    {
        root->right = insert(root->right, val);
    }
    return root;
}

void inorder(node* root,vector<int>& a,int& i) 
{
    if (root == nullptr) return;
    inorder(root->left,a,i);
    a[i] = root->val;
    i++;
    inorder(root->right, a, i);
}

void deltree(node* root) 
{
    if (root == nullptr) return;
    deltree(root->left);
    deltree(root->right);
    delete root;
}

void sort(vector<int>& a) 
{
    node* root = nullptr;
    for (int x :a) root = insert(root,x);

    int i = 0;
    inorder(root,a,i);
    deltree(root);
}

int main() 
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }

    sort(a);

    cout << "Sorted: ";
    for (int x : a) 
    {
        cout << x << " ";
    }
    cout << endl;

}