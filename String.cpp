#include "String.h"
#include <fstream>
String::String(const char* str) : str(nullptr), len(0) {
	if (str == nullptr) {
		str = "";
	}
	this->len = strlen(str);
	this->str = new char[this->len + 1];
	strcpy(this->str, str);
}
String::String() : String("") {};
String::String(const String& other) {
	copyFrom(other);
}

String& String::operator=(const String& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

String::~String() {
	free();
}

void String::copyFrom(const String& other) {

	this->len = other.len;
	this->str = new char[this->len + 1];
	strcpy(this->str, other.str);
}

size_t String::getLength() const {
	return this->len;
}

const char* String::getStr() const {
	return str;
}

void String::free() {
	delete[] str;
	str = nullptr;
	len = 0;
}

char& String::operator[](size_t idx) {
	if (idx >= this->len) {
		return this->str[this->len - 1];
	}
	else if (idx < 0) {
		return this->str[0];
	}
	return this->str[idx];
}

const char& String::operator[](size_t idx) const {
	if (idx >= this->len) {
		return this->str[this->len - 1];
	}
	else if (idx < 0) {
		return this->str[0];
	}
	return this->str[idx];
}

std::ostream& operator<<(std::ostream& os, const String& other) {
	os << other.getStr();
	return os;
}
std::istream& operator>>(std::istream& is, String& other) {
	char buffer[BUFFER_LENGTH];
	is >> buffer;
	//is.getline(buffer, BUFFER_LENGTH);
	if (!is) {
		other = "";
		return is;
	}
	other = buffer;
	return is;
}

bool operator==(const String& lhs, const String& rhs) {
	return(strcmp(lhs.getStr(), rhs.getStr()) == 0);
}

bool operator!=(const String& lhs, const String& rhs) {
	return !(lhs == rhs);
}


String& String::operator+=(const String& other) {
	size_t newlen = this->len + other.len;
	char* result = new char[newlen + 1];
	strcpy(result, this->str);
	strcat(result, other.str);
	free();
	this->len = newlen;
	this->str = result;
	return *this;
}
bool operator>(const String& lhs, const String& rhs) {
	return (strcmp(lhs.getStr(), rhs.getStr()) > 0);
}
bool operator<(const String& lhs, const String& rhs) {
	return (strcmp(lhs.getStr(), rhs.getStr()) < 0);
}

bool operator>=(const String& lhs, const String& rhs) {
	return (lhs > rhs || lhs == rhs);
}
bool operator<=(const String& lhs, const String& rhs) {
	return (lhs < rhs || lhs == rhs);
}
String operator+(const String& lhs, const String& rhs) {
	String result = lhs;
	result += rhs;
	return result;

}