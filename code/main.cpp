// handle console config
// add admin class


#include <iostream>
#include <vector>
#include <conio.h>
#include "actorClasses.h"
using namespace std;

// create doctors
void createDoctors() {
    const Doctor doctor1("Ahmed Maher Algohary", "123 Main St", "123-456-7890", "ahmedmaher.dev1@gmail.com", "pass123", 100000.0, "Cardiologist");
    const Doctor doctor2("Ahmed Khaled", "456 Oak Ave", "098-765-4321", "ahmedkhaled.dev1@gmail.com", "pass456", 90000.0, "Pediatrician");
    vector<Doctor> doctors = {doctor1, doctor2};
};
// create receptionists
void createReceptionists() {
    const Receptionist receptionist1("Ahmed Gaber", "321 Elm St", "444-555-6666", "ahmedgaber.dev1@gmail.com", "ahmed123", 50000.0, 25.0F);
    const Receptionist receptionist2("Islam Adel", "654 Maple Ave", "777-888-9999", "islamadel.dev1@gmail.com", "islam456", 45000.0, 30.0F);
    const Receptionist receptionist3("Abdelrahman Nagah", "789 Pine Rd", "111-222-3333", "abdelrahman.nagah@gmail.com", "secret789", 85000.0, 28.0F);
    vector<Receptionist> receptionists = {receptionist1, receptionist2, receptionist3};
};

#ifdef _WIN32
#include <windows.h>

void enableRawMode() {
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hStdin, &mode);
    mode &= ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT);
    SetConsoleMode(hStdin, mode);
}

void disableRawMode() {
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hStdin, &mode);
    mode |= (ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT);
    SetConsoleMode(hStdin, mode);
}

#else
#include <termios.h>
#include <unistd.h>

termios orig_term;

void enableRawMode() {
    tcgetattr(STDIN_FILENO, &orig_term);
    termios raw = orig_term;

    raw.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_term);
}
#endif

// clear console helper
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
};

// read key, handle arrow keys
int readKey() {
    int ch = getchar();

    // Arrow keys start with ESC (27)
    if (ch == 27) {
        int next1 = getchar();
        int next2 = getchar();

        // ESC [ A → Up arrow
        if (next1 == '[') {
            if (next2 == 'A') return 1;  // up
            if (next2 == 'B') return 2;  // down
        }
    }

    return ch; // normal key
};

// draw login menu
void renderLoginMenu(int choice, const string& highlight, const string& reset) {
    cout << "# =========== Login Page ========== #" << endl;
    cout << (choice == 0 ? highlight + "> 1. Doctor" + reset : "1. Doctor") << endl;
    cout << (choice == 1 ? highlight + "> 2. Receptionist" + reset : "2. Receptionist") << endl;
    cout << (choice == 2 ? highlight + "> 3. Admin" + reset : "3. Admin") << endl;
    cout << (choice == 3 ? highlight + "> 4. Exit" + reset : "4. Exit") << endl;
};

// draw doctor management menu
void renderDoctorManagementMenu(int choice, const string& highlight, const string& reset) {
    cout << "# What do you want to manage?" << endl;
    cout << (choice == 0 ? highlight + "> 1. check assigned patients" + reset : "1. check assigned patients") << endl;
    cout << (choice == 1 ? highlight + "> 2. Exit" + reset : "2. Exit") << endl;
};

// get user choice
int getUserChoice(string currentMenu) {
    const string highlight = "\033[1;32m";
    const string reset = "\033[0m";
    int choice = 0;
    bool confirmed = false;

    clearScreen();

    switch(currentMenu) {
        case "loginPage":  
            renderLoginMenu(choice, highlight, reset);
            break;
        case "doctorManagement":  
            renderDoctorManagementMenu(choice, highlight, reset);
            break;
    }
    
    

    while (!confirmed) {
        int key = readKey();
        int oldChoice = choice;

        if (key == 1) {  
            // up arrow
            choice = (choice + 2) % 4;
        }
        else if (key == 2) { 
            // down arrow
            choice = (choice + 1) % 4;
        }
        else if (key == 'w' || key == 'W') {
            choice = (choice + 2) % 4;
        }
        else if (key == 's' || key == 'S') {
            choice = (choice + 1) % 4;
        }
        else if (key == '\n' || key == '\r') {
            confirmed = true;
        }

        if (choice != oldChoice) {
            clearScreen();
            switch(currentMenu) {
                case "loginPage":  
                    renderLoginMenu(choice, highlight, reset);
                    break;
                case "doctorManagement":  
                    renderDoctorManagementMenu(choice, highlight, reset);
                    break;
            }
        }
    }

    return choice;
};



void showDoctorManagementMenu(Doctor doctor) {
    int activeMenuChoice = getUserChoice("doctorManagement");
    
    switch (choice) {
        case 1: showPatientManagementMenu(doctor); break;
    }
}

void verifyDoctorLogin(vector<Doctor> doctors) {
    string email, password;
    cout << "Login as a (Doctor)" << endl;
    // Enter your email: 
    cout << "Enter your email: ";
    cout << "Enter your password: ";
    // take a string
    getline(cin, email);
    getline(cin, password);
    // take email and password => show them at the same time and go to password after clicking enter and ensuring there is content in email
    
    for (int i = 0; i < doctors.size(); i++) {
        if (!doctors[i].getEmail() == email) {
            cout << "Invalid email" << endl;
            cout << "enter any key to go back to login page" << endl;
            cin.get();
            showLoginPage(doctors, receptionists);
        } else {
            if (!doctors[i].getPassword() == password) {
                cout << "Invalid password" << endl;
                cout << "enter any key to go back to login page" << endl;
                cin.get();
                showLoginPage(doctors, receptionists);
            } else {
                cout << "Hello Dr. " << doctors[i].getName() << endl;
                showDoctorManagementMenu(doctors[i]);
            }
        }
    }
    // loop over doctor and check if anyone meets the credentials, 
        // if yes => Hello Dr. Ahmed Maher Algohary then What do you want to manage? patients + appointments + receptionists
        // if no => show a message then after clicking any key => go to login page again
};


// show Login Page
void showLoginPage(vector<Doctor> doctors, vector<Receptionist> receptionists) {
    int activeChoice = getUserChoice("loginPage");
    clearScreen();
    // Login as a 
    switch (activeChoice) {
        case 0: verifyDoctorLogin(doctors); break;

        case 1: verifyReceptionistLogin(reciptionists); break;
        case 1: verifyAdminLogin(admins); break;
        
        case 2: cout << "Exit" << endl; break;
    };
    
    cout << "You chose option #" << (activeChoice + 1) << endl;
};



int main() {
    createDoctors();
    createReceptionists();
    
    showLoginPage(doctors, receptionists);
    

    // show doctors
    // for (int i = 0; i < doctors.size(); i++) cout << doctors[i].getName() << endl;



    // show login page header
    // show login options
    // determine the active choice => colored
    // switch between the choices using up/down keys
    // when enter is pressed, clear the screen then execute a function  
        // show interactive menu according to the active choice
            // doctor => What do you want to manage? patients + appointments + receptionists
                // add patient + show patients + show patient info
                // add appointemnts + show appointments + show appointment details
                // add receptionist + show receptionists + remove receptionist
            // receptionist => What do you want to manage? patients + appointments
                // add patient + show patients + show patient info
                // add appointemnts + show appointments + show appointment details




    return 0;
}