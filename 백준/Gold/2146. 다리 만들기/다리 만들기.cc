#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 다리 만들기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 10
	cin >> n;

	vector<vector<int> > graph(n, vector<int>(n)); // 그래프
	vector<vector<int> > dis(n, vector<int>(n)); // 거리
	vector<vector<pair<int, int> > > labelPos; // 각 섬의 내부좌표 저장
	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	//	1 1 1 0 0 0 0 1 1 1
	//	1 1 1 1 0 0 0 0 1 1
	//	1 0 1 1 0 0 0 0 1 1
	//	0 0 1 1 1 0 0 0 0 1
	//	0 0 0 1 0 0 0 0 0 1
	//	0 0 0 0 0 0 0 0 0 1
	//	0 0 0 0 0 0 0 0 0 0
	//	0 0 0 0 1 1 0 0 0 0
	//	0 0 0 0 1 1 1 0 0 0
	//	0 0 0 0 0 0 0 0 0 0
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
		}
	}

	// 1.그래프 돌면서 각 섬에 라벨링  : 첫번째 섬은 2 두번째 섬은 3 ....
	// 2.그래프 돌면서 각 섬 내부 1 좌표를 큐에 넣고
	// 각 섬 라벨보다 큰 라벨을 갖는 다른섬을 연결하는 최단거리 갱신
	// 첫섬은 3, 4 최단거리 갱신, 둘섬은 4 최단거리 갱신

	// 1.그래프 돌면서 각 섬에 라벨링  : 첫번째 섬은 1 두번째 섬은 2 ....

	int curLabel = 1; // 현재 라벨

	for (int i = 0; i < n; i++) // 그래프 돌면서
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] == 1) // 아직 라벨링 되지않은곳을 만나면
			{
				// 이 위치부터 BFS
				checkPos.push({ i, j });
				curLabel++;
				graph[i][j] = curLabel;
				vector<pair<int, int> > curLabelPos;
				curLabelPos.push_back({ i, j });

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
						if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= n)
						{
							continue;
						}
						
						// 방문체크(라벨로)
						if (graph[checkI][checkJ] == curLabel)
						{
							continue;
						}

						// 바다체크
						if (graph[checkI][checkJ] == 0)
						{
							continue;
						}

						// 큐에저장 라벨링 내부좌표백업
						checkPos.push({ checkI, checkJ });
						graph[checkI][checkJ] = curLabel;
						curLabelPos.push_back({ checkI, checkJ });
					}
				}

				// 현재 섬의 내부좌표 저장
				labelPos.push_back(curLabelPos);
			}
		}
	}

	// 디버깅용
	//for (auto a : graph)
	//{
	//	for (auto b : a)
	//	{
	//		cout << b << ' ';
	//	}
	//	cout << '\n';
	//}

	//for (auto a : labelPos)
	//{
	//	for (auto b : a)
	//	{
	//		cout << b.first << ' ' << b.second << '\n';
	//	}
	//	cout << '\n';
	//}

	// 2.그래프 돌면서 각 섬 내부 좌표를 큐에 넣고
	// 각 섬보다 큰 라벨을 갖는 다른섬을 연결하는 최단거리 갱신 : 첫섬은 3, 4 최단거리 갱신, 둘섬은 4 최단거리 갱신

	curLabel = 2; // 첫섬이 라벨2부터 시작
	int minDis = 2147000000; // 두 섬을 잇는 최단거리

	for (int i = 0; i < n; i++) // 그래프 돌면서
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] == curLabel) // 각 섬을 만나면
			{
				// 일단 거리 및 큐 초기화
				for (int k = 0; k < n; k++)
				{
					for (int l = 0; l < n; l++)
					{
						dis[k][l] = 0;
					}
				}

				while (!checkPos.empty())
				{
					checkPos.pop();
				}

				// 각 섬의 내부좌표부터 BFS 돌리다가
				// 자기보다 라벨이 큰 섬을 만나면 최단거리 갱신

				// 각 섬의 내부좌표 큐에 저장하고 거리 1
				for (int k = 0; k < labelPos[curLabel - 2].size(); k++)
				{
					checkPos.push({ labelPos[curLabel - 2][k] });
					dis[labelPos[curLabel - 2][k].first][labelPos[curLabel - 2][k].second] = 1;
				}

				// 각 섬의 내부좌표부터 BFS
				while (!checkPos.empty()) // 큐가 빌대까지
				{
					// 기준위치 꺼냄
					pair<int, int> standardPos = checkPos.front();
					checkPos.pop();

					bool isBridge = false; // 각 섬에서 다른 섬까지 최단거리 다리를 찾았는지 체크

					// 상하좌우
					for (int k = 0; k < 4; k++)
					{
						// 체크 할 위치
						int checkI = standardPos.first + checkDir[k].first;
						int checkJ = standardPos.second + checkDir[k].second;

						// 경계체크
						if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= n)
						{
							continue;
						}

						// 자기보다 큰 라벨을 만나면 최단거리 갱신
						if (graph[checkI][checkJ] > curLabel)
						{
							isBridge = true;
							minDis = min(minDis, dis[standardPos.first][standardPos.second]);

							break;
						}

						// 같은라벨체크
						if (graph[checkI][checkJ] == curLabel)
						{
							continue;
						}

						// 방문체크(거리로)
						if (dis[checkI][checkJ] > 0)
						{
							continue;
						}

						// 큐에저장 거리저장
						checkPos.push({ checkI, checkJ });
						dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;
					}

					if (isBridge)
					{
						break;
					}
				}

				// 다음 섬도 다음섬보다 큰 라벨을 갖는 섬 체크하기위해
				curLabel++;
			}
		}
	}

	// 1로 시작했으니 1 빼줌
	cout << minDis - 1 << '\n';

	return 0;
}