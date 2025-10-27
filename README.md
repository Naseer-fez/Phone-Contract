# Phone-Contract
Contact Book Management System
A simple command-line contact management system written in C that allows users to store, manage, and organize their contacts using a doubly linked list data structure.
Features

Add Contacts: Store new contacts with name and phone number
Delete Contacts: Remove contacts by phone number
Display Contacts: View all saved contacts in a formatted list
Edit Contacts: Modify existing contact names or phone numbers
Input Validation: Built-in phone number validation (digits only)
User-Friendly Interface: Interactive menu-driven system with error handling

Data Structure
The program uses a doubly linked list to store contacts, allowing efficient insertion, deletion, and traversal in both directions.
Prerequisites

GCC compiler or any C compiler
Standard C libraries (stdio.h, stdlib.h, string.h, ctype.h)

Compilation
bashgcc contact_book.c -o contact_book
Usage
Run the compiled program:
bash./contact_book
Menu Options

Add a Contact: Enter name and phone number to add a new contact
Delete a Contact: Remove a contact by entering their phone number
Display Contacts: View all saved contacts
Edit a Contact: Modify contact name or phone number

Phone Number Format

Phone numbers must contain only digits
Maximum length: 10 digits
The program validates input and provides up to 3 attempts for correct entry

Code Structure
Main Functions

createcontact(): Allocates memory and creates a new contact node
newcontract(): Adds a new contact to the linked list
deletecontact(): Removes a contact by phone number
displaycontacts(): Prints all contacts in the list
editcontact(): Modifies existing contact information
phonenumbercheck(): Validates phone number input
menu(): Displays main menu and handles navigation

Data Structure
ctypedef struct contact {
    char name[50];
    char phone_number[10];
    struct contact *next;
    struct contact *prev;
} contact;
Limitations

Phone numbers limited to 10 digits
Names limited to 50 characters
No persistent storage (data lost when program exits)
Case-sensitive name matching for edits
