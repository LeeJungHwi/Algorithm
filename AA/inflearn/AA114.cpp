#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 숲속의 기사
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int w, h; // W, H 8, 4
	cin >> w >> h;

	vector<vector<int> > graph(h, vector<int>(w)); // 지도
	vector<vector<int> > minDis(h, vector<int>(w)); // 거리

	queue<pair<int, int> > checkPos; // 체크할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	vector<pair<int, int> > straw; // 산딸기 위치
	pair<int, int> sword; // 기사 위치
	pair<int, int> YoungHee; // 영희 위치

	//	4 1 0 0 0 0 1 0
	//	0 0 0 1 0 1 0 0
	//	0 2 1 1 3 0 4 0
	//	0 0 0 4 1 1 1 0
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> graph[i][j];

			// 영희 위치, 기사 위치, 산딸기 위치 저장
			if (graph[i][j] == 4)
			{
				straw.push_back({ i, j });
			}
			else if (graph[i][j] == 2)
			{
				YoungHee = { i, j };
			}
			else if (graph[i][j] == 3)
			{
				sword = { i, j };
			}
		}
	}

	// BFS
	// 산딸기 좌표에서 영희 위치 최단거리 + 기사 위치 최단거리 구한 후 최단거리 갱신
	// 방문체크, 경계체크, 벽 체크

	int result = 2147000000; // 최단거리

	for (int i = 0; i < straw.size(); i++)
	{
		// 산딸기 위치 큐에 저장 및 거리 1
		checkPos.push(straw[i]);
		minDis[straw[i].first][straw[i].second] = 1;

		while (!checkPos.empty()) // 큐가 빌때까지
		{
			// 큐에서 기준위치 꺼냄
			pair<int, int> standardPos = checkPos.front();
			checkPos.pop();

			for (int i = 0; i < 4; i++)
			{
				// 체크할 위치
				int checkI = standardPos.first + checkDir[i].first;
				int checkJ = standardPos.second + checkDir[i].second;

				// 경계체크
				if (checkI < 0 || checkJ < 0 || checkI >= h || checkJ >= w)
				{
					continue;
				}

				// 방문체크 : 거리가 할당되어있음
				if (minDis[checkI][checkJ] > 0)
				{
					continue;
				}

				// 벽 체크
				if (graph[checkI][checkJ] == 1)
				{
					continue;
				}

				// 길을 만나면 큐에 저장 후 거리증가
				checkPos.push({ checkI, checkJ });
				minDis[checkI][checkJ] = minDis[standardPos.first][standardPos.second] + 1;
			}
		}

		// 산딸기에서 출발해서 둘다 갈 수 있을때만 최단거리 갱신
		if (minDis[sword.first][sword.second] > 0 && minDis[YoungHee.first][YoungHee.second] > 0)
		{
			if (result > minDis[sword.first][sword.second] + minDis[YoungHee.first][YoungHee.second] - 2)
			{
				result = minDis[sword.first][sword.second] + minDis[YoungHee.first][YoungHee.second] - 2;
			}
		}

		// 거리 초기화
		for (int j = 0; j < h; j++)
		{
			for (int k = 0; k < w; k++)
			{
				minDis[j][k] = 0;
			}
		}
	}

	cout << result << '\n';

	return 0;
}