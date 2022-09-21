#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct record
{
    char name[30];
    char disease[30];
    char address[50];
    char phone[11];
    char gender;
    int room, age;
} x[100];

struct staffinfo
{
    char name[25];
    char spec[25];
    int exp;
} info[5];

int n, i, j = 0, a = 0, sum = 0, g, flag, num;

int read();
void add();
void view();
void search();
void edit();
void del();
void staff();
void expense();
int write();

int main()
{
    read();
    int c, i, q;
    int m, n;
    char pw[25];
    system("cls");
    printf("==================================================\n");
    printf("----------> Hospital Management System <----------\n");
    printf("==================================================\n");
    printf("\n\tWelcome to Admin Dashboard\n\tEnter your Password : ");
    gets(pw);
    int res=strcmp(pw,"admin");
    while(res != 0)
    {
        system("cls");
        printf("==================================================\n");
        printf("----------> Hospital Management System <----------\n");
        printf("==================================================\n");
        printf("\n\tWrong Password, Try again : ");
        gets(pw);
        res=strcmp(pw,"admin");
    }

    //Successful Login
    system("cls");
    printf("==================================================\n");
    printf("----------> Hospital Management System <----------\n");
    printf("======[ Successfully Entered the main menu ]======\n");
    while (c != 8)
    {

        printf("\n\tEnter your choice \n\n\t1. Add Information\n\t2. View Information\n\t3. Search\n\t4. Edit Information\n\t5. Delete Information\n\t6. Staff Information\n\t7. Expense Calculation\n\t8. Save & Exit\n\n\tOption : ");
        scanf("%d", &c); //choice for option
        fflush(stdin);   //making it clear
        if (c == 1)      //add
        {
            system("cls");
            add();
        }
        else if (c == 2) //view
        {
            system("cls");
            view();
        }
        else if (c == 3) //search
        {
            system("cls");
            search();
        }
        else if (c == 4) //edit
        {
            system("cls");
            edit();
        }
        else if (c == 5) //delete
        {
            system("cls");
            del();
        }
        else if (c == 6) //staff
        {
            system("cls");
            staff();
        }
        else if (c == 7) //expense
        {
            system("cls");
            expense();
        }
        else if (c == 8)
        {
            write();
            printf("\n\tEXITED FROM PROGRAM\n\n");
            return 0;
        }
        else
        {
            system("cls");
            printf("\n\n\tInvalid input , try again by using valid inputs");
        }
        printf("\n\n");
    }
}

void add()
{
    printf("\n\n");
    printf("\tRecords already inputed on the database : %d\n", num); //how many inputs
    printf("\tHow many entries do you want to add : ");
    scanf("%d", &n);
    sum = n + num;
    for (i = num, j = 0; i < sum; i++)
    {
        printf("\n");
        fflush(stdin);
        printf("\tEnter patient's Name : ");
        gets(x[i].name);
        fflush(stdin);
        printf("\tEnter disease : ");
        gets(x[i].disease);
        fflush(stdin);
        printf("\tEnter the age : ");
        scanf("%d", &x[i].age);
        fflush(stdin);
        printf("\tEnter the gender (M/F/N) : ");
        scanf("%c", &x[i].gender);
        fflush(stdin);
        printf("\tEnter patient's Address : ");
        gets(x[i].address);
        fflush(stdin);
        printf("\tEnter Room No. : ");
        scanf("%d", &x[i].room);
        fflush(stdin);
        printf("\tEnter phone number : ");
        gets(x[i].phone);
        fflush(stdin);
        printf("\n");
        j++;
        a++;
        num++;
    }
}

void view()
{
    for (i = 0; i < num; i++)
    {
        printf("\tSerial Number : %d\n", i);
        printf("\tName : ");
        puts(x[i].name);
        printf("\tDisease : ");
        puts(x[i].disease);
        printf("\tRoom no : %d\n\tAge : %d\n\tGender : %c", x[i].room, x[i].age, x[i].gender);
        printf("\n\tPhone No. : ");
        puts(x[i].phone);
        printf("\tPatient Address : ");
        puts(x[i].address);
        printf("---------------------------------------------------------------------------\n");
    }
}

