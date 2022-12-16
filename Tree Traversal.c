#include <stdio.h>
 #include <stdlib.h>
 
 
 struct abc
 {
     int data;
     struct abc *left, *right;
 };
 
 struct abc *create(int d)
 {
     struct abc *new;
     new=(struct abc*)malloc(sizeof(struct abc));
     new->data=d;
     new->left=NULL;
     new->right=NULL;
     return new;
 }
 
 struct abc *insert(struct abc *root, int d)
 {
     if(root==NULL)
     {
      return create(d);
     }
     else if(d < root->data)
     {
      root->left=insert(root->left,d);
     }
     else
     {
      root->right=insert(root->right,d);
     }
     return root;
 }
 
 void inorder(struct abc *root)
 {
     if(root==NULL)
     {
         return;
     }
     else{
         
     if(root!=NULL)
      inorder(root->left);
      printf("%d\t",root->data);
      inorder(root->right);
     }
 }
 
 void preorder(struct abc *root)
 {
      if(root==NULL)
     {
         return;
     }
     if(root!=NULL)
     {
         printf("%d\t",root->data);
     }
     preorder(root->left);
     preorder(root->right);
 }
 
 void postorder(struct abc *root)
 {
      if(root==NULL)
     {
         return;
     }
     if(root!=NULL)
     preorder(root->right);
     printf("%d\t",root->data);
 }
 
 int inorderS(struct abc *temp)
 {
    while(temp && temp->left!=NULL)
    {
        return temp->data;
    }
 } 

 struct abc *delete(struct abc *root,d)
 {
    if(root==NULL)
    { 
        return root;
    }
    if(d<root->data)
    {
        root->left=delete(root->left,d);
    }
    else if(d>root->data)
    {
        root->right=delete(root->right,d);
    }
    else
    {
        if(root->left==NULL) //FOR 1 RIGHT CHILD
        {
            struct abc *temp;
            temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL) //FOR 1 LEFT CHILD
        {
             struct abc *temp;
            temp=root->left;
            free(root);
            return temp;
        }
        else //FOR 2 CHILDS
        {
            struct abc *temp;
            temp=root->right;
            root->data=inorderS(temp);
            root->right=delete(temp,root->data);
        }
    }
    return root;
 }
 
 void main()
 {
     struct abc *root=NULL;
     int ch,y,d;
     
     do
     {  
        printf("\n1.Insert  \n2.Inorder \n3.Preorder  \n4.Postorder\n");
        scanf("%d",&ch);
       
        switch(ch)
        {
            case 1: printf("Enter data in the tree:\n");
                    scanf("%d",&d);
                    root = insert(root,d);
                    break;
                   
            case 2: printf("Inorder tree traversal is:\n");
                    inorder(root);
                    break;
                   
            case 3: printf("Preorder tree traversal is:\n");
                    preorder(root);
                    break;
                   
            case 4: printf("Postorder tree traversal is:\n");
                    postorder(root);
                    break;

            case 5: printf("Enter the data to be deleted from the tree:\n");
                    scanf("%d",&d);
                    root = delete(root,d);
                    break;
        }
       
        printf("\nDo you want to continue(0/1)");
        scanf("%d",&y);
         
     }while(y==1);
 }
