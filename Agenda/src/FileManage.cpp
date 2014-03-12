//  2013.09.04 Agenda FileManage.cpp
// zhuozhaojin 12330443

#include "FileManage.h"
#include <string>
#include <list>
#include <fstream>
#include <iostream>

FileManage* FileManage::instance_ = NULL;
bool FileManage::instanceFlag_ = false;

FileManage::FileManage()
    :userFileName_("user.dat"), meetingFileName_("meeting.dat") {
}
FileManage::~FileManage() {
    instanceFlag_ = false;
}
FileManage* FileManage::getInstance(void) {
     if (!instanceFlag_) {
        instance_ = new FileManage();
        instanceFlag_ = true;
        return instance_;
    }
   else {
        return instance_;
    }
}
std::list<User> FileManage::readUsersFromFile(void) {
    std::list<User> users;
    std::string userName;
    std::string password;
    std::string email;
    std::string phone;

    std::fstream userFile;
    userFile.open("user.dat", std::fstream::in);
    if (userFile.is_open()) {
	while (!userFile.eof()) {
	    userFile >> userName >> password >> email >> phone;
	    User user(userName, password, email, phone);
	    users.push_back(user);
	}        
    }
    userFile.close();
    return users;
}
void FileManage::writeUsersToFile(std::list<User> users) {
    std::fstream userFile;
    userFile.open("user.dat", std::fstream::out);
    std::list<User>::iterator iter;
    if (userFile.is_open()) {
	for (iter = users.begin(); iter != users.end(); iter++) {
	    userFile << iter->getName() << " " << iter->getPassword() 
		     << " " << iter->getEmail() << " " 
		     << iter->getPhone() << "\n";
	}
    }
    userFile.close();
}
std::list<Meeting> FileManage::readMeetingsFromFile(void) {
    std::list<Meeting> meetings;
    std::string sponsor;
    std::string participator;
    std::string sDate;
    std::string eDate;
    std::string title;

    std::fstream meetingFile;
    meetingFile.open("meeting.dat",std::fstream::in);
    if(meetingFile.is_open()) {
	while (!meetingFile.eof()) {
	    meetingFile >> sponsor >> participator
			>> sDate >> eDate >> title;
	    Meeting meeting(sponsor, participator,
			    Date::stringToDate(sDate),
			    Date::stringToDate(eDate), title);
	    meetings.push_back(meeting);
	}
    }
    meetingFile.close();
    return meetings;
}
void FileManage::writeMeetingsToFile(std::list<Meeting> meetings) {
    std::fstream meetingFile;
    meetingFile.open("meeting.dat", std::fstream::out);
    std::list<Meeting>::iterator iter;

    if (meetingFile.is_open()) {
	for (iter = meetings.begin(); iter != meetings.end(); 
	     iter++) {
	    Date sDate = iter->getStartDate();
	    Date eDate = iter->getEndDate();
	    std::string stime = Date::dateToString(sDate);
	    std::string etime = Date::dateToString(eDate);
	    meetingFile << iter->getSponsor() << " " 
			<< iter->getParticipator() << " "
			<< stime << " " << etime << " "
			<< iter->getTitle() << "\n";
	}
    }
    meetingFile.close();
}
