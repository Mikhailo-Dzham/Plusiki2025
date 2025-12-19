#include <iostream>
#include <cmath>

using namespace std;

// ==========================
// Class: Time
// ==========================
class Time {
private:
    int hours;
    int minutes;
    int seconds;

    // Helper to convert time to total seconds
    long toSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

public:
    // Constructor
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // Method to find difference in seconds
    // Returns the absolute difference in seconds
    long difference(const Time& other) const {
        long t1 = this->toSeconds();
        long t2 = other.toSeconds();
        return abs(t1 - t2);
    }

    void print() const {
        printf("%02d:%02d:%02d", hours, minutes, seconds);
    }
};

// ==========================
// Class: Date
// ==========================
// "Defined only once" -> Interpreted as Immutable (values set once) 
// and standard class definition structure.
class Date {
private:
    const int year;
    const int month;
    const int day;

    // Helper: count days from a hypothetical year 0
    // Simplified logic (ignoring complex historical leap year anomalies)
    long toDays() const {
        long totalDays = year * 365 + day;

        // Add days for months in current year
        int daysInMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i = 1; i < month; ++i) {
            totalDays += daysInMonths[i];
        }

        // Add leap days for past years
        // (Approximation: +1 day for every 4th year, -100th, +400th)
        totalDays += countLeapYears(year, month);
        
        return totalDays;
    }

    int countLeapYears(int y, int m) const {
        if (m <= 2) y--; // If current year is leap but month is Jan/Feb, don't include this year's leap day
        return y / 4 - y / 100 + y / 400;
    }

public:
    // Constructor (sets values once)
    Date(int y, int m, int d) : year(y), month(m), day(d) {}

    // Method to find difference in days
    long difference(const Date& other) const {
        long d1 = this->toDays();
        long d2 = other.toDays();
        return abs(d1 - d2);
    }

    void print() const {
        printf("%04d-%02d-%02d", year, month, day);
    }
};

// ==========================
// Main Function
// ==========================
int t15_8() {
    // 1. Test Time
    Time t1(10, 30, 0);
    Time t2(12, 45, 15);

    cout << "Time 1: "; t1.print(); cout << endl;
    cout << "Time 2: "; t2.print(); cout << endl;
    cout << "Difference (seconds): " << t1.difference(t2) << endl;
    
    // Formatting helper
    long diffSec = t1.difference(t2);
    int h = diffSec / 3600;
    int m = (diffSec % 3600) / 60;
    int s = diffSec % 60;
    cout << "Difference (formatted): " << h << "h " << m << "m " << s << "s" << endl;
    cout << "------------------------" << endl;

    // 2. Test Date
    Date d1(2023, 1, 1);
    Date d2(2023, 12, 31);

    cout << "Date 1: "; d1.print(); cout << endl;
    cout << "Date 2: "; d2.print(); cout << endl;
    cout << "Difference (days): " << d1.difference(d2) << endl;

    return 0;
}