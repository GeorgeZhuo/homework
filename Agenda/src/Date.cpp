// 2013.09.02 Agenda Date.cpp
// zhuozhaojin 12330443

#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Date.h"

Date::Date() {
}
Date::Date(int year, int month, int day, int hour, int minute) {
    setYear(year);
    setMonth(month);
    setDay(day);
    setHour(hour);
    setMinute(minute);
}
int Date::getYear(void) const {
    return year_;
}
void Date::setYear(int year) {
    year_ = year;
}
int Date::getMonth(void) const {
    return month_;
}
void Date::setMonth(int month) {
    month_ = month;
}
int Date::getDay(void) const {
    return day_;
}
void Date::setDay(int day) {
    day_ = day;
}
int Date::getHour(void) const {
    return hour_;
}
void Date::setHour(int hour) {
    hour_ = hour;
}

int Date::getMinute(void) const {
    return minute_;
}
void Date::setMinute(int minute) {
    minute_ = minute;
}
bool Date::isValid(Date date) {
    if (date.getYear() < 1000 || date.getYear() > 9999)
	return false;
    if (date.getMonth() < 1 || date.getMonth() > 12)
	return false;

    static const int daysPerMonth[13] =
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (date.getMonth() == 2 && date.getDay() == 29 &&
	(date.getYear() % 400 == 0 || (date.getYear()
	% 4 == 0 && date.getYear() % 100 != 0)));
    else if (date.getDay() <= 0 || date.getDay() >
	     daysPerMonth[date.getMonth()])
	return false;

    if (date.getHour() < 0 || date.getHour() > 24)
	return false;
    if (date.getMinute() < 0 || date.getMinute() > 60)
	return false;

    return true;
}
Date Date::stringToDate(std::string dateString) {
    int year = (dateString[0] - 48) * 1000 + (dateString[1] - 48) * 100
	+ (dateString[2] - 48) * 10 + dateString[3] - 48;
    int month = (dateString[5] - 48) * 10 + dateString[6] - 48;
    int day = (dateString[8] - 48) * 10 + dateString[9] - 48;
    int hour = (dateString[11] - 48) * 10 + dateString[12] - 48;
    int minute = (dateString[14] - 48) * 10 + dateString[15] -48;

    return Date(year, month, day, hour, minute);
}
std::string Date::dateToString(Date date) {
    std::string stringDate;
    char temp[5];
    sprintf(temp, "%d", date.getYear());
    stringDate = temp;
    stringDate +=(date.getMonth() < 10?"-0" : "-");
    sprintf(temp, "%d", date.getMonth());
    stringDate += temp;
    stringDate +=(date.getDay() < 10 ? "-0" : "-");
    sprintf(temp, "%d", date.getDay());
    stringDate += temp;
    stringDate += (date.getHour() < 10 ? "/0" : "/");
    sprintf(temp, "%d", date.getHour());
    stringDate += temp;
    stringDate += (date.getMinute() < 10 ? ":0" : ":");
    sprintf(temp, "%d", date.getMinute());
    stringDate += temp;
 
    return stringDate;
}
Date& Date::operator=(const Date &date) {
    this->year_ = date.year_;
    this->month_ = date.month_;
    this->day_ = date.day_;
    this->hour_ = date.hour_;
    this->minute_ = date.minute_;
}

bool Date::operator==(const Date& date) const {
    if (this->year_ == date.year_ && this->month_ == date.month_
	&& this->day_ == date.day_ && this->hour_ == date.hour_
	&& this->minute_ == date.minute_)
	return true;
    else
	return false;
}
bool Date::operator>(const Date& date) const {
    if (this->year_ > date.year_)
	return true;
    else if (this->year_ < date.year_)
	return false;
    else if (this->year_ == date.year_) {
	if (this->month_ > date.month_)
	    return true;
	else if (this->month_ < date.month_)
	    return false;
	else if (this->month_ == date.month_) {
	    if (this->day_ > date.day_)
		return true;
	    else if (this->day_ < date.day_)
		return false;
	    else if (this->day_ == date.day_) {
		if (this->hour_ > date.hour_)
		    return true;
		else if (this->hour_ < date.hour_)
		    return false;
		else if (this->hour_ == date.hour_) {
		    if (this->minute_ > date.minute_)
			return true;
		    else
			return false;
		}
	    }
	}
    }
}
bool Date::operator<(const Date& date) const {
    if (this->year_ > date.year_)
	return false;
    else if (this->year_ < date.year_)
	return true;
    else if (this->year_ == date.year_) {
	if (this->month_ > date.month_)
	    return false;
	else if (this->month_ < date.month_)
	    return true;
	else if (this->month_ == date.month_) {
	    if (this->day_ > date.day_)
		return false;
	    else if (this->day_ < date.day_)
		return true;
	    else if (this->day_ == date.day_) {
		if (this->hour_ > date.hour_)
		    return false;
		else if (this->hour_ < date.hour_)
		    return true;
		else if (this->hour_ == date.hour_) {
		    if (this->minute_ > date.minute_)
			return false;
		    else
			return true;
		}
	    }
	}
    }
}
bool Date::operator>=(const Date& date) const {
    if (this->year_ < date.year_) {
	return false;
    } else {
	if (this->month_ < date.month_) {
	    return false;
	} else {
	    if (this->day_ < date.day_) {
		return false;
	    } else {
		if (this->hour_ < date.hour_) {
		    return false;
		} else {
		    if (this->minute_ < date.minute_)
			return false;
		    else
			return true;
		}
	    }
	}
    }
}
bool Date::operator<=(const Date& date) const {
    if (this->year_ > date.year_) {
	return false;
    } else {
	if  (this->month_ > date.month_) {
	    return false;
	} else {
	    if (this->day_ > date.day_) {
		return false;
	    } else {
		if (this->hour_ > date.hour_) {
		    return false;
		} else {
		    if (this->minute_ > date.minute_)
			return false;
		    else
			return true;
		}
	    }
	}
    }
}
