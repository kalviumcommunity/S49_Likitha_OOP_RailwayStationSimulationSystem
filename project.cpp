#include <iostream>
#include <string>
using namespace std;

// Interface for scheduling operations
class Schedule {
public:
    virtual void setSchedule(int hour, int minute) = 0;
    virtual void setSchedule(int hour) = 0;
    virtual void getSchedule() = 0;
    virtual ~Schedule() = default;
};

// Interface for train details
class TrainDetails {
public:
    virtual void setTrainName(string name) = 0;
    virtual void displayTrainName() = 0;
    virtual ~TrainDetails() = default;
};

// Interface for additional train features
class TrainFeatures {
public:
    virtual void showFeatures() = 0;
    virtual ~TrainFeatures() = default;
};

// Train class implements only the required interfaces.
class Train : public Schedule, public TrainDetails, public TrainFeatures {
protected:
    int scheduleHour;  // Encapsulates schedule details
    int scheduleMinute;
    string trainName;

public:
    // Implementing methods from Schedule
    void setSchedule(int hour, int minute) override {
        scheduleHour = hour;
        scheduleMinute = minute;
    }

    void setSchedule(int hour) override {
        scheduleHour = hour;
        scheduleMinute = 0;
    }

    void getSchedule() override {
        cout << "Train Schedule: " << trainName << " "
             << scheduleHour << ":" << (scheduleMinute < 10 ? "0" : "") << scheduleMinute << endl;
    }

    // Implementing methods from TrainDetails
    void setTrainName(string name) override {
        trainName = name;
    }

    void displayTrainName() override {
        cout << "Train Name: " << trainName << endl;
    }

    // Implementing methods from TrainFeatures
    void showFeatures() override {
        cout << "Basic train features for " << trainName << "." << endl;
    }
};

// LuxuryTrain class implements the same interfaces but extends functionality
class LuxuryTrain : public Train {
public:
    void showFeatures() override {
        cout << trainName << " is a luxury train with premium features." << endl;
    }
};
