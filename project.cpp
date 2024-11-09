#include <iostream>
#include <string>
using namespace std;

// Train class demonstrating Abstraction, Constructors, and Destructors
class Train {
private:
    int scheduleHour;
    int scheduleMinute;
    static int trainCount;

public:
    // Default Constructor
    Train() {
        scheduleHour = 0;
        scheduleMinute = 0;
        trainCount++;
        cout << "Train object created. Train count: " << trainCount << endl;
    }

    // Parameterized Constructor
    Train(int hour, int minute) {
        scheduleHour = hour;
        scheduleMinute = minute;
        trainCount++;
        cout << "Train object created with schedule " << hour << ":" << minute << ". Train count: " << trainCount << endl;
    }

    // Destructor
    ~Train() {
        trainCount--;
        cout << "Train object destroyed. Remaining trains: " << trainCount << endl;
    }

    void setSchedule(int hour, int minute) {
        this->scheduleHour = hour;
        this->scheduleMinute = minute;
    }

    void getSchedule() {
        cout << "Train is scheduled at " << scheduleHour << ":" << scheduleMinute << endl;
    }

    static int getTrainCount() {
        return trainCount;
    }
};

// Initialize static variable
int Train::trainCount = 0;

// Passenger class demonstrating Abstraction, Constructors, and Destructors
class Passenger {
private:
    string name;
    static int passengerCount;

public:
    // Default Constructor
    Passenger() {
        name = "Unknown";
        passengerCount++;
        cout << "Passenger object created. Passenger count: " << passengerCount << endl;
    }

    // Parameterized Constructor
    Passenger(string n) {
        name = n;
        passengerCount++;
        cout << "Passenger object created with name " << name << ". Passenger count: " << passengerCount << endl;
    }

    // Destructor
    ~Passenger() {
        passengerCount--;
        cout << "Passenger object destroyed. Remaining passengers: " << passengerCount << endl;
    }

    void setName(string n) {
        this->name = n;
    }

    string getName() {
        return name;
    }

    static int getPassengerCount() {
        return passengerCount;
    }

    void displayInfo() {
        cout << "Passenger Name: " << name << endl;
    }
};

// Initialize static variable
int Passenger::passengerCount = 0;

int main() {
    // Using Default Constructor and setting schedule
    Train* myTrain = new Train;
    myTrain->setSchedule(10, 30);
    myTrain->getSchedule();

    // Using Parameterized Constructor
    Train* expressTrain = new Train(8, 45);

    // Creating Passenger objects using both default and parameterized constructors
    Passenger* passengers = new Passenger[3];
    passengers[0].setName("Bob");
    passengers[1].setName("Alice");
    passengers[2].setName("Charlie");

    // Displaying passenger names
    for (int i = 0; i < 3; i++) {
        cout << passengers[i].getName() << endl;
    }

    // Display total train count
    cout << "Total number of trains: " << Train::getTrainCount() << endl;

    // Display total passenger count
    cout << "Total number of passengers: " << Passenger::getPassengerCount() << endl;

    // Clean up memory
    delete myTrain;
    delete expressTrain;
    delete[] passengers;

    return 0;
}
