#include <iostream>
#include <iomanip>
#include <string>
#include <stdbool.h>
using namespace std;

class Calender {              
   public:
      _Bool isLeapYear(int year); 
      int getNumDaysInMonth(int year, int month);   
      int getStartDay(int year, int month);
      int leapYearCount(int currYear);  
      int getTotalNumDays(int year, int month);
      void setTitleMonth(int month);
      void setTitleYear(int year);
      void printCalender(int startDay, int daysInMonth);

    private:
      string titleMonth;
      int titleYear;
};

_Bool Calender::isLeapYear(int year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

int Calender::getNumDaysInMonth(int year, int month) {
    if (month == 2) {
        if (isLeapYear(year)) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else{
        return 31;
    }
}

int Calender::getStartDay(int year, int month) {
    int startDay1800 = 3; //Wednesday
    int totalNumDays = getTotalNumDays(year,month);

    if (isLeapYear(year)) return ((totalNumDays + startDay1800) % 7) - 1;
    else return (totalNumDays + startDay1800) % 7;
}

int Calender::leapYearCount(int currYear) {
    int leapYears = 0;
    for (int i = 1800; i <= currYear; i ++) {
        if (isLeapYear(i)) {
            leapYears += 1;
        }
    }
    return leapYears;
}

int Calender::getTotalNumDays(int year, int month) {
    int numTotalDays = 0;
    int numLeapYears = leapYearCount(year); 
    int numYearsTotal = year - 1800;
    int numNonLeapYears = numYearsTotal - numLeapYears;
    numTotalDays = 365 * numNonLeapYears + 366 * numLeapYears;
    if (month != 1) {
        for (int i = 1; i < month; i++) {
            numTotalDays += getNumDaysInMonth(year,i);
        }
    }

    return numTotalDays;
}

void Calender::setTitleMonth(int month) {
    if (month == 1) titleMonth = "January";
    else if (month == 2) titleMonth = "February";
    else if (month == 3) titleMonth = "March";
    else if (month == 4) titleMonth = "April";
    else if (month == 5) titleMonth = "May";
    else if (month == 6) titleMonth = "June";
    else if (month == 7) titleMonth = "July";
    else if (month == 8) titleMonth = "August";
    else if (month == 9) titleMonth = "September";
    else if (month == 10) titleMonth = "October";
    else if (month == 11) titleMonth = "November";
    else if (month == 12) titleMonth = "December";
}

void Calender::setTitleYear(int year) {
    titleYear = year;
}

void Calender::printCalender(int startDay, int daysInMonth) {
    if (titleMonth.size() > 5) cout << setw(18) << titleMonth << "  " << titleYear << endl;
    else cout << setw(16) << titleMonth << "  " << titleYear << endl;
    cout << "-----------------------------------" << endl;
    cout << " Sun" << "  " << "Mon" << "  " << "Tue" << "  " << "Wed" << "  " << "Thu" << "  " << "Fri" << "  " << "Sat" << endl;
    cout << setw(startDay * 5 + 2);
    string smallspace = " ";
    string medspace = "  ";
    string bigspace = "   ";
    for (int i = 1; i <= daysInMonth; i++) {
        if (((i+startDay) % 7 == 0 && i != 0) || ((i+startDay) % 7 == 0 && startDay == 6)) {
            if (i < 10) cout << smallspace << i << smallspace << endl;
            else if (i == 10) cout << i << smallspace << endl;
            else cout << smallspace << i << smallspace << endl;
        }
        else if ((i+startDay) % 7 == 1 && i < 10) {
            if (i + 1 < 10) cout << medspace << i << bigspace;
            else if (i + 1 == 10) cout << medspace << i << medspace;
            else cout << medspace << i << bigspace;
        }
        else if ((i+startDay) % 7 == 1 && i >= 10) {
            if (i == 10) cout << smallspace << i << medspace;
            else cout << smallspace << i << medspace;
        }
        else {
            if (i < 10) cout << smallspace << i << bigspace;
            else if (i == 10) cout << i << medspace;
            else cout << smallspace << i << medspace;
        }
    }
    cout << endl;
}

int main() {
    int year;
    int month;
    cout << "Enter a full year (e.g., 2001):" << endl;
    cin >> year;
    cout << "Enter a month in number between 1 and 12:" << endl;
    cin >> month;
    
    Calender newCalender;
    newCalender.setTitleMonth(month);
    newCalender.setTitleYear(year);
    int day = newCalender.getStartDay(year, month);
    int daysInMonth = newCalender.getNumDaysInMonth(year, month);
    newCalender.printCalender(day,daysInMonth);
}

