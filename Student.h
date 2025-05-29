#pragma once
#include "String.h"
#include "User.h"
#include "Vector.hpp"

#include "Message.h"
#include "Course.h"
#include "Homework.h"
//struct Grade {
//	Task* course;
//	double grade;
//};

class Student : public User {
	Vector<Homework*> homeworks;
	Vector<Course*> courses;

public:
	void addHomework(Homework& homework);
	void addCourse(Course& course);
	Student(const String& first_name, const String& last_name, const String& password);
	Student();
	void enrollCourse(Course& coursename, const String& password, std::ostream& os);
	//void giveHomework(Course& coursename, Homework& homework);
	Homework* getHomeworkByTaskName(const String& taskname);
	void seeGrades(std::ostream& os) const;
	//void sentEmail(Student& student, const Message& message);
	//void addMessage(const Message& message);
	//void deleteEmail(String& mail);

};