#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

vector<vector<int> > graph(9, vector<int>(9)); // ������ ��
vector<pair<int, int> > blankPos; // ��ĭ ��ǥ

// ���� ��ĭ��ġ�� ���ڰ� ��ȿ���� üũ
bool isValid(int row, int col, int num)
{
	// ���� �࿡ �̹� num�� �ִ��� Ȯ��
	for (int i = 0; i < 9; ++i)
	{
		if (graph[row][i] == num)
		{
			return false;
		}
	}

	// ���� ���� �̹� num�� �ִ��� Ȯ��
	for (int i = 0; i < 9; ++i)
	{
		if (graph[i][col] == num)
		{
			return false;
		}
	}

	// ���� ���ڿ� �̹� num�� �ִ��� Ȯ��
	int startRow = row - row % 3;
	int startCol = col - col % 3;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (graph[startRow + i][startCol + j] == num)
			{
				return false;
			}
		}
	}

	return true;
}

// DFS
void DFS(int L)
{
	if (L == blankPos.size()) // �������� : ��� ��ĭ�� ä����
	{ 
		// ������ ��� �� ���α׷� ����
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << graph[i][j] << " ";
			}

			cout << '\n';
		}

		exit(0);
	}
	else
	{
		// ��ĭ ��ǥ ����
		int row = blankPos[L].first;
		int col = blankPos[L].second;

		// 1���� 10���� �־
		// ������ ������ �������ڿ� �������ڰ� ������ �ȵ�
		for (int num = 1; num < 10; num++)
		{
			// ������ ������ ���
			if (isValid(row, col, num))
			{
				graph[row][col] = num; // ���ڸ� ����
				DFS(L + 1);
				graph[row][col] = 0; // ���ڸ� ����
			}
		}
	}
}

// ������
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	//	0 2 3 0 5 0 7 8 9
	//	0 5 6 0 8 9 1 0 3
	//	0 8 9 1 0 3 0 5 6
	//	0 1 0 0 6 0 8 9 0
	//	3 0 5 0 9 7 0 1 4
	//	0 9 7 0 1 0 0 6 5
	//	5 3 0 6 0 2 9 7 8
	//	6 0 2 9 0 8 5 3 1
	//	9 0 8 0 3 0 6 0 2
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> graph[i][j];

			// ��ĭ ��ǥ ����
			if (graph[i][j] == 0)
			{
				blankPos.push_back({ i, j });
			}
		}
	}

	// DFS
	DFS(0);

	return 0;
}
