#include <iostream>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <chrono>
#include <numeric>
#include <time.h>

using namespace std;

const unsigned long MIN = 60;
const unsigned long HOUR = MIN * 60;
const unsigned long DAY = 24 * HOUR;


void print_title(string title);
void getBirthDate(int& day, int& month, int& year);
unsigned long ageToSeconds(int day, int month, int year);
unsigned numberOfDaysInYear(int year);
bool isLeapYear(int year);

int main()
{
    print_title("Calculate age in seconds");
    int day{}, month{}, year{};
    getBirthDate(day, month, year);
    unsigned long age_in_seconds = ageToSeconds(day, month, year);
    cout << "Your age in seconds = " << age_in_seconds << "\n";
    return 0;
}

void print_title(string title)
{
    cout << "\n    #    " << title << "    #\n\n";
}

void getBirthDate(int& day, int& month, int& year)
{
    cout << "Type in your date of birth (dd-mm-yyyy): ";
    string line{};
    cin >> line;
    vector<string> date{};
    boost::split(date, line, boost::is_any_of("-"));

    if(date.size() != 3)
    {
        cout << "Date you provided does not contain 3 numbers or have bad separator\n";
        std::runtime_error("Wrong arguments number");
    }

    try {
        day = boost::lexical_cast<int>(date[0]);
        month = boost::lexical_cast<int>(date[1]);
        year = boost::lexical_cast<int>(date[2]);
    } catch (...) {
        cout << "Error while casting numbers\n";
    }

}

unsigned long ageToSeconds(int day, int month, int year)
{
    vector<unsigned> month_days {31,28,31,30,31,30,31,31,30,31,30,31};

    auto now = chrono::system_clock::now();
    time_t tt = chrono::system_clock::to_time_t(now);

    tm local_tm = *localtime(&tt);

    auto c_year = local_tm.tm_year + 1900;
    auto c_month = local_tm.tm_mon + 1;
    auto c_day = local_tm.tm_mday;

    unsigned days{};

    for (int i = year+1; i < c_year; i++)
    {
        days += numberOfDaysInYear(i);
    }

    days = std::accumulate(month_days.begin(), month_days.begin()+c_month-1, days);
    days += static_cast<unsigned int>(c_day);

    days = std::accumulate(month_days.end()-(12-month), month_days.end(), days);
    days += month_days[static_cast<unsigned long>(month-1)] - static_cast<unsigned int>(day);

    if(isLeapYear(c_year) && c_month > 2)
        days += 1;
    else if (isLeapYear(year) && month <= 2)
        days += 1;

    unsigned long seconds = days * DAY;
    seconds += static_cast<unsigned int>(local_tm.tm_hour) * HOUR;
    seconds += static_cast<unsigned int>(local_tm.tm_min) * MIN;
    seconds += static_cast<unsigned int>(local_tm.tm_sec);

    return seconds;
}

unsigned numberOfDaysInYear(int year)
{
    if (isLeapYear(year))
        return 366u;
    else {
        return 365u;
    }
}

bool isLeapYear(int year)
{
    if((year%4==0) && (year%100!=0))
        return true;
    else if((year%100==0) && (year%400==0))
        return true;
    else if(year%400==0)
        return true;
    else
        return false;
}
