#include "System.h"
#include "CommandMap.h"
#include <fstream>
#include <sstream>
System::System() {
	users.push_back(new Administrator());
}
System::~System() {
	for (int i = 0;i < users.getSize();i++) {
		delete users[i];
	}
	users.clear();
}
User* System::findUserByID(size_t ID) {
	for (int i = 0;i < users.getSize();i++) {
		if (users[i]->getID() == ID) {
			return users[i];
		}
	}
	return nullptr;
}
int System::findUserIdxByID(size_t ID) {
	for (int i = 0;i < users.getSize();i++) {
		if (users[i]->getID() == ID) {
			return i;
		}
	}
	return -1;
}
Course* System::findCourseByName(const String& name) {
	
	for (int i = 0;i < courses.getSize();i++) {
		
		if (courses[i]->getCoursename() == name) {
			
			return courses[i];
		}
	}
	return nullptr;
}
void System::createCourseInSystem(std::istream& is, std::ostream& os) {
	if (current_user->getRole() != Role::Teacher) {
		std::cout << "Only teachers can add courses!" << '\n';
		return;
	}
	Teacher* teacher = dynamic_cast<Teacher*>(current_user);

	String name;
	String password;
	is >> name >> password;
	Course* course = new Course(name, password, teacher);

	courses.push_back(course);
	teacher->createCourse(name, password);
}
void System::message(std::istream& is, std::ostream& os) {
	size_t id;
	is>> id;
	//is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	char buffer[1024];
	is.getline(buffer, 1024);
	User* user = findUserByID(id);
	if (!user) {
		os << "Invalid ID!" << '\n';
		return;
	}
	Message m(current_user, user, String(buffer));
	user->addMessage(m);
}

//void System::addUser(void (System::*addfunc)(const String&,const String&,const String&)) {
//	String fname, lname, pw;
//	std::cin >> fname >> lname >> pw;
//	(this->*addfunc)(fname, lname, pw);
//}
void System::change_password(std::istream& is, std::ostream& os){
	String old_pw;

	String new_pw;
	is >> old_pw >> new_pw;
	if (old_pw != current_user->getPassword()) {
		os << "Invalid old password!" << '\n';
		return;
	}
	current_user->setPassword(new_pw);
	os << "Password changed successfully!" << '\n';
}
void System::addToCourse(std::istream& is, std::ostream& os) {
	String coursename;
	size_t ID;
	is >> coursename >> ID;
	if (current_user->getRole() != Role::Teacher) {
		os << "You are not allowed to add students!";
	}
	Course* course = findCourseByName(coursename);
	if (course->getTeacher()->getID() != current_user->getID()) {
		std::cout << "You are not an owner of the course! You can't add students!" << '\n';
		return;
	}
	Student* student = dynamic_cast<Student*>(findUserByID(ID));
	if (!student) {
		std::cout << "This student is not in our system!" << '\n';
		return;
	}
	course->addStudent(student);
	String msg = current_user->getFirstName() + " " + current_user->getLastName()
		+ " added you to a course " + coursename + "\n";
	Message addedNotification = Message(current_user, student, msg);
	student->addMessage(addedNotification);
}
void System::enroll(std::istream& is, std::ostream& os) {
	String coursename;
	String password;
	is >> coursename >> password;

	Course* course = findCourseByName(coursename);
	if (!course) {
		os << "This course doesn't exist!" << '\n';
		return;
	}
	if (password != course->getPassword()) {
		os << "Invalid password, you cannot enroll for the course!" << '\n';
		return;
	}
	course->getStudents().push_back(dynamic_cast<Student*>(current_user));
	os << "Successfully enrolled for course " << coursename << '!' << '\n';
}
void System::message_students(std::istream& is, std::ostream& os) {
	String coursename;
	is >> coursename;
	Course* course = findCourseByName(coursename);
	if (!course) {
		return;
	}
	//is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	char buffer[1024];
	is.getline(buffer, 1024);
	String message(buffer);

	course->sentMessageToAllParticipants(message, current_user);
}
void System::submit_assignment(std::istream& is, std::ostream& os) {
	if (current_user->getRole() != Role::Student) {
		os << "You are not a student, so you cannot submit homework!" << '\n';
		return;
	}
	String coursename;
	String taskname;
	is >> coursename >> taskname;
	char buffer[1024];
	is.getline(buffer, 1024);
	Course* course = findCourseByName(coursename);
	String content(buffer);
	Task* task = course->getTaskByName(taskname);

	Homework* homework = new Homework(course, task, dynamic_cast<Student*>(current_user), content);
	dynamic_cast<Student*>(current_user)->addHomework(*homework);
	task->addHomework(*homework);
	os << "Succefully added task";
}
void System::assign_homework(std::istream& is, std::ostream& os) {
	if (current_user->getRole() != Role::Teacher) {
		os << "You are not a techer, so you cannot assign homework!" << '\n';
		return;
	}
	String coursename;
	String homeworkname;
	is >> coursename >> homeworkname;
	Course* course = findCourseByName(coursename);
	if (!course) {
		std::cout << "Not a valid coursename!" << '\n';
	}
	Task* task = new Task(homeworkname);
	course->addTask(*task);

	String msg = "You have a new assignment published in " + coursename;

	course->sentMessageToAllParticipants(msg, current_user);
	os << "Successfully created a new assignment!" << '\n';
}

