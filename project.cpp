#include <iostream>
#include <string>
using namespace std;

// Abstract class defining an interface for schedule-related operations.
// This adheres to OCP by allowing new types of TrainInfo implementations without modifying this class.
class TrainInfo {
public:
    virtual void displayScheduleDetails() = 0;  // Ensures flexibility for extended behavior.
};

// Base Train class defines core train functionality.
// It is open for extension (can be inherited) but closed for modification of its existing methods.
class Train : public TrainInfo {
private:
    int scheduleHour;  // Encapsulates schedule details
    int scheduleMinute;

protected:
    string trainName;  // Allows derived classes to use trainName for extension.

public:
    // Allows setting the train's schedule. Does not need to be modified for additional train types.
    void setSchedule(int hour, int minute) {
        scheduleHour = hour;
        scheduleMinute = minute;
    }

    // Overloaded schedule setter ensures additional flexibility without altering the existing method.
    void setSchedule(int hour) {
        scheduleHour = hour;
        scheduleMinute = 0;
    }

    // Displays the schedule in a standard format. It is closed for modification.
    void getSchedule() {
        cout << "Train Schedule: " << trainName << " " 
             << scheduleHour << ":" << (scheduleMinute < 10 ? "0" : "") << scheduleMinute << endl;
    }

    // Sets the name of the train. Core functionality remains unchanged.
    void setTrainName(string name) {
        trainName = name;
    }

    // Implements the abstract function, ensuring adherence to the TrainInfo interface.
    void displayScheduleDetails() override {
        cout << "Train Name: " << trainName << ", Scheduled Time: "
             << scheduleHour << ":" << (scheduleMinute < 10 ? "0" : "") << scheduleMinute << endl;
    }

    // Provides a basic train feature. Open for overriding by derived classes for extended behavior.
    virtual void showFeatures() {
        cout << "Basic train features for " << trainName << "." << endl;
    }
};

// LuxuryTrain class extends the Train class to add specific features for luxury trains.
// It adheres to OCP by extending the functionality without altering the base Train class.
class LuxuryTrain : public Train {
public:
    // Overrides the showFeatures method to introduce additional behavior.
    void showFeatures() override {
        cout << trainName << " is a luxury train with premium features." << endl;
    }
};
