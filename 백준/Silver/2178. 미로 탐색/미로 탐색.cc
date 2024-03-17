#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 미로탐색
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 4, 6
	cin >> n >> m;

	vector<vector<char> > graph(n, vector<char>(m)); // 그래프
	vector<vector<int> > dis(n, vector<int>(m)); // 거리
	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	//	101111
	//	101010
	//	101011
	//	111011

	string inputString; // 입력문자열

	for (int i = 0; i < n; i++)
	{
		cin >> inputString;

		for (int j = 0; j < m; j++)
		{
			graph[i][j] = inputString[j];
		}
	}

	// (1,1)에서 BFS
	checkPos.push({ 0, 0 });
	dis[0][0] = 1;

	while (!checkPos.empty()) // 큐가 빌때까지
	{
		// 기준위치 꺼냄
		pair<int, int> standardPos = checkPos.front();
		checkPos.pop();

		// 상하좌우
		for (int i = 0; i < 4; i++)
		{
			// 체크 할 위치
			int checkI = standardPos.first + checkDir[i].first;
			int checkJ = standardPos.second + checkDir[i].second;

			// 경계체크
			if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m)
			{
				continue;
			}

			// 방문체크(거리로)
			if (dis[checkI][checkJ] > 0)
			{
				continue;
			}

			// 벽체크
			if (graph[checkI][checkJ] == '0')
			{
				continue;
			}

			// 큐에추가, 거리저장
			checkPos.push({ checkI, checkJ });
			dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;
		}
	}

	cout << dis[n - 1][m - 1] << '\n';

	return 0;
}