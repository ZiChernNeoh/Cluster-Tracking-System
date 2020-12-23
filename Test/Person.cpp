#include "Person.h"
#include <iostream>
#include <conio.h>
using namespace std;
//constructor
Person::Person()
{
    this->healthState = NULL;
    strcpy_s(this->treatmentLocation, "");
    cout << "============ Adding Customer ==============\n";
    cout << "Please enter day\n";
    cin >> this->day;
    cout << "Please enter name\n";
    cin >> this->name;
    cout << "Please enter age\n";
    cin >> this->age;
    cout << "Please enter address\n";
    cin >> this->address;
    cout << "Please enter phoneNumber\n";
    cin >> this->phoneNumber;
    cout << "Please enter IC No.\n";
    cin >> this->ICNO;
    cout << "Does he(she) had a swab test? y or n>>\n";
    char test;
    test = _getch();
    if (test == 'y') {
        this->hasTest = true;
        cout << "Is it result positive? y or n>>\n";
        char testRes;
        testRes = _getch();
        if (testRes == 'y') {
            this->isPositiveResult = true;
            cout << "Please enter treatment location\n";
            cin >> this->treatmentLocation;
            HealthState *healthState1 = new HealthState();
            this->healthState = healthState1;
        }
        else {
            this->isPositiveResult = false;
            HealthState* healthState2 = new HealthState();
            this->healthState = healthState2;
        }
    }
    else {
        this->hasTest = false;
    }
    this->next = NULL;
}
// deconstructor
Person::~Person()
{
  
    delete healthState;
    delete treatmentLocation;
    delete name;
    delete address;
    delete phoneNumber;
    delete ICNO;
    delete next;
  


}
// display data
void Person::display()
{
     cout << "-------------------------" << endl;
     cout << "Day: " << this->day << endl;
     cout <<"Name: " <<this->name << endl;
     cout << "IC NO.: " << this->ICNO << endl;
     cout << "Age: " << this->age << endl;
     cout << "Address: " << this->address << endl;
     cout<< "PhoneNumber: " << this->phoneNumber << endl;
     if (this->healthState != NULL) {
         if (strcmp(this->healthState->state, "quarantine") == 0) {
             cout << "Date of release from quarantine: " << this->healthState->date << endl;
         }
         else if (strcmp(this->healthState->state, "under treatment") == 0) {
             cout << "Date of treatment begins: " << this->healthState->date << endl;
             cout << "Treatment Location: " << this->treatmentLocation << endl;
         }
         else {
             cout << "Treatment Location : " << this->treatmentLocation << endl;
             cout << "Status(Discharged/Death): " << this->healthState->state << endl;
             cout << "Date of Discharged/Death: " << this->healthState->date << endl;
         }
     }
     cout << "-------------------------" << endl;
}

//compare two persons
bool Person::equals(Person* person) {
    if (strcmp(this->name, person->name) != 0) {
        return false;
    }
    if (strcmp(this->address, person->address) != 0) {
        return false;
    }
    
    if (strcmp(this->phoneNumber, person->phoneNumber) != 0) {
        return false;
    }
    if (this->age != person->age) {
        return false;
    }
    if (strcmp(this->ICNO, person->ICNO) != 0) {
        return false;
    }
    return true;
}