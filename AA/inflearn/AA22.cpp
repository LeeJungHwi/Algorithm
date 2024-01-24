#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 1. �µ� �ִ� ���� ���ϴ� �Լ�
// n 10 k 3 �϶�
// 012 123 234 345 456 567 678 789
// ó�� �µ� ���� ���ϰ� �ε���0 ���� ������ �� ����
// �ڿ� 2�� �� ���� -> �ڿ� k - 1�� �� ����
// ���� �ε��� -> ����Ȱ� + (k + i)�ε����ǰ�
// n 10 k 4 �϶�
// 0123 1234 2345 3456 4567 5678 6789
// ó�� �µ� ���� ���ϰ� �ε���0 ���� ������ �� ����
// �ڿ� 3�� �� ���� -> �ڿ� k - 1�� �� ����
// ���� �ε��� -> ����Ȱ� + (k + i)�ε����ǰ�
void GetMaxTemp(vector<int> &tempVec, int &max, int sum, int n, int k)
{
	int reuseTemp = 0; // ������ �µ� ��

	for (int i = 0; i < k; i++) // ó�� �µ� �� �� ���� �µ�
	{
		sum += tempVec[i]; // 0 + 1 + 2
		reuseTemp = sum - tempVec[0]; // 1 + 2
	}

	if (max < sum) // �ִ� �µ� �� ����
	{
		max = sum;
	}

	sum = 0; // �µ� �� �ʱ�ȭ

	for (int i = 0; i < n - k; i++) // 1���� n-k ���� �µ� ����
	{
		sum = reuseTemp + tempVec[k + i]; // 0 : 1 + 2 + 3 -> 1 : 2 + 3 + 4 -> ... -> 6 : 7 + 8 + 9
		reuseTemp = sum - tempVec[i + 1]; // 0 : 1 + 2 - 1 + 3 = 2 + 3 -> 1 : 2 + 3 - 2 + 4 = 3 + 4 -> ... -> 6 : 7 + 8 - 7 + 9 = 8 + 9

		if (max < sum) // �ִ� �µ� �� ����
		{
			max = sum; // 1 + 2 + 3
		}

		sum = 0; // �µ� �� �ʱ�ȭ
	}

	cout << max << '\n';
}

// �µ��� �ִ밪
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n, k; // N, K
	cin >> n >> k;

	vector<int> temperatures(100000, 0); // �µ� ����

	int temp; // �µ�

	int sumTemp = 0; // �µ� ��
	int maxTempSum = -10000000; // �ִ� �µ� �� : 100000 * (-100) = 10000000

	// �µ� ����
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		temperatures[i] = temp;
	}

	// 1. �µ� �ִ� ���� ���ϴ� �Լ�
	GetMaxTemp(temperatures, maxTempSum, sumTemp, n, k);

	return 0;
}

// �ٽ�
// ������ ����