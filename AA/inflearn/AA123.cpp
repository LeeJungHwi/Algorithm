#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// ū ȣ��
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m, k; // N, M, K 3, 4, 5
	cin >> n >> m >> k;

	vector<vector<int> > graph(n + 1, vector<int>(m + 1)); // �׷���
	vector<vector<bool> > vis(n + 1, vector<bool>(m + 1)); // �湮üũ

	queue<pair<int, int> > checkPos; // üũ�� ��ġ
	vector<pair<int, int> > checkDir; // �����¿�
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	/*
	input : 3 2
			2 2
			3 1
			2 3
			1 1

	graph : 1 0 0 0
			0 1 1 0
			1 1 0 0
	*/

	int col, row; // ħ���� ���� ��ǥ

	for (int i = 0; i < k; i++)
	{
		cin >> col >> row;

		graph[col][row] = 1;
	}

	// BFS
	// 1�� ������ ť�� ����, �湮üũ, ȣ��ũ�� 1
	// ���üũ, �湮üũ, 0üũ, 1�� ������ ȣ��ũ�� ����, ť�� ����, �湮üũ

	int maxSize = 0; // ���� ū ȣ�� ũ��

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			if (graph[i][j] == 1)
			{
				// 1�� ������ ť�� ���� �� �湮üũ
				checkPos.push({ i, j });
				vis[i][j] = true;

				// ȣ�� ũ�� 1
				int size = 1;

				while (!checkPos.empty()) // ť�� ��������
				{
					// ������ġ ����
					pair<int, int> standardPos = checkPos.front();
					checkPos.pop();

					// �����¿� üũ
					for (int l = 0; l < 4; l++)
					{
						// üũ�� ��ġ
						int checkI = standardPos.first + checkDir[l].first;
						int checkJ = standardPos.second + checkDir[l].second;

						// ���üũ
						if (checkI < 1 || checkJ < 1 || checkI >= n + 1 || checkJ >= m + 1)
						{
							continue;
						}

						// �湮üũ
						if (vis[checkI][checkJ])
						{
							continue;
						}

						// 0 üũ
						if (graph[checkI][checkJ] == 0)
						{
							continue;
						}

						// 1�� ������ ȣ��ũ�� ����, ť�� ���� �� �湮üũ
						size++;
						checkPos.push({ checkI, checkJ });
						vis[checkI][checkJ] = true;
					}
				}

				// ���� ū ȣ�� ũ�� ����
				if (maxSize < size)
				{
					maxSize = size;
				}
			}
		}
	}

	cout << maxSize;

	return 0;
}