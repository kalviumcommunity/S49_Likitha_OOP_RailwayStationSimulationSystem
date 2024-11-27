#include <iostream>
#include <string>
using namespace std;

// Abstract class with a pure virtual function


// The TrainInfo class is responsible solely for defining the interface for schedule-related operations.
class TrainInfo {
public:
    virtual void displayScheduleDetails() = 0;  // Pure virtual function
};

// The Train class is responsible for handling train details such as name, schedule, and basic features.
class Train : public TrainInfo {
private:
    int scheduleHour;  // Stores the hour of the train's schedule
    int scheduleMinute;  // Stores the minutes of the train's schedule

protected:
    string trainName;  // Stores the train's name

public:
    // The setSchedule function is responsible for assigning schedule time.
    void setSchedule(int hour, int minute) {
        scheduleHour = hour;
        scheduleMinute = minute;
    }

    // Overloaded function to set schedule with only hour; defaults minute to 0.
    void setSchedule(int hour) {
        scheduleHour = hour;
        scheduleMinute = 0;
    }

    // The getSchedule function is responsible for retrieving the schedule in a formatted string.
    void getSchedule() {
        cout << "Train Schedule: " << trainName << " " 
             << scheduleHour << ":" << (scheduleMinute < 10 ? "0" : "") << scheduleMinute << endl;
    }

    // The setTrainName function is responsible for assigning a name to the train.
    void setTrainName(string name) {
        trainName = name;
    }

    // The displayScheduleDetails function is overridden to meet the interface defined by TrainInfo.
    void displayScheduleDetails() override {
        cout << "Train Name: " << trainName << ", Scheduled Time: "
             << scheduleHour << ":" << (scheduleMinute < 10 ? "0" : "") << scheduleMinute << endl;
    }

    // The showFeatures function is responsible for providing basic features of the train.
    virtual void showFeatures() {
        cout << "Basic train features for " << trainName << "." << endl;
    }
};

// The LuxuryTrain class adds additional features and overrides functionality specific to luxury trains.
class LuxuryTrain : public Train {
public:
    void showFeatures() override {
        cout << trainName << " is a luxury train with premium features." << endl;
    }
};
