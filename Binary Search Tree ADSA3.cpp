//Inorder, Preorder, Postorder Traversal of Binary Search Tree
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

 void inorder(struct node *);
 void preorder(struct node *);
 void postorder(struct node *);
 void clear(struct node *);
  
struct node
{    
     int root;
     struct node *left;
     struct node *right;
     node(int val)
     {
         root=val;
         left=NULL;
         right=NULL;
     }
 };

node *insert(node *root,int val)
{
    if(root==NULL)
    {
        return new node(val);
    }
    else if(val>root->root)
    {
        root->right=insert(root->right,val);
    }
    else
    {
        root->left=insert(root->left,val);
    }
    return root;
}

void inorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->root);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d ",root->root);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->root);
}

void clear(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    clear(root->left);
    clear(root->right);
    delete root;
}

void main()
{
    node *root=NULL;
    int n,val;
    clrscr();
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("Enter the value of node %d: ",i);
        scanf("%d",&val);
        root=insert(root,val);
    }
    printf("\nInorder Traversal: \n");
    inorder(root);
    printf("\nPreorder Traversal: \n");
    preorder(root);
    printf("\nPostorder Traversal: \n");
    postorder(root);
    clear(root);
    getch();
}
