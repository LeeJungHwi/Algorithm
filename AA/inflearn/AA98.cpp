#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// �˸��ٹٿ� 40���� ����(bottomUp)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 5
	cin >> n;

	vector<vector<int> > graph(n + 1, vector<int>(n + 1)); // ���ٸ� �׷���
	vector<vector<int> > heights(n + 1, vector<int>(n + 1)); // �� ������ �ּҿ����� ����

	//	3 7 2 1 9
	//	5 8 3 9 2
	//	5 3 1 2 3
	//	5 4 3 2 1
	//	1 7 5 2 4
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			cin >> graph[i][j];
		}
	}

	// ���������� (1, i) �϶� : ���� ������ �ּҿ����� + �ڽſ�����
	// ���������� (i, 1) �϶� : ���� ������ �ּҿ����� + �ڽſ�����
	// ���������� (2, 2) ~ (N, N)�� (i, j) �϶� : min(���� ������ �ּҿ�����, ���� ������ �ּҿ�����) + �ڽſ�����
	heights[1][1] = graph[1][1];

	for (int i = 2; i < n + 1; i++)
	{
		// ���������� (1, i) �϶� : ���� ������ �ּҿ����� + �ڽſ�����
		// ���������� (i, 1) �϶� : ���� ������ �ּҿ����� + �ڽſ�����
		heights[1][i] = heights[1][i - 1] + graph[1][i];
		heights[i][1] = heights[i - 1][1] + graph[i][1];
	}

	for (int i = 2; i < n + 1; i++)
	{
		// ���������� (2, 2) ~ (N, N)�� (i, j) �϶� : min(���� ������ �ּҿ�����, ���� ������ �ּҿ�����) + �ڽſ�����
		for (int j = 2; j < n + 1; j++)
		{
			heights[i][j] = min(heights[i][j - 1], heights[i - 1][j]) + graph[i][j];
		}
	}

	cout << heights[n][n] << '\n';

	return 0;
}