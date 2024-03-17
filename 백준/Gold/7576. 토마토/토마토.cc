#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 토마토 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 6, 4
	cin >> n >> m;

	vector<vector<int> > graph(m, vector<int>(n)); // 그래프
	vector<vector<int> > dis(m, vector<int>(n)); // 거리
	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDIr; // 상하좌우
	checkDIr.push_back({ -1, 0 });
	checkDIr.push_back({ 1, 0 });
	checkDIr.push_back({ 0, -1 });
	checkDIr.push_back({ 0, 1 });

	int maxDis = 0; // 거리최대값(모두 익는데 걸리는 최소시간)

	//	0 0 0 0 0 0
	//	0 0 0 0 0 0
	//	0 0 0 0 0 0
	//	0 0 0 0 0 1
	// 익은토마토 좌표 큐에 저장, 거리 저장
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];

			if (graph[i][j] == 1)
			{
				checkPos.push({ i, j });
				dis[i][j] = 1;

				maxDis = max(maxDis, dis[i][j]);
			}
		}
	}

	// 익은토마토부터 BFS

	while (!checkPos.empty()) // 큐가 빌때까지
	{
		// 기준위치 꺼냄
		pair<int, int> standardPos = checkPos.front();
		checkPos.pop();

		// 상하좌우
		for (int i = 0; i < 4; i++)
		{
			// 체크 할 위치
			int checkI = standardPos.first + checkDIr[i].first;
			int checkJ = standardPos.second + checkDIr[i].second;

			// 경계체크
			if (checkI < 0 || checkJ < 0 || checkI >= m || checkJ >= n)
			{
				continue;
			}

			// 토마토가 없는칸 체크
			if (graph[checkI][checkJ] == -1)
			{
				continue;
			}

			// 방문체크(거리로)
			if (dis[checkI][checkJ] > 0)
			{
				continue;
			}

			// 큐에 추가, 거리 저장, 거리최대 갱신
			checkPos.push({ checkI, checkJ });
			dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;
			maxDis = max(maxDis, dis[checkI][checkJ]);
		}
	}

	// 그래프 돌면서 아직 익지않은 토마토면서 거리가 0이면 -1 출력 후 종료

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] == 0 && dis[i][j] == 0)
			{
				cout << -1 << '\n';

				return 0;
			}
		}
	}

	// 1로 시작했으니 1 빼줌
	cout << maxDis - 1 << '\n';

	return 0;
}