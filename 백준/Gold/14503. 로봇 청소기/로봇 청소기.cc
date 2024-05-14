#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 기준위치 구조체
struct Standard
{
	int col;
	int row;
	int dir;

	Standard() {} // 생성자
	Standard(int c, int r, int d) : col(c), row(r), dir(d) {} // 생성자
};

// 로봇청소기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 11, 10
	cin >> n >> m;

	int col, row, dir; // 행, 열, 방향 7, 4, 0
	cin >> col >> row >> dir;

	Standard standardPos = Standard(col, row, dir); // 시작위치

	vector<vector<int> > graph(n, vector<int>(m)); // 그래프
	vector<pair<int, int> > checkDir; // 북동남서
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 0, 1 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });

	//	1 1 1 1 1 1 1 1 1 1
	//	1 0 0 0 0 0 0 0 0 1
	//	1 0 0 0 1 1 1 1 0 1
	//	1 0 0 1 1 0 0 0 0 1
	//	1 0 1 1 0 0 0 0 0 1
	//	1 0 0 0 0 0 0 0 0 1
	//	1 0 0 0 0 0 0 1 0 1
	//	1 0 0 0 0 0 1 1 0 1
	//	1 0 0 0 0 0 1 1 0 1
	//	1 0 0 0 0 0 0 0 0 1
	//	1 1 1 1 1 1 1 1 1 1
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];
		}
	}

	//for (auto a : graph)
	//{
	//	for (auto b : a)
	//	{
	//		cout << b << ' ';
	//	}
	//	cout << '\n';
	//}

	// 1.현재칸이 아직 청소되지 않았다면 현재칸 청소
	// 2.현재칸을 기준으로 북동남서 모두 청소과 완료되었다면
	// 2-1.바라보는 방향을 유지한 채 한칸 후진할수있다면 한칸 후진하고 1번으로 돌아감
	// 2-2.바라보는 방향의 뒤쪽이 벽이라 후진할수없다면 작동 멈춤
	// 3.현재칸을 기준으로 동서남북 중 청소되지않은 빈칸이있다면
	// 3-1.반시계 방향으로 90도 회전함
	// 3-2.바라보는 방향을 기준으로 앞쪽이 청소되지않은 빈칸이라면 앞으로 한칸 이동함
	// 3-3.1번으로 돌아감

	int cleanCnt = 0; // 청소한 횟수

	while (true)
	{
		// 1.현재칸이 아직 청소되지 않았다면 현재칸 청소 -> 청소가 끝나면 값을 2로 바꿔놓자
		if (graph[standardPos.col][standardPos.row] == 0)
		{
			graph[standardPos.col][standardPos.row] = 2;
			cleanCnt++;
		}

		// 현재위치를 기준으로 북동남서 모두 청소가 완료되었는지 체크
		bool isAllClear = true;

		for (int i = 0; i < 4; i++)
		{
			// 체크 할 위치
			int checkI = standardPos.col + checkDir[i].first;
			int checkJ = standardPos.row + checkDir[i].second;

			// 경계체크
			if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m) continue;

			// 벽체크
			if (graph[checkI][checkJ] == 1) continue;

			// 빈칸인 경우 하나라도 청소되지않은 빈칸을 발견하면 모두 청소된거 아님
			if (graph[checkI][checkJ] == 0)
			{
				isAllClear = false;
				break;
			}
		}

		// 2.현재위치를 기준으로 북동남서 모두 청소과 완료되었다면
		if (isAllClear)
		{
			// 2-1.바라보는 방향을 유지한 채 한칸 후진할수있다면 한칸 후진하고 1번으로 돌아감

			if (standardPos.dir == 0) // 바라보는 방향이 북쪽이라면
			{
				if (graph[standardPos.col + 1][standardPos.row] != 1) standardPos.col += 1; // 남쪽이 벽이 아니면 한칸 후진하고 1번으로 돌아감
				else break; // 2-2.바라보는 방향의 뒤쪽이 벽이라 후진할수없다면 작동 멈춤
			}
			else if (standardPos.dir == 1) // 바라보는 방향이 동쪽이라면
			{
				if (graph[standardPos.col][standardPos.row - 1] != 1) standardPos.row -= 1; // 서쪽이 벽이 아니면 한칸 후진하고 1번으로 돌아감
				else break; // 2-2.바라보는 방향의 뒤쪽이 벽이라 후진할수없다면 작동 멈춤
			}
			else if (standardPos.dir == 2) // 바라보는 방향이 남쪽이라면
			{
				if (graph[standardPos.col - 1][standardPos.row] != 1) standardPos.col -= 1; // 북쪽이 벽이 아니면 한칸 후진하고 1번으로 돌아감
				else break; // 2-2.바라보는 방향의 뒤쪽이 벽이라 후진할수없다면 작동 멈춤
			}
			else if (standardPos.dir == 3) // 바라보는 방향이 서쪽이라면
			{
				if (graph[standardPos.col][standardPos.row + 1] != 1) standardPos.row += 1; // 동쪽이 벽이 아니면 한칸 후진하고 1번으로 돌아감
				else break; // 2-2.바라보는 방향의 뒤쪽이 벽이라 후진할수없다면 작동 멈춤
			}

			continue; // 한 칸 후진했으면 1번으로 돌아감
		}
		else // 3.현재칸을 기준으로 북동남서 중 청소되지않은 빈칸이있다면
		{
			// 3-1.반시계 방향으로 90도 회전함

			if (standardPos.dir == 0) // 바라보는 방향이 북쪽이라면
			{
				standardPos.dir = 3; // 서쪽으로
			}
			else if (standardPos.dir == 1) // 바라보는 방향이 동쪽이라면
			{
				standardPos.dir = 0; // 북쪽으로
			}
			else if (standardPos.dir == 2) // 바라보는 방향이 남쪽이라면
			{
				standardPos.dir = 1; // 동쪽으로
			}
			else if (standardPos.dir == 3) // 바라보는 방향이 서쪽이라면
			{
				standardPos.dir = 2; // 남쪽으로
			}

			// 3-2.바라보는 방향을 기준으로 앞쪽이 청소되지않은 빈칸이라면 앞으로 한칸 이동함

			if (standardPos.dir == 0) // 바라보는 방향이 북쪽이라면
			{
				if (graph[standardPos.col - 1][standardPos.row] == 0) // 북쪽 한칸 앞이 청소되지않은 빈칸이면
				{
					standardPos.col -= 1; // 북쪽으로 한칸 이동함
				}
			}
			else if (standardPos.dir == 1) // 바라보는 방향이 동쪽이라면
			{
				if (graph[standardPos.col][standardPos.row + 1] == 0) // 동쪽 한칸 앞이 청소되지않은 빈칸이면
				{
					standardPos.row += 1; // 동쪽으로 한칸 이동함
				}
			}
			else if (standardPos.dir == 2) // 바라보는 방향이 남쪽이라면
			{
				if (graph[standardPos.col + 1][standardPos.row] == 0) // 남쪽 한칸 앞이 청소되지않은 빈칸이면
				{
					standardPos.col += 1; // 남쪽으로 한칸 이동함
				}
			}
			else if (standardPos.dir == 3) // 바라보는 방향이 서쪽이라면
			{
				if (graph[standardPos.col][standardPos.row - 1] == 0) // 서쪽 한칸 앞이 청소되지않은 빈칸이면
				{
					standardPos.row -= 1; // 서쪽으로 한칸 이동함
				}
			}

			continue; // 3-3.1번으로 돌아감
		}
	}

	cout << cleanCnt << '\n';

	return 0;
}