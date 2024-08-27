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
    myTrain.setSchedule(10, 30);
    myTrain.displaySchedule();

    Passenger passengers[3];

    passengers[0].setName("Bob");
    passengers[1].setName("Alice");
    passengers[2].setName("Charlie");

    for (int i = 0; i < 3; i++) {
        passengers[i].displayInfo();
    }

    Train* trainPointer = myTrain.getSchedulePointer();

    cout << "Memory address of Train object: " << trainPointer << endl;

    return 0;
}
