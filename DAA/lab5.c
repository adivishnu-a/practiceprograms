#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_NAME 25
#define TABLE_SIZE 10

typedef struct
{
    char name[MAX_NAME];
    int age;
} person;    // Structure name

person *hash_table[TABLE_SIZE]; // Array of pointers to the structure which can access the structure members

void hash_intial_table()        // Assigning all the values of the table to 0
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = 0;
    }
}

void print_table() // Printing the hash table
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i] == NULL) // If no element is found then it prints the ----
        {
            printf("\n\t%i\t----", i);
        }
        else // else it print the hashtable with index and name
        {
            printf("\n\t%i\t%s", i, hash_table[i]->name);
        }
    }
}

int hash(char *name) // Acceppting the string and assigning the hash index
{
    int length = strnlen(name, MAX_NAME); // Calcculating the string length
    int hash_value = 0;                   // Intially we are assigning the hash value to zero so that we can increment for each letter of the string
    for (int i = 0; i < length; i++)
    {
        hash_value += name[i]; // Calculating ASCII Values of each letter and summing up them
    }
    hash_value %= TABLE_SIZE; // On performing this operation it will return the hash table index
    return hash_value;        // Returning hashvalue
}

bool insert(person *p) // Here person is the structure name and p is pointer of the structure
{
    if (p == NULL) // If the input is null then the function will terminate
    {
        return false;
    }
    int index = hash(p->name);     // We are storing the hash value of the string into the index
    if (hash_table[index] != NULL) // If the hashtable index is already occupied then flow jumps to while loop
    {
        while (hash_table[index] != NULL)//If the index has been occupied by some other,the loop executes until we find NULL
        {
            index = (index + 1) % 10;//Here index will be incremented till it is null because its a closed hashing
        }
        hash_table[index] = p;//When the index value is null the string willbe stored at that index
        return true;
    }
    hash_table[index] = p;//if the index is NULL Then it stores directly without any collision
    return true;
}

person *traversing(char *name)//Traversing for the string in the hashtable
{
    int index = hash(name);// We are storing the hash value of the string into the index
    if (hash_table[index] != NULL && strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0)
    {
        return hash_table[index];
    }
    else
    {
        return NULL;
    }
}

int main() // Driver Code
{
    person ram = {.name = "ram", .age = 19};// is the structure variable
    person shyam = {.name = "shyam", .age = 5};// shyam is the structure variable
    person bheem = {.name = "bheem", .age = 55};//bheem is the structure variable
    person tej = {.name = "tej", .age = 12};//tej is the structure variable
    person krishna = {.name = "krishna", .age = 19};//krishna is the structure variable
    person sai = {.name = "sai", .age = 20};//sai is the structure variable
    person raj = {.name = "raj", .age = 21};//raj is the structure variable
    person guna = {.name = "guna", .age = 54};//guna is the structure variable
    hash_intial_table();//Calling the intial function
    insert(&ram);//Insertion of the element to the table and the hashing is done
    insert(&shyam);//Insertion of the element to the table and the hashing is done
    insert(&bheem);//Insertion of the element to the table and the hashing is done
    insert(&tej);//Insertion of the element to the table and the hashing is done
    insert(&krishna);//Insertion of the element to the table and the hashing is done
    insert(&sai);//Insertion of the element to the table and the hashing is done
    insert(&raj);//Insertion of the element to the table and the hashing is done
    insert(&guna);//Insertion of the element to the table and the hashing is done
    print_table();//Printing the final table
    return 0;
}