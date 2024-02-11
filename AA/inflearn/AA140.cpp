#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// ����ã��
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 4
	cin >> n;

	vector<vector<int> > graph(n, vector<int>(n)); // �׷���
	vector<vector<vector<int> > > dis(3, vector<vector<int> >(n, vector<int>(n))); // �����ð�, ����ð�, �����ð�
	queue<pair<int, int> > checkPos; // üũ �� ��ġ
	vector<pair<int, int> > checkDir; // �����¿�
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	//	1 0 0 0
	//	0 0 0 0
	//	0 1 0 1
	//	1 0 0 1
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
		}
	}

	int x, y; // ��ǥ

	//	1 2 -> ������ġ (0, 1) ���� BFS ������
	//	4 3 -> ������ġ (3, 2) ���� BFS ������
	//	3 1 -> ������ġ (2, 0) ���� BFS ������
	for (int i = 0; i < 3; i++)
	{
		cin >> x >> y;

		// ������ġ���� BFS ������
		checkPos.push({ x - 1, y - 1 }); 
		dis[i][x - 1][y - 1] = 1;

		// BFS
		while (!checkPos.empty()) // ť�� ��������
		{
			// ������ġ ����
			pair<int, int> standardPos = checkPos.front();
			checkPos.pop();

			// �����¿�
			for (int j = 0; j < 4; j++)
			{
				// üũ �� ��ġ
				int checkI = standardPos.first + checkDir[j].first;
				int checkJ = standardPos.second + checkDir[j].second;

				// ���üũ
				if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= n)
				{
					continue;
				}

				// �湮üũ
				if (dis[i][checkI][checkJ] > 0)
				{
					continue;
				}

				// �̵��Ұ�����üũ
				if (graph[checkI][checkJ] == 1)
				{
					continue;
				}

				// ť�� ���� �� �Ÿ� ����
				checkPos.push({ checkI, checkJ });
				dis[i][checkI][checkJ] = dis[i][standardPos.first][standardPos.second] + 1;
			}
		}
	}

	// BFS ���� ���� �ð�
	//	0 1 2 3
	//	3 2 3 4
	//	4 0 4 0
	//	0 6 5 0

	// BFS ���� ���� �ð�
	//	0 5 4 5
	//	5 4 3 4
	//	6 0 2 0
	//	0 2 1 0

	// BFS ���� ���� �ð�
	//	0 4 5 6
	//	2 3 4 5
	//	1 0 5 0
	//	0 7 6 0

	// 1�� ���� ���� ���� ��ġ
	// �� ģ���� ��ġ�� 1�ʺ��� ���������Ƿ� ���� �ð��� �� �ð� - 1

	// �ð��� 0�� �� : ���� ���� ������ ���� �� ���� ��ġ
	// �ð��� 0�� �ƴ� �� : ���� �ʰ� �����ϴ� ģ���� �ð��� ���� �� �ִ� �ð� -> max(�����ð�, ����ð�, �����ð�)

	// ���� �� �ִ� �ִܽð� : �ð��� 0�� �ƴ� ������ ���� �� �ִ� �ð��� ���� ���ؼ� �� �� �ִܽð� ����

	int treasureCnt = 0; // ���� ����
	int minDis = 2147000000; // �� ģ���� ���� �� �ִ� �ִܽð�

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// �ð��� 0�� �� üũ
			if (dis[0][i][j] == 0 || dis[1][i][j] == 0 || dis[2][i][j] == 0)
			{
				continue;
			}

			// �ð��� 0�� �ƴ� ������ ���� �ʰ� �����ϴ� ģ���� �ð��� �� ģ���� ���̴� �ð�
			int latestDis = max({ dis[0][i][j], dis[1][i][j], dis[2][i][j] });

			// �� ģ���� ���̴� �ð��� �ִܽð��� ������ ���� ���� ī����
			if (latestDis == minDis)
			{
				treasureCnt++;
			}
			else // �� ģ���� ���̴� �ð��� �ִܽð��� �����ʴٸ� �ִܽð��� ���ŵǴ� ��� -> �ִܽð� �� �������� �ʱ�ȭ
			{
				if (minDis > latestDis)
				{
					minDis = latestDis;
					treasureCnt = 1;
				}
			}
		}
	}
	
	// �ִܽð��� ���ŵ����ʰ� 2147000000 �״�θ� ���� �� �����Ƿ� -1 ����ϱ�
	if (minDis == 2147000000)
	{
		cout << -1 << '\n';

		return 0;
	}

	// �� ģ���� ���� �� �ִ� ������ �ִٸ� ���� ���� ����ϱ�
	cout << treasureCnt << '\n';

	return 0;
}