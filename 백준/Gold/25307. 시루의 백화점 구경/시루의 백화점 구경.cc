#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 시루의 백화점 구경
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 시작 위치 저장
	// 마네킹 위치 큐에 저장
	// 확장하면서 의자 cnt--
	// 확장 할 때 거리 갱신된 곳 중 최단거리는 큐에 다시 저장
	// 방문한 곳은 큐에 중복 저장 X
	// 의자 cnt == 0이면 -1
	// BFS 돌리면서 의자 까지 거리
	// 거리 갱신 안 되면 -1

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int> > graph(n, vector<int>(m));
	vector<vector<int> > dis(n, vector<int>(m));
	vector<vector<bool> > vis(n, vector<bool>(m));
	queue<pair<int, int> > checkPos;
	vector<pair<int, int> > checkDir;
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	pair<int, int> startPos;
	int chairCnt = 0;
	vector<pair<int, int> > mannequinPos;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 4) startPos = { i, j };
			else if (graph[i][j] == 3)
			{
				checkPos.push({ i, j });
				dis[i][j] = 1;
			}
			else if (graph[i][j] == 2) chairCnt++;
		}
	}

	while (!checkPos.empty())
	{
		pair<int, int> standardPos = checkPos.front();
		checkPos.pop();

		// k번 확장
		if (dis[standardPos.first][standardPos.second] > k) continue;

		for (int j = 0; j < 4; j++)
		{
			int checkI = standardPos.first + checkDir[j].first;
			int checkJ = standardPos.second + checkDir[j].second;

			if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m) continue;

			// 거리가 체크된 곳 중 최단거리만 체크
			if (dis[checkI][checkJ] != 0 && dis[checkI][checkJ] < dis[standardPos.first][standardPos.second] + 1) continue;

			// 큐에 중복 저장 방지 => 메모리 초과
			if (vis[checkI][checkJ] > 0) continue;

			checkPos.push({ checkI, checkJ });
			dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;
			vis[checkI][checkJ] = true;

			// 의자면 의자 수 감소하고 3으로
			if (graph[checkI][checkJ] == 2)
			{
				chairCnt--;
				graph[checkI][checkJ] = 3;
			}
			else if (graph[checkI][checkJ] < 2) graph[checkI][checkJ] = 3;
		}
	}

	// 의자 수가 없으면 -1
	if (chairCnt == 0)
	{
		cout << -1 << '\n';
		return 0;
	}

	//for (auto a : graph)
	//{
	//	for (auto b : a)
	//	{
	//		cout << b << ' ';
	//	}
	//	cout << '\n';
	//}

	// 시작위치 부터 의자위치 까지 거리
	checkPos.push(startPos);
	dis[startPos.first][startPos.second] = 1;

	while (!checkPos.empty())
	{
		pair<int, int> standardPos = checkPos.front();
		checkPos.pop();

		// 의자 찾으면
		if (graph[standardPos.first][standardPos.second] == 2)
		{
			cout << dis[standardPos.first][standardPos.second] - 1 << '\n';
			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			int checkI = standardPos.first + checkDir[i].first;
			int checkJ = standardPos.second + checkDir[i].second;

			if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m) continue;
			if (dis[checkI][checkJ] > 0) continue;
			if (graph[checkI][checkJ] != 0 && graph[checkI][checkJ] != 2) continue;

			checkPos.push({ checkI, checkJ });
			dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;
		}
	}

	// 여기 오면 의자 못 찾음
	cout << -1 << '\n';

	return 0;
}