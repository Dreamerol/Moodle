#pragma once
#include "Homework.h"
#include "String.h"
#include "Vector.hpp"
class Task {
	String name;
	Vector<Homework*> homeworks;
public:
	Task(const String& name);
	Vector<Homework*>& getHomeworks();
	const String& getName() const;
	void printHomeworks(std::ostream& os) const;
	void addHomework(Homework& h);
};