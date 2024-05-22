#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// Bitmap
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 3, 4;
	cin >> n >> m;

	vector<vector<int> > graph(n, vector<int>(m)); // 그래프
	vector<vector<int> > dis(n, vector<int>(m)); // 거리
	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	// 그래프 초기화
	// 흰색 픽셀 저장
	string inputString;
	for (int i = 0; i < n; i++)
	{
		cin >> inputString;
		for (int j = 0; j < m; j++)
		{
			graph[i][j] = inputString[j] - '0';
			if (graph[i][j] == 1)
			{
				checkPos.push({ i, j });
				dis[i][j] = 1;
			}
		}
	}

	// BFS
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

	for (auto a : dis)
	{
		for (auto b : a)
		{
			cout << b - 1 << ' ';
		}
		cout << '\n';
	}


	return 0;
}