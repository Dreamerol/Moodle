#pragma once
#include "Vector.hpp"
#include "User.h"
#include "String.h"
#include "Task.h"
#include"Course.h"
class Student;
class Teacher : public User {

	Vector<Course*> courses;
public:
	Teacher(const String& first_name, const String& last_name, const String& password);
	Teacher();
	void createCourse(const String& coursename, const String& password);
	void createTaskInCourse(Course& coursename, const String& name, const String& description);
	void createPasswordForCourse(Course& coursename, const String& password);
	void enrollStudentInCourse(Course& coursename, Student& student);
	void sentMailInCourse(Course& coursename, const Message& message);
	void examineTask(Course& coursename, Task& task, Student& student, double grade);


};