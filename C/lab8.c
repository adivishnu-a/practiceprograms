#include <stdio.h>  
#include <stdlib.h>
//LAB 8 - By Adi Vishnu Avula

//Struct containing integer item data and self referenceing pointers *left and *right
struct node{  
    int data;  
    struct node *left,*right;
};

struct node *root= NULL;   //Declaring root node

struct node* create(int data)
{  
    struct node *newNode = (struct node*)malloc(sizeof(struct node)); 
    newNode->data= data;  //storing the data item
    newNode->left=newNode->right=NULL;  //setting the left and right fields to point to NULL
    return newNode;     //returning the address pointing to newly created node
}

void inorder(struct node *node);    //function prototype
void insert(int data);              //function prototype

struct node* minimum(struct node *root)   //function to find the minimum element
{  
    if (root->left != NULL)  
        return minimum(root->left);  
    else   
        return root;
}   

struct node* deleteNode(struct node *node,int num) 
{  
    if(node == NULL)
    {  
          return NULL;
    }  
    else 
    {
        if(num < node->data)  //if the number is less than current node element
            node->left = deleteNode(node->left, num); //traversing the left subtree 
          
        else if(num > node->data)  //if the number is greater than current node element
            node->right = deleteNode(node->right, num);  //traversing the right subtree 
          
        else 
        {  
           
            if(node->left == NULL && node->right == NULL)  //if the current node has no children
                node = NULL;  //setting that node to NULL
            else if(node->left == NULL) //if it has no left child
            {  
                node = node->right; //replace it with it's right child  
            }  
              
            else if(node->right == NULL) //if it has no right child
            {  
                node = node->left; //replace it with it's left child 
            }  
            else 
            { 
                struct node *temp = minimum(node->right);  //getting minimum node of right subtree
                node->data = temp->data;  
                //exchanging the data and deleting the duplicate
                node->right = deleteNode(node->right, temp->data);  
            }  
        }  
        return node;  
    }  
}  
        
int main()  
{  
    int ch=0;
    while(ch!=4)
    {
        printf("\n1. Insert a Node");
        printf("\n2. Delete a Node");
        printf("\n3. Inorder Traversal");
        printf("\n4. Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        if(ch==1)
        {
            int num;
            printf("\nEnter the number to be inserted : ");
            scanf("%d",&num);
            insert(num);
        }
        else if(ch==2)
        {   int num;
            printf("\nEnter the number to be deleted : ");
            scanf("%d",&num);
            root=deleteNode(root,num);
        }
        else if(ch==3)
        {
            printf("Inorder traversal:\t");
            inorder(root);
            printf("\n");
        }
        else if(ch=4)
        {
            exit(0);
        }
        else
        {
            printf("\nWrong choice!!Please enter correct choice");
        }
    }
    return 0;  
}

void inorder(struct node *node) //function to perform inorder traversal
{  
    if(root == NULL)
    {  
        printf("\nTree is empty");  
        return;  
     }  
    else 
    {  
        if(node->left!= NULL) 
            inorder(node->left);  
        printf("%d\t", node->data);  
        if(node->right!= NULL)  
          inorder(node->right); 
    }        
}  

void insert(int data) //function to insert a node
{  
    struct node *newNode = create(data);  
    if(root == NULL)
    {
        //if tree is empty, create a new node
        root = newNode;  
        return;  
    }  
    else
    {
        struct node *current = root;  
        while(1) 
        {  
            if(data < current->data) //if insertion data is less than current data
            {  
                if(current->left== NULL) //if the left child is NULL
                {  
                    current->left = newNode;  //inserting the new node
                    return;  
                }  
                current = current->left; 
            }  
            else    //if insertion data is NOT less than current data
            {  
                if(current->right == NULL) //if the right child is NULL
                {  
                    current->right = newNode;  //inserting the new node
                    return;  
                } 
                current = current->right; 
            }  
        }  
    }  
}  