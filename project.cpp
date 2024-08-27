#include <iostream>
#include <string>
using namespace std;

class Train {
    private:
    int scheduleHour;
    int scheduleMinute;
public:
    void setSchedule(int hour, int minute) {
        scheduleHour = hour;
        scheduleMinute = minute;
    }

    void displaySchedule() {
        cout << "Train is scheduled at " << scheduleHour << ":" << scheduleMinute << endl;
    }
};

class Passenger {
private:
    string name;
public:
    void setName(string n) {
        name = n;
    }

    void displayInfo() {
        cout << "Passenger Name: " << name << endl;
    }
};

int main() {
    Train myTrain;
    Passenger passenger;

    myTrain.setSchedule(10, 30);
    myTrain.displaySchedule();

    passenger.setName("Bob");
    passenger.displayInfo();

    return 0;
}