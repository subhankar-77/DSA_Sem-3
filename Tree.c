#include <stdio.h>
#include <stdlib.h>

typedef struct Leaf 
{
    int data;
    struct Leaf *left;
    struct Leaf *right;
} Leaf;

Leaf *root = NULL;

Leaf *Theleafcreator(int dat) 
{
    Leaf *L = (Leaf *)malloc(sizeof(Leaf));
    if (L == NULL) 
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    L->data = dat;
    L->left = NULL;
    L->right = NULL;
    return L;
}

Leaf *Insert(int dat, Leaf *originalroot) 
{
    if (originalroot == NULL) 
    {
        return Theleafcreator(dat);
    }
    if (dat < originalroot->data) 
    {
        originalroot->left = Insert(dat, originalroot->left); 
    } 
    else 
    {
        originalroot->right = Insert(dat, originalroot->right); 
    }

    return originalroot;
}


void Inorderdisplay(Leaf *root) 
{
    if (root == NULL) 
    {
        return;
    }

    Inorderdisplay(root->left);
    printf("%d ", root->data); 
    Inorderdisplay(root->right); 
}

int main()
{
    root = Insert(80, root);
    root = Insert(90, root);
    root = Insert(30, root);
    root = Insert(60, root);
    root = Insert(70, root);
    root = Insert(20, root);
    root = Insert(32, root);
    printf("In-order Traversal: ");
    Inorderdisplay(root);
    printf("\n");
    return 0; 
}
