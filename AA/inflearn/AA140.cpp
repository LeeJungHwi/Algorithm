#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 보물찾기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 4
	cin >> n;

	vector<vector<int> > graph(n, vector<int>(n)); // 그래프
	vector<vector<vector<int> > > dis(3, vector<vector<int> >(n, vector<int>(n))); // 현수시간, 영희시간, 동현시간
	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	//	1 0 0 0
	//	0 0 0 0
	//	0 1 0 1
	//	1 0 0 1
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
		}
	}

	int x, y; // 좌표

	//	1 2 -> 현수위치 (0, 1) 부터 BFS 돌리기
	//	4 3 -> 영희위치 (3, 2) 부터 BFS 돌리기
	//	3 1 -> 동현위치 (2, 0) 부터 BFS 돌리기
	for (int i = 0; i < 3; i++)
	{
		cin >> x >> y;

		// 현수위치부터 BFS 돌리기
		checkPos.push({ x - 1, y - 1 }); 
		dis[i][x - 1][y - 1] = 1;

		// BFS
		while (!checkPos.empty()) // 큐가 빌때까지
		{
			// 기준위치 꺼냄
			pair<int, int> standardPos = checkPos.front();
			checkPos.pop();

			// 상하좌우
			for (int j = 0; j < 4; j++)
			{
				// 체크 할 위치
				int checkI = standardPos.first + checkDir[j].first;
				int checkJ = standardPos.second + checkDir[j].second;

				// 경계체크
				if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= n)
				{
					continue;
				}

				// 방문체크
				if (dis[i][checkI][checkJ] > 0)
				{
					continue;
				}

				// 이동불가지역체크
				if (graph[checkI][checkJ] == 1)
				{
					continue;
				}

				// 큐에 저장 후 거리 증가
				checkPos.push({ checkI, checkJ });
				dis[i][checkI][checkJ] = dis[i][standardPos.first][standardPos.second] + 1;
			}
		}
	}

	// BFS 이후 현수 시간
	//	0 1 2 3
	//	3 2 3 4
	//	4 0 4 0
	//	0 6 5 0

	// BFS 이후 영희 시간
	//	0 5 4 5
	//	5 4 3 4
	//	6 0 2 0
	//	0 2 1 0

	// BFS 이후 동현 시간
	//	0 4 5 6
	//	2 3 4 5
	//	1 0 5 0
	//	0 7 6 0

	// 1은 현수 영희 동현 위치
	// 각 친구의 위치를 1초부터 시작했으므로 실제 시간은 각 시간 - 1

	// 시간이 0인 곳 : 현수 영희 동현이 모일 수 없는 위치
	// 시간이 0이 아닌 곳 : 가장 늦게 도착하는 친구의 시간이 모일 수 있는 시간 -> max(현수시간, 영희시간, 동현시간)

	// 모일 수 있는 최단시간 : 시간이 0이 아닌 곳에서 모일 수 있는 시간을 각각 구해서 그 중 최단시간 갱신

	int treasureCnt = 0; // 보물 개수
	int minDis = 2147000000; // 세 친구가 모일 수 있는 최단시간

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// 시간이 0인 곳 체크
			if (dis[0][i][j] == 0 || dis[1][i][j] == 0 || dis[2][i][j] == 0)
			{
				continue;
			}

			// 시간이 0이 아닌 곳에서 가장 늦게 도착하는 친구의 시간이 세 친구가 모이는 시간
			int latestDis = max({ dis[0][i][j], dis[1][i][j], dis[2][i][j] });

			// 세 친구가 모이는 시간이 최단시간과 같으면 보물 개수 카운팅
			if (latestDis == minDis)
			{
				treasureCnt++;
			}
			else // 세 친구가 모이는 시간이 최단시간과 같지않다면 최단시간이 갱신되는 경우 -> 최단시간 및 보물개수 초기화
			{
				if (minDis > latestDis)
				{
					minDis = latestDis;
					treasureCnt = 1;
				}
			}
		}
	}
	
	// 최단시간이 갱신되지않고 2147000000 그대로면 모일 수 없으므로 -1 출력하기
	if (minDis == 2147000000)
	{
		cout << -1 << '\n';

		return 0;
	}

	// 세 친구가 모일 수 있는 지점이 있다면 보물 개수 출력하기
	cout << treasureCnt << '\n';

	return 0;
}