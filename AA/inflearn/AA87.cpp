#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

// 섬나라 아일랜드
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 7
	cin >> n;

	vector<vector<int> > graph(n, vector<int>(n)); // 그래프
	vector<vector<bool> > vis(n, vector<bool>(n)); // 방문체크
	queue<pair<int, int> > island; // 섬 저장
	int islandCnt = 0; // 섬 개수
	vector<pair<int, int> > checkDir; // 상 하 좌 우  왼상 우상 왼하 우하
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
	그래프 돌면서 1을 만나면 방문체크 후 큐에 저장
	큐가 비면 종료하고 섬 개수 증가
	상 하 좌 우 왼상 우상 왼하 우하 큐에서 꺼냄
	경계를 벗어나거나 0을 만나면 continue
	1을만나면 방문체크 후 큐에 저장
	*/
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] == 1) // 1을 만나면
			{
				if (vis[i][j]) // 방문한 섬이면 continue
				{
					continue;
				}

				vis[i][j] = true; // 방문체크
				island.push({ i, j }); // 큐에 저장

				while (!island.empty())
				{
					pair<int, int> curIsland = island.front(); // 큐에 저장된 섬 꺼냄
					island.pop();

					for (int i = 0; i < 8; i++) // 상 하 좌 우 왼상 우상 왼하 우하
					{
						int checkI = curIsland.first + checkDir[i].first; // 체크할 I
						int checkJ = curIsland.second + checkDir[i].second; // 체크할 J

						// 경계체크
						if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= n)
						{
							continue;
						}

						// 바다인 경우
						if (graph[checkI][checkJ] == 0)
						{
							continue;
						}

						// 섬인 경우
						if (!vis[checkI][checkJ]) // 방문하지 않은곳만
						{
							vis[checkI][checkJ] = true; // 방문체크
							island.push({ checkI, checkJ }); // 큐에 저장
						}
					}
				}

				islandCnt++; // 더이상 섬이 발견되지 않으면 섬 개수 증가
			}
		}
	}

	cout << islandCnt << '\n';

	return 0;
}