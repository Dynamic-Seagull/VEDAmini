#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
#include "user.h"
#include "To_do.h"

int main()
{
	int menuNum = 0;
	string name;
	string todo;
	User user;
	string fileName;
	ifstream loadFile(fileName);
	do
	{
		cout << "---------------" << endl;
		cout << "1. User : Add " <<endl;
		cout << "2. User : select " << endl;
		cout << "3. To-Do : Show List " << endl;
		cout << "4. To-Do : Add Task " << endl;
		cout << "5. To-Do : Edit " << endl;
		cout << "6. To-Do : Delete " << endl;
		cout << "7. Save " << endl;
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
			cout << endl;
			break;

		case 2:
			//사용자 선택
			cout << "Input Name (Select) : ";
			getline(cin, name);
			user.U_load(name);
			cout << endl;
			break;

		case 3:
			//할 일 조회
			cout << "To-Do List" << endl;
			user.U_allPrint();
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
			user.U_allPrint();
			cout << "Input Number : ";
			cin >> editN;
			user.U_del(editN);
			cout << "To-Do List" << endl;
			user.U_allPrint();
			cout << endl;
			break;

		case 7:
			user.U_save(name);
			cout << endl;
			break;

		case 9:
			cout << "Quit."<<endl;
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
