#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 큰 호수
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m, k; // N, M, K 3, 4, 5
	cin >> n >> m >> k;

	vector<vector<int> > graph(n + 1, vector<int>(m + 1)); // 그래프
	vector<vector<bool> > vis(n + 1, vector<bool>(m + 1)); // 방문체크

	queue<pair<int, int> > checkPos; // 체크할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	/*
	input : 3 2
			2 2
			3 1
			2 3
			1 1

	graph : 1 0 0 0
			0 1 1 0
			1 1 0 0
	*/

	int col, row; // 침수된 격자 좌표

	for (int i = 0; i < k; i++)
	{
		cin >> col >> row;

		graph[col][row] = 1;
	}

	// BFS
	// 1을 만나면 큐에 저장, 방문체크, 호수크기 1
	// 경계체크, 방문체크, 0체크, 1을 만나면 호수크기 증가, 큐에 저장, 방문체크

	int maxSize = 0; // 가장 큰 호수 크기

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			if (graph[i][j] == 1)
			{
				// 1을 만나면 큐에 저장 후 방문체크
				checkPos.push({ i, j });
				vis[i][j] = true;

				// 호수 크기 1
				int size = 1;

				while (!checkPos.empty()) // 큐가 빌때까지
				{
					// 기준위치 꺼냄
					pair<int, int> standardPos = checkPos.front();
					checkPos.pop();

					// 상하좌우 체크
					for (int l = 0; l < 4; l++)
					{
						// 체크할 위치
						int checkI = standardPos.first + checkDir[l].first;
						int checkJ = standardPos.second + checkDir[l].second;

						// 경계체크
						if (checkI < 1 || checkJ < 1 || checkI >= n + 1 || checkJ >= m + 1)
						{
							continue;
						}

						// 방문체크
						if (vis[checkI][checkJ])
						{
							continue;
						}

						// 0 체크
						if (graph[checkI][checkJ] == 0)
						{
							continue;
						}

						// 1을 만나면 호수크기 증가, 큐에 저장 후 방문체크
						size++;
						checkPos.push({ checkI, checkJ });
						vis[checkI][checkJ] = true;
					}
				}

				// 가장 큰 호수 크기 갱신
				if (maxSize < size)
				{
					maxSize = size;
				}
			}
		}
	}

	cout << maxSize;

	return 0;
}