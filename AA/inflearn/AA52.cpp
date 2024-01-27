#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
using namespace std;

// ��۸� ����
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 10
	cin >> n;

	int uglyNumCnt = 1; // ��۸� ���� ����
	int curNum = 2; // ��۸� �������� üũ�� ����

	if (n == 1) // ù��° ��۸� ���ڴ� 1
	{
		cout << 1 << '\n';

		return 0;
	}
	else // �ι�° ��۸� ���ں��ʹ�
	{
		while (uglyNumCnt < n) // n��° ��۸� ���ڰ� �Ǹ� ����
		{
			int i = curNum;
			
			// 2�� ���������� �������� 0�� �ƴҶ����� ������
			while (i % 2 == 0)
			{
				i /= 2;
			}

			// 3���� ���������� �������� 0�� �ƴҶ����� ������
			while (i % 3 == 0)
			{
				i /= 3;
			}

			// 5�� ���������� �������� 0�� �ƴҶ����� ������
			while (i % 5 == 0)
			{
				i /= 5;
			}

			// i�� 1�̸� ��۸� ����
			if (i == 1)
			{
				uglyNumCnt++;
			}

			// üũ�� ���� ����
			curNum++;
		}
	}

	cout << curNum - 1 << '\n';

	return 0;
}