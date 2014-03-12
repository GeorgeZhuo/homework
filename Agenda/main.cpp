// 2013.09.03 Agenda main.cpp
// zhuozhaojin 12330443

#include <iostream>
#include <string>
#include "Meeting.h"
#include "User.h"
#include "Date.h"
#include "UserManage.h"
/*using namespace std;

int main ()
{
    list<User> user;
    UserManage *UA = UserManage::getInstance();
   
    Date date1(2013, 9, 3, 13, 59);
    Date date2(2012, 2, 29, 13, 59);

    string one1 = "2013-09-03/17:20";
    
    
    User user1("george", "1234", "1443@dd","110");
    User user2("joe", "1234", "122@ss", "112");
  
    Meeting meeting1("george", "joe", date1, date2, "Agenda");
    
    date1 = date2.stringToDate("2013-08-01/12:00");
    
    cout << date1.dateToString(date2) << endl;
    cout << date1.getYear() << "-" << date1.getMonth() << "-" << date1.getDay() << "/" << date1.getHour() << ":" << date1.getMinute() << endl;
    user.push_back(user1);
    user.push_back(user2);
    UA->initUsersList(user);
    if (date1.isValid(date2))
	cout << "Y" << endl;
    else 
	cout << "N" << endl;

    cout << user1.getName() << endl;
    cout << user1.getPhone() << endl;

    cout << meeting1.getSponsor() << endl;

    if (UA->findUserByName("joe"))
	cout << "Y" << endl;
    else
	cout << "N" << endl;

    if(UA->createUser("izhu", "234", "133", "119"))
	cout << "Y" << endl;
    else
	cout << "N" << endl;

    if (UA->deleteUser(user1))
	cout << "Y" << endl;
    else
	cout << "N" << endl;
    
    return 0;
    }*/

#include <gtest/gtest.h>

int main(int argc, char** argv) {

testing::InitGoogleTest(&argc, argv);
// Runs all tests using Google Test.
return RUN_ALL_TESTS();

}
