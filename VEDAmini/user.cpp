#include "user.h"

User::User() : User("dummy") {}

void User::setName(string s)
{
	name = s;
}

void User::U_insert(string input)
{
	myList.insert(input);
}

void User::U_allPrint() const
{
	myList.allPrint();
}

void User::U_modify(int idx, string input)
{
	myList.modify(idx, input);
}

void User::U_del(int idx)
{
	myList.del(idx);
}

void User::U_load(string name)
{
	myList.load(name);
}

void User::U_save(string name) const
{
	myList.save(name);
}

bool User::U_check(string name)
{
	return myList.check(name);
}

void User::U_clear()
{
	myList.listClear();
}
