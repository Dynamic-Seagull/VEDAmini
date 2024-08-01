#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "To_do.h"
#include "user.h"

//std::vector<std::string> m_list;

void To_do::insert(std::string input)
{
	m_list.push_back(input);
}
void To_do::allPrint() const
{
	for (int i = 0; i < m_list.size(); i++)
	{
		cout << "To-Do List" << endl;
		cout << i << ". " << m_list[i] <<endl;
	}
}