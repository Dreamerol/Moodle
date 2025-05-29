#pragma once
#include "String.h"

class Task;
class Course;
class Student;
class Homework {

	double grade;
	bool is_submitted;
	Course* coursename;
	Task* task;
	Student* student;
	String feedback;
public:
	Homework(Course* coursename,Task* task, Student* student, String feedback);
	void printContent(std::ostream& os) const;
	void setGrade(double newgrade);
	double getGrade() const;
	Course* getCourse();
	const String& getTaskName() const;
	const String& getFeedback() const;
	Student* getStudent();
	void setFeedback(const String& text);
};