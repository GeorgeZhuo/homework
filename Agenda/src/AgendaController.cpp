//  2013.09.04 Agenda AgendaController.cpp
//  zhuozhaojin 12330443
#include <iostream>
#include <iomanip>
#include "AgendaController.h"

AgendaController::AgendaController() 
    :currentUser_(NULL){
    startAgenda();
}
void AgendaController::getOperation(void) {
    std::cout << "---------------------------------"
	      << "Agenda------------------------------\n"
	      << "\nAction :\n" << "l   -- "
	      << "log in Agenda by user name and password\n"
	      << "r   -- register an Agenda account\n"
	      << "q   -- quit Agenda\n"
	      << std::setfill('-') << std::setw(80) << std::endl;
    std::string operation;
    std::cout << "\nAgenda :~$";
    std::cin >> operation;
    executeOperation(operation);
}
//  Todo
void AgendaController::startAgenda(void) {
    agendaService_.startAgenda();
}
bool  AgendaController::executeOperation
(std::string op) {
  
    if (currentUser_ == NULL) {
	if (op == "l")
	     userLogIn();
	else if (op == "r")
	    userRegister();
	else if(op == "q") {
	    quitAgenda();
	    return false;
	} else {
	    getOperation();
	}
    } else {
	if (op == "o") {
	    userLogOut();
	    return false;
	} else if (op == "dc") {
	    deleteUser();
	    return false;
	}
	else if(op == "lu")
	    listAllUsers();
	else if (op == "cm")
	    createMeeting();
	else if (op == "la")
	    listAllMeetings();
	else if (op == "las")
	    listAllSponsorMeetings();
	else if (op == "lap")
	    listAllParticipateMeetings();
	else if (op == "qm")
	    queryMeetingByTitle();
	else if (op == "qt")
	    queryMeetingByTimeInterval();
	else if (op == "dm")
	    deleteMeetingByTitle();
	else if (op == "da")
	    deleteAllMeetings();
    }
    return true;
}
void AgendaController::userLogIn(void) {
    std::string name;
    std::string password;
    std::cout << "[Log in] [user name] [password]"
	      << "\n[Log in] ";
    std::cin >> name >> password;
    currentUser_ = agendaService_.userLogIn(name, password);
    if (agendaService_.userLogIn(name, password)) {
	std::cout << "[Log in] succeed!" << std::endl;
	std::cout << "----------------------------------"
		  << "Agenda-------------------------------\n"
		  << "Action :\n" << "o  -- "
		  << "Log out Agenda"<< std::endl << "dc  -- "
		  << "delete Agenda account" << std::endl
		  << "lu  -- list all Agenda user" << std::endl
		  << "cm  -- create a meeting" << std::endl
		  << "la  -- list all meetings" << std::endl
		  << "las -- list all sponsor meetings\n" 
		  << "lap -- list all participator meetings\n"
		  << "qm  -- query meeting by title\n"
		  << "qt  -- query meeting by time interval\n"
		  << "dm  -- delete meeting by title\n"
		  << "da  -- delete all meetings" << std::endl
		  << std::setfill('-') << std::setw(80) << std::endl;
	std::string operation;
	std::cout << std::endl << "\nAgenda@" << name << " : #";
	while (std::cin >> operation, executeOperation(operation)) {
	    std::cout << "----------------------------------"
		      << "Agenda-------------------------------\n"
		      << "Action :\n" << "o  -- "
		      << "Log out Agenda"<< std::endl << "dc  -- "
		      << "delete Agenda account" << std::endl
		      << "lu  -- list all Agenda user" << std::endl
		      << "cm  -- create a meeting" << std::endl
		      << "la  -- list all meetings" << std::endl
		      << "las -- list all sponsor meetings\n" 
		      << "lap -- list all participator meetings\n"
		      << "qm  -- query meeting by title\n"
		      << "qt  -- query meeting by time interval\n"
		      << "dm  -- delete meeting by title\n"
		      << "da  -- delete all meetings" << std::endl
		      << std::setfill('-') << std::setw(80) << std::endl;
	    std::cout << "\nAgenda@" << name << " : #";
	}
    } else {
	std::cout << "[error] log in fail!" << std::endl;
    }
    getOperation();
}
void AgendaController::userRegister(void) {
    std::string name, password, email, phone;
    std::cout << "\n[register] [user name] [password] [email] [phone]\n"
	      << "[register] ";
    std::cin >> name >> password >> email >> phone;
    if (agendaService_.userRegister(name, password, email, phone))
	std::cout << "[register] succeed!" << std::endl;
    else 
	std::cout << "[error] register fail!" << std::endl;
    getOperation();
}
void AgendaController::quitAgenda(void) {
    agendaService_.quitAgenda();
    currentUser_ = NULL;
}
//  Todo
void AgendaController::userLogOut(void) {
    currentUser_ = NULL;
}
void AgendaController::deleteUser(void) {
    if (agendaService_.deleteUser(*currentUser_))
	std::cout << "\n[delete agenda account] succeed"
		  << std::endl;
    else
	std::cout << "\n[error] delete agenda account fail!"
		  << std::endl;
    currentUser_ = NULL;
}
void AgendaController::listAllUsers(void) {
    std::cout << "\n[list all users]\n" << std::endl;
    std::list<User>::iterator it;
    std::list<User> users =  agendaService_.listAllUsers();
    std::cout << "name" << "        " << "email"
	      << "       " << "phone" << std::endl;
    for (it = users.begin(); it != users.end(); it++) {
	std::cout << it->getName() << "       "
		  << it->getEmail() << "       "
		  << it->getPhone() << std::endl;
    }
}
void AgendaController::createMeeting(void) {
    std::cout << "[create meeting] [title] [participator] "
	      << "[start time(yyyy-mm-dd/hh:mm)] "
	      << "[end time(yyyy-mm-dd/hh:mm)]" << std::endl;
    std::cout << "[create meeting] ";
    std::string participator, title, stime, etime;
    std::string sponsor = currentUser_->getName();
    std::cin >> title >> participator >> stime >> etime;
    if (agendaService_.createMeeting(sponsor,title, participator,
				     stime, etime))
	std::cout << "[create meeting] succeed!"<< std::endl;
    else
	std::cout << "[error] create meeting fail!" << std::endl;
}
void AgendaController::listAllMeetings(void) {
    std::cout << "[list all meetings]"
	      << std::endl << std::endl;
    std::string name = currentUser_->getName();
    std::list<Meeting> meetings = agendaService_.listAllMeetings(name);
    printMeetings(meetings);
}
void AgendaController::listAllSponsorMeetings(void) {
    std::cout << "[list all sponsor meetings]"
	      << std::endl << std::endl;
    std::string name = currentUser_->getName();
    std::list<Meeting> meetings = agendaService_.listAllMeetings(name);
    printMeetings(meetings);
}
void AgendaController::listAllParticipateMeetings(void) {
    std::cout << "[list all participator meetings]"
	      << std::endl << std::endl;
    std::string name = currentUser_->getName();
    std::list<Meeting> meetings = agendaService_.listAllMeetings(name);
    printMeetings(meetings);
}
void AgendaController::queryMeetingByTitle(void) {
    std::cout << "[query meeting] [title]" << std::endl
	      << "[query meeting] ";
    std::string title;
    std::cin >> title;
    Meeting *ptr= agendaService_.meetingQuery(title);
    std::cout << "sponsor" << "       " << "participator"
	      << "      " << "start time" << "      "
	      << "end time" << std::endl;
    std::cout << ptr->getSponsor() << "         "
	      << ptr->getParticipator() <<"      "
	      << Date::dateToString(ptr->getStartDate())
	      << "       "
	      << Date::dateToString(ptr->getEndDate())
	      << std::endl;
}
void AgendaController::queryMeetingByTimeInterval(void) {
    std::cout << "[query meetings] [start time(yyyy-mm-dd/hh:mm)]"
	      << " [end time(yyyy-mm-dd/hh:mm)]" << std::endl
	      << "[query meetings] ";
    std::string stime, etime;
    std::cin >> stime >> etime;
    std::cout << "\n\n[query meetings]" << std::endl;
    std::string name = currentUser_->getName();
    std::list<Meeting> meetings = agendaService_.meetingQuery
	(currentUser_->getName(), stime, etime);
    printMeetings(meetings);
}
void AgendaController::deleteMeetingByTitle(void) {
    std::cout << "[delete meeting] [title]" << std::endl
	      << "[delete meeting] ";
    std::string title, name;
    name = currentUser_->getName();
    std::cin >> title;
    if (agendaService_.deleteMeeting(name, title))
	std::cout << "[delete meeting by title] succeed!" 
		  << std::endl;
    else 
	std::cout << "[error] delete meeting fail!" << std::endl;
}
void AgendaController::deleteAllMeetings(void) {
    std::string name = currentUser_->getName();
    if (agendaService_.deleteAllMeetings(name))
	std::cout << "[delete all meetings] succeed!" << std::endl;
    else
	std::cout << "[error] delete all meetings fail!"
		  << std::endl;
}
void AgendaController::printMeetings
(std::list<Meeting> meetings) {
    std::list<Meeting>::iterator iter;
    std::cout << "title" << "       " << "sponsor"
	      << "      " << "participator" << "      "
	      << "start time" << "      " << "end time" 
	      << std::endl;
    for (iter = meetings.begin(); iter != meetings.end(); iter++) {
	std::cout << iter->getTitle() << "      " 
		  << iter->getSponsor() << "      "
		  << iter->getParticipator() << "      "
		  << Date::dateToString(iter->getStartDate())
		  << "      "
		  << Date::dateToString(iter->getEndDate())
		  << std::endl;
    }
}
