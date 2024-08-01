#include <vector>
#include <string>

#ifndef _TO_DO_H
#define _TO_DO_H
class ToDo
{
private:
	std::vector<std::string> m_list;
public:
	ToDo();
	~ToDo();
	void insert(std::string input);
	void modify(int idx, std::string input);
	void del(int dix);
	void allPrint() const;
	void load(std::string name);
	void save(std::string name) const;
	bool check(std::string name) const;
	void listClear();
};
#endif