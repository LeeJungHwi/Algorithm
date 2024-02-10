#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// ���ٸ� �ǳʱ�
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 7
	cin >> n;

	vector<int> rocks(n); // ���ٸ� ����
	int minCost = 2147000000; // �ּҺ�� ����

	// 2 2 50 2 3 50 5
	for (int i = 0; i < n; i++)
	{
		cin >> rocks[i];
	}

	// 1. ù��° ���ٸ� ���� �����ϴ� ���

	int cost = rocks[0]; // ���ٸ� ���
	int standardPos = 0; // ������ġ

	while (true)
	{
		// �������� : n - 2�϶� ��ĭ�����ϸ� ������ ����, n - 1�϶� ��ĭ�����ϸ� ������ ����
		if (standardPos == n - 1 || standardPos == n - 2)
		{
			break;
		}

		// ��ĭ���� �� ũ�ų� ������ ��ĭ���� ���� ���ٸ� ��ġ
		if (rocks[standardPos + 1] >= rocks[standardPos + 2])
		{
			cost += rocks[standardPos + 2];
			standardPos += 2;
		}
		else // ��ĭ���� �� ū ��� ��ĭ���� ���� ���ٸ� ��ġ
		{
			cost += rocks[standardPos + 1];
			standardPos += 1;
		}
	}

	// �ּҺ�� ����
	minCost = min(minCost, cost);

	// 2. �ι�° ���ٸ� ���� �����ϴ� ���

	cost = rocks[1]; // ���ٸ� ���
	standardPos = 1; // ������ġ

	while (true)
	{
		// �������� : n - 2�϶� ��ĭ�����ϸ� ������ ����, n - 1�϶� ��ĭ�����ϸ� ������ ����
		if (standardPos == n - 1 || standardPos == n - 2)
		{
			break;
		}

		// ��ĭ���� �� ũ�ų� ������ ��ĭ���� ���� ���ٸ� ��ġ
		if (rocks[standardPos + 1] >= rocks[standardPos + 2])
		{
			cost += rocks[standardPos + 2];
			standardPos += 2;
		}
		else // ��ĭ���� �� ū ��� ��ĭ���� ���� ���ٸ� ��ġ
		{
			cost += rocks[standardPos + 1];
			standardPos += 1;
		}
	}

	// �ּҺ�� ����
	minCost = min(minCost, cost);

	cout << minCost;

	return 0;
}