#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 그림
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// BFS로 그림개수, 가장큰그림 크기 구하기

	int n, m; // N, M 6, 5
	cin >> n >> m;

	vector<vector<int> > graph(n, vector<int>(m)); // 그래프
	vector<vector<bool> > vis(n, vector<bool>(m)); // 방문체크
	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	//	1 1 0 1 1
	//	0 1 1 0 0
	//	0 0 0 0 0
	//	1 0 1 1 1
	//	0 0 1 1 1
	//	0 0 1 1 1
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];
		}
	}

	// 그래프 돌면서

	int areaCnt = 0; // 그림 개수
	int maxAreaSize = 0; // 그림 최대크기

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// 아직 방문하지않은 1을 만나면
			if (graph[i][j] == 1 && !vis[i][j])
			{
				// 시작위치부터 BFS 돌림
				checkPos.push({ i, j });
				vis[i][j] = true;
				int areaSize = 1;
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

						// 방문체크
						if (vis[checkI][checkJ])
						{
							continue;
						}

						// 벽체크
						if (graph[checkI][checkJ] == 0)
						{
							continue;
						}

						// 큐에저장, 방문체크, 영역크기증가
						checkPos.push({ checkI, checkJ });
						vis[checkI][checkJ] = true;
						areaSize++;
					}
				}

				// 그림 최대크기 갱신
				maxAreaSize = max(maxAreaSize, areaSize);
			}
		}
	}

	cout << areaCnt << '\n';
	cout << maxAreaSize << '\n';

	return 0;
}