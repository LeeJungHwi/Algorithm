#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 보물섬
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M, 5, 7
	cin >> n >> m;
	vector<vector<char> > graph(n,vector<char>(m)); // 그래프
	vector<vector<int> > dis(n, vector<int>(m)); // 거리
	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	// 그래프 초기화

	string inputString; // 입력문자열

	//	WLLWWWL
	//	LLLWLLL
	//	LWLWLWW
	//	LWLWLLL
	//	WLLWLWW
	for (int i = 0; i < n; i++)
	{
		cin >> inputString;

		for (int j = 0; j < m; j++)
		{
			graph[i][j] = inputString[j];
		}
	}

	// 그래프 돌면서
	// L을 만나면 BFS 돌리면서
	// 최대거리 갱신

	int maxDis = 0;

	// 그래프 돌면서
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// L을 만나면
			if (graph[i][j] == 'L')
			{
				// BFS 돌림
				checkPos.push({ i, j });
				dis[i][j] = 1;

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

						// 방문체크
						if (dis[checkI][checkJ] > 0)
						{
							continue;
						}

						// 바다체크
						if (graph[checkI][checkJ] == 'W')
						{
							continue;
						}

						// 큐에저장, 거리증가, 최대거리 갱신
						checkPos.push({ checkI, checkJ });
						dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;
						maxDis = max(maxDis, dis[checkI][checkJ]);
					}
				}
			}

			// 거리 초기화
			for (int k = 0; k < n; k++)
			{
				for (int l = 0; l < m; l++)
				{
					dis[k][l] = 0;
				}
			}
		}
	}

	// 거리1로 시작했으니 1 빼줌
	cout << maxDis - 1 << '\n';

	return 0;
}