void edit()
{
    int q, p;
    fflush(stdin);
    printf("\tWhat do you want to edit ?\n");
    printf("\tEnter your option\n");
    printf("\t1. Name\n\t2. Disease\n\t3. Age\n\t4. Room No.\n\t5. Phone no.\n\t6. Gender\n\t7. Address\n");
    printf("\tOption : ");
    scanf("%d", &q); //option
    if (q <= 7)
    {
        printf("\tEnter the serial no of that patient (0 - %d) : ", num - 1);
        scanf("%d", &p); //serial number
        if (p < num)
        {
            if (q == 1)
            {
                fflush(stdin);
                printf("\tEnter the new Name : ");
                gets(x[p].name);
            }
            else if (q == 2)
            {
                fflush(stdin);
                printf("\tEnter the new Disease : ");
                gets(x[p].disease);
            }
            else if (q == 3)
            {
                fflush(stdin);
                printf("\tEnter the new Age : ");
                scanf("%d", &x[p].age);
            }

            else if (q == 4)
            {
                fflush(stdin);
                printf("\tEnter the new Room no : ");
                scanf("%d", &x[p].room);
            }

            else if (q == 5)
            {
                fflush(stdin);
                printf("\tEnter the new Phone no : ");
                gets(x[p].phone);
            }
            else if (q == 6)
            {
                fflush(stdin);
                printf("\tEnter the new Gender : ");
                scanf("%c", &x[p].gender);
            }
            else if (q == 7)
            {
                fflush(stdin);
                printf("\tEnter the new Address : ");
                gets(x[p].address);
            }
        }
        else
        {
            printf("\n\n\tInvalid Option \nTry Again !!\n\n");
        }
    }
    else
    {
        printf("\n\n\tInvalid option\nTry Again!!\n\n");
    }
}

