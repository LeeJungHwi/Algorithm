#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 안전 영역
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// n이 주어지면 n by n 그래프에 높이 저장
	// 내리는 비의 양보다 높이가 작거나같으면 물에 잠기게 됨
	// 잠기지 않는 영역의 최대 개수 구하기

	int n; // N 5
	cin >> n;

	vector<vector<int> > graph(n, vector<int>(n)); // 그래프
	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	int minHeight = 2147000000; // 높이 최소값
	int maxHeight = 0; // 높이 최대값

	//	6 8 2 6 2
	//	3 2 3 4 6
	//	6 7 3 3 2
	//	7 2 5 3 6
	//	8 9 5 2 7
	// 높이 최소값, 높이 최대값 구하기
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];

			minHeight = min(minHeight, graph[i][j]);
			maxHeight = max(maxHeight, graph[i][j]);
		}
	}

	// 비의 양 : 높이 최소값 ~ 높이 최대값 - 1
	// 비의 양에 따라 그래프 돌면서 BFS 돌리기
	// 비의 양보다 큰 높이를 만나면 큐에 저장 후 방문체크
	// 큐가 빌때까지
	// 경계체크, 방문체크, 비의 양보다 작거나 같은 높이 체크, 비의 양보다 큰 높이를 만나면 큐에 저장 후 방문체크
	// 한스텝 끝나면 영역 개수 증가
	// BFS 모두 끝나면 최대 영역 개수 갱신

	int maxAreaCnt = 1; // 최대 영역 개수 : 아무 지역도 물에 잠기지 않으면 영역 개수는 1개이므로 1부터 시작
	int areaCnt = 0; // 영역 개수
	
	for (int i = minHeight; i < maxHeight; i++) // 비의 양에 따라
	{
		vector<vector<bool> > vis(n, vector<bool>(n)); // 방문체크
		areaCnt = 0;

		// 그래프 돌면서
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (graph[j][k] > i) // 비의 양 보다 큰 높이를 만나면
				{
					// 방문체크
					if (vis[j][k])
					{
						continue;
					}

					checkPos.push({ j, k }); // 큐에 저장
					vis[j][k] = true; // 방문체크

					while (!checkPos.empty()) // 큐가 빌때까지
					{
						// 기준위치 꺼냄
						pair<int, int> standardPos = checkPos.front();
						checkPos.pop();

						// 상하좌우
						for (int l = 0; l < 4; l++)
						{
							// 체크 할 위치
							int checkI = standardPos.first + checkDir[l].first;
							int checkJ = standardPos.second + checkDir[l].second;

							// 경계체크
							if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= n)
							{
								continue;
							}

							// 방문체크
							if (vis[checkI][checkJ])
							{
								continue;
							}

							// 비의 양보다 작거나 같은 높이 체크
							if (graph[checkI][checkJ] <= i)
							{
								continue;
							}

							// 비의 양보다 큰 높이를 만나면 큐에 저장 후 방문체크
							checkPos.push({ checkI, checkJ });
							vis[checkI][checkJ] = true;
						}
					}

					// 한스텝 끝나면 영역 개수 증가
					areaCnt++;
				}
			}
		}

		// BFS 모두 끝나면 최대 영역 개수 갱신
		maxAreaCnt = max(maxAreaCnt, areaCnt);
	}

	cout << maxAreaCnt << '\n';

	return 0;
}