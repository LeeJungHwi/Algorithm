#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// ����Լ� ������ ���
// 11
// 5 ... 1
// 2 ... 1
// 1 ... 0
// 0 ... 1
void PrintBinary(int n)
{
	if (n / 2 == 0)
	{
		cout << n % 2 << ' ';
	}
	else
	{
		PrintBinary(n / 2);
		cout << n % 2 << ' ';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	PrintBinary(n);

	return 0;
}
// �ٽ�
// �Լ� ȣ�⽺�� üũ