# **<p align="center">Clinic Appointment Scheduling System</p>**

Small clinics and individual healthcare providers often struggle with managing appointments due to manual or outdated methods such as paper logs or spreadsheets. These methods make it difficult to track doctor availability, avoid scheduling conflicts, and maintain accurate patient information.

The **Clinic Appointment Scheduling System** provides a lightweight, console-based digital solution developed using **C++** and **Object-Oriented Programming (OOP)** principles.

This system simplifies scheduling, ensures accuracy, and improves the organization of clinic operations without requiring complex infrastructure.


## <strong>System Objectives</strong>

1. Streamline the process of scheduling and managing clinic appointments.  
2. Provide a simple, conflict-free method for booking doctor–patient appointments.  
3. Reduce manual errors caused by paper-based or spreadsheet scheduling.  
4. Offer an organized structure for storing doctor and patient information.  
5. Implement a lightweight system using C++ and OOP concepts.  
6. Provide an intuitive, menu-driven console interface for clinic staff.  
7. Allow staff to view, add, modify, and delete appointment records.  
8. Demonstrate a full SDLC workflow for academic and portfolio purposes.


## <strong>Development Model</strong>

### <strong>Agile</strong>
Agile provides quick, flexible development through small iterations.  
Since the system is simple and requirements may evolve, Agile helps deliver features early, gather feedback fast, and adjust without heavy rework.


# <strong>System Requirements</strong>

- The system shall allow users to log in (Admin, Receptionist, Doctor).  
- The system shall authenticate users quickly with role-based access.  
- Admin can add, update, and delete doctors and receptionists.  
- Receptionist can schedule appointments between patients and doctors.  
- The system assigns each patient a number for managing visit order.  
- Doctors can view all appointments assigned to them.  
- Receptionists can update or delete appointments.  
- Receptionists can list all doctors and view their appointment counts.  
- The system shall run on any OS that supports C++.  
- The system shall be simple and easy to use.


# <strong>Functional Requirements (SMART)</strong>

## **1. User Authentication & Authorization**
- The system shall allow Admin, Receptionist, and Doctor to log in using a username and password.  
- The system shall validate credentials within **1 second**.  
- The system shall restrict access so each role only sees its permitted features.  


## **2. Doctor Management (Admin Only)**
- The system shall allow the Admin to add, update, and delete doctor profiles.  
- The system shall assign each doctor a unique **DoctorID**.  
- The system shall allow the Admin to view all registered doctors.


## **3. Patient & Appointment Management (Receptionist)**  
- The system shall allow the Receptionist to add new patients.  
- The system shall assign each patient a unique **PatientID**.  
- The system shall allow the Receptionist to book appointments for patients.  
- The system shall allow selecting a doctor and entering date & time.  
- The system shall prevent double-booking a doctor at the same time.  
- The system shall allow the Receptionist to update or cancel appointments.  


## **4. Doctor Features**
- Doctors shall be able to view **only their own** appointments.  
- Doctors shall not modify, create, or cancel appointments.


# <strong>Non-Functional Requirements (SMART)</strong>

## **1. Performance**
- The system shall respond to any user action in **less than 1 second**.  
- The system shall handle up to 100 doctors, patients, and appointments in memory.


## **2. Usability**
- The system shall offer a simple, readable console interface.  
- All user actions shall require no more than **4—5 steps**.


## **3. Reliability**
- The system shall prevent double-booking for the same doctor and time.


## **4. Portability**
- The system shall run on any operating system with a C++ compiler.


## **5. Maintainability**
- The system shall follow OOP principles and use a modular structure.
