// 2013.09.02 Agenda User.cpp
// zhuozhaojin 12330443

#include <iostream>
#include <string>
#include "User.h"

User::User(std::string name, std::string password,
           std::string email, std::string phone) {
    setName(name);
    setPassword(password);
    setEmail(email);
    setPhone(phone);
}
//  The definition of getname and setname
std::string User::getName(void) {
    return name_;
}
void User::setName(std::string n) {
    name_ = n;
}
//  The definition of getpassword and set password
std::string User::getPassword(void) {
    return password_;
}
void User::setPassword(std::string pw) {
    password_ = pw;
}
//  The definition of getemail and setemail
std::string User::getEmail() {
    return email_;
}
void User::setEmail(std::string e) {
    email_ = e;
}
// The definition of getphone and setphone
std::string User::getPhone() {
    return phone_;
}
void User::setPhone(std::string ph) {
    phone_ = ph;
}
