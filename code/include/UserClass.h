#ifndef USER_CLASS_H
#define USER_CLASS_H

#include <iostream>
#include <string>
#include "PersonClass.h"
using namespace std;

class User: public Person {
    private:
        string username;
        string password;
        string role;
    public:
        // default constructor
        User(): Person(), username(""), password(""), role("") {}
        // parametrized constructor
        User(string username, string password, string role): Person(), username(username), password(password), role(role) {}
        // getters
        string getUsername() {
            return username;
        };
        string getRole() {
            return role;
        };
        // setters
        void setUsername(string username) {
            this->username = username;
        };
        void setRole(string role) {
            this->role = role;
        };
        void setPassword(string password) {
            this->password = password;
        };
        // print Info
        void printInfo() override {
            cout << "ID: " << personID << endl;
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Phone Number: " << phoneNumber << endl;
            cout << "Username: " << this->username << endl;
            cout << "Role: " << this->role << endl;
        }
        // Login
        bool login(string username, string password) {
            if (username != this->username) {
                cout << "Invalid username!" << endl;
                return false;
            } else {
                if (password != this->password) {
                    cout << "Invalid password!" << endl;
                    return false;
                }
            }
            return true;
        };
};

#endif