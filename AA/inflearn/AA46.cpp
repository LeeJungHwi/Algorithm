#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// ��Ƽ�½�ŷ
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");
	//freopen("input.txt", "rt", stdin);

	int n; // N 3
	//cin >> n;
	scanf_s("%d", &n);

	vector<int> processTimes(n); // �� �۾��� ó���ϴµ� �ʿ��� �ð� ����
	int sumProcessTimes = 0; // �۾��ð� ����

	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &processTimes[i]); // 1 2 3
		//cin >> processTimes[i]; // 1 2 3
		sumProcessTimes += processTimes[i];
	}

	int k; // K 5
	//cin >> k;
	scanf_s("%d", &k);

	// ù �۾����� 1�ʾ� �Ҵ�
	// �۾� ������ �Ϸ��� �۾��� �����층 ����
	// ������ �۾� ���� �� �ٽ� ù �۾����� �Ҵ�
	// k�ʿ� ���� �� �� �� �۾����� �ٽ� �����ؾ��ϴ��� ���ϱ�
	// 1 2 3
	// 0 2 3
	// 0 1 3
	// 0 1 2
	// 0 0 2
	// 0 0 1

	if (sumProcessTimes <= k) // ���μ��� �۾��ð� ������ k ���ϸ� ������ Ǯ�� �� ���� �� �۾��� ����
	{
		//cout << -1 << '\n';
		printf("%d\n", -1);
		return 0;
	}

	while (k > -1) // k�� �� �����̰� ������ Ǯ�� �� �ٽ� �����ؾ��ϴ� �۾��� k�� 0�϶� ����ǹǷ� k�� 0�϶��� ����
	{
		for (int i = 0; i < n; i++) // �۾� ũ�⸸ŭ ���鼭
		{
			if (processTimes[i] > 0) // ���� ������ ���� �۾���
			{
				if (k == 0) // ������ Ǯ�� �� ���� ������ ���� �۾��� ������ �ٽ� ������ �۾�
				{
					//cout << i + 1 << '\n';
					printf("%d\n", i + 1);
					return 0;
				}

				processTimes[i]--; // �۾� �ð� ����
				k--; // k�� 0�̵Ǹ� ���� -> k�� 0�϶� ������ Ǯ�� �� ���� �ؾ� �� �۾�
			}

			if (i == n - 1) // ������ �۾��̸� ù �۾�����
			{
				i = -1;
			}
		}
	}
}
// �ٽ�
// �����۽� ����