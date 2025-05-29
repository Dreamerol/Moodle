#include "Homework.h"
#include "Student.h"
Homework::Homework(Course* coursename,Task* task, Student* student, String content) :task(task), coursename(coursename), student(student), feedback(content) {
	is_submitted = true;
}
void Homework::printContent(std::ostream& os) const {
	os << student->getFirstName() << ' ' << student->getLastName();
		
		os<<" " << student->getID() << " " << feedback << '\n';
}
void Homework::setGrade(double newgrade) {
	grade = newgrade;
}
void Homework::setFeedback(const String& text) {
	feedback = text;
}
double Homework::getGrade() const {
	return grade;
}
Course* Homework::getCourse()  {
	return coursename;
}
const String& Homework::getFeedback() const {
	return feedback;
}
const String& Homework::getTaskName() const {
	return task->getName();
}

Student* Homework::getStudent() {
	return student;
}