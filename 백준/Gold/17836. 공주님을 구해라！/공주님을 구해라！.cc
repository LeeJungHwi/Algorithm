#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 공주님을 구해라!
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m, t;
	cin >> n >> m >> t;

	// 그람 검을 구하지 않고 바로 가는 경우
	// 그람 검을 구하고 가는 경우

	vector<vector<int> > graph(n, vector<int>(m));
	vector<vector<int> > dis(n, vector<int>(m));
	queue<pair<int, int> > checkPos;
	checkPos.push({ 0, 0 });
	dis[0][0] = 1;
	vector<pair<int, int> > checkDir;
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	pair<int, int> swordPos;
	bool isSword = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 2)
			{
				swordPos = { i, j };
				isSword = true;
			}
		}
	}

	// 그람 검을 구하지 않고 바로 가는 경우 => 벽 영향
	while (!checkPos.empty())
	{
		pair<int, int> standardPos = checkPos.front();
		checkPos.pop();

		for (int i = 0; i < 4; i++)
		{
			int checkI = standardPos.first + checkDir[i].first;
			int checkJ = standardPos.second + checkDir[i].second;

			if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m) continue;
			if (dis[checkI][checkJ] > 0) continue;
			if (graph[checkI][checkJ] == 1) continue;

			checkPos.push({ checkI, checkJ });
			dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;
		}
	}

	int minDis = dis[n - 1][m - 1] - 1;

	// 거리 초기화
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dis[i][j] = 0;
		}
	}

	// 그람 검이 없는 경우
	if (!isSword)
	{
		if (minDis == -1 || minDis > t) cout << "Fail" << '\n';
		else cout << minDis << '\n';

		return 0;
	}

	// 그람 검을 구하고 가는 경우
	checkPos.push({ 0, 0 });
	dis[0][0] = 1;
	int swordDis = -1;

	// 시작점 => 그람검 => 벽 영향
	while (!checkPos.empty())
	{
		pair<int, int> standardPos = checkPos.front();
		checkPos.pop();

		if (standardPos.first == swordPos.first && standardPos.second == swordPos.second)
		{
			swordDis = dis[standardPos.first][standardPos.second] - 1;

			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int checkI = standardPos.first + checkDir[i].first;
			int checkJ = standardPos.second + checkDir[i].second;

			if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m) continue;
			if (dis[checkI][checkJ] > 0) continue;
			if (graph[checkI][checkJ] == 1) continue;

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

	// 그람검 => 도착점 => 벽 영향 X 
	checkPos.push(swordPos);
	dis[swordPos.first][swordPos.second] = 1;

	while (!checkPos.empty())
	{
		// 그람 검을 구한 상태가 아니면 break
		if (swordDis == -1) break;

		pair<int, int> standardPos = checkPos.front();
		checkPos.pop();

		if (standardPos.first == n - 1 && standardPos.second == m - 1)
		{
			swordDis += dis[standardPos.first][standardPos.second] - 1;

			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int checkI = standardPos.first + checkDir[i].first;
			int checkJ = standardPos.second + checkDir[i].second;

			if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m) continue;
			if (dis[checkI][checkJ] > 0) continue;

			checkPos.push({ checkI, checkJ });
			dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;
		}
	}

	// 그람 검을 가지고 구하러 가지 않은 경우 도착 할 수 없으면 swordDis만 고려
	if (minDis == -1)
	{
		if (swordDis == -1 || swordDis > t) cout << "Fail" << '\n';
		else cout << swordDis << '\n';

		return 0;
	}

	// 둘다 도착 가능하면 minDis, swordDis 둘다 고려
	minDis = min(minDis, swordDis);
	if (minDis == -1 || minDis > t) cout << "Fail" << '\n';
	else cout << minDis << '\n';

	return 0;
}