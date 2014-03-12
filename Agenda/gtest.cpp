#include <gtest/gtest.h>
#include "Date.h"
#include "User.h"
#include "Meeting.h"
#include "UserManage.h"
#include "MeetingManage.h"
#include "FileManage.h"
#include "AgendaService.h"

TEST(DateTest, isValid) {
Date date1(2013, 3, 34, 1, 1);
EXPECT_FALSE(Date::isValid(date1));
Date date2(2012, 2, 29, 1, 1);
EXPECT_TRUE(Date::isValid(date2));
}

TEST(UserManageTest, findUserByName) {
    std::list<User> user;
    UserManage *UA = UserManage::getInstance();
    User user1("george", "1234", "1443@dd","110");
    User user2("a", "1", "11", "111");
    User user3("b", "2", "22", "222");
    user.push_back(user1);
    user.push_back(user2);
    user.push_back(user3);
    UA->initUsersList(user);

    EXPECT_TRUE(UA->findUserByName("a"));
    EXPECT_TRUE(UA->findUserByName("b"));
    EXPECT_FALSE(UA->findUserByName("c"));

}
TEST(UserManageTest, deleteUser) {
    std::list<User> user;
    UserManage *UA = UserManage::getInstance();
    User user1("george", "1234", "1443@dd","110");
    User user2("a", "1", "11", "111");
    User user3("b", "2", "22", "222");
    user.push_back(user1);
    user.push_back(user2);

    UA->initUsersList(user);

    EXPECT_TRUE(UA->deleteUser(user1));
    EXPECT_FALSE(UA->deleteUser(user1));
}
TEST(DateTest, dateToString) {
std::string str = "2013-12-12/12:12";
std::string str2 = "2012-02-20/01:01";
Date date1(2013, 12, 12, 12, 12);
Date date2(2012, 2, 20, 1, 1);

EXPECT_EQ(Date::dateToString(date2), str2);
}
TEST(DateTest, stringToDate) {
std::string str = "2013-12-12/12:12";
std::string str2 = "2012-02-20/01:01";
Date date1(2013, 12, 12, 12, 12);
Date date2(2012, 2, 20, 1, 1);
    EXPECT_EQ(Date::stringToDate(str), date1);
    }
TEST(AgendaServiceTest, userRegister) {
    AgendaService service1;
    EXPECT_TRUE(service1.userRegister("d", "4", "44", "111"));
    EXPECT_TRUE(service1.userRegister("b", "2", "22", "222"));
    EXPECT_FALSE(service1.userRegister("d", "4", "44", "444"));
    }
TEST(AgendaServiceTest, createMeeting) {
AgendaService service1;
service1.userRegister("a", "1", "11", "111");
service1.userRegister("b", "2", "22", "222");
service1.userRegister("c", "3", "33", "333");


EXPECT_TRUE(service1.createMeeting("a", "one", "b",
"2013-09-04/14:23", "2013-09-04/17:30"));
EXPECT_FALSE(service1.createMeeting("a", "one", "c",
"2013-09-04/14:30", "2013-09-04/17:00"));
EXPECT_FALSE(service1.createMeeting("a", "one", "b",
"2013-09-04/14:20", "2013-09-04/17:00"));
}

TEST(AgendaServiceTest, deleteMeeting) {
AgendaService service1;
service1.userRegister("a", "1", "11", "111");
service1.userRegister("b", "2", "22", "222");
service1.userRegister("c", "3", "33", "333");

service1.createMeeting("a", "one", "b",
		       "2013-09-04/14:23", "2013-09-04/17:30");
service1.createMeeting("b", "two", "c",
		       "2013-09-03/14:30", "2013-09-03/17:00");
service1.createMeeting("c", "three", "a",
		       "2012-09-04/14:23", "2012-09-04/17:30");
EXPECT_TRUE(service1.deleteMeeting("a", "one"));
EXPECT_TRUE(service1.deleteMeeting("b", "two"));
EXPECT_FALSE(service1.deleteMeeting("d", "two"));
EXPECT_FALSE(service1.deleteMeeting("a", "three"));
EXPECT_FALSE(service1.deleteMeeting("a", "one"));
}
TEST(AgendaServiceTest, deleteMeeting) {
AgendaService service1;
service1.userRegister("a", "1", "11", "111");
service1.userRegister("b", "2", "22", "222");
service1.userRegister("c", "3", "33", "333");

service1.createMeeting("a", "one", "b",
		       "2013-09-04/14:23", "2013-09-04/17:30");
service1.createMeeting("b", "two", "c",
		       "2013-09-03/14:30", "2013-09-03/17:00");
service1.createMeeting("c", "three", "a",
		       "2012-09-04/14:23", "2012-09-04/17:30");

}
