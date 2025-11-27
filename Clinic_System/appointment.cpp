#include "Appointment.h"
#include <iostream>
using namespace std;

Appointment::Appointment(int id, int dID, int pID) {
    this->appointmentID = id;
    this->doctorID = dID;
    this->patientID = pID;
}

int Appointment::getAppointmentID() const {
    return appointmentID;
}

int Appointment::getDoctorID() const {
    return doctorID;
}

int Appointment::getPatientID() const {
    return patientID;
}

void Appointment::setDoctorID(int dID) {
    doctorID = dID;
}

void Appointment::setPatientID(int pID) {
    patientID = pID;
}
void Appointment::printInfo() const {
    cout << "Appointment ID: " << appointmentID
         << " | Doctor ID: " << doctorID
         << " | Patient ID: " << patientID << endl;
}
