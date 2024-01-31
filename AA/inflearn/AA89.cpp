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

	vector<vector<int>> graph(n, vector<int>(m)); // 그래프
	vector<vector<int>> dis(n, vector<int>(m)); // 일수
	vector<pair<int, int> > checkDir; // 상 하 좌 우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });
	queue<pair<int, int>> standardPos; // 익은 토마토 위치 큐

	// 익은 토마토 위치 거리 1로 할당 후 큐에 추가(핵심 1)
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
	큐가 빌때까지 상 하 좌 우 체크하면서 토마토를 만나면 거리 증가
	*/
	while (!standardPos.empty())
	{
		// 기준위치 꺼냄
		pair<int, int> curPos = standardPos.front();
		standardPos.pop();

		// 상 하 좌 우 체크
		for (int i = 0; i < 4; i++)
		{
			int checkI = curPos.first + checkDir[i].first;
			int checkJ = curPos.second + checkDir[i].second;

			// 경계체크
			if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m)
			{
				continue;
			}

			// 토마토가 없는 상자 체크
			if (graph[checkI][checkJ] == -1)
			{
				continue;
			}

			// 이미 익은 토마트 체크
			if (graph[checkI][checkJ] == 1)
			{
				continue;
			}

			// 토마토를 만난 경우 거리 증가 후 큐에 저장(핵심 2)
			if (dis[checkI][checkJ] == 0) // 거리가 할당되지 않은경우면
			{
				dis[checkI][checkJ] = dis[curPos.first][curPos.second] + 1;
				standardPos.push({ checkI, checkJ });
			}
			else // 거리가 할당된 경우면
			{
				if (dis[checkI][checkJ] > dis[curPos.first][curPos.second] + 1) // 더 최소날짜인경우만
				{
					dis[checkI][checkJ] = dis[curPos.first][curPos.second] + 1;
					standardPos.push({ checkI, checkJ });
				}
			}
		}
	}

	int minDay = 0; // 최소 걸리는 날짜
	bool isOk = true; // 모두 익었는지 체크

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (graph[i][j] == 0 && dis[i][j] == 0) // 익지않은 토마토가 익지않았으면
			{
				isOk = false;
				break;
			}
		}

		if (!isOk) // 익지않은 토마토가 있으면 -1 출력
		{
			cout << -1 << '\n';
			return 0;
		}
	}

	// 최소 걸리는 날짜 갱신
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