void search()
{
    int s, h, f;
    char u[100];
    printf("\tBy what do you want to search ?\n");
    printf("\t1. Serial no.\n\t2. Name\n\t3. Disease\n\t4. Room no.\n\t5. Phone no.\n\t6. Age\n\t7. Gender\n\t8. Address\n\n\tOption : ");
    scanf("%d", &h);
    if (h == 1)
    {
        printf("\tEnter Serial number of the patient : ");
        scanf("%d", &s);
        if (s < num)
        {
            printf("\n");
            printf("\tSerial Number : %d\n", s);
            printf("\tName : ");
            puts(x[s].name);
            printf("\tDisease : ");
            puts(x[s].disease);
            printf("\tRoom no : %d\n\tAge : %d\n\tGender : %c", x[s].room, x[s].age, x[s].gender);
            printf("\n\tPhone No. : ");
            puts(x[s].phone);
            printf("\tAddress : ");
            puts(x[s].address);
            printf("\n\n");
        }
        else
            printf("\n\n\tNot Found\n\n");
    }
    else if (h == 2)
    {
        int f = 0;
        fflush(stdin);
        printf("\tEnter name : ");
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, x[g].name) == 0)
            {
                printf("\n");
                printf("\tSerial Number : %d\n", g);
                printf("\tName : ");
                puts(x[g].name);
                printf("\tDisease : ");
                puts(x[g].disease);
                printf("\tRoom no : %d\n\tAge : %d\n\tGender : %c", x[g].room, x[g].age, x[g].gender);
                printf("\n\tPhone No. : ");
                puts(x[g].phone);
                printf("\tAddress : ");
                puts(x[g].address);
                printf("\n\n");
                f = 1;
            }
        }
        if (f == 0)
            printf("\n\tNot Found\n");
    }
    else if (h == 3)
    {
        int f = 0;
        fflush(stdin);
        printf("\tEnter Disease : ");
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, x[g].disease) == 0)
            {
                printf("\n");
                printf("\tSerial Number : %d\n", g);
                printf("\tName : ");
                puts(x[g].name);
                printf("\tDisease : ");
                puts(x[g].disease);
                printf("\tRoom no : %d\n\tAge : %d\n\tGender : %c", x[g].room, x[g].age, x[g].gender);
                printf("\tPhone No. : ");
                puts(x[g].phone);
                printf("\n\tAddress : ");
                puts(x[g].address);
                printf("\n\n");
                f = 1;
            }
        }
        if (f == 0)
            printf("\n\tNot Found\n");
    }
    else if (h == 4)
    {
        int f = 0;
        printf("\tEnter Room number : ");
        scanf("%d", &f);
        for (g = 0; g < num; g++)
        {
            if (f == x[g].room)
            {
                printf("\n");
                printf("\tSerial Number : %d\n", g);
                printf("\tName : ");
                puts(x[g].name);
                printf("\tDisease : ");
                puts(x[g].disease);
                printf("\tRoom no : %d\n\tAge : %d\n\tGender : %c", x[g].room, x[g].age, x[g].gender);
                printf("\n\tPhone No. : ");
                puts(x[g].phone);
                printf("\tAddress : ");
                puts(x[g].address);
                printf("\n\n");
                f = 1;
            }
        }
        if (f == 0)
            printf("\n\tNot Found\n");
    }
    else if (h == 5)
    {
        int f = 0;
        char u[11];
        printf("\tEnter Phone number : ");
        gets(u);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, x[g].phone)==0)
            {
                printf("\n");
                printf("\tSerial Number : %d\n", g);
                printf("\tName : ");
                puts(x[g].name);
                printf("\tDisease : ");
                puts(x[g].disease);
                printf("\tRoom no : %d\n\tAge : %d\n\tGender : %c", x[g].room, x[g].age, x[g].gender);
                printf("\n\tPhone No. : ");
                puts(x[g].phone);
                printf("\tAddress : ");
                puts(x[g].address);
                printf("\n\n");
                f = 1;
            }
        }
        if (f == 0)
            printf("\tNot Found");
    }
    else if (h == 6)
    {
        int f = 0;
        printf("\tEnter Age : ");
        scanf("%d", &f);
        for (g = 0; g < num; g++)
        {
            if (f == x[g].age)
            {
                printf("\n");
                printf("\tSerial Number : %d\n", g);
                printf("\tName : ");
                puts(x[g].name);
                printf("\tDisease : ");
                puts(x[g].disease);
                printf("\tRoom no : %d\n\tAge : %d\n\tGender : %c", x[g].room, x[g].age, x[g].gender);
                printf("\n\tPhone No. : ");
                puts(x[g].phone);
                printf("\tAddress : ");
                puts(x[g].address);
                printf("\n\n");
                f = 1;
            }
        }
        if (f == 0)
            printf("\tNot Found\n\n");
    }
    else if (h == 7)
    {
        int f = 0;
        char gen;
        printf("\tEnter Gender : ");
        scanf("%c", &gen);
        for (g = 0; g < num; g++)
        {
            if (gen == x[g].gender)
            {
                printf("\n");
                printf("\tSerial Number : %d\n", g);
                printf("\tName : ");
                puts(x[g].name);
                printf("\tDisease : ");
                puts(x[g].disease);
                printf("\tRoom no : %d\n\tAge : %d\n\tGender : %c", x[g].room, x[g].age, x[g].gender);
                printf("\n\tPhone No. : ");
                puts(x[g].phone);
                printf("\tAddress : ");
                puts(x[g].address);
                printf("\n\n");
                f = 1;
            }
        }
        if (f == 0)
            printf("\n\tNot Found\n");
    }
    else if (h == 7)
    {
        int f = 0;
        fflush(stdin);
        printf("\tEnter Address : ");
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, x[g].address) == 0)
            {
                printf("\n");
                printf("\tSerial Number : %d\n", g);
                printf("\tName : ");
                puts(x[g].name);
                printf("\tDisease : ");
                puts(x[g].disease);
                printf("\tRoom no : %d\n\tAge : %d\n\tGender : %c", x[g].room, x[g].age, x[g].gender);
                printf("\n\tPhone No. : ");
                puts(x[g].phone);
                printf("\tAddress : ");
                puts(x[g].address);
                printf("\n\n");
                f = 1;
            }
        }
        if (f == 0)
            printf("\n\tNot Found\n");
    }
    else if (h == 8)
    {
        int f = 0;
        fflush(stdin);
        printf("\tEnter your address : ");
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, x[g].address) == 0)
            {
                printf("\n");
                printf("\tSerial Number : %d\n", g);
                printf("\tName : ");
                puts(x[g].name);
                printf("\tDisease : ");
                puts(x[g].disease);
                printf("\tRoom no : %d\n\tAge : %d\n\tGender : %c", x[g].room, x[g].age, x[g].gender);
                printf("\n\tPhone No. : ");
                puts(x[g].phone);
                printf("\tAddress : ");
                puts(x[g].address);
                printf("\n\n");
                f = 1;
            }
        }
        if (f == 0)
            printf("\n\tNot Found\n");
    }
    else
        printf("\n\n\tInvalid input\n\n");
}

