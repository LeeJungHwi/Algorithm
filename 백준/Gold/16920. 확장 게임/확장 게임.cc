#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 확장게임
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m, p; // N, M, P 3, 3, 2
	cin >> n >> m >> p;

	// 0.각 플레이어가 한턴에 이동하는 칸 저장
	vector<int> moveCnts(p + 1);
	int moveCnt;
	for (int i = 1; i < p + 1; i++)
	{
		cin >> moveCnt;
		moveCnts[i] = moveCnt;
	}

	// 1.그래프 돌면서 플레이어 위치 맵핑하고 맵 돌면서 각 플레이어를 순서대로 큐에 저장
	// 2.BFS 돌리면서 각 플레이어가 한턴에 이동하는 횟수만큼 확장
	// 3.그래프 돌면서 각 플레이어의 성 갯수 카운팅

	vector<vector<int> > graph(n, vector<int>(m));
	vector<vector<bool> > vis(n, vector<bool>(m));
	vector<vector<int> > dis(n, vector<int>(m));
	queue<pair<pair<int, int>, int> > checkPos; // 체크 할 위치, 각 플레이어 번호
	vector<pair<int, int> > checkDir;
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	// .은 0 #은 -1 각 플레리어는 숫자로 치환
	// 벽은 방문체크해서 이동못하게함
	map<int, vector<pair<int, int> > > playerPos; // 각 플레이어가 가지는 성 위치 맵핑
	string inputString;
	for (int i = 0; i < n; i++)
	{
		cin >> inputString;
		for (int j = 0; j < m; j++)
		{
			graph[i][j] = inputString[j] -'0';

			if (inputString[j] == '.') graph[i][j] = 0;
			else if (inputString[j] == '#')
			{
				graph[i][j] = -1;
				vis[i][j] = true;
			}
			else
			{
				graph[i][j] = inputString[j] - '0';
				playerPos[graph[i][j]].push_back({ i,j });
			}
		}
	}

	// 0. 더 이상 확장이 일어나지 않았을 때 종료
	// 1. 각 플레이어를 순서대로 확장 시작
	while (true)
	{
		int expandCnt = 0;

		for (auto it = playerPos.begin(); it != playerPos.end(); it++)
		{
			// 다음 확장 위치
			vector<pair<int, int> > nextPos;

			// 현재 플레이어 위치 모두 큐에 저장
			for (int i = 0; i < it->second.size(); i++)
			{
				checkPos.push({ it->second[i], it->first });
				vis[it->second[i].first][it->second[i].second] = true;
				dis[it->second[i].first][it->second[i].second] = 1;
			}

			while (!checkPos.empty())
			{
				pair<pair<int, int>, int> standardPos = checkPos.front();
				checkPos.pop();

				// 각 플레이어 확장 횟수 체크 하면서 다음 확장 위치 저장
				if (dis[standardPos.first.first][standardPos.first.second] > moveCnts[standardPos.second])
				{
					nextPos.push_back(standardPos.first);
					continue;
				}

				for (int i = 0; i < 4; i++)
				{
					int checkI = standardPos.first.first + checkDir[i].first;
					int checkJ = standardPos.first.second + checkDir[i].second;

					if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m) continue;

					// 내가 확장한 곳 중 최단거리만 체크
					if (graph[checkI][checkJ] == standardPos.second && dis[checkI][checkJ] != 0 && dis[checkI][checkJ] < dis[standardPos.first.first][standardPos.first.second] + 1) continue;

					// 큐에 중복 저장 방지 => 메모리 초과
					if (vis[checkI][checkJ]) continue;

					// 다른 플레이어가 확장한 곳 체크
					if (graph[checkI][checkJ] != 0 && graph[checkI][checkJ] != standardPos.second) continue;

					// 확장
					checkPos.push({ {checkI, checkJ}, standardPos.second });
					dis[checkI][checkJ] = dis[standardPos.first.first][standardPos.first.second] + 1;
					vis[checkI][checkJ] = true;
					graph[checkI][checkJ] = standardPos.second;
					expandCnt++;
				}
			}

			// 다음 확장 위치 갱신
			it->second = nextPos;
		}

		// 더 이상 확장이 일어나지 않으면 종료
		if (expandCnt == 0) break;
	}

	//for (auto a : graph)
	//{
	//	for (auto b : a)
	//	{
	//		cout << b << ' ';
	//	}
	//	cout << '\n';
	//}

	// 3.그래프 돌면서 각 플레이어의 성의 수 구하기

	map<int, int> castleCnts;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (graph[i][j] > 0)
			{
				castleCnts[graph[i][j]]++;
			}
		}
	}

	for (auto it = castleCnts.begin(); it != castleCnts.end(); it++) cout << it->second << ' ';

	return 0;
}
