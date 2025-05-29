#pragma once

#include "User.h"
#include "Student.h"
#include "Teacher.h"

class Administrator : public User {
	Vector<Student> students;
	Vector<Teacher> teachers;
public:
	Administrator();
	/*size_t findIdxStudent(size_t ID) const;
	size_t findIdxTeacher(size_t ID) const;
	void createStudent(const String& first_name, const String& last_name, const String& password);
	void createTeacher(const String& first_name, const String& last_name, const String& password);
	void deleteTeacher(size_t ID);
	void deleteStudent(size_t ID);
	void seeStudentMail() const;
	void sentMessageToAll(const String& content);*/



};


