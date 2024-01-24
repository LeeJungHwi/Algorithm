#include <iostream>
#include <fstream>
using namespace std;

// �Ҽ��� ����
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	int cntPrime = 0; // �Ҽ� ����
	bool isPrime = false; // �Ҽ����� üũ

	// �Ҽ����� üũ �� �Ҽ� ���� ����
	// 36
	// = 1 * 36
	// = 2 * 18
	// = 3 * 12
	// = 4 * 9
	// = 6 * 6
	// 36�� ������ ������ üũ�ϸ� ��
	for (int i = 2; i < n + 1; i++) // 2~N ����
	{
		isPrime = true;

		for (int j = 2; j * j <= i; j++) // 1�� �ڱ��ڽ��� ������ ���� ���������� ������ �������� �Ҽ� �ƴ�, �ڿ����� ������ ������ üũ
		{
			if (i % j == 0) // i�� ����� j�̸� �Ҽ��� �ƴ�
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime)
		{
			cntPrime++;
		}
	}

	cout << cntPrime << '\n';

	return 0;
}

// �ٽ�
// �Ҽ� üũ -> �ڿ����� ������ ������ üũ