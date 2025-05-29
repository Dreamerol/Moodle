#pragma once
#pragma once
#include <iostream>
#include <cstring>
#pragma warning (disable : 4996)
const int BUFFER_LENGTH = 1024;
class String {

	char* str;
	size_t len;

public:
	String(const char* str);

	String();
	String(const String& other);
	String& operator=(const String& other);
	~String();

	char& operator[](size_t idx);
	const char& operator[](size_t idx) const;
	String& operator+=(const String& other);

	size_t getLength() const;
	const char* getStr() const;

private:
	void free();
	void copyFrom(const String& other);

};
bool operator==(const String& lhs, const String& rhs);
bool operator!=(const String& lhs, const String& rhs);
bool operator>(const String& lhs, const String& rhs);
bool operator<(const String& lhs, const String& rhs);
bool operator>=(const String& lhs, const String& rhs);
bool operator<=(const String& lhs, const String& rhs);

String operator+(const String& lhs, const String& rhs);
std::ostream& operator<<(std::ostream& os, const String& rhs);
std::istream& operator>>(std::istream& is, String& rhs);

