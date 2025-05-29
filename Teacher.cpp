#include "Teacher.h"
#include "Course.h"
Teacher::Teacher(const String& first_name, const String& last_name, const String& password)
	: User(first_name, last_name) {
	this->password = password;
	role = Role::Teacher;
};
Teacher::Teacher() : User() {};
void Teacher::createCourse(const String& coursename, const String& password) {
	Course* course = new Course(coursename, password, this);
	courses.push_back(course);
}
void Teacher::createTaskInCourse(Course& coursename, const String& name, const String& description) {

	coursename.getTasks().push_back(new Task(name));
}
void Teacher::createPasswordForCourse(Course& coursename, const String& password) {
	coursename.setPassword(password);
}
void Teacher::enrollStudentInCourse(Course& coursename, Student& student) {
	coursename.getStudents().push_back(&student);
}
void Teacher::sentMailInCourse(Course& coursename, const Message& message) {
	for (int i = 0;i < coursename.getStudents().getSize();i++) {
		coursename.getStudents()[i]->addMessage(message);
	}
}
void Teacher::examineTask(Course& coursename,Task& task, Student& student, double grade) {
	for (int i = 0;i < coursename.getTasks().getSize();i++) {
		if (&task == coursename.getTasks()[i]) {
			for (int j = 0;j < coursename.getTasks()[i]->getHomeworks().getSize();j++) {
				if (&student == coursename.getTasks()[i]->getHomeworks()[j]->getStudent()) {
					coursename.getTasks()[i]->getHomeworks()[j]->setGrade(grade);
				}
			}
		}
	}
}