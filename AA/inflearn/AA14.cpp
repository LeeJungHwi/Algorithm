#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

// �ڿ��� �ڸ��� üũ
int NumPosCheck(int num)
{
	int pos = 0;

	if (num < 10)
	{
		return pos = 1;
	}
	else if (num >= 10 && num < 100)
	{
		return pos = 2;
	}
	else if (num >= 100 && num < 1000)
	{
		return pos = 3;
	}
	else if (num >= 1000 && num < 10000)
	{
		return pos = 4;
	}
	else if (num >= 10000 && num < 100000)
	{
		return pos = 5;
	}
}

// ���ڸ� ������ �Լ�
// 3700
// 37
// 73
int reverse(int num)
{
	int reverseNum = 0; // ������ �ڿ���
	int pos = 0; // �ڿ��� �ڸ���

	// 3700
	// 370
	// 37
	while (num % 10 == 0) // 10���� ���� �������� 0�϶� �ݺ�
	{
		num /= 10; // 1���ڸ� ����
	}

	// �ڿ��� ������
	// 37
	// 7 * 10^1 + 3 * 10^0
	// 73
	pos = NumPosCheck(num); // �ڿ��� �ڸ��� üũ

	for (int i = pos; i > 0; i--)
	{
		reverseNum += (num % 10) * pow(10, i - 1); // 70 + 3
		num /= 10; // 1���ڸ� ����
	}

	return reverseNum;
}

// �Ҽ����� üũ
// 1���� ū �ڿ��� �� ����� 1�� �ڱ��ڽŸ� ��������
bool isPrime(int num)
{
	if (num == 1) // ������ �ڿ����� 1�̸� �Ҽ� �ƴ�
	{
		return false;
	}

	for (int i = 2; i < num; i++) // 1�� �ڱ��ڽ��� ������ ���� ���������� ������ �������� �Ҽ� �ƴ�
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}

// ������ �Ҽ�
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	int num; // �ڿ���

	for (int i = 0; i < n; i++)
	{
		cin >> num;

		num = reverse(num); // �ڿ��� ������
		
		if (isPrime(num)) // ������ ���� �Ҽ��� ���
		{
			cout << num << ' ';
		}
	}

	return 0;
}

// �ٽ�
// �Ҽ� -> 1���� ū �ڿ��� �� 1�� �ڱ��ڽŸ� ����� ������ �� 