#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// �̷�Ž��(������)
void SearchGraph(int column, int row, int &caseCnt, vector<vector<int> > &graph, vector<vector<bool> > &vis, vector<pair<int, int> > &dir)
{
	if (column == 6 && row == 6) // �������� : �������� (6, 6)
	{
		caseCnt++;
	}
	else
	{
		// �����¿� üũ : 0�̸鼭 �湮���������� 
		for (int i = 0; i < 4; i++)
		{
			int checkI = column + dir[i].first;
			int checkJ = row + dir[i].second;

			// ���üũ : ���ڸ� ����� ���� üũ
			if (checkI < 0 || checkJ < 0 || checkI > 6 || checkJ > 6)
			{
				continue;
			}

			if (graph[checkI][checkJ] == 0 && vis[checkI][checkJ] == false) // 0�̸鼭 �湮�����������̸�
			{
				vis[checkI][checkJ] = true; // �湮üũ
				SearchGraph(checkI, checkJ, caseCnt, graph, vis, dir);
				vis[checkI][checkJ] = false; // �ڷ� �ǵ��ư��� �湮üũ �����������
			}
		}
	}
}

// �̷�Ž��(������)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	vector<vector<int> > graph(7, vector<int>(7)); // �׷���
	vector<vector<bool> > vis(7, vector<bool>(7)); // �湮üũ
	int caseCnt = 0; // ���������� ��� ��
	vector<pair<int, int> > dir; // �����¿�
	dir.push_back({ -1, 0 });
	dir.push_back({ 1, 0 });
	dir.push_back({ 0, -1 });
	dir.push_back({ 0, 1 });

	//	0 0 0 0 0 0 0
	//	0 1 1 1 1 1 0
	//	0 0 0 1 0 0 0
	//	1 1 0 1 0 1 1
	//	1 1 0 0 0 0 1
	//	1 1 0 1 1 0 0
	//	1 0 0 0 0 0 0
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cin >> graph[i][j];
		}
	}

	vis[0][0] = true;

	SearchGraph(0, 0, caseCnt, graph, vis, dir);

	cout << caseCnt << '\n';

	return 0;
}
// �ٽ�
// DFS ������ : �����¿� üũ, ��� üũ, ���ȣ�� �� �湮üũ ����