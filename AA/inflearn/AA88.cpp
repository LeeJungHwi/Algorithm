#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

// �̷��� �ִܰŸ� ���
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream cin;
	cin.open("input.txt");

	vector<vector<int> > graph(7, vector<int>(7)); // �׷���
	vector<vector<int> > dis(7, vector<int>(7)); // �Ÿ�
	vector<pair<int, int> > checkDir; // �� �� �� ��
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });
	queue<pair<int, int> > standardPos; // ������ġ

	//	0 0 0 0 0 0 0
	//	0 1 1 1 1 1 0
	//	0 0 0 1 0 0 0
	//	1 1 0 1 0 1 1
	//	1 1 0 1 0 0 0
	//	1 0 0 0 1 0 0
	//	1 0 1 0 0 0 0
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cin >> graph[i][j];
		}
	}

	// ù ���� �ʱ�ȭ
	standardPos.push({ 0, 0 });
	dis[0][0] = 1; // ����Ҷ� 1 ����

	// BFS
	while (!standardPos.empty()) // ť�� ��� ����
	{
		// ���� ��ġ ����
		pair<int, int> curPos = standardPos.front();
		standardPos.pop();

		// �� �� �� ��
		for (int i = 0; i < 4; i++)
		{
			int checkI = curPos.first + checkDir[i].first;
			int checkJ = curPos.second + checkDir[i].second;

			// ���üũ
			if (checkI < 0 || checkJ < 0 || checkI >= 7 || checkJ >= 7)
			{
				continue;
			}

			// �� üũ
			if (graph[checkI][checkJ] == 1)
			{
				continue;
			}

			// �Ÿ� �Ҵ� üũ : �Ÿ��� �Ҵ�Ǿ��ٴ°� �̹� �湮�� ���¶�°�
			if (dis[checkI][checkJ] != 0)
			{
				continue;
			}

			// �Ÿ� ����
			dis[checkI][checkJ] = dis[curPos.first][curPos.second] + 1;

			// ť�� ����
			standardPos.push({ checkI, checkJ });
		}
	}
	
	if (dis[6][6] == 0) // �����Ҽ������� -1 ���
	{
		cout << -1 << '\n';

		return 0;
	}

	cout << dis[6][6] - 1 << '\n'; // BFS�� �Ÿ��� ����Ǵ� ���� �ִܰŸ�

	return 0;
}