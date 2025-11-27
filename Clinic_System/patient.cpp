#include "Patient.h"
#include <iostream>

using namespace std;

Patient::Patient(int id, string name, int age, string phone, int qNum)
    : Person(id, name, age, phone) {
    this->queueNumber = qNum;
}
void Patient::setQueueNumber(int q) {
    queueNumber = q;
}
int Patient::getQueueNumber() const {
    return queueNumber;
}
void Patient::printInfo() {
    cout << "Patient Info:-" << endl;
    cout << "Queue No: " << queueNumber << endl;
    Person::printInfo();
}
