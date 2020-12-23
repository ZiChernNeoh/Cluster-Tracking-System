#include "HealthState.h"
#include <iostream>
using namespace std;

HealthState::HealthState()
{
	cout << "=========== Entering State ============\n";
	cout << "press 0: if discharged\n";
	cout << "press 1: if dead\n";
	cout << "press 2: if quarantine\n";
	cout << "press 3: if under treatment\n";
	int res;
	cin >> res;
	while (res < 0 || res>3) {
		cout << "Invalid number. Please try again.\n";
		cout << "=========== Entering State ============\n";
		cout << "press 0: if discharged\n";
		cout << "press 1: if dead\n";
		cout << "press 2: if quarantine\n";
		cout << "press 3: if under treatment\n";
		cin >> res;
	}
	if (res == 0) {
		strcpy_s(this->state, "discharged");
		cout << "Please enter the date\n";
		cin >> date;
	}
	else if (res == 1) {
		strcpy_s(this->state, "dead");
		cout << "Please enter the date\n";
		cin >> date;
	}
	else if (res == 3) {
		strcpy_s(this->state, "under treatment");
		cout << "Please enter the date\n";
		cin >> date;
	}
	else if (res == 2) {
		strcpy_s(this->state, "quarantine");
		cout << "Please enter the date\n";
		cin >> date;
	}
}

HealthState::~HealthState()
{
	delete[] state;
	delete[] date;
}
