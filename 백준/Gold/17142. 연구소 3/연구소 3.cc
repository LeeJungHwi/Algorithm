#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <fstream>
using namespace std;

int n, m; // N, M 7, 3
vector<pair<int, int> > virusPos; // 전체 바이러스위치 저장
vector<pair<int, int> > activeVirus; // 활성화 바이러스 저장
vector<pair<int, int> > deActiveVirus; // 비활성화 바이러스 저장
vector<bool> virusVis(2500); // 바이러스 놓는 위치 m개 선택 방문체크

// DFS
void DFS(int L, int cnt)
{
	if (L == virusPos.size() || cnt == m) // 종료조건 : 바이러스 위치 수를 넘긴경우나 m개의 활성화 바이러스를 선택한경우
	{
		if (L == virusPos.size()) // 바이러스 위치 수를 넘긴경우
		{
			if (cnt != m) // m개의 활성화 바이러스를 선택한게 아니면 리턴
			{
				return;
			}
		}

		// 활성화 바이러스와 비활성화 바이러스 저장
		for (int i = 0; i < virusPos.size(); i++)
		{
			if (virusVis[i])
			{
				activeVirus.push_back(virusPos[i]); // 활성화 바이러스

				continue;
			}

			deActiveVirus.push_back(virusPos[i]); // 비활성화 바이러스
		}
	}
	else
	{
		virusVis[L] = true; // 활성화 바이러스 선택
		DFS(L + 1, cnt += 1);
		virusVis[L] = false; // 활성화 바이러스 미 선택
		DFS(L + 1, cnt -= 1);
	}
}

