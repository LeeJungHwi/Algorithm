#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 유닛 이동시키기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 5, 5
	cin >> n >> m;

	int a, b; // A, B 2, 2
	cin >> a >> b;

	int k; // K 3
	cin >> k;

	vector<vector<int> > graph(n, vector<int>(m)); // 그래프
	vector<vector<int> > dis(n, vector<int>(m)); // 거리
	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1 * a, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 * b});

	// 장애물
	//	2 2
	//	3 2
	//	3 3
	int y, x;

	for (int i = 0; i < k; i++)
	{
		cin >> y >> x;

		graph[y - 1][x - 1] = 1;
	}

	//for (auto a : graph)
	//{
	//	for (auto b : a)
	//	{
	//		cout << b << ' ';
	//	}
	//	cout << '\n';
	//}

	// 시작위치, 도착위치
	pair<int, int> startPos; // 4 1
	cin >> startPos.first >> startPos.second;
	checkPos.push({ startPos.first - 1, startPos.second - 1 });
	dis[startPos.first - 1][startPos.second - 1] = 1;

	//cout << startPos.first - 1 << ' ' << startPos.second - 1 << '\n';

	pair<int, int> endPos; // 1 4
	cin >> endPos.first >> endPos.second;

	//cout << endPos.first - 1 << ' ' << endPos.second - 1 << '\n';

	// BFS
	while (!checkPos.empty()) // 큐가 빌때까지
	{
		// 기준위치 꺼냄
		pair<int, int> standardPos = checkPos.front();
		checkPos.pop();

		// 유닛위치가 유닛전체부분에서 좌상위치
		// 상하좌우 체크할 때 상하는 b만큼 좌우는 a만큼 체크해야함
		for (int i = 0; i < 4; i++)
		{
			// 경계체크, 방문체크 => 좌상에서 상하좌우 한칸씩만 확인하면됨
			if (i % 2 == 0)
			{
				int checkI = standardPos.first + checkDir[i].first;
				int checkJ = standardPos.second + checkDir[i].second;
				if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m)continue;
				if (dis[checkI][checkJ] > 0) continue;
			}
			else
			{
				if (i == 1)
				{
					int checkI = standardPos.first + checkDir[i].first / a;
					int checkJ = standardPos.second + checkDir[i].second;
					if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m)continue;
					if (dis[checkI][checkJ] > 0) continue;
				}
				else if (i == 3)
				{
					int checkI = standardPos.first + checkDir[i].first;
					int checkJ = standardPos.second + checkDir[i].second / b;
					if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m)continue;
					if (dis[checkI][checkJ] > 0) continue;
				}
			}

			bool isMove = true; // 움직일수있는지 체크

			// 상하
			if (i < 2)
			{
				// b만큼 우로 가면서 상하 체크
				// 하나라도 경계를 만나거나 벽에 막히면 isMove false, break
				for (int j = 0; j < b; j++)
				{
					// 체크 할 위치
					int checkI = standardPos.first + checkDir[i].first;
					int checkJ = standardPos.second + checkDir[i].second + j;

					// 경계체크
					if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m)
					{
						isMove = false;

						break;
					}

					// 장애물체크
					if (graph[checkI][checkJ] == 1)
					{
						isMove = false;

						break;
					}
				}

				if (!isMove) continue;
			}
			else // 좌우
			{
				// a만큼 하로 가면서 좌우 체크
				// 하나라도 경계를 만나거나 벽에 막히면 isMove false, break
				for (int j = 0; j < a; j++)
				{
					// 체크 할 위치
					int checkI = standardPos.first + checkDir[i].first + j;
					int checkJ = standardPos.second + checkDir[i].second;

					// 경계체크
					if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m)
					{
						isMove = false;

						break;
					}

					// 장애물체크
					if (graph[checkI][checkJ] == 1)
					{
						isMove = false;

						break;
					}
				}

				if (!isMove) continue;
			}

			// 큐에저장, 거리저장
			// standard에서 상하좌우 중 하나
			if (i % 2 == 0)
			{
				checkPos.push({ standardPos.first + checkDir[i].first, standardPos.second + checkDir[i].second });
				dis[standardPos.first + checkDir[i].first][standardPos.second + checkDir[i].second] = dis[standardPos.first][standardPos.second] + 1;
			}
			else
			{
				if (i == 1)
				{
					checkPos.push({ standardPos.first + checkDir[i].first / a, standardPos.second + checkDir[i].second });
					dis[standardPos.first + checkDir[i].first / a][standardPos.second + checkDir[i].second] = dis[standardPos.first][standardPos.second] + 1;
				}
				else if (i == 3)
				{
					checkPos.push({ standardPos.first + checkDir[i].first, standardPos.second + checkDir[i].second / b});
					dis[standardPos.first + checkDir[i].first][standardPos.second + checkDir[i].second / b] = dis[standardPos.first][standardPos.second] + 1;
				}
			}
		}
	}

	//for (auto a : dis)
	//{
	//	for (auto b : a)
	//	{
	//		cout << b << ' ';
	//	}
	//	cout << '\n';
	//}

	cout << dis[endPos.first - 1][endPos.second - 1] - 1 << '\n';

	return 0;
}