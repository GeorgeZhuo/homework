// 2013.09.04 Agenda AgendaService.cpp
//  zhuozhaojin 12330443

#include <string>
#include <iostream>
#include "AgendaService.h"

//  ToDo
AgendaService::AgendaService() {
    userManage_ = UserManage::getInstance();
    meetingManage_ = MeetingManage::getInstance();
    fileManage_ = FileManage::getInstance();
}
AgendaService::~AgendaService() {
    delete userManage_;
    delete meetingManage_;
    delete fileManage_;
}
User* AgendaService::userLogIn(std::string userName,
std::string password) {
    std::list<User>::iterator it;
    std::list<User> users = userManage_->listAllUsers();
    for (it = users.begin(); it != users.end(); it++) {
	if ( it->getName() == userName &&
	     it->getPassword() == password)
	    return &(*it);
    }
    return NULL;
}
bool AgendaService::userRegister(std::string userName,
				 std::string password, std::string email,
				 std::string phone) {
    return userManage_->createUser(userName, password, email, phone);
}
bool AgendaService::deleteUser(User user) {
    std::list<Meeting>::iterator it;
    std::string name = user.getName();
    std::list<Meeting> meetings =  meetingManage_->listAllMeetings(name);
    for (it = meetings.begin(); it != meetings.end(); it++) {
	if (it->getSponsor() == name || it->getParticipator() == name) {
	    return false;
	}
    }
    return userManage_ ->deleteUser(user);
}
std::list<User> AgendaService::listAllUsers(void) {
    return userManage_->listAllUsers();
}
bool AgendaService::createMeeting(std::string userName, std::string title,
				  std::string participator, std::string
				  startDate, std::string endDate) {
    Date sDate = Date::stringToDate(startDate);
    Date eDate = Date::stringToDate(endDate);
    if (userManage_->findUserByName(userName) && 
	userManage_->findUserByName(participator)) {
	return meetingManage_->addMeeting(userName, participator,
					    sDate, eDate, title);
    } else {
	return false;
    }
}
Meeting* AgendaService::meetingQuery(std::string title) {
    return meetingManage_ -> queryMeetingByTitle(title);
}
std::list<Meeting> AgendaService::meetingQuery(std::string userName,
					       std::string startDate,
					       std::string endDate) {
    return meetingManage_ -> queryMeetingsByTime
	(userName, Date::stringToDate(startDate), 
	 Date::stringToDate(endDate));
}
std::list<Meeting> AgendaService::listAllMeetings(std::string userName) {
    return meetingManage_->listAllMeetings(userName);
}
std::list<Meeting> AgendaService::listAllSponsorMeetings
(std::string userName) {
    return meetingManage_ ->listAllSponsorMeetings(userName);
}
std::list<Meeting> AgendaService::listAllParticipateMeetings
(std::string userName) {
    return meetingManage_ -> listAllParticipateMeetings(userName);
}
bool AgendaService::deleteMeeting(std::string userName,
				   std::string title) {
    return meetingManage_->deleteMeeting(userName, title);
}
bool AgendaService::deleteAllMeetings(std::string userName) {
    return meetingManage_->deleteAllMeetings(userName);
}
// ToDo
void AgendaService::startAgenda(void) {
    userManage_->initUsersList(fileManage_->readUsersFromFile());
    meetingManage_->initMeetingsList(fileManage_->
				     readMeetingsFromFile());
}
//  ToDo
void AgendaService:: quitAgenda(void) {
    std::list<User> users = userManage_->listAllUsers();
    std::list<Meeting> meetings = meetingManage_->acquireMeetingsList();
    fileManage_->writeUsersToFile(users);
    fileManage_->writeMeetingsToFile(meetings);
}
