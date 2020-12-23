
#include <iostream>
#include "Customer.h"
#include <conio.h>
using namespace std;
int main()
{
    Customer* customer = new Customer();

     system("cls");
     while (1)
     {
         system("cls");
         cout << "******* MAIN MENU ******\n";
         cout << "press 1 for adding Customer \n";
         cout << "press 2 for editing Customer\n";
         cout << "press 3 for deleting Customer\n";
         cout << "press 4 for search customer with name\n";
         cout << "press 5 for displaying all customers\n";
         cout << "press 6 for tracking number of customers who has/has not done swab test\n";
         cout << "press 7 for tracking number of customers who are tested positive\n";
         cout << "press 8 for tracking number of customers who are tested negative\n";
         cout << "press 9 for tracking customers who are discharged/dead\n";
         cout << "press 0 for exit\n ";
         char choice;
         choice = _getch();
         switch (choice)
         {
         case '1':
             system("cls");
             customer->addCustomer();
             break;
         case '2':
             system("cls");
             customer->editCustomer();
             break;
         case '3':
             system("cls");
             customer->deleteCustomer();
             break;
         case '4':
             system("cls");
             customer->searchCustomer();
             _getch();
             break;
         case '5':
             system("cls");
             customer->displayCustomer();
             _getch();
             break;
         case '6':
             system("cls");
             customer->displayTestedNumbers();
             _getch();
             break;
         case '7':
             system("cls");
             customer->displayPositiveCustomers();
             _getch();
             break;
         case '8':
             system("cls");
             customer->displayNegetiveCustomers();
             _getch();
             break;
         case '9':
             system("cls");
             customer->displayChargeOrDeathCustomers();
             _getch();
             break;
         case '0':
             exit(1);
         }
     }


}

