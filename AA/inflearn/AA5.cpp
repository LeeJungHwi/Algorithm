#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// 나이계산
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	string id; // 주민번호
	cin >> id;

	int age = 0; // 나이
	char gen = 'M'; // 성별

	switch (id[7] - '0') // 뒷자리 첫번째 수에 따른 나이와 성별 계산
	{
		case 1:
			age = 2019 - (1900 + ((id[0] - '0') * 10 + (id[1]) - '0')) + 1;
			break;
		case 2:
			age = 2019 - (1900 + ((id[0] - '0') * 10 + (id[1]) - '0')) + 1;
			gen = 'W';
			break;
		case 3:
			age = 2019 - (2000 + ((id[0] - '0') * 10 + (id[1]) - '0')) + 1;
			break;
		case 4:
			age = 2019 - (2000 + ((id[0] - '0') * 10 + (id[1]) - '0')) + 1;
			gen = 'W';
			break;
	}

	cout << age << ' ' << gen << '\n';

	return 0;
}

// 핵심
// 문자를 숫자로 -> char - '0'