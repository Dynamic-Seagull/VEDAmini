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
	string fileName = name + ".txt";
	ifstream loadFile(fileName);

	do
	{
	
		cout << "---------------" << endl;
		cout << "1. 사용자 추가 " <<endl;
		cout << "2. 사용자 선택 " << endl;
		cout << "3. 할 일 조회 " << endl;
		cout << "4. 할 일 추가 " << endl;
		cout << "5. 할 일 수정 " << endl;
		cout << "6. 할 일 삭제 " << endl;
		cout << endl;
		cout << "9. 저장 후 종료 " << endl;
		cout << "---------------" << endl;
	
		cout << "선택 : ";
		cin >> menuNum;
		getchar();
		switch (menuNum)
		{
		case 1:
			//사용자 추가
			cout << "사용자 추가 : ";
			getline(cin, name);
			//사용자가 이미 있으면 break.
			if (loadFile)
				std::cout << "이전에 작성 한 기록이 없습니다.\n";
			user.setName(name);

			while (true)
			{
				cout << "할 일 입력 (종료코드 : end) : ";
				getline(cin, todo);
				if (todo == "end") break;
				user.U_insert(todo);
			}
			// 사용자 파일 생성. 내용 출력 후 닫기.
			user.U_save(fileName);
			break;

		case 2:
			//사용자 선택
			cout << "사용자 선택 : ";
			getline(cin, name);
			user.U_load(name);
			break;

		case 3:
			//할 일 조회
			cout << "To-Do List" << endl;
			user.U_allPrint();
			break;

		case 4:
			//할 일 추가
			while (true)
			{
				cout << "할 일 입력 (종료코드 : end) : ";
				getline(cin, todo);
				if (todo == "end") break;
				user.U_insert(todo);
			}
			break;

		case 5:
			//할 일 수정
			int editN;
			cout << "수정할 할 일의 번호를 선택해주세요" << endl;
			cout << "To-Do List" << endl;
			user.U_allPrint();
			cout << "번호 : ";
			cin >> editN;
			cout << "내용을 작성해주세요" << endl;
			cout << "입력 : ";
			cin >> todo;
			user.U_modify(editN, todo);
			break;

		case 6:
			//할 일 삭제
			cout << "삭제할 번호를 선택해주세요" << endl;
			user.U_allPrint();
			cout << "번호 : ";
			cin >> editN;
			user.U_del(editN);
			cout << "To-Do List" << endl;
			user.U_allPrint();
			break;

		case 9:
			user.U_save(name);
			break;

		defult:
			cout << "다시 선택해주세요." << endl;
			break;
		}
	} while (menuNum != 9);
	
	return 0;
}
