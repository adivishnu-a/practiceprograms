//Program to convert Infix to Postfix
//By Adi Vishnu Avula - AP21110010186
#include<stdio.h>   //header files
#include<ctype.h>
//Global Variable declaration
char *in;   //Pointer variable to store location of infix expression
char stack[100];    //declaring stack as an array
int t = -1;     //Variable to get the top item in stack

//User defined functions prototypes
void push(char ch);
char pop();
int prec(char ch);
int InToPost();

int main()  //main() function - program execution starts here
{
    char input[100];    //Declaring a string to store the infix expression
    printf("Enter the Infix Expression : ");
    scanf("%s",input);  //Inputting the infix String
    in=input;   //Storing the address of infix string
    InToPost(); //Function call
    return 0;   //Successful execution of program
}

void push(char ch)  //User-defined function - push function
{
    //used to push items into the stack
    t++;    //post-incrementing the value of t
    stack[t]=ch;    //adding character ch to top of stack
}

char pop()  //user-defined function - pop function
{
    //used to get items out of stack
    if(t == -1)
    {
        return (-1);
    }
    else
    {
        return (stack[t--]);
        //element is popped out and t is decremented
    }
}

int prec(char ch)   //user-defined function to check precedence
{  
    //checking precedence of operators
    if(ch == '(' || ch == '[' || ch == '{')
    return 0;
    if(ch == '+' || ch == '-')
    return 1;
    if(ch == '*' || ch == '/')
    return 2;
    if(ch == '^')
    return 3;

    return 0;
}

int InToPost()  //user-defined function - InToPost
{
    //used to convert Infix to Postfix
    char ch;    //declaring character variable ch
    while(*in != '\0')
    {
        if(isalnum(*in))    
        {
            //if the character is alphabet or numeric
            printf("%c ",*in);  //print the character
        }
        else if(*in == '(')
        {
            //if the character is an opening bracket
            push(*in);  //push the character into stack
        }
        else if(*in == ')')
        {
            //if the character is a closing bracket
            while ((ch = pop()) != '(')
            {   
                //pop the elements from stack until opening bracket
                printf("%c ",ch);   //print the character
            }
        }
        else if(*in == '[')
        {   
            //if the character is an opening square bracket
            push(*in);  //push the character into stack
        }
        else if(*in == ']')
        {
            //if the character is a closing square bracket
            while ((ch = pop()) != '[')
            {
                //pop the elements from stack until opening square bracket
                printf("%c ",ch);   //print the character
            }
        }
        else if(*in == '{')
        {
            //if the character is an opening curly bracket
            push(*in);  //push the character into stack
        }
        else if(*in == '}')
        {
            //if the character is a closing curly bracket
            while ((ch = pop()) != '{')
            {
                //pop the elements from stack until opening curly bracket
                printf("%c ",ch);   //print the character
            }
        }
        else
        {
            while(prec(stack[t]) >= prec(*in))
            {
            /*While the precedence order of top operand in stack is greater than 
                precedence order of the operator found in the infix string*/
                printf("%c ",pop());    //popping the top operator and printing
            }
            push(*in);  //then pusing lower precedence operator into stack
        }
        in++;   //moving to the next subsequent location
    }
    while(t != -1)
    {
        printf("%c ",pop());    //popping elements from stack
    }
}