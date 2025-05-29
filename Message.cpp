#include "Message.h"
#include <ctime>

Message::Message(User* sender, User* receiver, const String& content) :sender(sender),
receiver(receiver),
content(content) {
	timestamp = std::time(nullptr);
}
Message::Message() {
	sender = nullptr;
	receiver = nullptr;
	content = "";
}
String Message::getContent() const {
	return content;
}
User* Message::getSender() const {
	return sender;
}
String Message::getTime() const {
	struct tm* timeinfo;
	timeinfo = localtime(&timestamp);
	char buffer[30];
	strftime(buffer, 30, "%Y-%m-%d %H:%M:%S", timeinfo);
	return String(buffer);

}