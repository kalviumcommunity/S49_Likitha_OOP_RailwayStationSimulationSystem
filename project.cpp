#include <iostream>
#include <string>
using namespace std;

class Train {
private:
    int scheduleHour;
    int scheduleMinute;

protected:
    string trainName;

public:
    void setSchedule(int hour, int minute) {
        scheduleHour = hour;
        scheduleMinute = minute;
    }

    void getSchedule() {
        cout << "Train Schedule: " << trainName << " " 
             << scheduleHour << ":" << (scheduleMinute < 10 ? "0" : "") << scheduleMinute << endl;
    }

    void setTrainName(string name) {
        trainName = name;
    }
};

class LuxuryTrain : public Train {
public:
    void displayLuxuryFeatures() {
        cout << trainName << " is a luxury train with premium features." << endl;
    }
};

class Passenger {
private:
    string name;

protected:
    int passengerID;

public:
    void setName(string passengerName) {
        name = passengerName;
    }

    void getName() {
        cout << "Passenger Name: " << name << " (ID: " << passengerID << ")" << endl;
    }

    void setPassengerID(int id) {
        passengerID = id;
    }
};

class VIPPassenger : public Passenger {
public:
    void displayVIPStatus() {
        cout << "VIP Passenger ID: " << passengerID << endl;
    }
};

int main() {
    Train train1;
    train1.setTrainName("Express");
    train1.setSchedule(14, 30);
    train1.getSchedule();

    LuxuryTrain luxuryTrain1;
    luxuryTrain1.setTrainName("Titan");
    luxuryTrain1.setSchedule(16, 45);
    luxuryTrain1.getSchedule();
    luxuryTrain1.displayLuxuryFeatures();

   

    Passenger passenger1;
    passenger1.setName("John Doe");
    passenger1.setPassengerID(1234);
    passenger1.getName();

    VIPPassenger vipPassenger;
    vipPassenger.setName("Jane Doe");
    vipPassenger.setPassengerID(5678);
    vipPassenger.getName();
    vipPassenger.displayVIPStatus();

    return 0;
}
