#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

// źȭ���� ����
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	string ch; // źȭ���ҽ�
	cin >> ch;

	string a, b; // a, b ���� ����
	int sum = 0; // a, b ���� ��

	int hIndex = 0;

	// a ���ϱ�
	for (int i = 1; i < ch.size(); i++) // 1~chũ�� ���鼭
	{
		if (ch[i] == 'H') // H�� ������ H �ε��� ���� �� ����
		{
			hIndex = i;
			break;
		}

		a.push_back(ch[i]); // 2 4
	}

	// b ���ϱ�
	for (int i = hIndex + 1; i < ch.size(); i++) // hIndex~chũ�� ���鼭
	{
		b.push_back(ch[i]); // 4 2
	}

	// a �������ϱ�
	// 12 * 24
	if (a.empty())
	{
		sum += 12;
	}
	else
	{
		for (int i = 0; i < a.size(); i++)
		{
			sum += 12 * (a[i] - '0') * pow(10, a.size() - i - 1);
		}
	}

	// b �������ϱ�
	// 1 * 42
	if (b.empty())
	{
		sum += 1;
	}
	else
	{
		for (int i = 0; i < b.size(); i++)
		{
			sum += 1 * (b[i] - '0') * pow(10, b.size() - i - 1);
		}
	}

	cout << sum << '\n';

	// //����� ��
	//for (int i = 0; i < a.size(); i++)
	//{
	//	cout << a[i] << ' ';
	//}

	//cout << '\n';

	//for (int i = 0; i < b.size(); i++)
	//{
	//	cout << b[i] << ' ';
	//}

	return 0;
}