// 2013.09.02 Agenda MeetingManage.h
// zhuozhaojin 12330443

#include "MeetingManage.h"
#include "Meeting.h"
#include <string>
#include <list>

bool MeetingManage::instanceFlag_ = false;
MeetingManage* MeetingManage::instance_ = NULL;

MeetingManage::MeetingManage() {
}
MeetingManage::~MeetingManage() {
    instanceFlag_ = false;
}
MeetingManage* MeetingManage::getInstance() {
    if (!instanceFlag_) {
        instance_ = new MeetingManage();
        instanceFlag_ = true;
        return instance_;
    } else {
        return instance_;
    }
}
void MeetingManage::initMeetingsList(std::list<Meeting> meetings) {
    meetings_ = meetings;
}
std::list<Meeting> MeetingManage::acquireMeetingsList(void) {
    return meetings_;
}
bool MeetingManage::addMeeting(std::string sponsor, std::string
			       participator, Date stime, Date etime,
			       std::string title) {
    std::list<Meeting>::iterator it;
    for (it = meetings_.begin(); it != meetings_.end(); it++) {
	if ( it->getTitle() == title )
	    return false;
	if (it->getSponsor() == sponsor || it->getParticipator()
	    == participator) {
	    if (stime < it->getEndDate())
		return false;
	}
    }
    if (stime > etime)
	return false;
    if (!Date::isValid(stime) || !Date::isValid(etime))
	return false;
    Meeting meeting(sponsor, participator, stime, etime, title);
    meetings_.push_back( meeting);
    return true;
}
bool MeetingManage::deleteMeeting(std::string userName, std::string title) {
    std::list<Meeting>::iterator it;
    for (it = this->meetings_.begin(); it != this->meetings_.end(); it++) {
	if ( it->getSponsor() == userName && it->getTitle() == title ) {
	    meetings_.erase(it);
	    return true;
	}
    }
    return false;
}
bool MeetingManage::deleteAllMeetings(std::string userName) {
    int flag = 0;
    std::list<Meeting>::iterator it;
    for (it = meetings_.begin(); it != meetings_.end();) {
	if (it->getSponsor() == userName) {
	    it = meetings_.erase(it);
	    flag++;
	} else {
	    it++;
	}
    }
    if ( flag != 0 )
	return true;
    else
	return false;
}
bool MeetingManage::updateMeetingParticipator(std::string title,
					      std::string newParticipator) {
     int flag = 0;
     std::list<Meeting>::iterator it;
    for (it = this->meetings_.begin(); it != this->meetings_.end(); it++) {
	if ( it->getTitle() == title ) {
	    it->setParticipator(newParticipator);
	    flag++;
	}
    }
    if ( flag != 0 )
	return true;
    else
	return false;
}
bool MeetingManage::updateMeetingStartDate(std::string title,
					   Date newStartDate) {
    int flag = 0;
    std::list<Meeting>::iterator it;
    for (it = this->meetings_.begin(); it != this->meetings_.end(); it++) {
	if ( it->getTitle() == title ) {
	    if (newStartDate >= it->getEndDate())
		return false;
	    it->setStartDate(newStartDate);
	    flag++;
	}
    }
    if ( flag != 0 )
	return true;
    else
	return false;
}
bool MeetingManage::updateMeetingEndDate(std::string title,
					   Date newEndDate) {
    int flag = 0;
    std::list<Meeting>::iterator it;
    for (it = this->meetings_.begin(); it != this->meetings_.end(); it++) {
	if ( it->getTitle() == title ) {
	    if (newEndDate >= it->getStartDate())
		return false;
	    it->setEndDate(newEndDate);
	    flag++;
	}
    }
    if ( flag != 0 )
	return true;
    else
	return false;
}
Meeting* MeetingManage::queryMeetingByTitle(std::string title) {
    std::list<Meeting>::iterator it;
    for (it = this->meetings_.begin(); it != this->meetings_.end(); it++)
	if( it->getTitle() == title )
	    return &(*it);
}
std::list<Meeting> MeetingManage::queryMeetingsByTime(std::string userName,
                                         Date stime, Date etime) {
    std::list<Meeting> record;
    std::list<Meeting>::iterator it;
    for (it = this->meetings_.begin(); it != this->meetings_.end(); it++) {
	if (it->getSponsor() == userName || it->getParticipator() 
	    == userName) {
	    if (!(stime > it->getEndDate() || etime < it->getStartDate()))
		record.push_back(*it);
	}
    }
    return record;
}
std::list<Meeting> MeetingManage::listAllMeetings(std::string userName) {
    std::list<Meeting> record;
    std::list<Meeting>::iterator it;
    for (it = this->meetings_.begin(); it != this->meetings_.end(); it++) {
	if (it->getSponsor() == userName || it->getParticipator() == userName)
	   record.push_back(*it);
    }
    return record;
}
std::list<Meeting> MeetingManage::listAllSponsorMeetings(std::string userName) {
    std::list<Meeting> record;
    std::list<Meeting>::iterator it;
    for (it = this->meetings_.begin(); it != this->meetings_.end(); it++) {
	if (it->getSponsor() == userName)
	   record.push_back(*it);
    }
    return record;
}
std::list<Meeting> MeetingManage::listAllParticipateMeetings
(std::string userName) {
    std::list<Meeting> record;
    std::list<Meeting>::iterator it;
    for (it = this->meetings_.begin(); it != this->meetings_.end(); it++) {
	if (it->getParticipator() == userName)
	   record.push_back(*it);
    }
    return record;
}
