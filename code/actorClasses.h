#ifndef CLASSES_H
#define CLASSES_H

#include <string>
using namespace std;

// person class
class Person {
    private:
        static int nextId;            // shared counter
        int id;                       // unique per instance
        string name;
        double salary;
        string address;
        string phone;
        string email;
        string password;
    public:
        // default constructor
        Person() {
            id = nextId++;
            name = "";
            address = "";
            phone = "";
            email = "";
            password = "";
            salary = 0.0;
        }
        // parametrized constructor
        Person(string name, string address, string phone, string email, string password, double salary) {
            id = nextId++;
            this->name = name;
            this->address = address;
            this->phone = phone;
            this->email = email;
            this->password = password;
            this->salary = salary;
        };
        // getters
        int getId() {
            return id;
        };
        string getName() {
            return name;
        };
        string getEmail() {
            return email;
        };
        string getPassword() {
            return password;
        };
};

// doctor class
class Doctor: public Person {
    private:
        string specialization;
    public:
        // default constructor
        Doctor(): Person(), specialization("") {};
        // constructor
        Doctor(string name, string address, string phone, string email, string password, double salary, string specialization): Person(name, address, phone, email, password, salary) {
            this->specialization = specialization;
        }
        string getSpecialty() {
            return specialization;
        }
};

// receptionist class
class Receptionist: public Person {
    float age;
    public:
        // default constructor
        Receptionist(): Person(), age(0.0F) {};
        // parametrized constructor
        Receptionist(string name, string address, string phone, string email, string password, double salary, float age): Person(name, address, phone, email, password, salary) {
            this->age = age;
        };
};

// intialize static members
inline int Person::nextId = 1000;

#endif