// 연구소3
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n >> m;

	vector<vector<int> > graph(n, vector<int>(n)); // 그래프
	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	// 입력받을때 바이러스를 놓을수있는 위치는 따로 저장해놓고 일단 빈칸으로 둠
	// 1. 활성화 바이러스 m개를 DFS로 선택하기
	// 2. 선택한 m칸에 바이러스를 큐에 저장 후 거리 1로
	// 3. 바이러스 BFS 돌리면서 거리할당하기
	// 4. 바이러스가 빈칸에 모두 퍼지는 시간 = 거리 최대값, 비활성화 바이러스가 아닌 경우만 갱신
	// 5. 바이러스가 빈칸에 모두 퍼졌을때만 최단시간 갱신 = 거리 최대값 중 최소값, 비활성화 바이러스가 아닌 경우만 갱신

	//	2 0 0 0 1 1 0
	//	0 0 1 0 1 2 0
	//	0 1 1 0 1 0 0
	//	0 1 0 0 0 0 0
	//	0 0 0 2 0 1 1
	//	0 1 0 0 0 0 0
	//	2 1 0 0 0 0 2
	// 바이러스 놓을 수 있는 위치는 따로 저장하고 일단 빈칸으로 둠
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];

			if (graph[i][j] == 2)
			{
				graph[i][j] = 0; // 일단 빈칸으로
				virusPos.push_back({ i, j }); // 바이러스 위치 저장
			}
		}
	}

	// 비활성화 바이러스 계수
	/*
	1. m = 3 일때
	0 ~ 3 -> (i = 0) coef * (virusPos.size - m) ~ coef * (virusPos.size - m) + virusPos.size - m
	4 ~ 7 -> (i = 3) coef * (virusPos.size - m) ~ coef * (virusPos.size - m) + virusPos.size - m
	8 ~ 11 -> (i = 6) coef * (virusPos.size - m) ~ coef * (virusPos.size - m) + virusPos.size - m
	....
	2. m = 5 일때
	0 ~ 1 -> (i = 0) coef * (virusPos.size - m) ~ coef * (virusPos.size - m) + virusPos.size - m
	2 ~ 3 -> (i = 5) coef * (virusPos.size - m) ~ coef * (virusPos.size - m) + virusPos.size - m
	4 ~ 5 -> (i = 10) coef * (virusPos.size - m) ~ coef * (virusPos.size - m) + virusPos.size - m
	....
	*/
	int coef = 0;

	// 1. 바이러스를 놓을수있는 칸 중 m개를 DFS로 선택하기
	DFS(0, 0);

	int minMaxDis = 2147000000; // 바이러스가 모두 퍼지는 시간 중 최소값

	// 2. 선택한 m칸에 바이러스를 큐에 저장 후 거리 1로
	for (int i = 0; i < activeVirus.size(); i += m)
	{
		vector<vector<int> > dis(n, vector<int>(n)); // 거리
		int maxDis = 1; // 바이러스가 모두 퍼지는 시간 : 바이러스를 놓자마자 퍼지는 경우 1

		for (int j = i; j < i + m; j++)
		{
			checkPos.push(activeVirus[j]);
			dis[activeVirus[j].first][activeVirus[j].second] = 1;
		}

		// 3. 바이러스 BFS 돌리면서 거리할당하기
		while (!checkPos.empty()) // 큐가 빌때까지
		{
			// 기준위치 꺼냄
			pair<int, int> standardPos = checkPos.front();
			checkPos.pop();

			// 상하좌우
			for (int j = 0; j < 4; j++)
			{
				// 체크 할 위치
				int checkI = standardPos.first + checkDir[j].first;
				int checkJ = standardPos.second + checkDir[j].second;

				// 경계체크
				if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= n)
				{
					continue;
				}

				// 벽체크
				if (graph[checkI][checkJ] == 1)
				{
					continue;
				}

				// 거리가 할당되지 않았다면 큐에 저장 후 거리 할당
				if (dis[checkI][checkJ] == 0)
				{
					checkPos.push({ checkI, checkJ });
					dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;

					// 4. 바이러스가 빈칸에 모두 퍼지는 시간 = 거리 최대값

					// 비활성화 바이러스인지 체크
					bool isVirus = false;

					for (int k = coef * (virusPos.size() - m); k < coef * (virusPos.size() - m) + virusPos.size() - m; k++)
					{
						if (checkI == deActiveVirus[k].first && checkJ == deActiveVirus[k].second)
						{
							isVirus = true;
							break;
						}

						if (isVirus)
						{
							break;
						}
					}

					// 비활성화 바이러스가 아닌 경우만 거리 최대값 갱신
					if (!isVirus)
					{
						maxDis = max(maxDis, dis[checkI][checkJ]);
					}
				}
				else // 거리가 할당되어있다면 거리가 더 작을때만 큐에 저장 후 거리 할당
				{
					if (dis[checkI][checkJ] > dis[standardPos.first][standardPos.second] + 1)
					{
						checkPos.push({ checkI, checkJ });
						dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;

						// 4. 바이러스가 빈칸에 모두 퍼지는 시간 = 거리 최대값

						// 비활성화 바이러스인지 체크
						bool isVirus = false;

						for (int k = coef * (virusPos.size() - m); k < coef * (virusPos.size() - m) + virusPos.size() - m; k++)
						{
							if (checkI == deActiveVirus[k].first && checkJ == deActiveVirus[k].second)
							{
								isVirus = true;
								break;
							}

							if (isVirus)
							{
								break;
							}
						}

						// 비활성화 바이러스가 아닌 경우만 거리 최대값 갱신
						if (!isVirus)
						{
							maxDis = max(maxDis, dis[checkI][checkJ]); 
						}
					}
				}
			}
		}

		// 5. 바이러스가 빈칸에 모두 퍼졌을때만 최단시간 갱신 = 거리 최대값 중 최소값
		// 비활성화 바이러스가 아닌 경우만 최단시간 갱신

		bool isAll = true;

		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (graph[j][k] != 1) // 벽이 아니면서
				{
					// 비활성화 바이러스인지 체크
					bool isVirus = false;

					for (int l = coef * (virusPos.size() - m); l < coef * (virusPos.size() - m) + virusPos.size() - m; l++)
					{
						if (j == deActiveVirus[l].first && k == deActiveVirus[l].second)
						{
							isVirus = true;
							break;
						}

						if (isVirus)
						{
							break;
						}
					}

					if (!isVirus) // 비활성화 바이러스가 아닌경우
					{
						if (dis[j][k] == 0) // 거리가 하나라도 할당되지 않았으면 모두 퍼지지 못함
						{
							isAll = false;
							break;
						}
					}
				}

				if (!isAll)
				{
					break;
				}
			}

			if (!isAll)
			{
				break;
			}
		}

		if (isAll) // 바이러스가 모두 퍼진 경우만 최단시간 갱신
		{
			minMaxDis = min(minMaxDis, maxDis);
		}

		// 비활성화 바이러스 계수 증가
		coef++;
	}

	// 최단시간이 갱신되지않았다면 어떻게 바이러스를 놓아도 퍼지지 않으므로 -1 출력
	if (minMaxDis == 2147000000)
	{
		cout << -1 << '\n';

		return 0;
	}

	// 거리 1로 시작했으므로 1 빼줌
	cout << minMaxDis - 1 << '\n';

	return 0;
}