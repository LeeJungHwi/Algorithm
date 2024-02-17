#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// 기준위치 구조체
struct Standard
{
	// 행, 열, 방향, 이동 및 회전 횟수
	int col;
	int row;
	int dir;
	int transformCnt;

	// 생성자
	Standard() {}
	Standard(int c, int r, int d, int t) : col(c), row(r), dir(d), transformCnt(t) {}

	// 횟수 가 적은 것이 먼저
	bool operator<(const Standard& standard) const
	{
		return transformCnt > standard.transformCnt;
	}
};

// 로봇
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int m, n; // M, N 5, 6
	cin >> m >> n;

	vector<vector<int>> graph(m + 1, vector<int>(n + 1)); // 그래프
	vector<vector<vector<int>>> dis(m + 1, vector<vector<int>>(n + 1, vector<int>(5))); // 거리
	priority_queue<Standard> checkPos; // 체크 할 위치
	vector<pair<int, int>> checkDir; // 동서남북
	checkDir.push_back({ 0, 1 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ -1, 0 });

	// 0 0 0 0 0 0
	// 0 1 1 0 1 0
	// 0 1 0 0 0 0
	// 0 0 1 1 1 0
	// 1 0 0 0 0 0
	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			cin >> graph[i][j];
		}
	}

	// 4 2 3
	// 2 4 1
	int col, row, dir; // 행, 열, 방향

	cin >> col >> row >> dir;
	Standard startPos = Standard(col, row, dir, 0); // 시작위치

	cin >> col >> row >> dir;
	Standard endPos = Standard(col, row, dir, 0); // 도착위치

	// 시작 위치부터 BFS 돌리기
	checkPos.push(startPos);
	dis[startPos.col][startPos.row][startPos.dir] = startPos.transformCnt;

	while (!checkPos.empty()) // 큐가 빌때까지
	{
		// 기준위치 꺼냄
		Standard standardPos = checkPos.top();
		checkPos.pop();

		// 종료조건: 목표 지점 및 방향에 도달한 경우
		if (standardPos.col == endPos.col && standardPos.row == endPos.row && standardPos.dir == endPos.dir)
		{
			cout << standardPos.transformCnt << '\n';

			return 0;
		}

		// 이동횟수 처리
		// Go K : 1, 2, 3 칸 앞까지 이동하는지 체크
		// 누적해서 이동횟수 계산
		for (int i = 1; i < 4; i++)
		{
			int c = standardPos.col + checkDir[standardPos.dir - 1].first * i;
			int r = standardPos.row + checkDir[standardPos.dir - 1].second * i;
			int d = standardPos.dir;
			int t = standardPos.transformCnt + 1;

			// 경계 체크
			if (c < 1 || r < 1 || c >= m + 1 || r >= n + 1)
			{
				break;
			}

			// 궤도 체크
			if (graph[c][r] == 1)
			{
				break;
			}

			// 이미 할당되어있는 거리값이 더 비용이 적은 경우인지 체크
			if (dis[c][r][d] > 0 && dis[c][r][d] <= t)
			{
				continue;
			}

			// 큐에 추가 후 방문 체크
			checkPos.push(Standard(c, r, d, t));
			dis[c][r][d] = t;
		}

		// 회전횟수 처리
		// 기준위치에서 회전할수있는 경우 체크
		// 회전할때 회전횟수 계산
		for (int i = 1; i < 5; i++)
		{
			// 같은방향체크
			if (standardPos.dir == i)
			{
				continue;
			}

			// 회전횟수계산
			// 방향이 90도인 경우 1
			int turnCnt = 1;

			// 방향이 180도인 경우 2
			if (standardPos.dir == 1 && i == 2) // 동 서
			{
				turnCnt++;
			}
			else if (standardPos.dir == 2 && i == 1) // 서 동
			{
				turnCnt++;
			}
			else if (standardPos.dir == 3 && i == 4) // 남 북
			{
				turnCnt++;
			}
			else if (standardPos.dir == 4 && i == 3) // 북 남
			{
				turnCnt++;
			}

			// 이미 할당되어있는 거리값이 더 비용이 적은 경우인지 체크
			if (dis[standardPos.col][standardPos.row][i] > 0 && dis[standardPos.col][standardPos.row][i] <= standardPos.transformCnt + turnCnt)
			{
				continue;
			}

			// 큐에 추가 후 방문 체크
			checkPos.push(Standard(standardPos.col, standardPos.row, i, standardPos.transformCnt + turnCnt));
			dis[standardPos.col][standardPos.row][i] = standardPos.transformCnt + turnCnt;
		}
	}

	return 0;
}
