#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

// ������ ���Ϸ���
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 7
	cin >> n;

	vector<vector<int> > graph(n, vector<int>(n)); // �׷���
	vector<vector<bool> > vis(n, vector<bool>(n)); // �湮üũ
	queue<pair<int, int> > island; // �� ����
	int islandCnt = 0; // �� ����
	vector<pair<int, int> > checkDir; // �� �� �� ��  �޻� ��� ���� ����
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });
	checkDir.push_back({ -1, -1 });
	checkDir.push_back({ -1, 1 });
	checkDir.push_back({ 1, -1 });
	checkDir.push_back({ 1, 1 });

	//	1 1 0 0 0 1 0
	//	0 1 1 0 1 1 0
	//	0 1 0 0 0 0 0
	//	0 0 0 1 0 1 1
	//	1 1 0 1 1 0 0
	//	1 0 0 0 1 0 0
	//	1 0 1 0 1 0 0
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
		}
	}

	// BFS
	/*
	�׷��� ���鼭 1�� ������ �湮üũ �� ť�� ����
	ť�� ��� �����ϰ� �� ���� ����
	�� �� �� �� �޻� ��� ���� ���� ť���� ����
	��踦 ����ų� 0�� ������ continue
	1�������� �湮üũ �� ť�� ����
	*/
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] == 1) // 1�� ������
			{
				if (vis[i][j]) // �湮�� ���̸� continue
				{
					continue;
				}

				vis[i][j] = true; // �湮üũ
				island.push({ i, j }); // ť�� ����

				while (!island.empty())
				{
					pair<int, int> curIsland = island.front(); // ť�� ����� �� ����
					island.pop();

					for (int i = 0; i < 8; i++) // �� �� �� �� �޻� ��� ���� ����
					{
						int checkI = curIsland.first + checkDir[i].first; // üũ�� I
						int checkJ = curIsland.second + checkDir[i].second; // üũ�� J

						// ���üũ
						if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= n)
						{
							continue;
						}

						// �ٴ��� ���
						if (graph[checkI][checkJ] == 0)
						{
							continue;
						}

						// ���� ���
						if (!vis[checkI][checkJ]) // �湮���� ��������
						{
							vis[checkI][checkJ] = true; // �湮üũ
							island.push({ checkI, checkJ }); // ť�� ����
						}
					}
				}

				islandCnt++; // ���̻� ���� �߰ߵ��� ������ �� ���� ����
			}
		}
	}

	cout << islandCnt << '\n';

	return 0;
}