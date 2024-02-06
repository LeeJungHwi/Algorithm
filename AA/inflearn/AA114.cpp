#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// ������ ���
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int w, h; // W, H 8, 4
	cin >> w >> h;

	vector<vector<int> > graph(h, vector<int>(w)); // ����
	vector<vector<int> > minDis(h, vector<int>(w)); // �Ÿ�

	queue<pair<int, int> > checkPos; // üũ�� ��ġ
	vector<pair<int, int> > checkDir; // �����¿�
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	vector<pair<int, int> > straw; // ����� ��ġ
	pair<int, int> sword; // ��� ��ġ
	pair<int, int> YoungHee; // ���� ��ġ

	//	4 1 0 0 0 0 1 0
	//	0 0 0 1 0 1 0 0
	//	0 2 1 1 3 0 4 0
	//	0 0 0 4 1 1 1 0
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> graph[i][j];

			// ���� ��ġ, ��� ��ġ, ����� ��ġ ����
			if (graph[i][j] == 4)
			{
				straw.push_back({ i, j });
			}
			else if (graph[i][j] == 2)
			{
				YoungHee = { i, j };
			}
			else if (graph[i][j] == 3)
			{
				sword = { i, j };
			}
		}
	}

	// BFS
	// ����� ��ǥ���� ���� ��ġ �ִܰŸ� + ��� ��ġ �ִܰŸ� ���� �� �ִܰŸ� ����
	// �湮üũ, ���üũ, �� üũ

	int result = 2147000000; // �ִܰŸ�

	for (int i = 0; i < straw.size(); i++)
	{
		// ����� ��ġ ť�� ���� �� �Ÿ� 1
		checkPos.push(straw[i]);
		minDis[straw[i].first][straw[i].second] = 1;

		while (!checkPos.empty()) // ť�� ��������
		{
			// ť���� ������ġ ����
			pair<int, int> standardPos = checkPos.front();
			checkPos.pop();

			for (int i = 0; i < 4; i++)
			{
				// üũ�� ��ġ
				int checkI = standardPos.first + checkDir[i].first;
				int checkJ = standardPos.second + checkDir[i].second;

				// ���üũ
				if (checkI < 0 || checkJ < 0 || checkI >= h || checkJ >= w)
				{
					continue;
				}

				// �湮üũ : �Ÿ��� �Ҵ�Ǿ�����
				if (minDis[checkI][checkJ] > 0)
				{
					continue;
				}

				// �� üũ
				if (graph[checkI][checkJ] == 1)
				{
					continue;
				}

				// ���� ������ ť�� ���� �� �Ÿ�����
				checkPos.push({ checkI, checkJ });
				minDis[checkI][checkJ] = minDis[standardPos.first][standardPos.second] + 1;
			}
		}

		// ����⿡�� ����ؼ� �Ѵ� �� �� �������� �ִܰŸ� ����
		if (minDis[sword.first][sword.second] > 0 && minDis[YoungHee.first][YoungHee.second] > 0)
		{
			if (result > minDis[sword.first][sword.second] + minDis[YoungHee.first][YoungHee.second] - 2)
			{
				result = minDis[sword.first][sword.second] + minDis[YoungHee.first][YoungHee.second] - 2;
			}
		}

		// �Ÿ� �ʱ�ȭ
		for (int j = 0; j < h; j++)
		{
			for (int k = 0; k < w; k++)
			{
				minDis[j][k] = 0;
			}
		}
	}

	cout << result << '\n';

	return 0;
}