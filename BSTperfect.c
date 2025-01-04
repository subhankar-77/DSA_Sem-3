#include <stdio.h>
#include <stdlib.h>

typedef struct Leaf {
    int data;
    struct Leaf *left;
    struct Leaf *right;
} Leaf;

Leaf *root = NULL;

Leaf *Theleafcreator(int dat) 
{
    Leaf *L = (Leaf *)malloc(sizeof(Leaf));
    if (L == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    L->data = dat;
    L->left = NULL;
    L->right = NULL;
    return L;
}


Leaf *MinValueNode(Leaf *node) 
{
    Leaf *current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}


Leaf *Delete(Leaf *root, int key) 
{
    if (root == NULL) {
        return root;
    }
    if (key < root->data) {
        root->left = Delete(root->left, key);
    } else if (key > root->data) {
        root->right = Delete(root->right, key);
    } else {
        if (root->left == NULL && root->right == NULL) 
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL) 
        {
            Leaf *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL) 
        {
            Leaf *temp = root;
            root = root->left;
            free(temp);
        }
        else 
        {
            Leaf *temp = MinValueNode(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
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

Leaf *Search(Leaf *root, int key, Leaf **parent) 
{
    Leaf *current = root;
    while (current != NULL && current->data != key)
    {
        *parent = current;
        if (key < current->data) 
        {
            current = current->left;
        }
        else 
        {
            current = current->right;
        }
    }
    return current;
}

void FreeTree(Leaf *root) 
{
    if (root == NULL) 
    {
        return;
    }
    FreeTree(root->left);
    FreeTree(root->right);
    free(root);
}

int main() 
{
    int ch, a ;
    do{
        printf ("Enter your choice 0 to insert 1 to delete 3 to display 4 to search");
        scanf ("%d", &ch);
        switch (ch)
        {
            case 0: 
            printf ("Enter element to be inserted ");
            scanf ("%d", &a);
            root = Insert (a, root);
            break;
            case 1:
            printf ("Enter element to be deleted ");
            scanf ("%d", &a);
            root = Delete (root, a);
            break;
            case 3:
            Inorderdisplay (root);
            printf ("\n");
            break;
            case 4:
            printf ("Enter element to be searched ");
            scanf ("%d", &a);
            Leaf *parent = NULL;
            Leaf * L =  Search(root, a, &parent);
            if (L != NULL) 
            {
                printf("Element found %d with address %p\n", L->data, (void*)L);
                if (parent != NULL)
                {
                    printf ("Parent of searched element is has data %d with address %p\n", parent->data, (void*)parent);
                }
                else 
                {
                    printf ("This node is origin root \n");
                }
            } 
            else 
            {
                printf("Element not found\n");
            }
            break;
            default :
            ch = -9;
        }
    }while (ch != -9);
    FreeTree(root);
    return 0;
}
