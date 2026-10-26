#include <iostream>
#include <vector>
#include <utility>

struct node
{
    int val;
    node *left;
    node *right;
    node(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorder(node *root, std::vector<int> &values)
{
    if (root == nullptr)
        return;
    inorder(root->left, values);
    values.push_back(root->val);
    inorder(root->right, values);
}

std::pair<int, int> kthSmallestAndLargest(node *root, int k)
{
    std::vector<int> values;
    inorder(root, values);
    return {values[k - 1], values[values.size() - k]};
}

int main()
{
    node *root = new node(5);
    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(8);

    int k = 2;
    auto result = kthSmallestAndLargest(root, k);
    std::cout << "kth smallest: " << result.first << "\n";
    std::cout << "kth largest: " << result.second << "\n";

    return 0;
}