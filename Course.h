#pragma once
#include "String.h"
#include "Vector.hpp"
#include "Student.h"
#include "Homework.h"

#include "Task.h"
class Teacher;

class Course {
	String courseName;
	Vector<Student*> students;
	Vector<Task*> tasks;
	String password;
	Teacher* teacher;

public:
	Vector<Task*>& getTasks();
	Course(const String& coursename, const String& password, Teacher* teacher);	
	void addStudent(Student* student);
	const String& getCoursename() const;
	const String& getPassword() const;
	void setPassword(const String& newPassword);
	Vector<Student*>& getStudents();
	Teacher* getTeacher() const;
	void sentMessageToAllParticipants(String& msg, User* sender);
	void addTask(Task& task);
	Task* getTaskByName(const String& taskname);
		
	
};