#ifndef PATIENT_H_INCLUDED
#define PATIENT_H_INCLUDED

using namespace std;

#include "Person.h"

class Patient : public Person {
private:
    int queueNumber;

public:
    Patient(int id, string name, int age, string phone, int qNum);
    void setQueueNumber(int q);
    int getQueueNumber() const;
    void printInfo() override;
};

#endif
