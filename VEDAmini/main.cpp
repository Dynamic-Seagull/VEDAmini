#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <windows.h>
using namespace std;
#include "user.h"
#include "To_do.h"
namespace sf = std::filesystem;

void tbColor(unsigned short textColor, unsigned short backColor) {
	int color = textColor + backColor * 16;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main()
{
	if (!(sf::exists(sf::path("./userInfo"))))
	{
		sf::create_directory(sf::path("./userInfo"));
		cout << "create directory" << endl;
	}
	if (!(sf::exists(sf::path("./done"))))
	{
		sf::create_directory(sf::path("./done"));
		cout << "create directory" << endl;
	}

	int menuNum = 0;
	string name;
	string todo;
	User user;
	string fileName;
	ifstream loadFile(fileName);

	do
	{
		cout << "---------------" << endl;
		cout << "1. User : Add " << endl;
		cout << "2. User : select " << endl;
		cout << "3. To-Do : Show List " << endl;
		cout << "4. To-Do : Add Task " << endl;
		cout << "5. To-Do : Edit " << endl;
		cout << "6. To-Do : Delete " << endl;
		cout << "7. To-Do : Clear " << endl;
		cout << "8. Save " << endl;
		cout << endl;
		cout << "9. Quit " << endl;
		cout << "---------------" << endl;

		cout << "Select : ";
		cin >> menuNum;
		getchar();
		switch (menuNum)
		{
		case 1:
			//사용자 추가
			cout << "Input Name (New) : ";
			getline(cin, name);
			//사용자가 이미 있으면 break.
			if (!user.U_check(name))
			{
				cout << "This name already exists." << endl;
				break;
			}
			user.setName(name);
			fileName = name;

			while (true)
			{
				cout << "Input Task (End Code : end) : ";
				getline(cin, todo);
				if (todo == "end") break;
				user.U_insert(todo);
			}
			// 사용자 파일 생성. 내용 출력 후 닫기.
			user.U_save(fileName);
			user.U_listClear();
			cout << endl;
			break;

		case 2:
			//사용자 선택
			user.U_listClear();
			cout << "Input Name (Select) : ";
			getline(cin, name);
			user.U_load(name);
			cout << endl;
			break;

		case 3:
			//할 일 조회
			tbColor(14, 0);
			user.U_allPrint();
			tbColor(15, 0);
			cout << endl;
			break;

		case 4:
			//할 일 추가
			while (true)
			{
				cout << "Input Task (End Code : end) : ";
				getline(cin, todo);
				if (todo == "end") break;
				user.U_insert(todo);
			}
			cout << endl;
			break;

		case 5:
			//할 일 수정
			int editN;
			cout << "Please select the number" << endl;
			cout << "To-Do List" << endl;
			user.U_allPrint();
			cout << "Input Number : ";
			cin >> editN;
			cout << "Input Task :";
			cin >> todo;
			user.U_modify(editN, todo);
			cout << endl;
			break;

		case 6:
			//할 일 삭제
			cout << "Please select the number you want to delete" << endl;
			tbColor(14, 0);
			user.U_allPrint();
			tbColor(15, 0);
			cout << "Input Number : ";
			cin >> editN;
			user.U_del(editN);
			cout << endl;
			break;

		case 7:
			//완료
			cout << "Choose clear task" << endl;
			tbColor(14, 0);
			user.U_allPrint();
			tbColor(15, 0);
			cout << "Input Number : ";
			cin >> editN;
			user.U_clear(editN);

		case 8:
			user.U_save(name);
			cout << endl;
			break;

		case 9:
			cout << "Quit." << endl;
			cout << endl;
			break;

		defult:
			cout << "Please select again." << endl;
			cout << endl;
			break;
		}
	} while (menuNum != 9);

	return 0;
}
