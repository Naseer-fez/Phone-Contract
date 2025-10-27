#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct contact
{

    char name[50];
    char phone_number[10];
    struct contact *next;
    struct contact *prev;

} contact;
int oneisavaliable;
contact *createcontact(char name[], char phone_number[]);
void newcontract(contact **head, char name[], char phone_number[]);
int deletecontact(contact **head, char phone_number[]);
int editcontact(contact **head, char name[], int number);
void displaycontacts(contact *head);
void menu();
int ask();
int optionselection(int range, int attempt);
int menuswitch(int option, contact **head);
char *phonenumbercheck(char ph[], int attempt);
int dataentry(char name[], char phone[], contact **head);
int removethecontat(char name[], char phone[], contact **head);
int doyouneedanythingelse(contact **head);

int main()
{
    contact *head = NULL;
printf("WLECOME TO THE CONTACT BOOK\n");
    menu(&head);
    printf("\nTHANK YOU\n");
   
}

contact *createcontact(char name[], char phone_number[])
{

    contact *newnode = (contact *)malloc(sizeof(contact));
    if (newnode == NULL)
    {
        printf("Memory allocation failed");
        return NULL;
    }

    strcpy(newnode->name, name);
    strcpy(newnode->phone_number, phone_number);
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}
void newcontract(contact **head, char name[], char phone_number[])
{

    contact *newnode = createcontact(name, phone_number);
    if (*head == NULL)
    {

        *head = newnode;
        oneisavaliable++;
    }
    else
    {
        contact *travel = *head;
        while (travel->next != NULL)
        {
            travel = travel->next;
        }
        travel->next = newnode;
        newnode->prev = travel;
        printf("\nCONTACT HAS BEEN ADDED SUCESSFULY!!");
        oneisavaliable++;
    }
}
int deletecontact(contact **head, char phone_number[])
{
    int found = 0;

    if (oneisavaliable == 0)
    {

        printf("\nThe Contact list is empty\n");
        return 0;
    }
    else
    {
        contact *temp = *head;

        while (temp != NULL)
        {

            if (!strcmp(temp->phone_number, phone_number))
            {
                found = 1;

                if (temp->prev != NULL)
                {
                    temp->prev->next = temp->next;
                }
                else
                {
                    *head = temp->next;
                }
                if (temp->next != NULL)
                {
                    temp->next->prev = temp->prev;
                }
                free(temp);
                oneisavaliable--;
                printf("\nContact is sucesfully removed\n");
                return 1;
            }

            temp = temp->next;
        }
        if (found == 0)
        {
            printf("\nNo contract like that");
            return -1;
        }
    }
}
void displaycontacts(contact *head)
{
    int count = 1;
    if (head == NULL)
    {
         printf("\nTHe contact list is empty");
    }
    else
    {
        printf("\nTHE CONTACT BOOK \n");
        contact *temp = head;
        while (temp != NULL)

        {
            printf("%d)", count++);
            printf("THE NAME:%s\n", temp->name);
            printf("THE PHONE NO:%s\n", temp->phone_number);
            temp = temp->next;
        }
    }
}
int editcontact(contact **head, char name[], int number)
{
    int found = 0;

    if (*head == NULL)
    {

        printf("\nThe Contact list is empty\n");
        return 0;
    }
    
    char newname[50];
        displaycontacts(*head);
        contact *temp = *head;
        if(number==1){
            printf("Entre the name you want to edit:");
                scanf("%s", newname);
        }
        else if  (number==2){
             //char newname[50];
                char *a = phonenumbercheck(newname, 3);
        }
        while (temp != NULL)
        {

            if ((strcasecmp(temp->name, newname) == 0) && number == 1)
            {
                found = 1;
                printf("\nEntre the new name:");
                scanf("%s", newname);
                strcpy(temp->name, newname);
                printf("Contact name  is eddited succefuly ");

                
                
            }
            if ((strcmp(temp->phone_number, newname) == 0) && number == 2)
            {
                found = 1;
                char *b = phonenumbercheck(newname, 3);
                strcpy(temp->phone_number, b);
               printf("Contact number is eddited succefuly ");
                
            }

            temp = temp->next;
        }
        if (found == 0)
        {
            printf("\nNo contract like that");
            return -1;
        }
    
}
int ask()
{
    // printf("Do you want to try again??\n");
    int timepass = 3;
    char a;
    //
    printf("\nY/N:");

    while (timepass != 0)
    {
        scanf(" %c", &a);
        if (a == 'Y' || a == 'y')
        {
            timepass = 0;

            return 1;
            break;
        }
        else if (a == 'N' || a == 'n')
        {
            // printf("\nThank you so much !\n");

            timepass = 0;
            return 0;
        }
        else
        {
            printf("\nEntre a valid option::");
            // scanf(" %c", &a);
            timepass--;
        }
        //
    }
    return 0;
}
int optionselection(int range, int attempt)
{
    int wannatryagain = 2;
    if (attempt == 0)
    {
        printf("You have exhaausted your attemmpts\n");
        printf("\nDo you want to try again??\n");
        wannatryagain = ask();
    }
    if (attempt == 1)
    {
        printf("\nBecarfull last attempt:\n");
    }
    if (wannatryagain == 1)
    {
        return 11;
    }
    else if (wannatryagain == 0)
    {
        return -1;
    }
    int number;

    printf("\nSelect the option you want:");
    scanf("%d", &number);
    if (number < 0 || number > range)
    {
        printf("\nINVALID OPTION\n");
        attempt--;

        return optionselection(range, attempt);
    }
    else
    {

        return number;
    }
}
int menuswitch(int option, contact **head)
{
    char n[50];
    char p[10];
    switch (option)
    {
    case 1:
    {

        dataentry(n, p, head);
        doyouneedanythingelse(head);
    }
    break;
    case 2:
    {
        if (oneisavaliable == 0)
        {
            printf("\nThe contact list is empty\n");
            doyouneedanythingelse(head);
            return 0;
        }
        else
        {
            removethecontat(n, p, head);
            doyouneedanythingelse(head);
        }
    }
    break;
    case 3:
    {

        displaycontacts(*head);
        doyouneedanythingelse(head);
    }
    case 4:
    {
        int number;
        if (oneisavaliable == 0)
        {
            printf("\nThe contact list is empty\n");
            doyouneedanythingelse(head);
            return 0;
        }
        else
        {
            printf("\nSelect the following\n");
            printf("1)To change the number\n ");
            printf("2)to change the Name");
            int k = optionselection(2, 3);
            if (k == 11)
            {
                menu(head);
            }
            else if (k == -1)
            {
                printf("\nThank YOU\n");
            }
            else
            {
                editcontact(head, n, k);
                doyouneedanythingelse(head);
            }
        }
    }
    break;

    default:
        break;
    }
}
char *phonenumbercheck(char ph[], int attempt)
{
    int wannatryagain = 2;
    if (attempt == 0)
    {
        printf("You have exhaausted your attemmpts\n");
        printf("\nDo you want to try again??\n");
        wannatryagain = ask();
    }

    if (attempt == 1)
    {
        printf("\nBecarfull last attempt:\n");
    }
    if (wannatryagain == 1)
    {
        phonenumbercheck(ph, 3);
    }
    else if (wannatryagain == 0)
    {
        ph = NULL;
        return NULL;
    }
    else
    {
        char newnumber[15];
        printf("\nEntre the phone number->");
        scanf("%s", newnumber);
        int found = 0;
        for (int i = 0; i < strlen(newnumber); i++)
        {
            if (!isdigit((unsigned char)newnumber[i]))
            {
                printf("Invalid entry!!,");
                attempt--;
                // newnumber="\0";
                phonenumbercheck(ph, attempt);
                found = 1;
            }
        }
        if (found == 0)
            strcpy(ph, newnumber);
    }
    return ph;
}
int dataentry(char name[], char phone[], contact **head)
{

    printf("\nEntre the name of the contact:");
    scanf("%s", name);
    char *a = phonenumbercheck(phone, 3);
    // strcpy(phone, a);
    newcontract(head, name, a);
}
int removethecontat(char name[], char phone[], contact **head)
{
    displaycontacts(*head);
    printf("Entre the number of the contact you want to delete:");
    char *a = phonenumbercheck(phone, 3);
    int j = deletecontact(head, a);
}
int doyouneedanythingelse(contact **head)

{
    printf("\nDo you need anything else ??");
    int k = ask();
    if (k == 1)
    {
        menu(head);
    }
    else
    {
        return 0;
    }
}
void menu(contact **head)
{
    printf("\n\n");
    printf("1)ADD A CONTACT\n");
    printf("2)DELETE A CONTACT\n");
    printf("3)DISPLAY CONTACTS \n");
    printf("4)EDIT A CONTACT\n");
    int k = optionselection(4, 3);
    if (k == 11)
    {
        menu(head);
    }
    else if (k == -1)
    {
        printf("\nThank YOU\n");
    }
    else
    {

        menuswitch(k, head);
    }
}
