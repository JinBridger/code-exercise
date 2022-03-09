#include <iostream>
using namespace std;


class Date {
    public:
    Date(int y, int m, int d): year(y), month((m >= 1 && m <=12)?m:1), day(d) {}
    Date() {}

    void setYear(int newYear) {year = newYear;}
    void setMonth(int newMonth) {month = newMonth;}
    void setDay(int newDay) {day = newDay;}

    int getYear() {return year;}
    int getMonth() {return month;}
    int getDay() {return day;}

    void displayDate() {
        cout << month << "/" << day << "/" << year << endl;
    }

    private:
    int year, month, day;
};
int main() {
    Date a(2021, 12, 2);
    a.displayDate();
    return 0;
}