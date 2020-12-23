#include "Customer.h"
#include <iostream>
#include <conio.h>
using namespace std;
//constructor
Customer::Customer()
{   // initialize the members
    head = NULL;
    tail = NULL;
    totalNumber=0;
    swabTestNumber=0;
    noSwabTestNumber=0;
    positiveNumber=0;
    negetiveNumber=0;
}
//deconstructor
Customer::~Customer()
{   // delete all data
    Person *current, *temp;
    current = head;
    while (current != NULL) {
        temp = current;
        delete current;
        current = temp->next;
    }
}
// add customer
void Customer::addCustomer()
{
    // create a new person by inputing personal data
    Person* temp = new Person();
    this->totalNumber++;
    if (temp->hasTest) {
        swabTestNumber++;
        if (temp->isPositiveResult) {
            positiveNumber++;
        }
        else
        {
            negetiveNumber++;
        }
    }
    else {
        noSwabTestNumber++;
    }
    // add temp person data into linkedlist that respresents the alll customers
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        //temp = NULL;
    }
    else
    {
        tail->next=temp;
        tail = temp;
    }
}
// edit customer
void Customer::editCustomer()
{
    // receive the name for edit from user
    displayNames();
    char tempName[20];
    cout << " Please enter name to edit" << endl;
    cin >> tempName;
    Person* current;
    current = head;
    // get person data while the condition
    while (current != NULL) {
        if (strcmp(current->name, tempName) == 0) {
            //if name is equals , change data
            cout << "======= Edit Customer =========\n";
            cout << "Pleas enter new day\n";
            cin >> current->day;
            cout << "Pleas enter new name\n";
            cin >> current->name;
            cout << "Pleas enter new age\n";
            cin >> current->age;
            cout << "Pleas enter new address\n";
            cin >> current->address;
            cout << "Pleas enter new phoneNumber\n";
            cin >> current->phoneNumber;
            cout << "Pleas enter new IC No.\n";
            cin >> current->ICNO;
           
            if (current->hasTest) {
                if (current->isPositiveResult) {
                    HealthState* healthState = new HealthState();
                    current->healthState = healthState;
                }
                else
                {
                    HealthState* healthState = new HealthState();
                    current->healthState = healthState;
                }
            }
            else {
                cout << "Does he(she) had a swab test? y or n>>\n";
                char test;
                test = _getch();
                // if customer has a swab test , increase the number of customer who have a test
                if (test == 'y') {
                    this->swabTestNumber++;
                    this->noSwabTestNumber--;
                    current->hasTest = true;
                    cout << "Is it's result Positive? y or n>>\n";
                    char testRes;
                    testRes = _getch();
                    // if test result is positive , increase the number of customer who have a positive result
                    if (testRes == 'y') {
                        this->positiveNumber++;
                        current->isPositiveResult = true;
                        cout << "Please enter treatment location\n";
                        cin >> current->treatmentLocation;
                        HealthState* healthState = new HealthState();
                        current->healthState = healthState;
                    }
                    // if test result is negetive , increase the number of customer who have a negetive result
                    else {
                        this->negetiveNumber++;
                        current->isPositiveResult = false;
                        HealthState* healthState = new HealthState();
                        current->healthState = healthState;
                    }
                }
                // if customer has no swab test , increase the number of customer who have no test
                else {
                    current->hasTest = false;
                }
            }
            break;
        }
        current = current->next;
    }
}
// delete customer with name
void Customer::deleteCustomer()
{
    // receive the name for edit from user
    displayNames();
    char tempName[20];
    cout << " Please enter name to delete" << endl;
    cin >> tempName;
    Person* current;
    Person* previous;
    current = head;
    previous = head;
    // get person data while the condition
    while (current != NULL) {
        if (strcmp(current->name, tempName) == 0) {
            if (current->equals(head)) {
                head = current->next;               
                current->next = NULL;
                current = NULL;
                break;
            }
            else {
                previous->next = current->next;
                current->next = NULL;
                current = NULL;
                break;
            }           
        }
        previous = current;
        current = current->next;
    }
}
void Customer::searchCustomer()
{
    // receive the name for edit from user
    displayNames();
    char tempName[20];
    cout << " Please enter name to search" << endl;
    cin >> tempName;
    Person* current;
    current = head;
    // get person data while the condition
    while (current != NULL) {
        if (strcmp(current->name, tempName) == 0) {
            current->display();
            break;
        }
        current = current->next;
    }
}
// display all customers
void Customer::displayCustomer()
{
    Person *current;
    current = head;
    while (current != NULL) {
        current->display();
        current = current->next;
    }
}

void Customer::displayTestedNumbers()
{
    cout << "Number of Customers Tested" << endl;
    for (int i = 1; i < 14; i++) {
        bool flag = false;
        int dayTotal = 0;
        int dayHasTest = 0;
        int dayHasNoTest = 0;
        Person* current;
        current = head;
        while (current != NULL) {
            if (current->day == i) {
                dayTotal++;
                flag = true;
                if (current->hasTest) {
                    dayHasTest++;
                }
                else {
                    dayHasNoTest++;
                }
            }
            current = current->next;
        }
        if (flag == true) {
            cout << "-------------------------------\n";
            cout << "Day : " << i << endl;
            cout << "Total number of customers : " << dayTotal << endl;
            cout << "Number of customers done with swab test : " << dayHasTest << endl;
            cout << "Number of customers without doing swab test : " << dayHasNoTest << endl;
            cout << "-------------------------------\n";
        }
    }
}

void Customer::displayPositiveCustomers()
{
    cout << "Customer Tested Positive" << endl;
    for (int i = 1; i < 14; i++) {
        Person* current;
        current = head;
        while (current != NULL) {
            if (current->isPositiveResult && current->day == i) {
                current->display();
            }
            current = current->next;
        }
    }
}

void Customer::displayNegetiveCustomers()
{
    cout << "Customer Tested Negative" << endl;
    for (int i = 1; i < 14; i++) {
        Person* current;
        current = head;
        while (current != NULL) {
            if (current->isPositiveResult != 1 && current->hasTest == 1 && current->day==i) {
                current->display();
            }
            current = current->next;
        }
    }
}

void Customer::displayChargeOrDeathCustomers()
{
    cout << "Record of Customers Discharged/Death" << endl;
    Person* current;
    current = head;
    while (current != NULL) {
        if (current->healthState != NULL) {
            if (strcmp(current->healthState->state, "quarantine") != 0 && strcmp(current->healthState->state, "under treatment") != 0) {
                cout << "-----------------------------\n";
                cout << "Day : " << current->day << endl;
                cout << "Name : " << current->name << endl;
                cout << "IC No. : " << current->ICNO << endl;
                cout << "Date of Discharged/Death : " << current->healthState->date << endl;
                cout << "Status(Discharged/Death) : " << current->healthState->state << endl;
                cout << "-----------------------------\n";
            }
        }
        current = current->next;
    }
}

void Customer::displayNames()
{
    Person* current;
    current = head;
    cout << "======= Names =========\n";
    while (current != NULL) {
        cout << current->name << endl;
        current = current->next;
    }
    cout << "==================\n";
}

