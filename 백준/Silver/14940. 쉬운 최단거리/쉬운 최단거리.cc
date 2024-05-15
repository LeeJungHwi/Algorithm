#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 쉬운 최단거리
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 15, 15
	cin >> n >> m;

	vector<vector<int>> graph(n, vector<int>(m)); // 그래프
	vector<vector<int>> dis(n, vector<int>(m)); // 거리
	queue<pair<int, int>> checkPos; // 체크 할 위치
	vector<pair<int, int>> checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	// 그래프 초기화
	// 목표지점 저장
	// 갈 수 없는곳 거리 0
	pair<int, int> desPos;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];

			if (graph[i][j] == 2)
			{
				desPos = { i, j };
				checkPos.push(desPos);
				dis[desPos.first][desPos.second] = 1;
			}
			else if (graph[i][j] == 0) dis[i][j] = 1;
		}
	}

	// 목표지점부터 BFS
	// 큐가 빌때까지
	while (!checkPos.empty())
	{
		// 기준위치 꺼냄
		pair<int, int> standardPos = checkPos.front();
		checkPos.pop();
		
		// 상하좌우
		for (int k = 0; k < 4; k++)
		{
			// 체크 할 위치
			int checkI = standardPos.first + checkDir[k].first;
			int checkJ = standardPos.second + checkDir[k].second;

			// 경계체크
			if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m) continue;

			// 방문체크
			if (dis[checkI][checkJ] > 0) continue;

			// 갈 수 없는곳 체크
			if (graph[checkI][checkJ] == 0) continue;

			// 큐에저장, 거리저장
			checkPos.push({ checkI, checkJ });
			dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;
		}
	}

	// 거리 출력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// 갈 수 있는 땅이면서 거리저장이 안 되어 있으면 못 감
			if (dis[i][j] == 0 && graph[i][j] == 1) cout << -1 << ' ';
			else cout << dis[i][j] - 1 << ' ';
		}
		cout << '\n';
	}

	return 0;
}
