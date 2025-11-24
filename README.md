# **<p align="center">Clinic Appointment Scheduling System</p>**

Small clinics and individual healthcare providers often struggle with managing appointments due to the use of manual or outdated methods such as paper logs, informal notes, or simple spreadsheets. These methods make it difficult to track doctor availability, avoid scheduling conflicts, and maintain accurate patient information.

The <strong>Clinic Appointment Scheduling System</strong> provides a lightweight, console-based digital solution developed using C++ and Object-Oriented Programming (OOP) principles.

This system simplifies the scheduling workflow, ensures accuracy, and improves the organization of clinic operations without requiring complex infrastructure.


## **System Objectives**

- Streamline the process of scheduling and managing clinic appointments.
- Provide a simple, conflict-free method for booking doctor-patient appointments.
- Reduce manual errors caused by paper-based or spreadsheet scheduling.
- Offer an organized structure for storing doctor and patient information.
- Implement a lightweight system using C++ and OOP concepts.
- Provide an intuitive, menu-driven console interface for clinic staff.
- Allow staff to view, add, modify, and delete appointment records.
- Demonstrate a full SDLC workflow for academic and portfolio purposes.


## **Development Model**

**Agile**  

It allows quick, flexible development through small iterations. The system is simple and requirements may change, so Agile helps deliver features early, get feedback fast, and make adjustments without heavy rework.


## **Functional Requirements**

### **Doctor Management**
- Allow adding new doctors.
- Assign each doctor a unique ID.
- Allow viewing all registered doctors.

### **Patient Management**
- Allow adding new patients.
- Assign each patient a unique ID.
- Allow viewing all registered patients.

### **Appointment Management**
- Allow booking an appointment by selecting a doctor and a patient.
- Allow specifying appointment date and time.
- Check for schedule conflicts before booking.
- Allow viewing all scheduled appointments.
- Allow canceling an appointment.

### **System Interface**
- Provide a menu-driven console interface.
- Validate input and display error messages when needed.


## **Non-Functional Requirements**

### **Performance**
- The system should respond to user actions instantly (less than 1 second).  
- The system should handle up to 100 doctors, patients, and appointments in memory.

### **Usability**
- The user interface should be simple and easy to understand.  
- All actions should require no more than 4 or 5 steps.

### **Reliability**
- The system should prevent double-booking a doctor at the same time.

### **Portability**
- The system should run on any operating system that supports C++.

### **Maintainability**
- The source code should follow OOP standards and be modular.
