#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// ȸ��̱�(�÷��̵�ͼ�)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 5
	cin >> n;

	int v1, v2; // ����

	vector<vector<int> > scores(n + 1, vector<int>(n + 1, 100)); // �߰�ȸ���� ��������� ���� �ּ����� ����
	vector<int> result(n + 1); // ���̳��� �� �� ���� �ִ����� ����

	//  ���������� ����(�߰�ȸ�� ���� ģ��), i == j�� 0, �������� max������ �ʱ�ȭ
	/*
	Input : 1 2
			2 3
			3 4
			4 5
			2 4
			5 3
			- 1 - 1
	
	graph : 0 1 0 0 0
			0 0 1 1 0
			0 0 0 1 0
			0 0 0 0 1
			0 0 1 0 0
	*/
	while (true)
	{
		cin >> v1 >> v2;

		if (v1 == -1 && v2 == -1) // ������ �� ����
		{
			break;
		}

		// ����� ����
		scores[v1][v2] = 1;
		scores[v2][v1] = 1;
	}

	for (int i = 1; i < n + 1; i++)
	{
		scores[i][i] = 0;
	}

	// �߰�ȸ���� ��������� ���� �ּ����� ���� : �ٷ�ģ�� 1, ģ���� ģ�� 2, ģ���� ģ���� ģ�� 3, ....
	for (int k = 1; k < n + 1; k++)
	{
		for (int i = 1; i < n + 1; i++)
		{
			for (int j = 1; j < n + 1; j++)
			{
				if (scores[i][j] > scores[i][k] + scores[k][j])
				{
					scores[i][j] = scores[i][k] + scores[k][j];
				}
			}
		}
	}

	// �� ��(ȸ������)�� �ִ����� ����
	for (int i = 1; i < n + 1; i++)
	{
		int maxScore = 0;

		for (int j = 1; j < n + 1; j++)
		{
			if (scores[i][j] > maxScore)
			{
				maxScore = scores[i][j];
			}
		}

		result[i] = maxScore; // 3 2 2 2 3
	}

	// ȸ�������� ���� ���� ����� ȸ���ĺ�
	int minScore = 100;

	for (int i = 1; i < n + 1; i++)
	{
		if (minScore > result[i])
		{
			minScore = result[i]; // 2
		}
	}

	cout << minScore << ' ';

	// ȸ���ĺ� ���� �� ������� ī����
	int candidateCnt = 0;
	vector<int> candidates;

	for (int i = 1; i < n + 1; i++)
	{
		if (result[i] == minScore)
		{
			candidateCnt++;
			candidates.push_back(i);
		}
	}

	cout << candidateCnt << '\n';

	for (int i = 0; i < candidates.size(); i++)
	{
		cout << candidates[i] << ' ';
	}

	return 0;
}