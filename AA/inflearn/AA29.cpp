#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int threeCnt; // 3�� ����

// �ڸ��� ��� �Լ�
int GetPos(int n)
{
	int pos = 0;

	if (n < 10)
	{
		return pos = 1;
	}
	else if (n < 100)
	{
		return pos = 2;
	}
	else if (n < 1000)
	{
		return pos = 3;
	}
	else if (n < 10000)
	{
		return pos = 4;
	}
	else if (n < 100000)
	{
		return pos = 5;
	}
}

// 3�� ������?(small)
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	for (int i = 1; i < n + 1; i++)
	{
		int tempNum = i; // ī�����ϱ����� �ӽü��� �ʱ�ȭ 353

		for (int j = 0; j < GetPos(i); j++)
		{
			if (tempNum % 10 == 3) // 10���� ���� �������� 3�̸� ī����
			{
				threeCnt++;
			}

			tempNum /= 10; // 1�� �ڸ� ���� 35
		}
	}
	cout << threeCnt;

	return 0;
}

// �ٽ�
// ���� �ڸ� üũ