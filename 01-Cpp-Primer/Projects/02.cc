/*
# P-1.2
Write a C++ program that, when given a starting day (Sunday through
Saturday) as a string, and a four-digit year, prints a calendar for that year.
Each month should contain the name of the month, centered over the dates
for that month and a line containing the names of the days of the week,
running from Sunday to Saturday. Each week should be printed on a separate 
line. Be careful to check for a leap year.
*/

#include <iostream>
#include <iomanip>
#include <string>

void printMonth(int days, int startDay)
{
    std::cout << " S  M  T  W  T  F  S \n";

    int counter = startDay;
    
    for (int i = (startDay); i > 0; i--)
        std::cout << "   ";

    for (int i = 1; i <= days; i++)
    {
        std::cout << std::setw(2) << std::setfill('0') << i << " ";

        if (counter == 6)
            std::cout << "\n";
        counter = (counter + 1) % 7;
    }
    std::cout << "\n\n";
}

bool isLeapYear(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return true;
            }   
            else 
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    } 
    else
    {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    int year, startDay;
    std::string day;

    std::cout << "Enter Year: ";
    std::cin >> year;

    std::cout << "Enter Start Day: ";
    std::cin >> day;

    if (day == "sunday")
        startDay = 0;
    else if (day == "monday")
        startDay = 1;
    else if (day == "tuesday")
        startDay = 2;
    else if (day == "wednesday")
        startDay = 3;
    else if (day == "thursday")
        startDay = 4;
    else if (day == "friday")
        startDay = 5;
    else if (day == "saturday")
        startDay = 6;
    else 
        std::cout << "Invalid day input." << std::endl;


    std::cout << "Calander of Year: " << year;
    std::cout << "\n\nJanuary\n" ;
    printMonth(31, startDay);
    startDay = (startDay + 31) % 7;

    std::cout << "February\n" ;
    printMonth((isLeapYear(year) ? 29 : 28), startDay);
    startDay = (startDay + (isLeapYear(year) ? 29 : 28)) % 7;

    std::cout << "March\n" ;
    printMonth(31, startDay);
    startDay = (startDay + 31) % 7;

    std::cout << "April\n" ;
    printMonth(30, startDay);
    startDay = (startDay + 30) % 7;

    std::cout << "May\n" ;
    printMonth(31, startDay);
    startDay = (startDay + 31) % 7;

    std::cout << "June\n" ;
    printMonth(30, startDay);
    startDay = (startDay + 31) % 7;

    std::cout << "July\n" ;
    printMonth(31, startDay);
    startDay = (startDay + 31) % 7;

    std::cout << "August\n" ;
    printMonth(31, startDay);
    startDay = (startDay + 31) % 7;

    std::cout << "September\n" ;
    printMonth(30, startDay);
    startDay = (startDay + 30) % 7;

    std::cout << "October\n" ;
    printMonth(31, startDay);
    startDay = (startDay + 31) % 7;

    std::cout << "November\n" ;
    printMonth(30, startDay);
    startDay = (startDay + 30) % 7;

    std::cout << "December\n" ;
    printMonth(31, startDay);
    startDay = (startDay + 31) % 7;

    return 0;
}

