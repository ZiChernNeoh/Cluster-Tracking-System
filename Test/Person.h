#pragma once
#include "HealthState.h"
#ifndef PERSON_H
#define PERSON_H

class Person
{
public:
	Person();
	~Person();
	void display();
	bool equals(Person * person);
	//name of person
	char name[20];
	//age 
	int age;
	//address
	char address[30];
	//phoneNumber
	char phoneNumber[20];
	//IC number
	char ICNO[10];
	//test flag for having swab test or not, true if he had a test, false if he had no test
	bool hasTest = false;
	// day
	int day=0;
	// swab test resut, true if it is positive result, false if it is negetive result
	bool isPositiveResult = false;
	// location where customer is caring , while the test result of customer is positive
	char treatmentLocation[20];
	// state of health, discharging or die with date
	HealthState* healthState;
	Person* next;
private:
};

#endif
