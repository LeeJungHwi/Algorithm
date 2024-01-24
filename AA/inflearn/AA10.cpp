#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// �ڸ��� ��
// 125 = 100 + 20 + 5 = ((num - num % 100) / 100) + (num % 100 - num % 10) + num % 10
int digit_sum(int x)
{
	int sum = 0; // �ڸ��� ��

	for (int j = 10000000; j > 0; j /= 10) // �ڸ��� �� ���ϱ�
	{
		sum += ((x - x % j) / j);
		x %= j;
	}

	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	int num; // �ڿ���

	int maxSum = 0; // �ڸ��� �� �ִ�

	int maxNum = 0; // �ڸ��� �� �ִ��� ��

	vector<int> sums(101); // �� �ڿ����� �ڸ��� ��

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		int saveNum = num; // �ڿ��� ���

		sums[i] = digit_sum(num); // �ڸ��� ��

		if (maxSum < sums[i]) // �ڸ��� �� �ִ뺸�� ũ�� �ڸ��� �� �ִ� ����
		{
			maxSum = sums[i];
			maxNum = saveNum;
		}
		else if (maxSum == sums[i]) // �ڸ��� �� �ִ�� ������ �ڸ��� �� �ִ��� �� ����
		{
			if (maxNum < saveNum)
			{
				maxNum = saveNum;
			}
		}
	}

	cout << maxNum << '\n';

	return 0;
}