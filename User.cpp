#include "User.h"
int User::currentID = 98;

User::User(const String& first_name, const String& last_name) {
	this->first_name = first_name;
	this->last_name = last_name;
	ID = currentID++;
	password = "0000";
}
size_t User::getID() const {
	return ID;
}
void User::printInfo(std::ostream& os) const {
	os << getFirstName() << " " << getLastName() << " | ";
	printRole(getRole(), os);
	os << " | " << getID() << '\n';
}
void User::seeMails(std::ostream& os) const {
	if (messages.empty()) {
		os << "No messages to show!" << '\n';
		return;
	}
	os << "MailBox: ";
	for (int i = 0;i < messages.getSize();i++) {
		os << messages[i].getTime() << " sent by "
			<< messages[i].getSender()->getFirstName() << " "
			<< messages[i].getSender()->getLastName() << ": "
			<< messages[i].getContent() << std::endl;

	}
}
void User::sentMessage(const Message& msg, User* user) {
	user->addMessage(msg);
}
void User::deleteMail() {
	messages.clear();
}
void User::addMessage(const Message& message) {
	messages.push_back(message);
}
User::User() {
	first_name = "";
	last_name = "";
	password = "0000";
}
User::~User() {};
void User::setPassword(const String& password) {
	this->password = password;
}

const String& User::getFirstName() const {
	return first_name;
}
const String& User::getLastName() const {
	return last_name;
}
const String& User::getPassword() const{
	return password;
}
Vector<Message>& User::getMail() {
	return messages;
}
Role User::getRole() const{
	return role;
}

