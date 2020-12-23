#pragma once
#include "Person.h"
#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer
{
public:
	//constructor
	Customer();
	//deconstructor
	~Customer();
	//add customer
	void addCustomer();
	// edit customer
	void editCustomer();
	//delete customer
	void deleteCustomer();
	// search customer with its naem
	void searchCustomer();
	// display all customers
	void displayCustomer();
	// display tested numbers
	void displayTestedNumbers();
	//display customers with positive result
	void displayPositiveCustomers();
	//display customers with negetive result
	void displayNegetiveCustomers();
	//display customers with charge or die
	void displayChargeOrDeathCustomers();

private:
	Person* head;
	Person* tail;
	int totalNumber;
	int swabTestNumber;
	int noSwabTestNumber;
	int positiveNumber;
	int negetiveNumber;
	void displayNames();
};

#endif

