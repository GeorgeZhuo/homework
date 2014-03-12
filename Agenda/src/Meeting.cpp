// 2013.09.02 Agenda Meeting.cpp
// zhuozhaojin 12330443

#include <iostream>
#include <string>
#include "Meeting.h"
#include "Date.h"

Meeting::Meeting() {
}
Meeting::Meeting(std::string sponsor, std::string participator,
                 Date startTime, Date endTime, std::string title)
    :startDate_(startTime), endDate_(endTime) {
    setSponsor(sponsor);
    setParticipator(participator);
    setTitle(title);
}
std::string Meeting::getSponsor(void) {
    return sponsor_;
}
void Meeting::setSponsor(std::string sponsor) {
    sponsor_ = sponsor;
}
std::string Meeting::getParticipator(void) {
    return participator_;
}
void Meeting::setParticipator(std::string participator) {
    participator_ = participator;
}
Date Meeting::getStartDate(void) {
    return startDate_;
}
void Meeting::setStartDate(Date startTime) {
    startDate_ = startTime;
}
Date Meeting::getEndDate(void) {
    return endDate_;
}
void Meeting::setEndDate(Date endTime) {
    endDate_ = endTime;
}
std::string Meeting::getTitle(void) {
    return title_;
}
void Meeting::setTitle(std::string title) {
    title_ = title;
}
