#pragma once
#include "System.h"
struct Command {
	const char* command;
	void (System::*func)(std::istream& is, std::ostream& os);
};
Command commands[] = {
    {"login", &System::login},
    {"logout", &System::logout},
    {"message", &System::message},
     {"change_password", &System::change_password},
    {"message_students", &System::message_students},
    {"submit_assignment", &System::submit_assignment},
    {"assign_homework", &System::assign_homework},
    {"clear_mailbox", &System::clear_mailbox},
    {"view_assignment_submissions", &System::view_assignment_submissions},
     {"grade_assignment", &System::grade_assignment},
    {"delete", &System::deleteUser},
    {"grades", &System::grades},
    {"create_course", &System::createCourseInSystem},
     {"add_to_course", &System::addToCourse},
    {"enroll", &System::enroll},
    {"add_teacher", &System::add_teacher},
     {"add_student", &System::add_student},
    {"message_all", &System::message_all},
    {"mailbox", &System::mailbox},
    {"change_password_for_course", &System::changePasswordForCourse}


};
const int COMMANDS_MAP_SIZE = sizeof(commands) / sizeof(commands[0]);