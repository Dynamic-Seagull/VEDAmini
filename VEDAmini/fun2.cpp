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
		std::cout << "수정 완료되었습니다.\n";
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
				std::cout << idx << "번 째 할 일 목록 삭제가 완료되었습니다.\n";

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
		std::cout << "이전에 작성 한 기록이 없습니다.\n";

	std::string temp;
	m_list.clear();

	while (std::getline(loadFile, temp))
	{
		m_list.push_back(temp);
	}

	loadFile.close();
	std::cout << "할 일 리스트 불러오기가 완료 되었습니다.\n";

	// ---------------------------------------------------------

	if (c_list.size() > 0)
	{
		fileName = ".\\done\\" + name + "_clear" + ".txt";

		std::ifstream loadFile(fileName);
		if (!loadFile)
			std::cout << "이전에 작성 한 기록이 없습니다.\n";

		temp;
		c_list.clear();

		while (std::getline(loadFile, temp))
		{
			c_list.push_back(temp);
		}

		loadFile.close();
		std::cout << "완료한 일 리스트 불러오기가 완료 되었습니다.\n";
	}
}

void ToDo::save(std::string name) const
{
	std::string fileName = ".\\userInfo\\" + name + ".txt";
	std::ofstream saveFile(fileName);
	if (!saveFile)
		std::cout << "파일을 열 수 없습니다.\n";

	for (auto& x : m_list)
	{
		saveFile << x << std::endl;
	}

	saveFile.close();
	std::cout << "저장이 완료 되었습니다.\n";

	// ---------------------------------------------------------

	if (c_list.size() > 0)
	{
		fileName = ".\\done\\" + name + "_clear" + ".txt";
		std::ofstream saveFile(fileName);
		if (!saveFile)
			std::cout << "파일을 열 수 없습니다.\n";

		for (auto& x : c_list)
		{
			saveFile << x << std::endl;
		}

		saveFile.close();
		std::cout << "저장이 완료 되었습니다.\n";
	}
}

bool ToDo::check(std::string name) const
{
	std::string fileName = ".\\userInfo\\" + name + ".txt";
	std::ifstream checkPtr(fileName);
	if (!checkPtr)
		return true; // 최초 작성
	else return false; // 이미 있는 이름
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
				std::cout << idx << "번 째 일을 완료 상태로 변경하였습니다.\n";

				break;
			}
		}
	}
}