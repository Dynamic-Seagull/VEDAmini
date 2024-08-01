#ifndef _USER_H
#define _USER_H
#include <string>
using namespace std;

class User
{
	string name;
public:
	User();
	User(string s) { setName(s); }
	void setName(string s);
};


#endif
