#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node 
{
    char data[20];  //string to store the data
    struct node *left;  //left sub-node
    struct node *right; //right sub-node
};

struct node* newnode(char *data) 
{
    //used to create a new node
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    strcpy(newnode->data, data);
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int calculate(struct node *root)
{
    //Used to evaluate the expression
    if (root == NULL)   //if the tree is empty
        return 0;
    if(root->left == NULL && root->right == NULL)
        return atoi(root->data);//converts character to an integer
    int leftitem = calculate(root->left);
    int rightitem = calculate(root->right);
    //Checking for operators
    if(root->data[0] == '+')//if '+' operator is present
        return ((leftitem) + (rightitem));//perform addition 
    else if(root->data[0] == '-')//if '-' operator is present
        return ((leftitem) - (rightitem));//perform subtraction
    else if(root->data[0] == '*')//if '*' operator is present
        return ((leftitem) * (rightitem));//perform multiplication 
    else if(root->data[0] == '/')//if '/' operator is present
        return ((leftitem) / (rightitem));//perform division
    else
        printf("\n The expression cannot be evaluted"); //If invalid entries are present

}

void display(char exp[20], struct node *root)
{
    //used to display the evaluated result
    int res = calculate(root);
    printf("\n %s = %d\n",exp, res); 
}

int main()
{
    //Storing the given expressions
    char exp1[20] = "3+((5+9)*2)";
    char exp2[20] = "(5*4)+(100-20)";
    char exp3[20] = "(5*4)+(100-(20/2))";
    
    //creating first expression tree
    struct node* root1 = newnode("+");
    root1->left = newnode("3");
    root1->right = newnode("*");
    root1->right->left = newnode("+");
    root1->right->right = newnode("2");
    root1->right->left->left = newnode("5");
    root1->right->left->right = newnode("9");

    //creating second expression tree
    struct node* root2 = newnode("+");
    root2->left = newnode("*");
    root2->right = newnode("-");
    root2->left->left = newnode("5");
    root2->left->right = newnode("4");
    root2->right->left = newnode("100");
    root2->right->right = newnode("20");

    //creating third expression tree
    struct node* root3 = newnode("+");
    root3->left = newnode("*");
    root3->right = newnode("-");
    root3->left->left = newnode("5");
    root3->left->right = newnode("4");
    root3->right->left = newnode("100");
    root3->right->right = newnode("/");
    root3->right->right->left = newnode("20");
    root3->right->right->right = newnode("2");

    //Displaying the evaluated outputs
    printf("\n Result of evaluation of expression 1 :");
    display(exp1, root1);
    printf("\n Result of evaluation of expression 2 :");
    display(exp2, root2);
    printf("\n Result of evaluation of expression 3 :");
    display(exp3, root3);
    return 0;
}