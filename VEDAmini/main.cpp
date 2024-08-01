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
	//폴더 없으면 생성 (사용자 정보 저장용)
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
	unique_ptr<User> pUser;
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
			pUser = make_unique <User>();
			//사용자가 이미 있으면 break.
			if (!pUser->U_check(name))
			{
				cout << "This name already exists." << endl;
				break;
			}
			pUser->setName(name);
			fileName = name;

			while (true)
			{
				cout << "Input Task (End Code : end) : ";
				getline(cin, todo);
				if (todo == "end") break;
				pUser->U_insert(todo);
			}
			cout << endl;
			break;

		case 2:
			//사용자 선택
			pUser = make_unique <User>();
			cout << "Input Name (Select) : ";
			getline(cin, name);
			pUser->U_load(name);
			cout << endl;
			break;

		case 3:
			//할 일 조회
			tbColor(14, 0);
			pUser->U_allPrint();
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
				pUser->U_insert(todo);
			}
			cout << endl;
			break;

		case 5:
			//할 일 수정
			int editN;
			cout << "Please select the number" << endl;
			tbColor(14, 0);
			pUser->U_allPrint();
			tbColor(15, 0);
			cout << "Input Number : ";
			cin >> editN;
			cout << "Input Task :";
			cin >> todo;
			pUser->U_modify(editN, todo);
			cout << endl;
			break;

		case 6:
			//할 일 삭제
			cout << "Please select the number you want to delete" << endl;
			tbColor(14, 0);
			pUser->U_allPrint();
			tbColor(15, 0);
			cout << "Input Number : ";
			cin >> editN;
			pUser->U_del(editN);
			cout << endl;
			break;

		case 7:
			//완료
			cout << "Choose clear task" << endl;
			tbColor(14, 0);
			pUser->U_allPrint();
			tbColor(15, 0);
			cout << "Input Number : ";
			cin >> editN;
			pUser->U_clear(editN);

		case 8:
			pUser->U_save(name);
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
