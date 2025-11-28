#ifndef APPOINTMENT_H_INCLUDED
#define APPOINTMENT_H_INCLUDED

using namespace std;

class Appointment {
private:
    int appointmentID;
    int doctorID;
    int patientID;
public:
    Appointment(int id, int dID, int pID);
    int getAppointmentID() const;
    int getDoctorID() const;
    int getPatientID() const;
    void setDoctorID(int dID);
    void setPatientID(int pID);
    void printInfo() const;
};

#endif
