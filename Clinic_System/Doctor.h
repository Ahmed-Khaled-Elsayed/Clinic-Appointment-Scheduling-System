#pragma once

#include "User.h"

class Doctor : public User
{
	
private:
	static int counter;
	string speciality;

public:
	Doctor() : User(), speciality("") {
		personID = counter;
		counter++;
	}

	Doctor(string name, int age, string phoneNumber, string username, string password, string role, string spec) :
		User(name, age, phoneNumber, username, password, role), speciality(spec) {
		personID = counter;
		counter++;
	}


	void setSpec(string spec) { this->speciality = spec; }
	string getSpec() { return speciality; }

	void viewMyAppointments() { cout << "view all doctors appointments"; }

	void printInfo() override {
		cout << this->getName() << " | Age: " << this->getAge() << " | Phone no: " << this->getPhoneNumber()
			<< " | UserName: " << this->getUsername() << " | Specialization: " << speciality << endl;
	}

};

inline int Doctor::counter = 2000;

