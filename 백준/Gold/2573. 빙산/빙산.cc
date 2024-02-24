#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 빙산
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 5, 7
	cin >> n >> m;

	vector<vector<int> > graph(n, vector<int>(m)); // 그래프
	vector<vector<bool> > vis(n, vector<bool>(m)); // 방문체크
	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	//	0 0 0 0 0 0 0
	//	0 2 4 5 3 0 0
	//	0 3 0 2 5 2 0
	//	0 7 6 2 4 0 0
	//	0 0 0 0 0 0 0
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];
		}
	}

	// 그래프 돌면서 영역개수 카운팅
	// 만약 영역 개수가 2덩어리 이상으로 분리되면 시간 출력, 만약 영역개수가 0개라면 0 출력
	// 그래프 돌면서 빙산의 각 부분을 만나면
	// 상하좌우에 0이 몇개인지 체크해서 감소, 감소했을때 각 부분의 높이가 0이하가되면 0으로 없앰

	int time = 0; // 빙산이 두개로 분리되는 최초시간

	while (true)
	{
		// 그래프돌면서 영역개수 카운팅

		int areaCnt = 0; // 영역 개수

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (graph[i][j] > 0) // 그래프 돌면서 빙산의 부분을 만나면
				{
					// 방문체크
					if (vis[i][j])
					{
						continue;
					}
					
					// 큐에 저장 후 방문체크
					checkPos.push({ i, j });
					vis[i][j] = true;

					// 영역개수 증가
					areaCnt++;

					while (!checkPos.empty()) // 큐가 빌때까지
					{
						// 기준위치 꺼냄
						pair<int, int> standardPos = checkPos.front();
						checkPos.pop();

						// 상하좌우
						for (int k = 0; k < 4; k++)
						{
							// 체크 할 위치
							int checkI = standardPos.first + checkDir[k].first;
							int checkJ = standardPos.second + checkDir[k].second;

							// 경계체크
							if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m)
							{
								continue;
							}

							// 바다체크
							if (graph[checkI][checkJ] == 0)
							{
								continue;
							}

							// 방문체크
							if (vis[checkI][checkJ])
							{
								continue;
							}

							// 큐에 저장 후 방문체크
							checkPos.push({ checkI, checkJ });
							vis[checkI][checkJ] = true;
						}
					}
				}
			}
		}

		// vis 초기화
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				vis[i][j] = false;
			}
		}

		// 만약 영역 개수가 2덩어리 이상으로 분리되면 시간 출력, 만약 영역개수가 0개라면 0 출력
		if (areaCnt >= 2)
		{
			cout << time << '\n';

			return 0;
		}
		else if (areaCnt == 0)
		{
			cout << 0 << '\n';

			return 0;
		}

		// 그래프 돌면서 빙산의 각 부분을 만나면
		// 상하좌우에 0이 몇개인지 체크해서 감소시킬 빙산의 위치와 감소시킬 값 저장
		// 전부 체크가 끝나고 감소시킴
		// 감소했을때 각 부분의 높이가 0이하가되면 0으로 없앰

		vector<pair<pair<int, int>, int > > removePos; // (감소시킬 위치, 감소시킬 값) 쌍 저장

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (graph[i][j] > 0)
				{
					int seaCnt = 0; // 상하좌우에있는 바다 개수

					// 상하좌우
					for (int k = 0; k < 4; k++)
					{
						// 체크 할 위치
						int checkI = i + checkDir[k].first;
						int checkJ = j + checkDir[k].second;

						// 경계체크
						if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m)
						{
							continue;
						}

						// 바다체크
						if (graph[checkI][checkJ] == 0)
						{
							seaCnt++;
						}
					}

					// 감소시킬 빙산의 위치와 감소시킬 값 저장
					if (seaCnt > 0)
					{
						removePos.push_back({ {i, j}, seaCnt });
					}
				}
			}
		}

		// 전부 체크가 끝나고 감소시킴
		// 감소했을때 각 부분의 높이가 0이하가되면 0으로 없앰
		for (int i = 0; i < removePos.size(); i++)
		{
			graph[removePos[i].first.first][removePos[i].first.second] -= removePos[i].second;

			if (graph[removePos[i].first.first][removePos[i].first.second] < 0)
			{
				graph[removePos[i].first.first][removePos[i].first.second] = 0;
			}
		}

		// 시간++
		time++;
	}

	return 0;
}