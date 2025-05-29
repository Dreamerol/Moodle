#include "Administrator.h"
#include "Student.h"
#include "Teacher.h"

Administrator::Administrator() : User("admin", "") {
	password = "0000";
	ID = 0;
	role = Role::Admin;
}
/*size_t Administrator::findIdxTeacher(size_t ID) const {
	for (int i = 0;i < teachers.getSize();i++) {
		if (teachers[i].getID() == ID) {
			return i;
		}
	}
	throw std::out_of_range("Invalid ID!");
}
size_t Administrator::findIdxStudent(size_t ID) const {
	for (int i = 0;i < students.getSize();i++) {
		if (students[i].getID() == ID) {
			return i;
		}
	}
	throw std::out_of_range("Invalid ID!");

}*/
//void Administrator::createStudent(const String& first_name, const String& last_name, const String& password) {
//	Student s(first_name, last_name, password);
//	students.push_back(s);
//	std::cout << "Added student " << s.getFirstName() << " " << s.getLastName() << "with ID " << s.getID() << "!" << std::endl;
//}
//void Administrator::createTeacher(const String& first_name, const String& last_name, const String& password) {
//	Teacher t(first_name, last_name, password);
//	teachers.push_back(t);
//	std::cout << "Added teacher " << t.getFirstName() << " " << t.getLastName() << "with ID " << t.getID() << "!" << std::endl;
//}

//void Administrator::deleteTeacher(size_t ID) {
//	size_t idx = findIdxTeacher(ID);
//	teachers.erase(idx);
//}
//void Administrator::deleteStudent(size_t ID) {
//	size_t idx = findIdxStudent(ID);
//	students.erase(idx);
//}
//void Administrator::seeStudentMail() const {
//	std::cout << "Students mail: " << '\n';
//	for (int i = 0;i < students.getSize();i++) {
//		students[i].seeMails();
//	}
//	std::cout << "Teachers mail: " << '\n';
//	for (int i = 0;i < teachers.getSize();i++) {
//		teachers[i].seeMails();
//	}
//}
//void Administrator::sentMessageToAll(const String& content) {
//	for (int i = 0;i < students.getSize();i++) {
//		Message m(this, &students[i], content);
//		students[i].addMessage(m);
//	}
//
//	for (int i = 0;i < teachers.getSize();i++) {
//		Message m(this, &teachers[i], content);
//		teachers[i].addMessage(m);
//	}
//}

