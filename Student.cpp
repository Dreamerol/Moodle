#include "Student.h"

Student::Student(const String& first_name, const String& last_name, const String& password)
	: User(first_name, last_name) {
	this->password = password;
	role = Role::Student;
};
Student::Student() :User() {};
void Student::enrollCourse(Course& course, const String& password, std::ostream& os) {
	if (password == course.getPassword()) {
		courses.push_back(&course);
		course.addStudent(this);
	}
	else {
		os << "You are not able to sign for " << course.getCoursename() << "!" << std::endl;
	}

}
//void Student::giveHomework(Course& coursename, Homework& homework) {
//	coursename.addHomework(homework);
//}
void Student::addCourse(Course& course) {
	courses.push_back(&course);
}
void Student::seeGrades(std::ostream& os) const {
	for (int i = 0;i < homeworks.getSize();i++) {
	
		os << homeworks[i]->getCourse()->getCoursename()<<" | " <<homeworks[i]->getTaskName()<< " | " << homeworks[i]->getGrade() << " | " << homeworks[i]->getFeedback() << '\n';
	}
}
Homework* Student::getHomeworkByTaskName(const String& taskname) {
	for (int i = 0;i < homeworks.getSize();i++) {
	
		if (homeworks[i]->getTaskName() == taskname) {
			return homeworks[i];
		}
	}
	return nullptr;
}
void Student::addHomework(Homework& homework) {
	homeworks.push_back(&homework);
}
