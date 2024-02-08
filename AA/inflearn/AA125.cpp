#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// �ܵ�
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 5
	cin >> n;

	vector<vector<int> > graph(n, vector<int>(n)); // �׷���
	vector<vector<int> > dis(n, vector<int>(n)); // �Ÿ�

	queue<pair<int, int> > checkPos; // üũ�� ��ġ
	vector<pair<int, int> > checkDir; // �����¿�
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	//	1 0 0 0 0
	//	0 0 0 1 0
	//	0 1 2 1 0
	//	0 0 1 2 0
	//	0 0 0 0 0
	// �ܵ� ��ġ �Ÿ� 1 �Ҵ� �� ť�� �߰�
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];

			if (graph[i][j] == 2)
			{
				dis[i][j] = 1;
				checkPos.push({ i, j });
			}
		}
	}

	// BFS
	// ť�� ��������
	// ���üũ, ����üũ, �Ƕ��� ������ �Ÿ��� �̹� �Ҵ�� ��� �ּҰ�, �Ÿ��� �Ҵ���� ������� ���� �Ÿ� + 1, ť�� ����
	// �Ÿ� �ִ밪 ���

	while (!checkPos.empty())
	{
		// ������ġ ����
		pair<int, int> standardPos = checkPos.front();
		checkPos.pop();

		for (int i = 0; i < 4; i++)
		{
			// üũ�� ��ġ
			int checkI = standardPos.first + checkDir[i].first;
			int checkJ = standardPos.second + checkDir[i].second;

			// ���üũ
			if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= n)
			{
				continue;
			}

			// ����üũ
			if (graph[checkI][checkJ] == 1)
			{
				continue;
			}

			// �Ƕ��� ������ �Ÿ��� �̹� �Ҵ�� ��� �ּҰ�, �Ÿ��� �Ҵ���� ������� ���� �Ÿ� + 1, ť�� ����
			if (dis[checkI][checkJ] > 0)
			{
				if (dis[checkI][checkJ] > dis[standardPos.first][standardPos.second] + 1)
				{
					dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;
					checkPos.push({ checkI, checkJ });
				}
			}
			else if (dis[checkI][checkJ] == 0)
			{
				dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;
				checkPos.push({ checkI, checkJ });
			}
		}
	}

	// ��� �Ƕ��� �ܵ� �ɾ����µ� �ɸ��� �ּҽð� = �׷��� ��� �� �ִ�Ÿ�

	int result = 0; // �ּҽð�

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (result < dis[i][j])
			{
				result = dis[i][j];
			}
		}
	}

	cout << result - 1 << '\n';

	return 0;
}