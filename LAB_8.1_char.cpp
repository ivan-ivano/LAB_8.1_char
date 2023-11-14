#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
bool hasPair(char* s)
{
	if (strchr(s, 'SQ') && strchr(s, 'QS'))
		return true;
	else
		return false;
}

char* Change(char str[]) {
	char* position = nullptr;

	while ((position = strstr(str, "SQ")) != nullptr || (position = strstr(str, "QS")) != nullptr) {
		memmove(position + 3, position + 2, strlen(position + 2) + 1);
		strncpy(position, "***", 3);
	}

	return str;
}

int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);

	if (hasPair(str))
		cout << "Found a pair 'SQ' or 'QS' in the string." << std::endl;

	else
		cout << "No pair 'SQ' or 'QS' found in the string." << std::endl;

	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}
