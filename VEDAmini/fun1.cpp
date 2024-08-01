#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "To_do.h"
#include "user.h"

void ToDo::insert(std::string input)
{
	m_list.push_back(input);
}
void ToDo::allPrint() const
{
	for (int i = 0; i < m_list.size(); i++)
	{
		cout << i+1 << ". " << m_list[i] <<endl;
	}
}