void del()
{
    int f, h;
    printf("\tEnter the serial number of the patient that you want to delete : (0 - %d) : ", num - 1);
    scanf("%d", &f);
    if (f < num)
    {
        printf("\tWhat do you want ?\n");
        printf("\t1. Remove the whole record\n\t2. Remove Name\n\t3. Remove Disease\n\t4. Remove age\n\t5. Remove Room No.\n\t6. Remove phone number\n\t7. Remove Gender\n\t8. Remove Address\n\tOption : ");
        scanf("%d", &h);
        if (h == 1)
        {
            while (f < num)
            {
                strcpy(x[f].name, x[f + 1].name);
                strcpy(x[f].disease, x[f + 1].disease);
                strcpy(x[f].address, x[f + 1].address);
                strcpy(x[f].phone, x[f + 1].phone);
                x[f].age = x[f + 1].age;
                x[f].gender = x[f + 1].gender;
                x[f].room = x[f + 1].room;
                f++;
            }
            num--;
        }
        else if (h == 2)
        {
            strcpy(x[f].name, "Cleared");
        }
        else if (h == 3)
        {
            strcpy(x[f].disease, "Cleared");
        }
        else if (h == 4)
        {
            x[f].age = 0;
        }
        else if (h == 5)
        {
            x[f].room = 0;
        }
        else if (h == 6)
        {
            strcpy(x[f].phone, "Cleared");
        }
        else if (h == 7)
        {
            x[f].gender = 'O';
        }
        else if (h == 8)
        {
            strcpy(x[f].address, "Cleared");
        }
        printf("\n\tDeleted");
    }
    else
        printf("\n\n\tInvalid Serial number\n");
}

void staff()
{
    
    strcpy(info[0].name, "Dr. Naresh Trehan");
    strcpy(info[0].spec, "Cardiology");
    info[0].exp = 15;

    strcpy(info[1].name, "Dr. Myles Abbott");
    strcpy(info[1].spec, "Pediatrician");
    info[1].exp = 22;

    strcpy(info[2].name, "Dr. Fouad Abbas");
    strcpy(info[2].spec, "Oncology");
    info[2].exp = 12;

    strcpy(info[3].name, "Dr. Reese Anderson");
    strcpy(info[3].spec, "Psychiatry");
    info[3].exp = 10;

    strcpy(info[4].name, "Dr. Sudhansh Datta");
    strcpy(info[4].spec, "Neurosurgery");
    info[4].exp = 14;

    for (int i = 0; i < 5; i++)
    {
        printf("\tDoctor Name    : %s\n", info[i].name);
        printf("\tSpecialization : %s\n", info[i].spec);
        printf("\tExperience     : %d Years\n", info[i].exp);
        printf("---------------------------------------------------\n");
    }
}

void expense()
{
    int days;
    float rent, medi, lab, trent, total, tax, final;
    printf("\tEnter the number of days : ");
    scanf("%d", &days);
    printf("\tEnter the rent of room per day : ");
    scanf("%f", &rent);
    printf("\tEnter the total cost of medicines : ");
    scanf("%f", &medi);
    printf("\tEnter the total laboratory expenses : ");
    scanf("%f", &lab);
    trent = days * rent;
    total = trent + medi + lab;
    tax = 0.15 * total;
    final = total + tax;
    printf("------------------------------------------------------------\n");
    printf("\tTotal Rent                  = %.2f\n", trent);
    printf("\tTotal Cost of all expenses  = %.2f\n", total);
    printf("\tTax on total                = %.2f\n", tax);
    printf("------------------------------------------------------------\n");
    printf("\tFinal Total incl. tax       = %.2f\n", final);
    printf("------------------------------------------------------------\n");
}

int read()
{
    FILE *fp = fopen("records.txt", "r");
    if (fp == NULL)
    {
        //create empty file, so that we can open it
        //in the next execution of this program
        fp = fopen("records.txt", "w");
        fclose(fp);
        printf("\tFile does not exist, creating now...\n\n");
        return 0;
    }

    num = fread(x, sizeof(struct record), 100, fp);
    fclose(fp);
}

int write()
{
    FILE *fp = fopen("records.txt", "w");
    if (fp == NULL)
    {
        printf("\tError");
        exit(1);
    }
    fwrite(x, sizeof(struct record), num, fp);

    fclose(fp);
}