#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// �� ������
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int r, c; // R, C 6, 7
	cin >> r >> c;

	vector<vector<char> > graph(r, vector<char>(c)); // �׷���
	vector<vector<bool> > vis(r, vector<bool>(c)); // �湮üũ

	queue<pair<int, int> > checkPos; // üũ�� ��ġ
	vector<pair<int, int> > checkDir; // �����¿�
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	int areaCnt = 0; // �������� ���� ����

	//	.#....#
	//	..#...#
	//	..#..#.
	//	...##..
	//	.#....#
	//	.#..#.#
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> graph[i][j];
		}
	}

	// BFS
	// ������(#)�� ������ BFS ������
	// ���üũ, �湮üũ, �������ΰ�üũ, �����̸� ������ ť�� ����, �湮üũ
	// BFS�� ������ �����̿��� ���� ����

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (graph[i][j] == '#') // �����̸� ������
			{
				if (vis[i][j]) // �̹� �湮�Ѱ��̸� continue
				{
					continue;
				}

				checkPos.push({ i, j }); // BFS�� ������ ������ ��ǥ ����
				vis[i][j] = true; // BFS�� ������ ������ ��ǥ �湮üũ

				while (!checkPos.empty()) // ť�� ��������
				{
					// ������ġ ����
					pair<int, int> standardPos = checkPos.front();
					checkPos.pop();

					// �����¿�
					for (int k = 0; k < 4; k++)
					{
						// üũ�� ��ġ
						int checkI = standardPos.first + checkDir[k].first;
						int checkJ = standardPos.second + checkDir[k].second;

						// ���üũ
						if (checkI < 0 || checkJ < 0 || checkI >= r || checkJ >= c)
						{
							continue;
						}
						
						// �湮üũ
						if (vis[checkI][checkJ])
						{
							continue;
						}

						// �������ΰ�üũ
						if (graph[checkI][checkJ] == '.')
						{
							continue;
						}

						// �����̸� ������ ť������, �湮üũ
						checkPos.push({ checkI, checkJ });
						vis[checkI][checkJ] = true;
					}
				}

				areaCnt++;
			}
		}
	}

	cout << areaCnt;

	return 0;
}