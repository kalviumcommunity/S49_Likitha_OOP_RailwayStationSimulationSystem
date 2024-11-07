#include <iostream>
#include <string>
using namespace std;

// Abstract class with a pure virtual function
class TrainInfo {
public:
    virtual void displayScheduleDetails() = 0;  // Pure virtual function
};

class Train : public TrainInfo {
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

    void setSchedule(int hour) {
        scheduleHour = hour;
        scheduleMinute = 0;
    }

    void getSchedule() {
        cout << "Train Schedule: " << trainName << " " 
             << scheduleHour << ":" << (scheduleMinute < 10 ? "0" : "") << scheduleMinute << endl;
    }

    void setTrainName(string name) {
        trainName = name;
    }

    // Override the pure virtual function from TrainInfo
    void displayScheduleDetails() override {
        cout << "Train Name: " << trainName << ", Scheduled Time: "
             << scheduleHour << ":" << (scheduleMinute < 10 ? "0" : "") << scheduleMinute << endl;
    }

    virtual void showFeatures() {
        cout << "Basic train features for " << trainName << "." << endl;
    }
};

class LuxuryTrain : public Train {
public:
    void showFeatures() override {
        cout << trainName << " is a luxury train with premium features." << endl;
    }
};

int main() {
    Train train1;
    train1.setTrainName("Express");
    train1.setSchedule(14, 30);
    train1.displayScheduleDetails();
    train1.showFeatures();

    LuxuryTrain luxuryTrain1;
    luxuryTrain1.setTrainName("Titan");
    luxuryTrain1.setSchedule(16, 45);
    luxuryTrain1.displayScheduleDetails();
    luxuryTrain1.showFeatures();

    return 0;
}
