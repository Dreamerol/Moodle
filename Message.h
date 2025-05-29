#pragma once
#pragma once
#include "String.h"
#include <ctime>
class User;

class Message {
	User* sender;
	User* receiver;
	String content;
	time_t timestamp;


public:
	User* getSender() const;
	String getContent() const;
	Message(User* sender, User* receiver, const String& content);
	String getTime() const;
	Message();


};