void System::view_assignment_submissions(std::istream& is, std::ostream& os) {
	String coursename;
	String taskname;
    is >> coursename >> taskname;
	if (current_user->getRole() != Role::Teacher) {
		std::cout << "You are not able to view assignments!" << '\n';
		return;
	}

	Course* course = findCourseByName(coursename);
	if (!course) {
	    os << "Course not found!" << '\n';
		return;
	}

	Task* task = course->getTaskByName(taskname);
	if (!task) {
		os << "Task not found";
		return;
	}

	task->printHomeworks(os);
}
void System::grade_assignment(std::istream& is, std::ostream& os) {
	String coursename;
	String taskname;
	size_t ID;
	double grade;
	is >> coursename >> taskname >> ID >> grade;
	Student* student = dynamic_cast<Student*>(findUserByID(ID));
	if (!student) {
		os << "Invalid ID!" << '\n';
		return;
	}

	char buffer[1024];
	is.getline(buffer, 1024);
	String feedback(buffer);
	Homework* h = student->getHomeworkByTaskName(taskname);
	if (!h) {
		os << "This student hasn't submitted yet!" << '\n';
	}
	h->setGrade(grade);
	h->setFeedback(feedback);
	String text = current_user->getFirstName() + " " + current_user->getLastName() + " graded your work in " + taskname + " in " + coursename + "\n";
	Message msg = Message(current_user, student, text);
	student->addMessage(msg);
}
void System::grades(std::istream& is, std::ostream& os) {
	if (current_user->getRole() != Role::Student) {
		os << "You are not a student, so you don't have grades!" << '\n';
		return;
	}
	Student* student = dynamic_cast<Student*>(current_user);
	student->seeGrades(os);
}
void System::deleteUser(std::istream& is, std::ostream& os) {
	if (current_user->getRole() != Role::Admin) {
		std::cout << "You are not admin! You cannot delete from the system!" << '\n';
	}
	size_t ID;
	is >> ID;
	int idx = findUserIdxByID(ID);
	if (idx == -1) {
		os << "This user doesn't exist!" << '\n';
	}
	users.erase(idx);
}
void System::login(std::istream& is, std::ostream& os) {
	
	int id;
	String password;
	is >> id >> password;
	for (int i = 0;i < users.getSize();i++) {
		
		if (id == users[i]->getID() && password == users[i]->getPassword()) {
			current_user = users[i];
		 os << "Login successful!" << '\n';
			/*os << users[i]->getFirstName() << " " << users[i]->getLastName() << " | ";
			printRole(users[i]->getRole(), os);
			os << " | " << users[i]->getID() << '\n';*/
		 users[i]->printInfo(os);
			return;
		}
	}
	os << "Login failed"<<'\n';
}
void System::logout(std::istream& is, std::ostream& os) {
	current_user = nullptr;
	os << "Logged out!" << '\n';
}
void System::add_teacher(std::istream& is, std::ostream& os) {
	
	if (current_user->getRole() != Role::Admin) {
		os << "You are not admin!"<<'\n';
		return;
	}
	String fname, lname, pw;
	is>> fname >> lname >> pw;
	Teacher* newTeacher = new Teacher(fname, lname, pw);
	users.push_back(newTeacher);
	os << "Added teacher " << fname << " " << lname << " with ID " << newTeacher->getID() << "!" << '\n';
}
void System::add_student(std::istream& is, std::ostream& os){
	if (current_user->getRole() != Role::Admin){
	 os << "You are not admin!"<<'\n';
		return;
	}
	String fname, lname, pw;
	is >> fname >> lname >> pw;
	Student* newStudent = new Student(fname, lname, pw);
	users.push_back(newStudent);
	os << "Added student "<< fname<<" "<<lname<< " with ID "<<newStudent->getID()<<"!"<<'\n';
}
void System::message_all(std::istream& is, std::ostream& os) {
	char buffer[1024];
	is.ignore();
	is.getline(buffer, 1024);
	String message(buffer);
	for (int i = 0;i < users.getSize();i++) {
		Message m(current_user, users[i], message);
		users[i]->addMessage(m);
	}
}
void System::mailbox(std::istream& is, std::ostream& os) {
	if (!current_user) {
		os << "You are not logged in!";
		return;
	}
	
	current_user->seeMails(os);

}
void System::changePasswordForCourse(std::istream& is, std::ostream& os) {
	if (current_user->getRole() != Role::Teacher) {
		os << "You are not a teacher, so you can't change the password for the course!" << '\n';
	}
	String coursename;
	String new_password;
	is >> coursename >> new_password;
	Course* course = findCourseByName(coursename);
	if (!course) {
		std::cout << "There is not such a course!" << '\n';
	}
	course->setPassword(new_password);
	os << "Password changed successfully for course " << coursename << '\n';
}
void System::clear_mailbox(std::istream& is, std::ostream& os) {
	current_user->deleteMail();
}
//void System::run() {
//	String command;
//	while (true) {
//		std::cout << ">";
//		std::cin >> command;
//		if (command == "login") {
//			login();
//		}
//		else if (command == "logout") {
//			logout();
//		}
//		else if (command == "add_student") {
//			add_student();
//		}
//		else if (command == "add_teacher") {
//			add_teacher();
//		}
//		else if (command == "message") {
//			message();
//		}
//		else if (command == "change_password") {
//			change_password();
//		}
//		else if (command == "clear_mailbox") {
//			clear_mailbox();
//		}
//		else if (command == "message_all") {
//			message_all();
//		}
//		else if (command == "create_course") {
//			createCourseInSystem();
//		}
//		else if (command == "add_to_course") {
//			addToCourse();
//		}
//		else if (command == "enroll") {
//			enroll();
//		}
//		else if (command == "message_students") {
//			message_students();
//		}
//		else if (command == "submit_assignment") {
//			submit_assignment();
//
//		}
//		else if (command == "assign_homework") {
//			assign_homework();
//		}
//		else if (command == "view_assignment_submissions") {
//			view_assignment_submissions();
//		}
//		else if (command == "grade_assignment") {
//			grade_assignment();
//		}
//		else if (command == "grades") {
//			grades();
//		}
//		else if (command == "delete") {
//			deleteUser();
//		}
//		else if (command == "exit") {
//			break;
//		}
//		else if (command == "mailbox") {
//			mailbox();
//		}
//		else {
//			std::cout << "Unknown command";
//		}
//
//	}
//}

