#pragma once
#include "Vector.hpp"
#include "User.h"
#include "Administrator.h"
class System {
	Vector<User*> users;
	Vector<Course*> courses;
	User* current_user = nullptr;
public:
	System();
	~System();
	void run(std::istream& is, std::ostream& os);
	void login(std::istream& is, std::ostream& os);
	void logout(std::istream& is, std::ostream& os);
	void message(std::istream& is, std::ostream& os);
	void change_password(std::istream& is, std::ostream& os);
	void message_students(std::istream& is, std::ostream& os);
	void submit_assignment(std::istream& is, std::ostream& os);
	void assign_homework(std::istream& is, std::ostream& os);
	void clear_mailbox(std::istream& is, std::ostream& os);
	void view_assignment_submissions(std::istream& is, std::ostream& os);
	void grade_assignment(std::istream& is, std::ostream& os);
	void grades(std::istream& is, std::ostream& os);
	void deleteUser(std::istream& is, std::ostream& os);
	void createCourseInSystem(std::istream& is, std::ostream& os);
	void addToCourse(std::istream& is, std::ostream& os);
	void enroll(std::istream& is, std::ostream& os);
	void add_teacher(std::istream& is, std::ostream& os);
	void add_student(std::istream& is, std::ostream& os);
	void message_all(std::istream& is, std::ostream& os);
	void mailbox(std::istream& is, std::ostream& os);
	void changePasswordForCourse(std::istream& is, std::ostream& os);
	
	void readFromFile(const char* filename);
	void writeInFile(const char* filename);
	User* findUserByID(size_t ID);
	Course* findCourseByName(const String& name);
	//void addUser(void (System::* addfunc)(const String&,const String& ,const String&));
	
	int findUserIdxByID(size_t ID);
};