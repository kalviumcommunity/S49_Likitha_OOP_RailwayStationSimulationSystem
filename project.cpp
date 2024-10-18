#include <iostream>
#include <string>
using namespace std;

// Train class
class Train {
private:
    int scheduleHour;   // Private members (not accessible directly)
    int scheduleMinute;

protected:
    string trainName;  // Protected member, accessible in derived classes

public:
    // Public setter method to set train schedule
    void setSchedule(int hour, int minute) {
        scheduleHour = hour;
        scheduleMinute = minute;
    }

    // Public getter method to display train schedule
    void getSchedule() {
        cout << "Train Schedule: " << trainName << " " 
             << scheduleHour << ":" << (scheduleMinute < 10 ? "0" : "") << scheduleMinute << endl;
    }

    // Public method to set the train name (protected member)
    void setTrainName(string name) {
        trainName = name;
    }
};

// Passenger class
class Passenger {
private:
    string name;  // Private member

protected:
    int passengerID;  // Protected member, accessible in derived classes

public:
    // Public setter method to set passenger name
    void setName(string passengerName) {
        name = passengerName;
    }

    // Public getter method to display passenger name
    void getName() {
        cout << "Passenger Name: " << name << " (ID: " << passengerID << ")" << endl;
    }

    // Public setter for protected passengerID
    void setPassengerID(int id) {
        passengerID = id;
    }
};

// Derived class showing protected inheritance (optional to demonstrate inheritance and abstraction)
class VIPPassenger : public Passenger {
public:
    void displayVIPStatus() {
        cout << "VIP Passenger ID: " << passengerID << endl; // Accessing protected member from base class
    }
};

int main() {
    // Create Train object
    Train train1;
    train1.setTrainName("Express");  // Setting train name (protected member)
    train1.setSchedule(14, 30);      // Setting train schedule
    train1.getSchedule();            // Displaying train schedule

    // Create Passenger object
    Passenger passenger1;
    passenger1.setName("John Doe");  // Setting passenger name
    passenger1.setPassengerID(1234); // Setting passenger ID (protected member via public method)
    passenger1.getName();            // Displaying passenger details

    // Create VIPPassenger object (demonstrates protected inheritance)
    VIPPassenger vipPassenger;
    vipPassenger.setName("Jane Doe");
    vipPassenger.setPassengerID(5678);
    vipPassenger.displayVIPStatus(); // Displaying VIP status

    return 0;
}
