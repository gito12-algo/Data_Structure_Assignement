#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left, *right;
    int thread;
};
struct Node* newNode(int x)
{
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    p->data = x;
    p->left = p->right = NULL;
    p->thread = 0;
    return p;
}
struct Node* leftMost(struct Node *p)
{
    while (p && p->left)
        p = p->left;
    return p;
}
void inorder(struct Node *root)
{
    struct Node *cur = leftMost(root);
    while (cur)
    {
        printf("%d ", cur->data);
        if (cur->thread)
            cur = cur->right;
        else
            cur = leftMost(cur->right);
    }
}
int main()
{
    struct Node *root = newNode(20);
    root->left = newNode(10);
    root->right = newNode(30);
    root->left->left = newNode(5);
    root->left->right = newNode(15);
    root->left->left->right = root->left;
    root->left->left->thread = 1;
    root->left->right->right = root;
    root->left->right->thread = 1;
    printf("Inorder: ");
    inorder(root);
    return 0;
}
