// 2013.09.02 Agenda UserManage.cpp
// zhuozhaojin 12330443

#include "UserManage.h"
#include <list>
#include <string>

bool UserManage::instanceFlag_ = false;
UserManage* UserManage:: instance_ = NULL;

UserManage::UserManage() {
}
UserManage::~UserManage() {
    instanceFlag_ = false;
}
UserManage* UserManage::getInstance(void) {
    if (!instanceFlag_) {
        instance_ = new UserManage();
        instanceFlag_ = true;
        return instance_;
    } else {
        return instance_;
    }
}
void UserManage::initUsersList(std::list<User> users) {
    this->users_ = users;
}
User* UserManage::findUserByName(std::string userName) {
    std::list<User> :: iterator it;
    for (it = this->users_.begin(); it != this->users_.end(); it++)
	if (it->getName() == userName)
	    return &(*it);
    return NULL;
}
bool UserManage::createUser(std::string userName, std::string userPassword,
			    std::string userEmail, std::string userPhone) {
    if (findUserByName(userName) == NULL) {
	User user(userName, userPassword,
		  userEmail, userPhone);
	users_.push_back(user);
	return true;
    } else {
	return false;
    }
}
bool UserManage::deleteUser(User user) {
    std::list<User> :: iterator it;
    for (it = this->users_.begin(); it != this->users_.end(); it++)
	if (it->getName() == user.getName()) {
	    users_.erase(it);
	    return true;
	}

    return false;
}
bool UserManage::updateUserPassword(User user, std::string newPassword) {
    std::list<User> :: iterator it;
    for (it = this->users_.begin(); it != this->users_.end(); it++)
	if (it->getName() == user.getName()) {
	       it->setPassword(newPassword);
	       return true;
	   }

    return false;
}
bool UserManage::updateUserEmail(User user, std::string newEmail) {
    std::list<User> :: iterator it;
    for (it = this->users_.begin(); it != this->users_.end(); it++)
	if (it->getName() == user.getName()) {
	       it->setEmail(newEmail);
	       return true;
	   }

    return false;
}
bool UserManage::updateUserPhone(User user, std::string newPhone) {
    std::list<User> :: iterator it;
    for (it = this->users_.begin(); it != this->users_.end(); it++)
	if (it->getName() == user.getName()) {
	       it->setPassword(newPhone);
	       return true;
	   }

    return false;
}
std::list<User> UserManage::listAllUsers(void) {
    return users_;
}
