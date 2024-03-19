#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 불켜기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 3, 6
	cin >> n >> m;

	vector<vector<int> > graph(n + 1, vector<int>(n + 1)); // 그래프
	vector<vector<bool> > vis(n + 1, vector<bool>(n + 1)); // 방문체크
	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1});

	//	1 1 1 2
	//	2 1 2 2
	//	1 1 1 3
	//	2 3 3 1
	//	1 3 1 2
	//	1 3 2 1

	int x, y, a, b; // X, Y, A, B
	map<pair<int, int>, vector<pair<int, int> > > switches; // (스위치가 있는 방, 스위치로 불을 켤 수 있는 방들) 맵핑

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> a >> b;

		switches[{x, y}].push_back({ a, b });
	}

	//// 디버깅용
	////	11 12 13
	////	13 12 21
	////	21 22
	////	23 31
	//for (auto it = switches.begin(); it != switches.end(); it++)
	//{
	//	cout << it->first.first << it->first.second << ' ';
	//	for (int i = 0; i < it->second.size(); i++)
	//	{
	//		cout << it->second[i].first << it->second[i].second << ' ';
	//	}
	//	cout << '\n';
	//}

	// 일단 (1,1)에서 불을 켤수있는 방의 불을 킴

	int sumTurnCnt = 0;

	graph[1][1] = 1;
	sumTurnCnt++;

	for (int i = 0; i < switches[{1, 1}].size(); i++)
	{
		if (graph[switches[{1, 1}][i].first][switches[{1, 1}][i].second] == 0)
		{
			graph[switches[{1, 1}][i].first][switches[{1, 1}][i].second] = 1;
			sumTurnCnt++;
		}
	}

	// 디버깅용
	//for (auto a : graph)
	//{
	//	for (auto b : a)
	//	{
	//		cout << b << ' ';
	//	}
	//	cout << '\n';
	//}

	// 현재 그래프에서 BFS 돌려서 켤수있는 스위치 모두 켬
	// 1 1 1
	// 0 0 0
	// 0 0 0

	// 더이상 스위치를 켠 방이 없으면 종료
	while (true)
	{
		int turnCnt = 0; // 스위치를 켠 횟수

		// (1,1)부터 BFS 시작
		checkPos.push({ 1, 1 });
		vis[1][1] = true;

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
				if (checkI < 1 || checkJ < 1 || checkI >= n + 1 || checkJ >= n + 1)
				{
					continue;
				}

				// 방문체크
				if (vis[checkI][checkJ])
				{
					continue;
				}

				// 불이켜지지않은방체크
				if (graph[checkI][checkJ] == 0)
				{
					continue;
				}

				// 큐에저장 방문체크 스위치켜기
				checkPos.push({ checkI, checkJ });
				vis[checkI][checkJ] = true;

				for (int j = 0; j < switches[{checkI, checkJ}].size(); j++)
				{
					// 어두운방일때만 불 켜기
					if (graph[switches[{checkI, checkJ}][j].first][switches[{checkI, checkJ}][j].second] == 0)
					{
						graph[switches[{checkI, checkJ}][j].first][switches[{checkI, checkJ}][j].second] = 1;
						turnCnt++;
					}
				}
			}
		}

		// 더이상 스위치를 켠 방이 없으면 종료
		if (turnCnt == 0)
		{
			break;
		}

		// 켠 방이 있다면 누적하고 vis 초기화
		sumTurnCnt += turnCnt;

		for (int i = 1; i < n + 1; i++)
		{
			for (int j = 1; j < n + 1; j++)
			{
				vis[i][j] = false;
			}
		}
	}

	cout << sumTurnCnt << '\n';

	return 0;
}