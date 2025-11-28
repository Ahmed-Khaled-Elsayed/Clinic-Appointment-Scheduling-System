

#include <iostream>
#include <conio.h>
using namespace std;

class Admin {
public:

    // ------------------ Admin Menu ------------------
    void adminMenu() {
        string options[] = {
            "Add Doctor",
            "Delete Doctor",
            "Add Receptionist",
            "Delete Receptionist",
            "Exit"
        };

        int selected = 0;
        int totalOptions = 5;

        while (true) {
            system("cls");
            cout << "==== Admin Menu ====\n\n";
            /////// menu printing 
            for (int i = 0; i < totalOptions; i++) {
                if (i == selected)
                    cout << " => " << options[i] << "\n";
                else
                    cout << "   " << options[i] << "\n";
            }

            char key = _getch();

            if (key == 72) selected--;        // => arrow up
            else if (key == 80) selected++;     // => arrow down 
            else if (key == 13) {   // ENTER
                system("cls");
                handleSelection(selected); // pass the index to choose action needed 
                system("pause");
                if (selected == 4) return;
            }

            if (selected < 0) selected = totalOptions - 1;
            if (selected >= totalOptions) selected = 0;
        }
    }

    // ------------- CALL FUNCTION BASED ON SELECTION -------------
    void handleSelection(int index) {
        switch (index) {
        case 0: {
            Doctor d = createDoctor();
            printDoctor(d);
            break;
        }
        case 1: {
            int id = requestDoctorDeletion();
            cout << "Doctor ID to delete: " << id << endl;
            break;
        }
        case 2: {
            Receptionist r = createReceptionist();
            printReceptionist(r);
            break;
        }
        case 3: {
            int id = requestReceptionistDeletion();
            cout << "Receptionist ID to delete: " << id << endl;
            break;
        }
        case 4:
            cout << "Exiting menu...\n";
            break;
        }
    }

    // ---------------- RETURNING FUNCTIONS ---------------------

    Doctor createDoctor() {
        int id, age;
        string name, phone, specialty;

        cout << "=== Add New Doctor ===\n";
        cout << "Enter ID: "; cin >> id;
        cout << "Enter Name: "; cin >> name;
        cout << "Enter Age: "; cin >> age;
        cout << "Enter Phone: "; cin >> phone;
        cout << "Enter Specialty: "; cin >> specialty;

        return Doctor(id, name, age, phone, specialty);
    }

    int requestDoctorDeletion() {
        int id;
        cout << "Enter Doctor ID to delete: ";
        cin >> id;
        return id;
    }

    Receptionist createReceptionist() {
        int id, age;
        string name, phone, username;

        cout << "=== Add New Receptionist ===\n";
        cout << "Enter ID: "; cin >> id;
        cout << "Enter Name: "; cin >> name;
        cout << "Enter Age: "; cin >> age;
        cout << "Enter Phone: "; cin >> phone;
        cout << "Enter Username: "; cin >> username;

        return Receptionist(id, name, age, phone, username);
    }

    int requestReceptionistDeletion() {
        int id;
        cout << "Enter Receptionist ID to delete: ";
        cin >> id;
        return id;
    }

    // ------------------- PRINT HELPERS (TESTING ONLY) -------------------
    void printDoctor(const Doctor& d) {
        cout << "\nDoctor Added:\n";
        cout << "ID: " << d.id << "\nName: " << d.name
            << "\nAge: " << d.age << "\nPhone: " << d.phone
            << "\nSpecialty: " << d.specialty << "\n";
    }

    void printReceptionist(const Receptionist& r) {
        cout << "\nReceptionist Added:\n";
        cout << "ID: " << r.id << "\nName: " << r.name
            << "\nAge: " << r.age << "\nPhone: " << r.phone
            << "\nUsername: " << r.username << "\n";
    }
};
