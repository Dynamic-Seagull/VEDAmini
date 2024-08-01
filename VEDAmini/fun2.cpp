#include <iostream>
#include "To_do.h"
#include "user.h"

ToDo::ToDo()
{
	m_list.clear();
}
ToDo::~ToDo()
{
	m_list.clear();
}

void ToDo::modify(int idx, std::string input)
{
	if (m_list.size() > idx)
		std::cout << "Out of range.\n";
	else
	{
		m_list[idx - 1] = input;
		std::cout << "���� �Ϸ�Ǿ����ϴ�.\n";
	}
}

void ToDo::del(int idx)
{
	if (m_list.size() < idx)
		std::cout << "Out of range.\n";
	else
	{
		for (auto it = m_list.begin(); it != m_list.end(); it++)
		{
			if (it == m_list.begin() + idx - 1)
			{
				std::string test = m_list.at(idx - 1);
				m_list.erase(it);
				std::cout << idx << "�� ° �� �� ��� ������ �Ϸ�Ǿ����ϴ�.\n";

				break;
			}
		}
	}
}