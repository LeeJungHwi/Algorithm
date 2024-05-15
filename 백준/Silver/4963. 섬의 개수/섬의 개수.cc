#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 섬의 개수
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	while (true)
	{
		int m, n; // M, N
		cin >> m >> n;
		if (n == 0 && m == 0) break;

		vector<vector<int> > graph(n, vector<int>(m)); // 그래프
		vector<vector<bool> > vis(n, vector<bool>(m)); // 방문체크
		queue<pair<int, int> > checkPos; // 체크 할 위치
		vector<pair<int, int> > checkDir; // 8방향
		checkDir.push_back({ -1, 0 });
		checkDir.push_back({ 1, 0 });
		checkDir.push_back({ 0, -1 });
		checkDir.push_back({ 0, 1 });
		checkDir.push_back({ -1, -1 });
		checkDir.push_back({ 1, -1 });
		checkDir.push_back({ -1, 1 });
		checkDir.push_back({ 1, 1 });

		// 그래프 초기화
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> graph[i][j];
			}
		}

		int cnt = 0; // 섬 개수

		// 그래프 돌면서
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				// 땅이면서 방문하지 않은곳을 만나면
				if (graph[i][j] == 1 && !vis[i][j])
				{
					// 해당 위치부터 BFS 돌리면서 섬 개수 카운팅
					checkPos.push({ i, j });
					vis[i][j] = true;
					cnt++;

					// 큐가 빌때까지
					while (!checkPos.empty())
					{
						// 기준위치 꺼냄
						pair<int, int> standardPos = checkPos.front();
						checkPos.pop();

						// 상하좌우
						for (int k = 0; k < 8; k++)
						{
							// 체크 할 위치
							int checkI = standardPos.first + checkDir[k].first;
							int checkJ = standardPos.second + checkDir[k].second;

							// 경계체크
							if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m) continue;

							// 방문체크
							if (vis[checkI][checkJ]) continue;

							// 바다체크
							if (graph[checkI][checkJ] == 0) continue;

							// 땅을 만나면 큐에저장, 방문체크
							checkPos.push({ checkI, checkJ });
							vis[checkI][checkJ] = true;
						}
					}
				}
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}