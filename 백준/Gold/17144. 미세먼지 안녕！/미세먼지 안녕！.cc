#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 미세먼지 안녕!
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// r by c 1-based 행렬
	// 그래프 각 요소는 미세먼지의 양
	// 공기청정기는 항상 1열에 두행을 차지함
	// 1 초 동안 발생하는 일
	/*
	1.모든 미세먼지가 있는칸에서 확산됨
	인접한 네방향으로 확산됨
	인접한 방향에 공기청정기가 있거나 경계를 벗어나면 확산이 일어나지않음
	인접한 방향당 확산되는 미세먼지양 = 기존 칸의 미세먼지양 / 5
	기존 칸에 남은 미세먼지양 = 기존 칸의 미세먼지양 - 인접한 방향당 확산되는 미세먼지양 * 확산된 방향의 수
	2.공기청정기가 작동함
	공기청정기에서 바람이 나옴
	위쪽 공기청정기의 바람은 반시계, 아래쪽 공기청저기의 바람은 시계 방향으로 순환함
	바람이 불면 미세먼지가 바람의 방향대로 모두 한 칸씩 이동함
	공기청정기의 바람은 미세먼지가 없으며 공기청정기로 미세먼지가 들어가면 모두 정화됨
	*/

	// T초가 지난 후 남아있는 미세먼지양 구하기

	int r, c, t; // R, C, T 7, 8, 2
	cin >> r >> c >> t;

	vector<vector<int> > graph(r + 1, vector<int>(c + 1)); // 그래프
	vector<vector<int> > add(r + 1, vector<int>(c + 1)); // 확산돼서 각 칸에 더해질 미세먼지 양 저장
	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });
	int ui = 0, di = 0; // 공기청정기 위, 아래 행

	//	0 0 0 0 0 0 0 9
	//	0 0 0 0 3 0 0 8
	//	-1 0 5 0 0 0 22 0
	//	-1 8 0 0 0 0 0 0
	//	0 0 0 0 0 10 43 0
	//	0 0 5 0 15 0 0 0
	//	0 0 40 0 0 0 20 0
	// 미세먼지는 큐에 저장 -> 모든 미세먼지에서 확산하기위해서
	// 공기청정기 위, 아래 행 저장
	for (int i = 1; i < r + 1; i++)
	{
		for (int j = 1; j < c + 1; j++)
		{
			cin >> graph[i][j];

			if (graph[i][j] > 0)
			{
				checkPos.push({ i, j });
			}
			else if (graph[i][j] == -1)
			{
				if (ui == 0)
				{
					ui = i; // 3

					continue;
				}

				di = i; // 4
			}
		}
	}

	// t초가 지나면 종료
	while (t != 0)
	{
		// 1초 동안 발생
		t--;

		// 1. 미세먼지 확산
		/*
		0 30 7
		공10 0
		공 0 20

		0  30 7
		공 10 4
		공 4 12

		0 32 7
		공 4 6
		공 6 12

		6 15 11
		공10 7
		공 6 12
		*/
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
				if (checkI < 1 || checkJ < 1 || checkI >= r + 1 || checkJ >= c + 1)
				{
					continue;
				}

				// 공기청정기체크
				if (graph[checkI][checkJ] == -1)
				{
					continue;
				}

				// 확산돼서 추가되는 미세먼지양 저장, 기존 칸의 미세먼지양은 해당 값만큼 빼줌
				add[checkI][checkJ] += graph[standardPos.first][standardPos.second] / 5;
				add[standardPos.first][standardPos.second] -= graph[standardPos.first][standardPos.second] / 5;
			}
		}

		// 모든 미세먼지에 대해 확산이 끝났다면
		// 그래프에 추가되는 미세먼지양 추가
		for (int i = 1; i < r + 1; i++)
		{
			for (int j = 1; j < c + 1; j++)
			{
				if (add[i][j] != 0) // add 값이 있다면 추가
				{
					graph[i][j] += add[i][j];
				}
			}
		}

		// 2. 공기청정기가 작동함
		/*
		공기청정기 위쪽 행 = ui
		공기청정기 아래쪽 행 = di

		2-1 공기청정기 위쪽
		(ui - 2, 1)부터 아래로 값 덮어씀
		(1, 2)부터 왼쪽으로 값 덮어씀
		(2, c)부터 위쪽으로 값 덮어씀
		(ui, c - 1)부터 오른쪽으로 값 덮어씀

		2-2 공기청정기 아래쪽
		(di + 2, 1)부터 위로 값 덮어씀
		(r, 2)부터 왼쪽으로 값 덮어씀
		(r - 1, c)부터 아래로 값 덮어씀
		(di, c - 1)부터 오른쪽으로 값 덮어씀
		*/

		// 2 - 1 공기청정기 위쪽
		// (ui - 2, 1)부터 아래로 값 덮어씀
		for (int i = ui - 2; i > 0; i--)
		{
			graph[i + 1][1] = graph[i][1];
		}

		// (1, 2)부터 왼쪽으로 값 덮어씀
		for (int i = 2; i < c + 1; i++)
		{
			graph[1][i - 1] = graph[1][i];
		}

		// (2, c)부터 위쪽으로 값 덮어씀
		for (int i = 2; i < ui + 1; i++)
		{
			graph[i - 1][c] = graph[i][c];
		}

		// (ui, c - 1)부터 오른쪽으로 값 덮어씀
		for (int i = c - 1; i > 1; i--)
		{
			graph[ui][i + 1] = graph[ui][i];
		}

		// 공기청정기 위쪽 바로 옆에 붙어있는 값 0으로
		graph[ui][2] = 0;

		// 2 - 2 공기청정기 아래쪽
		// (di + 2, 1)부터 위로 값 덮어씀
		for (int i = di + 2; i < r + 1; i++)
		{
			graph[i - 1][1] = graph[i][1];
		}

		// (r, 2)부터 왼쪽으로 값 덮어씀
		for (int i = 2; i < c + 1; i++)
		{
			graph[r][i - 1] = graph[r][i];
		}

		// (r - 1, c)부터 아래로 값 덮어씀
		for (int i = r - 1; i > di - 1; i--)
		{
			graph[i + 1][c] = graph[i][c];
		}

		// (di, c - 1)부터 오른쪽으로 값 덮어씀
		for (int i = c - 1; i > 1; i--)
		{
			graph[di][i + 1] = graph[di][i];
		}
		
		// 공기청정기 아래쪽 바로 옆에 붙어있는 값 0으로
		graph[di][2] = 0;

		// add 초기화
		for (int i = 1; i < r + 1; i++)
		{
			for (int j = 1; j < c + 1; j++)
			{
				add[i][j] = 0;

				// checkPos에 미세먼지 위치 저장
				if (graph[i][j] > 0)
				{
					checkPos.push({ i, j });
				}
			}
		}
	}

	// T초가 지나고 미세먼지 총합 구하기
	int sum = 0;

	for (int i = 1; i < r + 1; i++)
	{
		for (int j = 1; j < c + 1; j++)
		{
			if (graph[i][j] > 0)
			{
				sum += graph[i][j];
			}
		}
	}

	cout << sum << '\n';

	return 0;
}