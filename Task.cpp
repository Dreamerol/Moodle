#include "Task.h"
Task::Task(const String& name) :name(name) {};
Vector<Homework*>& Task::getHomeworks() {
	return homeworks;
}
const String& Task::getName() const {
	return name;
}
void Task::printHomeworks(std::ostream& os) const {
	
	for (int i = 0;i < homeworks.getSize();i++) {
		homeworks[i]->printContent(os);
	}
}
void Task::addHomework(Homework& h) {
	homeworks.push_back(&h);
}