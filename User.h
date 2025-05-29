#pragma once
#include "String.h"
#include "Message.h"
#include "Vector.hpp"
enum class Role {
	Student,
	Teacher,
	Admin
};
void static printRole(Role role, std::ostream& os) {
	if (Role::Admin == role) {
		os << "Admin";
	}
	else if (role == Role::Student) {
		os << "Student";
	}
	else {
		os << "Teacher";
	}
}
class User {
protected:
	String first_name;
	String last_name;
	static int currentID;
	size_t ID;
	String password;
	Vector<Message> messages;
	Role role;

public:
	User();
	Role getRole() const;
	User(const String& first_name, const String& last_name);
	size_t getID() const;
	Vector<Message>& getMail();
	void setPassword(const String& password);
	const String& getFirstName() const;
	const String& getLastName() const;
	const String& getPassword() const;
	void seeMails(std::ostream& os) const;
	void deleteMail();
	void addMessage(const Message& message);
	void sentMessage(const Message& message, User* user);
	void printInfo(std::ostream& os) const;
	virtual ~User() = 0;
};
