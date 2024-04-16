#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 농장 관리
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 8, 7
	cin >> n >> m;

	vector<vector<int> > graph(n, vector<int>(m)); // 그래프
	vector<vector<bool> > vis(n, vector<bool>(m)); // 방문체크
	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 8방향
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });
	checkDir.push_back({ -1, -1 });
	checkDir.push_back({ -1, 1 });
	checkDir.push_back({ 1, -1 });
	checkDir.push_back({ 1, 1 });

	//	4 3 2 2 1 0 1
	//	3 3 3 2 1 0 1
	//	2 2 2 2 1 0 0
	//	2 1 1 1 1 0 0
	//	1 1 0 0 0 1 0
	//	0 0 0 1 1 1 0
	//	0 1 2 2 1 1 0
	//	0 1 1 1 2 1 0
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];
		}
	}

	int peekCnt = 0; // 봉우리 개수

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (graph[i][j] > 0 && !vis[i][j])
			{
				// BFS
				checkPos.push({ i, j });
				vis[i][j] = true;
				bool isPeek = true;
				int curPeek = graph[i][j];
				vector<pair<int, int> > peekSet;
				peekSet.push_back({ i, j });

				while (!checkPos.empty()) // 큐가 빌때까지
				{
					// 기준위치 꺼냄
					pair<int, int> standardPos = checkPos.front();
					checkPos.pop();

					// 8방향
					for (int k = 0; k < 8; k++)
					{
						// 체크 할 위치
						int checkI = standardPos.first + checkDir[k].first;
						int checkJ = standardPos.second + checkDir[k].second;

						// 경계체크
						if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m)
						{
							continue;
						}

						// 방문체크
						if (vis[checkI][checkJ])
						{
							continue;
						}

						// 다른높이체크
						if (graph[checkI][checkJ] != curPeek)
						{
							continue;
						}

						// 큐에저장, 방문체크, 봉우리집합저장
						checkPos.push({ checkI, checkJ });
						vis[checkI][checkJ] = true;
						peekSet.push_back({ checkI, checkJ });
					}
				}

				// 봉우리집합 돌면서
				for (int k = 0; k < peekSet.size(); k++)
				{
					// 기준위치
					pair<int, int> standardPos = peekSet[k];

					// 더 높은 높이가 있으면 봉우리 아님
					for (int l = 0; l < 8; l++)
					{
						int checkI = standardPos.first + checkDir[l].first;
						int checkJ = standardPos.second + checkDir[l].second;

						if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m)
						{
							continue;
						}

						if (graph[checkI][checkJ] > curPeek)
						{
							isPeek = false;
							break;
						}
					}

					if (!isPeek)
					{
						break;
					}
				}

				// 봉우리면 카운팅
				if (isPeek)
				{
					peekCnt++;
				}
			}
		}
	}

	cout << peekCnt << '\n';

	return 0;
}
