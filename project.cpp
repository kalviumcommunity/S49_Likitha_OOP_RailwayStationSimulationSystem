#include <iostream>
#include <string>
using namespace std;

class Train {
private:
    int scheduleHour;
    int scheduleMinute;
public:
    void setSchedule(int hour, int minute) {
        this->scheduleHour = hour;
        this->scheduleMinute = minute;
    }

    void displaySchedule() {
        cout << "Train is scheduled at " << scheduleHour << ":" << scheduleMinute << endl;
    }

    Train* getSchedulePointer() {
        return this;
    }
};

class Passenger {
private:
    string name;
public:
    void setName(string n) {
        this->name = n;
    }

    void displayInfo() {
        cout << "Passenger Name: " << name << endl;
    }

    Passenger* getNamePointer() {
        return this;
    }
};

int main() {
    Train myTrain;
    Passenger passenger;

    myTrain.setSchedule(10, 30);
    myTrain.displaySchedule();

    passenger.setName("Bob");
    passenger.displayInfo();

    Train* trainPointer = myTrain.getSchedulePointer();
    Passenger* passengerPointer = passenger.getNamePointer();

    cout << "Memory address of Train object: " << trainPointer << endl;
    cout << "Memory address of Passenger object: " << passengerPointer << endl;

    return 0;
}
