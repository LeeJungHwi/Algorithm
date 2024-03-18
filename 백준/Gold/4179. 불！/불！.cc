#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 불!
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int r, c; // R, C 4, 4
	cin >> r >> c;

	vector<vector<char> > graph(r, vector<char>(c)); // 그래프
	vector<vector<int> > dis(r, vector<int>(c)); // 거리 체크
	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	//####
	//#JF#
	//#..#
	//#..#

	string inputString; // 입력 문자열
	pair<int, int> jihunPos; // 지훈이 시작위치

	for (int i = 0; i < r; i++)
	{
		cin >> inputString;

		for (int j = 0; j < c; j++)
		{
			graph[i][j] = inputString[j];

			// 불 먼저 BFS 돌리기위해 큐에 저장, 거리 1
			if (graph[i][j] == 'F')
			{
				checkPos.push({ i, j });
				dis[i][j] = 1;
			}
			else if (graph[i][j] == 'J') // 지훈이도 BFS 돌리기위해 위치 저장
			{
				jihunPos = { i, j };
			}
		}
	}

	// 불 먼저 BFS 돌리고
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
			if (checkI < 0 || checkJ < 0 || checkI >= r || checkJ >= c)
			{
				continue;
			}

			// 벽체크
			if (graph[checkI][checkJ] == '#')
			{
				continue;
			}

			// 방문체크(거리로)
			if (dis[checkI][checkJ] > 0)
			{
				continue;
			}

			// 큐에저장, 거리저장
			checkPos.push({ checkI, checkJ });
			dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;
		}
	}

	// 디버깅용
	//for (auto a : dis)
	//{
	//	for (auto b : a)
	//	{
	//		cout << b << ' ';
	//	}
	//	cout << '\n';
	//}

	// 지훈이를 BFS 돌리면서 최단거리일때만 큐에저장 거리저장 하면서 나가다가 경계를 만나면
	// 탈출시간에 거리 저장, 저장된 거리가 0이면 탈출 불가능하므로 IMPOSSIBLE 출력 아니면 탈출시간 출력

	checkPos.push(jihunPos);
	dis[jihunPos.first][jihunPos.second] = 1;

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

			// 경계체크(탈출 가능)
			if (checkI < 0 || checkJ < 0 || checkI >= r || checkJ >= c)
			{
				cout << dis[standardPos.first][standardPos.second] << '\n';

				return 0;
			}

			// 벽체크
			if (graph[checkI][checkJ] == '#')
			{
				continue;
			}

			// 최단거리이거나 불이 퍼지지않은곳이면 갱신
			if (dis[checkI][checkJ] > dis[standardPos.first][standardPos.second] + 1 || dis[checkI][checkJ] == 0)
			{
				checkPos.push({ checkI, checkJ });
				dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;
			}
		}
	}

	// 지훈이의 BFS가 끝나고도 탈출하지못하면 탈출불가능
	cout << "IMPOSSIBLE" << '\n';

	return 0;
}