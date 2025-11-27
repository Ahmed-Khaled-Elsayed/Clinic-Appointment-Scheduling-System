#include "Patient.h"
#include <iostream>

using namespace std;

Patient::Patient(string name, int age, string phone, int qNum)
    : Person(name, age, phone) {
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
    cout<<"Patient name: "<<Person::getName()<<endl;
    cout<<"Patient age: "<<Person::getAge()<<endl;
    cout << "Queue No: " << queueNumber << endl;
}
