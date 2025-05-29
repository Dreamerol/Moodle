#include "Course.h"
#include "Teacher.h"
const String& Course::getCoursename() const {
	return courseName;
}
const String& Course::getPassword() const {
	return password;
}
void Course::addStudent(Student* student) {
	students.push_back(student);
}
void Course::setPassword(const String& newPassword) {
	password = newPassword;
}
Vector<Student*>& Course::getStudents() {
	return students;
}
//void Course::addHomework(Homework& homework) {
//	homework.is_submitted = true;
//	homeworks.push_back(homework);
//}

Course::Course(const String& coursename, const String& password, Teacher* teacher) :
	courseName(coursename), password(password), teacher(teacher) {
};
Teacher* Course::getTeacher() const {
	return teacher;
}
void Course::sentMessageToAllParticipants(String& msg, User* sender) {
	for (int i = 0;i < students.getSize();i++) {
		Message message(sender, students[i], msg);
		students[i]->addMessage(message);
	}
}
Vector<Task*>& Course::getTasks()  {
	return tasks;
}
void Course::addTask(Task& task) {
	tasks.push_back(&task);
}
Task* Course::getTaskByName(const String& taskname) {
	
	for (int i = 0;i < tasks.getSize();i++) {
		
		if (tasks[i]->getName() == taskname) {
			return tasks[i];
		}
	}
	return nullptr;
}