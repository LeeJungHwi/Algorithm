#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 영역구하기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int m, n, k; // M, N, K 5, 7, 3
	cin >> m >> n >> k;

	vector<vector<int> > graph(m, vector<int>(n)); // 그래프

	int leftX, leftY; // 왼쪽 좌표
	int rightX, rightY; // 오른쪽 좌표

	//	input :
	/*
	0 2 4 4 -> (2,0) (4,4) -> (2,0)~(3,3)
	1 1 2 5 -> (1,1) (5,2) -> (1,1)~(4,1)
	4 0 6 2 -> (0,4) (2,6) -> (0,4)~(1,5)
	*/
	//	graph :
	/*
	0 0 0 0 1 1 0 
	0 1 0 0 1 1 0 
	1 1 1 1 0 0 0 
	1 1 1 1 0 0 0 
	0 1 0 0 0 0 0 
	*/
	for (int i = 0; i < k; i++)
	{
		// 왼쪽 아래 좌표
		cin >> leftX >> leftY; // 4 0

		// 오른쪽 위 좌표
		cin >> rightX >> rightY; // 6 2

		// 직사각형 그리기
		for (int j = leftY; j < rightY; j++)
		{
			for (int l = leftX; l < rightX; l++)
			{
				graph[j][l] = 1;
			}
		}
	}

	// BFS
	// 그래프를 돌면서 0을 만나면 방문체크, 넓이 1, 큐에 저장, 큐가 빌때까지 BFS 돌리기
	// 방문체크, 경계체크, 1 체크, 0 만나면 넓이++, 방문체크, 큐에 저장
	// BFS 끝나면 영역 넓이 벡터에 저장, 영역개수++
	// 모두 끝나면 영역개수 출력, 영역넓이 벡터 오름차순 정렬 후 출력

	vector<vector<bool> > vis(m, vector<bool>(n)); // 방문체크
	queue<pair<int, int> > checkPos; // 체크할 영역
	vector<pair<int, int> > checkDir; // 상 하 좌 우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });
	vector<int> areas; // 영역 넓이 벡터
	int area = 0; // 영역 넓이
	int areaCnt = 0; // 영역 개수

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] == 0)
			{
				// 방문체크
				if (vis[i][j])
				{
					continue;
				}

				vis[i][j] = true;

				// 넓이 1
				area = 1;

				// 큐에 저장
				checkPos.push({ i, j });

				// BFS
				while (!checkPos.empty()) // 큐가 빌때까지
				{
					// 체크할 기준위치 꺼냄
					pair<int, int> curPos = checkPos.front();
					checkPos.pop();

					// 상 하 좌 우 체크
					for (int l = 0; l < 4; l++)
					{
						// 꺼낸 위치 기준 상하좌우 체크
						int checkI = curPos.first + checkDir[l].first;
						int checkJ = curPos.second + checkDir[l].second;

						// 경계체크
						if (checkI < 0 || checkJ < 0 || checkI >= m || checkJ >= n)
						{
							continue;
						}

						// 방문체크
						if (vis[checkI][checkJ])
						{
							continue;
						}

						// 1 체크
						if (graph[checkI][checkJ] == 1)
						{
							continue;
						}

						// 0을 만나면 넓이 증가, 방문체크, 큐에 저장
						area++;
						vis[checkI][checkJ] = true;
						checkPos.push({ checkI, checkJ });
					}
				}

				// BFS 끝나면 영역넓이 벡터에 저장, 영역개수 증가
				areas.push_back(area);
				areaCnt++;
			}
		}
	}

	// 모두 끝나면 영역개수 출력, 영역넓이 벡터 오름차순 후 출력
	cout << areaCnt << '\n';

	sort(areas.begin(), areas.end());

	for (int i = 0; i < areas.size(); i++)
	{
		cout << areas[i] << ' ';
	}

	return 0;
}