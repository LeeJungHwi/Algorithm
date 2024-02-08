#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 잔디
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 5
	cin >> n;

	vector<vector<int> > graph(n, vector<int>(n)); // 그래프
	vector<vector<int> > dis(n, vector<int>(n)); // 거리

	queue<pair<int, int> > checkPos; // 체크할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	//	1 0 0 0 0
	//	0 0 0 1 0
	//	0 1 2 1 0
	//	0 0 1 2 0
	//	0 0 0 0 0
	// 잔디 위치 거리 1 할당 후 큐에 추가
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];

			if (graph[i][j] == 2)
			{
				dis[i][j] = 1;
				checkPos.push({ i, j });
			}
		}
	}

	// BFS
	// 큐가 빌때까지
	// 경계체크, 바위체크, 맨땅을 만나면 거리가 이미 할당된 경우 최소값, 거리가 할당되지 않은경우 이전 거리 + 1, 큐에 저장
	// 거리 최대값 출력

	while (!checkPos.empty())
	{
		// 기준위치 꺼냄
		pair<int, int> standardPos = checkPos.front();
		checkPos.pop();

		for (int i = 0; i < 4; i++)
		{
			// 체크할 위치
			int checkI = standardPos.first + checkDir[i].first;
			int checkJ = standardPos.second + checkDir[i].second;

			// 경계체크
			if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= n)
			{
				continue;
			}

			// 바위체크
			if (graph[checkI][checkJ] == 1)
			{
				continue;
			}

			// 맨땅을 만나면 거리가 이미 할당된 경우 최소값, 거리가 할당되지 않은경우 이전 거리 + 1, 큐에 저장
			if (dis[checkI][checkJ] > 0)
			{
				if (dis[checkI][checkJ] > dis[standardPos.first][standardPos.second] + 1)
				{
					dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;
					checkPos.push({ checkI, checkJ });
				}
			}
			else if (dis[checkI][checkJ] == 0)
			{
				dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;
				checkPos.push({ checkI, checkJ });
			}
		}
	}

	// 모든 맨땅에 잔디가 심어지는데 걸리는 최소시간 = 그래프 요소 중 최대거리

	int result = 0; // 최소시간

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (result < dis[i][j])
			{
				result = dis[i][j];
			}
		}
	}

	cout << result - 1 << '\n';

	return 0;
}