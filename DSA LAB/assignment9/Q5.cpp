#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node 
{
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) 
{
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

int countNodes(struct Node* root) 
{
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void writeNodes(struct Node* root, char **out) 
{
    if (!root) {
        *(*out)++ = '#';
        *(*out)++ = ',';
        return;
    }
    *out += sprintf(*out, "%d,", root->data);
    writeNodes(root->left, out);
    writeNodes(root->right, out);
}

char* serialize(struct Node* root) 
{
    int n = countNodes(root);
    char *buf = (char *)malloc(14 * n + 3);
    char *p = buf;
    writeNodes(root, &p);
    *(p - 1) = '\0';
    return buf;
}

struct Node* build(const char **p) 
{
    if (**p == '\0') return NULL;

    if (**p == '#') {
        (*p)++;
        if (**p == ',') (*p)++;
        return NULL;
    }

    char *end;
    long v = strtol(*p, &end, 10);
    if (end == *p) return NULL;
    *p = end;
    if (**p == ',') (*p)++;

    struct Node* node = newNode((int)v);
    node->left = build(p);
    node->right = build(p);
    return node;
}

struct Node* deserialize(const char *data) 
{
    const char *p = data;
    return build(&p);
}

void inorder(struct Node* root) 
{
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void freeTree(struct Node* root) 
{
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void test(struct Node* root, const char *name) 
{
    char *s = serialize(root);
    struct Node* copy = deserialize(s);
    char *s2 = serialize(copy);

    printf("%s\n  serialized : %s\n  inorder    : ", name, s);
    inorder(copy);
    printf("\n  round trip : %s\n\n", strcmp(s, s2) == 0 ? "match" : "MISMATCH");

    free(s);
    free(s2);
    freeTree(copy);
}

int main() 
{
    struct Node* t1 = newNode(1);
    t1->left = newNode(2);
    t1->right = newNode(3);
    t1->right->left = newNode(4);
    t1->right->right = newNode(5);
    test(t1, "Example tree");
    freeTree(t1);

    test(NULL, "Empty tree");

    struct Node* t3 = newNode(-7);
    t3->right = newNode(12);
    t3->right->left = newNode(-300);
    test(t3, "Negative values / missing children");
    freeTree(t3);

    return 0;
}