void System::run(std::istream& is, std::ostream& os) {
	std::cout << ">";
	String command;
	while (is >> command) {
		if (command == "exit") {
			break;
		}
		bool isvalid = false;
		for (int i = 0;i < COMMANDS_MAP_SIZE;i++) {
			if (command == commands[i].command) {
				(this->*commands[i].func)(is, os);
				isvalid = true;
			}
		}
		if (!isvalid) {
			os << "UNKNOWN COMMAND!"<<'\n';
		}
		
	}
}
void System::writeInFile(const char* filename) {
	std::ofstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Cannot open the file!";

	}
	for (int i = 0;i < users.getSize();i++) {
		users[i]->printInfo(file);
	}
	file.close();
}
void System::readFromFile(const char* filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Cannot open the file!";
	
}
	while (!file.eof()) {
		char buffer[1024];
		file.getline(buffer, 1024);
		std::stringstream ss(buffer);
		String role, first_name, last_name, password;
		ss >> role;
		ss.ignore(3);
		ss >> first_name;
		ss >> last_name;
		ss.ignore(3);
		ss >> password;
		User* user;
		if (role == "Admin") {
			std::cerr << "You cannot add an admin!" << '\n';
		}
		
		else if (role == "Student") {
			user= new Student(first_name, last_name, password);
		}
		else if (role == "Teacher") {
			user = new Teacher(first_name, last_name, password);
		}
		else {
			std::cerr << "Not a valid command";
		}
		users.push_back(user);
	}

	file.close();
}