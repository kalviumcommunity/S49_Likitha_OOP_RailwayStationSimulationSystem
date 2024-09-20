#include <iostream>
#include <string>
using namespace std;

class Train {
private:
    int scheduleHour;
    int scheduleMinute;
    static int trainCount;  // Static variable to keep track of train instances

public:
    Train() {
        trainCount++;  // Increment count when a new train is created
    }

    void setSchedule(int hour, int minute) {
        this->scheduleHour = hour;
        this->scheduleMinute = minute;
    }

    void displaySchedule() {
        cout << "Train is scheduled at " << scheduleHour << ":" << scheduleMinute << endl;
    }

    static int getTrainCount() {  // Static method to access the static variable
        return trainCount;
    }
};

// Initialize static variable
int Train::trainCount = 0;

class Passenger {
private:
    string name;
    static int passengerCount;  // Static variable to keep track of passenger instances

public:
    Passenger() {
        passengerCount++;  // Increment count when a new passenger is created
    }

    void setName(string n) {
        this->name = n;
    }

    void displayInfo() {
        cout << "Passenger Name: " << name << endl;
    }

    static int getPassengerCount() {  // Static method to access the static variable
        return passengerCount;
    }
};

// Initialize static variable
int Passenger::passengerCount = 0;

int main() {
    Train* myTrain = new Train;
    myTrain->setSchedule(10, 30);
    myTrain->displaySchedule();

    Passenger* passengers = new Passenger[3];

    passengers[0].setName("Bob");
    passengers[1].setName("Alice");
    passengers[2].setName("Charlie");

    for (int i = 0; i < 3; i++) {
        passengers[i].displayInfo();
    }

    cout << "Total number of trains: " << Train::getTrainCount() << endl;
    cout << "Total number of passengers: " << Passenger::getPassengerCount() << endl;

    delete myTrain;      
    delete[] passengers;  

    return 0;
}
