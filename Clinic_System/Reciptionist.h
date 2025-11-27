#pragma once

#include "User.h"
#include "Patient.h"
#include "Appointment.h"
#include "Doctor.h"
#include <vector>


class Reciptionist : public User
{
public:

	Reciptionist() : User() {}

	Reciptionist(string name, int age, string phoneNumber, string username, string password, string role, string spec) :
		User(name, age, phoneNumber, username, password, role) {
	}

	Patient addPatient(int pQnum) {

		string name, phone;
		int age;

		cout << "Enter patient's name: ";
		getline(cin, name);

		cout << "Enter patient's age: ";
		cin >> age;

		cout << "Enter patient's phone: ";
		cin >> phone;

		Patient p(name, age, phone, pQnum);

		return p;
	}

	void updatePatient(vector<Patient>& patients, int pId, string n, int a) {
		bool flag = false;

		for (int i = 0; i < patients.size(); i++)
		{
			if (patients.at(i).getPersonID() == pId)
			{
				flag = true;
				patients.at(i).setName(n);
				patients.at(i).setAge(a);
				cout << "Patient updated successfully.\n";
				break;
			}
		}
		if (!flag)
			cout << "No patient found with this id :(\n";

	}

	void deletePatient(vector<Patient>& patients, int pId) {
		bool flag = false;

		for (int i = 0; i < patients.size(); i++)
		{
			if (patients.at(i).getPersonID() == pId)
			{
				flag = true;
				patients.erase(patients.begin() + i);
				cout << "Patient deleted successfully.\n";
				break;
			}
		}
		if (!flag)
			cout << "No patient found with this id :(\n";

	}

	Appointment bookAppointment() {
		int aId, pId, dId;
		cout << "Enter appointment id: ";
		cin >> aId;
		cout << "Enter patient's id: ";
		cin >> pId;

		cout << "Enter doctor's id: ";
		cin >> dId;

		return Appointment(aId, dId, pId);
	}

	void cancelAppointment(vector<Appointment>& appointments, int aId) {
		bool flag = false;

		for (int i = 0; i < appointments.size(); i++)
		{
			if (appointments.at(i).getAppointmentID() == aId)
			{
				flag = true;
				appointments.erase(appointments.begin() + i);
				cout << "Appointment is canceled successfully.\n";
				break;
			}
		}
		if (!flag)
			cout << "No Appointment found with this id :(\n";
	}


	void viewAllDoctors(vector<Doctor>& doctors) {
		for (auto d : doctors)
			d.printInfo();
	}
	void viewAllPatients(vector<Patient>& patients) {
		for (auto p : patients)
			p.printInfo();
	}
	void viewAllAppointments(vector<Appointment>& appointments) {
		for (auto a : appointments)
			a.printInfo();
	}

};

