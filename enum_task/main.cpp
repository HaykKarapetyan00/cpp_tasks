#include <QCoreApplication>
#include <iostream>

enum DayOfWeek {
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

struct Date {
    int day;
    int month;
    int year;
};

void printDate(const Date& date, DayOfWeek dayOfWeek) {
    const char* dayNames[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    std::cout << "Day of the Week: " << dayNames[static_cast<int>(dayOfWeek)] << std::endl;
    std::cout << "Date: " << date.year << "-" << date.month << "-" << date.day << std::endl;
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    Date date = {2024, 23, 2};
    DayOfWeek dayOfWeek = DayOfWeek::Friday;

    printDate(date, dayOfWeek);

    return a.exec();
}
