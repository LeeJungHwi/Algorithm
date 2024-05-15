#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// Cheese
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m, c; // 3 3 1
	cin >> n >> m >> c;

	vector<vector<char> > graph(n, vector<char>(m)); // 그래프
	vector<vector<int> > dis(n, vector<int>(m)); // 거리
	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });
	
	// 그래프 초기화
	// 시작위치, 각 치즈 저장

	map<int, pair<int, int> > path;
	string inputString;

	for (int i = 0; i < n; i++)
	{
		cin >> inputString;

		for (int j = 0; j < m; j++)
		{
			graph[i][j] = inputString[j];
			if (graph[i][j] == 'S') path[0] = { i, j };
			else if (isdigit(graph[i][j])) path[graph[i][j] - '0'] = { i, j };
		}
	}

	//for (auto a : graph)
	//{
	//	for (auto b : a)
	//	{
	//		cout << b << ' ';
	//	}
	//	cout << '\n';
	//}

	//for (auto it = path.begin(); it != path.end(); it++)
	//{
	//	cout << it->first << ' ' << it->second.first << ' ' << it->second.second << '\n';
	//}

	// 맵 돌면서
	// 다음 치즈 까지 거리 누적

	int sumDis = 0;

	for (auto it = path.begin(); it != path.end(); )
	{
		if (it == --path.end()) break;
		checkPos.push({ it->second.first, it->second.second });
		dis[it->second.first][it->second.second] = 1;
		it++;

		// 큐가 빌때까지
		while (!checkPos.empty())
		{
			// 기준위치 꺼냄
			pair<int, int> standardPos = checkPos.front();
			checkPos.pop();

			// 다음 치즈위치면 거리 누적하고 break
			if (standardPos.first == it->second.first && standardPos.second == it->second.second)
			{
				sumDis += dis[standardPos.first][standardPos.second];
				break;
			}

			// 상하좌우
			for (int i = 0; i < 4; i++)
			{
				// 체크 할 위치
				int checkI = standardPos.first + checkDir[i].first;
				int checkJ = standardPos.second + checkDir[i].second;

				// 경계체크
				if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m) continue;

				// 방문체크(거리로)
				if (dis[checkI][checkJ] > 0) continue;

				// 벽체크
				if (graph[checkI][checkJ] == 'X') continue;

				// 큐에저장, 거리저장
				checkPos.push({ checkI, checkJ });
				dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;
			}
		}

		// 큐 초기화
		while (!checkPos.empty()) checkPos.pop();

		// 거리 초기화
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				dis[i][j] = 0;
			}
		}
	}

	// 치즈 개수 빼줌
	cout << sumDis - c << '\n';

	return 0;
}