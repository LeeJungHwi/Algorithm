#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// �Ÿ� �α�
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 10
	cin >> n;

	/*
	0�� 1�� : �Ÿ� 1
	0�� 2�� : �Ÿ� 1
	0�� 3�� : �Ÿ� 2
	0�� 4�� : �Ÿ� 2
	0�� 5�� : �Ÿ� 3
	....
	*/
	// max(�ִ뿬�� 0�� ����, ù�ڸ��� ���ڸ��϶� ���� 0�� ����, �������ڸ��� ���ڸ��϶� ���� 0�� ����) ���

	int maxZeroCnt = 0; // �ִ뿬�� 0�� ����
	int zeroCnt = 0; // ���� 0�� ����

	int num; // ���ڸ�(0) ���� �̹̾����ڸ� (1) ����

	bool isFirst = false; // ù�ڸ��� ���ڸ����� üũ
	bool isLast = false; // �������ڸ��� ���ڸ����� üũ

	int firstZeroCnt = 0; // ù�ڸ��� ���ڸ��϶� ���� 0�� ���� ����
	int lastZeroCnt = 0; // �������ڸ��� ���ڸ��϶� ���� 0�� ���� ����

	vector<int> seats(n); // �¼� ����

	// 1 0 0 0 1 0 0 1 0 1
	for (int i = 0; i < n; i++)
	{
		cin >> num;

		seats[i] = num;

		if (i == 0 && num == 0)
		{
			isFirst = true;
		}

		if (i == n - 1 && num == 0)
		{
			isLast = true;
		}

		if (num == 0) // ���ڸ��� ���� 0�� ���� ����
		{
			zeroCnt++;

			// �ִ뿬�� 0�� ���� ����
			if (maxZeroCnt < zeroCnt)
			{
				maxZeroCnt = zeroCnt;
			}
		}
		else // �̹� �����ڸ��� ���� 0�� ���� �ʱ�ȭ
		{
			zeroCnt = 0;
		}
	}

	// ù�ڸ��� ���ڸ��϶� ���� 0�� ���� ���ϱ�
	if (isFirst)
	{
		for (int i = 0; i < n; i++)
		{
			if (seats[i] == 0) // ���ڸ� ������ ���� 0�� ���� ����
			{
				firstZeroCnt++;
			}
			else // �����ڸ� ������ ����
			{
				break;
			}
		}
	}

	// �������ڸ��� ���ڸ��϶� ���� 0�� ���� ���ϱ�
	if (isLast)
	{
		for (int i = n - 1; i > -1; i--)
		{
			if (seats[i] == 0) // ���ڸ� ������ ���� 0�� ���� ����
			{
				lastZeroCnt++;
			}
			else // �����ڸ� ������ ����
			{
				break;
			}
		}
	}

	// 0�� Ȧ���� : �ִ뿬�� 0�� ���� / 2 + 1
	// 0�� ¦���� : �ִ뿬�� 0�� ���� / 2
	if (maxZeroCnt % 2 == 1)
	{
		maxZeroCnt = maxZeroCnt / 2 + 1;
	}
	else
	{
		maxZeroCnt = maxZeroCnt / 2;
	}

	// max(�ִ뿬�� 0�� ����, ù�ڸ��� ���ڸ��϶� ���� 0�� ����, �������ڸ��� ���ڸ��϶� ���� 0�� ����) ���
	maxZeroCnt = max(maxZeroCnt, firstZeroCnt);
	maxZeroCnt = max(maxZeroCnt, lastZeroCnt);

	cout << maxZeroCnt;

	return 0;
}