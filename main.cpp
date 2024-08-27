#include <iostream>
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
        cout << "Train scheduled at " << scheduleHour << ":" << scheduleMinute << endl;
    }


};

class Passenger {
public:
    void setName(string n) {
        name = n;
    }

    void displayInfo() {
        cout << "Passenger Name: " << name << endl;
    }

private:
    string name;
};

int main() {
    Train myTrain;
    Passenger passenger;

    myTrain.setSchedule(10, 30);
    myTrain.displaySchedule();

    passenger.setName("Alice");
    passenger.displayInfo();

    return 0;
}
