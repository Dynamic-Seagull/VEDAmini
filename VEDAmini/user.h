#ifndef _USER_H
#define _USER_H
#include <string>
#include "To_do.h"
using namespace std;

class User
{
	string name;
	ToDo myList;
public:
	User();
	User(string s) { setName(s); }
	void setName(string s);
	void U_insert(string input);
	void U_allPrint() const;
	void U_modify(int idx, string input);
	void U_del(int idx);
};


#endif
