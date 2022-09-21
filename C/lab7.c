#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Program to demonstrate the searching in a binary tree
//By Adi Vishnu Avula - AP21110010186

int found=-1;   //Global variable

struct node     
{
    char input[20];     //String to store the name
    struct node *left;
    struct node *right;
};

struct node *create(char input[30])     //function to create the nodes
{
    struct node *name;
    name=(struct node*)malloc(sizeof(struct node));
    strcpy(name->input,input);
    name->left=NULL;
    name->right=NULL;
    return (name);
}

void preorder_traversal(struct node *root)    //To print in pre-order traversal
{
    if(root==NULL)  //if root is NULL
    return; //exit the function
    printf("%s\n",root->input);     //printing the root
    preorder_traversal(root->left); //traversing left subtree using recursion
    preorder_traversal(root->right); //traversing right subtree using recursion
}

int search(struct node *root,char term[30])     //Function to search the name
{
    if(root==NULL)  //if the root node is NULL
    {
        printf("\nEmpty Tree");     //Displaying "Empty Tree"
    }
    else    //if the root node is not NULL
    {
        if(strcasecmp(term,root->input)==0) //if current node matches search term
        {
            found=0;  
            return(found);
        }
    }
    if(found!=0 && root->left!=NULL)    //if the left subtree is not NULL 
    {
        search(root->left,term);        //searching left subtree using recursion
    }
    
    if(found!=0 && root->right!=NULL)   //if the right subtree is not NULL
    {
        search(root->right,term);       //searching right subtree using recursion
    }
}

int main()
{
    char term[20];     //To store the search term
    int k=1;    //to control the while loop
    struct node *root=create("sonam");  //creating the root node
    root->left=create("rahul");         //left child of root node
    root->right=create("rohit");        //right child of root node
    root->left->left=create("ajay");    //left grand-child of root node 
    root->left->right=create("amit");   //right grand-child of root node
    root->right->left=create("ashiya");
    root->right->right=create("heena");
    root->left->left->left=create("riya");
    root->left->left->right=create("naina");
    root->left->right->left=create("zovi");
    root->left->right->right=create("aru");
    root->right->left->left=create("virat");
    root->right->left->right=create("navya");
    root->right->right->left=create("yogesh");
    root->right->right->right=create("suresh");
    printf("Printing tree preorder traversal:\n");
    preorder_traversal(root);
    printf("\nEnter the name to be searched : ");
    scanf("%s",term);   //inputting the search term
    while(k<16) //loop executes for 15 times
    {
       search(root,term);
       if(found==0) //If name is found
       {
           printf("\nYes, name is present", term);
           exit(0); //exiting the program
       }
       k++; //incrementing k
    }   
    printf("\nName is not present", term);  //if name is not found
}