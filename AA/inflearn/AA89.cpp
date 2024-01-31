#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int m, n; // M, N 
	cin >> m >> n;

	vector<vector<int>> graph(n, vector<int>(m)); // �׷���
	vector<vector<int>> dis(n, vector<int>(m)); // �ϼ�
	vector<pair<int, int> > checkDir; // �� �� �� ��
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });
	queue<pair<int, int>> standardPos; // ���� �丶�� ��ġ ť

	// ���� �丶�� ��ġ �Ÿ� 1�� �Ҵ� �� ť�� �߰�(�ٽ� 1)
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];

			if (graph[i][j] == 1)
			{
				dis[i][j] = 1;
				standardPos.push({ i, j });
			}
		}
	}

	// BFS
	/*
	ť�� �������� �� �� �� �� üũ�ϸ鼭 �丶�並 ������ �Ÿ� ����
	*/
	while (!standardPos.empty())
	{
		// ������ġ ����
		pair<int, int> curPos = standardPos.front();
		standardPos.pop();

		// �� �� �� �� üũ
		for (int i = 0; i < 4; i++)
		{
			int checkI = curPos.first + checkDir[i].first;
			int checkJ = curPos.second + checkDir[i].second;

			// ���üũ
			if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m)
			{
				continue;
			}

			// �丶�䰡 ���� ���� üũ
			if (graph[checkI][checkJ] == -1)
			{
				continue;
			}

			// �̹� ���� �丶Ʈ üũ
			if (graph[checkI][checkJ] == 1)
			{
				continue;
			}

			// �丶�並 ���� ��� �Ÿ� ���� �� ť�� ����(�ٽ� 2)
			if (dis[checkI][checkJ] == 0) // �Ÿ��� �Ҵ���� ��������
			{
				dis[checkI][checkJ] = dis[curPos.first][curPos.second] + 1;
				standardPos.push({ checkI, checkJ });
			}
			else // �Ÿ��� �Ҵ�� ����
			{
				if (dis[checkI][checkJ] > dis[curPos.first][curPos.second] + 1) // �� �ּҳ�¥�ΰ�츸
				{
					dis[checkI][checkJ] = dis[curPos.first][curPos.second] + 1;
					standardPos.push({ checkI, checkJ });
				}
			}
		}
	}

	int minDay = 0; // �ּ� �ɸ��� ��¥
	bool isOk = true; // ��� �;����� üũ

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (graph[i][j] == 0 && dis[i][j] == 0) // �������� �丶�䰡 �����ʾ�����
			{
				isOk = false;
				break;
			}
		}

		if (!isOk) // �������� �丶�䰡 ������ -1 ���
		{
			cout << -1 << '\n';
			return 0;
		}
	}

	// �ּ� �ɸ��� ��¥ ����
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			minDay = max(minDay, dis[i][j]);
		}
	}

	cout << minDay  - 1 << '\n';

	return 0;
}
