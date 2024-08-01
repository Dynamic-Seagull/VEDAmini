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