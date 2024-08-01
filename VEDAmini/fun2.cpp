#include <iostream>
#include "To_do.h"
#include <fstream>
#include <filesystem>

ToDo::ToDo()
{
	m_list.clear();
	c_list.clear();
}
ToDo::~ToDo()
{
	m_list.clear();
	c_list.clear();
}

void ToDo::modify(int idx, std::string input)
{
	if (m_list.size() < idx)
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

void ToDo::load(std::string name)
{
	std::string fileName = ".\\userInfo\\" + name + ".txt";

	std::ifstream loadFile(fileName);
	if (!loadFile)
		std::cout << "������ �ۼ� �� ����� �����ϴ�.\n";

	std::string temp;
	m_list.clear();

	while (std::getline(loadFile, temp))
	{
		m_list.push_back(temp);
	}

	loadFile.close();
	std::cout << "�� �� ����Ʈ �ҷ����Ⱑ �Ϸ� �Ǿ����ϴ�.\n";

	// ---------------------------------------------------------

	if (c_list.size() > 0)
	{
		fileName = ".\\done\\" + name + "_clear" + ".txt";

		std::ifstream loadFile(fileName);
		if (!loadFile)
			std::cout << "������ �ۼ� �� ����� �����ϴ�.\n";

		temp;
		c_list.clear();

		while (std::getline(loadFile, temp))
		{
			c_list.push_back(temp);
		}

		loadFile.close();
		std::cout << "�Ϸ��� �� ����Ʈ �ҷ����Ⱑ �Ϸ� �Ǿ����ϴ�.\n";
	}
}

void ToDo::save(std::string name) const
{
	std::string fileName = ".\\userInfo\\" + name + ".txt";
	std::ofstream saveFile(fileName);
	if (!saveFile)
		std::cout << "������ �� �� �����ϴ�.\n";

	for (auto& x : m_list)
	{
		saveFile << x << std::endl;
	}

	saveFile.close();
	std::cout << "������ �Ϸ� �Ǿ����ϴ�.\n";

	// ---------------------------------------------------------

	if (c_list.size() > 0)
	{
		fileName = ".\\done\\" + name + "_clear" + ".txt";
		std::ofstream saveFile(fileName);
		if (!saveFile)
			std::cout << "������ �� �� �����ϴ�.\n";

		for (auto& x : c_list)
		{
			saveFile << x << std::endl;
		}

		saveFile.close();
		std::cout << "������ �Ϸ� �Ǿ����ϴ�.\n";
	}
}

bool ToDo::check(std::string name) const
{
	std::string fileName = ".\\userInfo\\" + name + ".txt";
	std::ifstream checkPtr(fileName);
	if (!checkPtr)
		return true; // ���� �ۼ�
	else return false; // �̹� �ִ� �̸�
}

void ToDo::clear(int idx)
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
				c_list.push_back(test);
				std::cout << idx << "�� ° ���� �Ϸ� ���·� �����Ͽ����ϴ�.\n";

				break;
			}
		}
	}
}