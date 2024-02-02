#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int n; // N 10
vector<vector<int> > graph(21, vector<int>(21)); // ���ٸ� �׷���
vector<vector<int> > heights(21, vector<int>(21)); // �� ���� ������ �ּҿ����� ����

// DFS
int DFS(int i, int j)
{
	if (heights[i][j] > 0)
	{
		return heights[i][j]; // ����
	}
	else if (i == 2 && j == 2) // �������� : (2, 2)
	{
		return heights[2][2] = min(heights[1][2], heights[2][1]) + graph[2][2]; // (2, 2) �޸�
	}
	else
	{
		return heights[i][j] = min(DFS(i - 1, j), DFS(i, j - 1)) + graph[i][j]; // (i, j) �޸�
	}
}

// �˸��ٹٿ� 40���� ����(topDown)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n;

	//	9 4 6 7 5 1 3 1 5 3
	//	2 4 6 3 9 8 9 1 3 2
	//	6 9 6 2 4 1 8 3 7 8
	//	3 9 7 5 3 1 3 6 6 1
	//	3 6 6 3 8 9 6 7 7 4
	//	1 4 5 3 1 8 1 9 1 3
	//	7 3 1 1 7 7 3 7 4 3
	//	8 5 6 7 7 9 1 8 3 2
	//	2 8 7 4 3 4 2 9 2 9
	//	1 1 1 2 6 1 3 8 1 9
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			cin >> graph[i][j];
		}
	}

	// ���������� (1, i) �϶� : ���� ������ �ּҿ����� + �ڽſ�����
	// ���������� (i, 1) �϶� : ���� ������ �ּҿ����� + �ڽſ�����
	// heights[N][N] = min(heights[N - 1][N], heights[N][N - 1]) + graph[n][n]
	heights[1][1] = graph[1][1];

	for (int i = 2; i < n + 1; i++)
	{
		// ���������� (1, i) �϶� : ���� ������ �ּҿ����� + �ڽſ�����
		// ���������� (i, 1) �϶� : ���� ������ �ּҿ����� + �ڽſ�����
		heights[1][i] = heights[1][i - 1] + graph[1][i];
		heights[i][1] = heights[i - 1][1] + graph[i][1];
	}

	// DFS
	DFS(n, n);

	cout << heights[n][n] << '\n';

	return 0;
}