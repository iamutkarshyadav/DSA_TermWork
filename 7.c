
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void inOrder(struct node *root)
{
    if (root == 0)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

struct node *createNode(int x)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    new->left = NULL;
    new->right = NULL;
    return new;
}
void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("cannot delete");
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *n = createNode(key);
    if (key < prev->data)
    {
        prev->left = n;
    }
    else
    {
        prev->right = n;
    }
}
struct node *inOrderPredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct node *deletion(struct node *root, int value)
{
    struct node *iPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if (value < root->data)
    {
        root->left = deletion(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deletion(root->right, value);
    }
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deletion(root->left, iPre->data);
    }
    return root;
}

int maxDepth(struct node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}
int count = 0;
int leafnodes(struct node *root)
{
    if (root != NULL)
    {
        leafnodes(root->left);
        if ((root->left == NULL) && (root->right == NULL))
        {
            count++;
        }
        leafnodes(root->right);
    }
    return count;
}
int totalNodes(struct node *root)
{
    if (root == NULL)
        return 0;
    int r = totalNodes(root->right);
    int l = totalNodes(root->left);

    return 1 + l + r;
}
int searchNode(struct node *root, int value)
{
    while (root != NULL)
    {
        if (value > root->data)
            root = root->right;
        else if (value < root->data)
            root = root->left;
        else
            return 1;
    }
    return 0;
}
int main()
{
    int val;
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    printf("\nInorder traversal of BST is :\n");
    inOrder(p);

    printf("\nEnter a node to be inserted :");
    scanf("%d",&val);
    insert(p, val);
    printf("\nAfter inserting %d the BST is :\n",val);
    inOrder(p);

    int del;
    printf("\nEnter a node to be deleted :");
    scanf("%d",&del);
    deletion(p, del);
    printf("\nAfter deleting %d the BST is :\n");
    inOrder(p);

    int m = maxDepth(p);
    printf("\nThe maximum height of BST is :%d\n",m);

    int leaf = leafnodes(p);
    printf("\nNumber of Leaf Nodes are :%d\n", leaf);
    int total = totalNodes(p);
    printf("\nTotal nodes are :%d\n", total);
    int s;
    printf("Enter a value to be searched :");
    scanf("%d",&s);
    int search = searchNode(p, s);
    if (search)
        printf("\nSearch Successful :%d present\n",s);
    else
        printf("\nSearch Unsuccessful :%d not present\n",s);
    return 0;
}
