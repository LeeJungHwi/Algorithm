#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// ���̰��
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	string id; // �ֹι�ȣ
	cin >> id;

	int age = 0; // ����
	char gen = 'M'; // ����

	switch (id[7] - '0') // ���ڸ� ù��° ���� ���� ���̿� ���� ���
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

// �ٽ�
// ���ڸ� ���ڷ� -> char - '0'