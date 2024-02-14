#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <fstream>
using namespace std;

// 상범 빌딩
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int l, r, c; // L, R, C 3, 4, 5

	// 0 0 0이 입력될때까지 입력받기
	// 그래프에 시작지점(S), 빈칸(.), 금(#), 출구(E) 저장
	// S부터 BFS 돌리기
	// 경계체크, 방문체크(거리로), 금체크, 빈칸을 만나면 큐에 추가 후 거리 저장
	// 만약 출구 거리가 할당되지 않아있다면 Trapped! 출력 후 continue
	// 거리가 할당되어있다면 Escaped in {출구 거리 - 1} minutes(s). 출력

	queue<tuple<int ,int, int> > checkPos; // 체크 할 위치
	vector<tuple<int, int, int> > checkDir; // 상하좌우위층아래층
	checkDir.push_back({ 0, -1, 0 });
	checkDir.push_back({ 0, 1, 0 });
	checkDir.push_back({ 0, 0, -1 });
	checkDir.push_back({ 0, 0, 1 });
	checkDir.push_back({ -1, 0, 0 });
	checkDir.push_back({ 1, 0, 0 });

	while (true)
	{
		cin >> l >> r >> c;

		// 0 0 0이 입력되면 종료
		if (l == 0 && r == 0 && c == 0)
		{
			break;
		}

		vector<vector<vector<char> > > graph(l, vector<vector<char> >(r, vector<char>(c))); // 그래프
		vector<vector<vector<int> > > dis(l, vector<vector<int> >(r, vector<int>(c))); // 거리
		tuple<int, int, int> endPos;

		//S....
		//.###.
		//.##..
		//###.#
		//
		//#####
		//#####
		//##.##
		//##...
		//
		//#####
		//#####
		//#.###
		//####E
		// 시작지점 큐에 저장 후 거리 저장
		// 도착지점 백업
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < r; j++)
			{
				for (int k = 0; k < c; k++)
				{
					cin >> graph[i][j][k];

					if (graph[i][j][k] == 'S')
					{
						checkPos.push({ i, j, k });
						dis[i][j][k] = 1;
					}
					else if (graph[i][j][k] == 'E')
					{
						endPos = { i, j, k };
					}
				}
			}
		}

		// S부터 BFS 돌리기
		while (!checkPos.empty()) // 큐가 빌때까지
		{
			// 기준위치 꺼냄
			tuple<int, int, int> standardPos = checkPos.front();
			checkPos.pop();

			// 상하좌우위층아래층
			for (int i = 0; i < 6; i++)
			{
				// 체크 할 위치
				int checkI = get<0>(standardPos) + get<0>(checkDir[i]);
				int checkJ = get<1>(standardPos) + get<1>(checkDir[i]);
				int checkK = get<2>(standardPos) + get<2>(checkDir[i]);

				// 경계체크
				if (checkI < 0 || checkJ < 0 || checkK < 0 || checkI >= l || checkJ >= r || checkK >= c)
				{
					continue;
				}

				// 방문체크(거리로)
				if (dis[checkI][checkJ][checkK] > 0)
				{
					continue;
				}

				// 금체크
				if (graph[checkI][checkJ][checkK] == '#')
				{
					continue;
				}
				
				// 빈칸을 만나면 큐에 추가 후 거리 저장
				checkPos.push({ checkI, checkJ, checkK });
				dis[checkI][checkJ][checkK] = dis[get<0>(standardPos)][get<1>(standardPos)][get<2>(standardPos)] + 1;
			}
		}

		// 만약 출구 거리가 할당되지 않아있다면 Trapped! 출력 후 continue
		// 거리가 할당되어있다면 Escaped in {출구 거리 - 1} minutes(s). 출력
		if (dis[get<0>(endPos)][get<1>(endPos)][get<2>(endPos)] == 0)
		{
			cout << "Trapped!\n";

			continue;
		}

		cout << "Escaped in " << dis[get<0>(endPos)][get<1>(endPos)][get<2>(endPos)] - 1 << " minute(s).\n";
	}

	return 0;
}