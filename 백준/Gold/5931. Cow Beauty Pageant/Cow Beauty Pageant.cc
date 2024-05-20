#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// Cow Beauty Pageant
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 6, 16
	cin >> n >> m;

	vector<vector<int> > graph(n, vector<int>(m)); // 그래프
	vector<vector<int> > dis(n, vector<int>(m)); // 거리
	vector<vector<pair<int, int> > > labelPos; // 각 반점 내부좌표 저장
	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	// 그래프 초기화
	// . => 0 X => 1로 치환
	string inputString;
	for (int i = 0; i < n; i++)
	{
		cin >> inputString;
		for (int j = 0; j < m; j++)
		{
			if (inputString[j] == '.') graph[i][j] = 0;
			else if (inputString[j] == 'X') graph[i][j] = 1;
		}
	}

	// 1.그래프 돌면서 각 반점 라벨링  : 첫번째 반점은 2 두번째 반점은 3
	// 2.그래프 돌면서 각 반점 내부 1 좌표를 큐에 넣고
	// 각 반점 라벨보다 큰 라벨을 갖는 다른 반점을 연결하는 최단거리 갱신

	// 1.그래프 돌면서 각 반점 라벨링  : 첫번째 반점은 2 두번째 반점은 3

	int curLabel = 1; // 현재 라벨

	for (int i = 0; i < n; i++) // 그래프 돌면서
	{
		for (int j = 0; j < m; j++)
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
						if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m) continue;

						// 방문체크(라벨로)
						if (graph[checkI][checkJ] == curLabel) continue;

						// 벽체크
						if (graph[checkI][checkJ] == 0) continue;

						// 큐에저장 라벨링 내부좌표백업
						checkPos.push({ checkI, checkJ });
						graph[checkI][checkJ] = curLabel;
						curLabelPos.push_back({ checkI, checkJ });
					}
				}

				// 현재 반점의 내부좌표 저장
				labelPos.push_back(curLabelPos);
			}
		}
	}

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

	// 2.그래프 돌면서 각 반점 내부 1 좌표를 큐에 넣고
	// 각 반점 라벨보다 큰 라벨을 갖는 다른 반점을 연결하는 최단거리 갱신

	curLabel = 2; // 첫 반점 부터
	int minDis = 2147000000; // 두 반점을 잇는 최단거리

	for (int i = 0; i < n; i++) // 그래프 돌면서
	{
		for (int j = 0; j < m; j++)
		{
			if (graph[i][j] == curLabel) // 각 반점을 만나면
			{
				// 일단 거리 및 큐 초기화
				for (int k = 0; k < n; k++)
				{
					for (int l = 0; l < m; l++)
					{
						dis[k][l] = 0;
					}
				}
				while (!checkPos.empty()) checkPos.pop();

				// 각 반점의 내부좌표부터 BFS 돌리다가
				// 자기보다 라벨이 큰 반점을 만나면 최단거리 갱신

				// 각 반점의 내부좌표 큐에 저장하고 거리 1
				for (int k = 0; k < labelPos[curLabel - 2].size(); k++)
				{
					checkPos.push({ labelPos[curLabel - 2][k] });
					dis[labelPos[curLabel - 2][k].first][labelPos[curLabel - 2][k].second] = 1;
				}

				// 각 반점의 내부좌표부터 BFS
				while (!checkPos.empty()) // 큐가 빌때까지
				{
					// 기준위치 꺼냄
					pair<int, int> standardPos = checkPos.front();
					checkPos.pop();

					bool isDot = false; // 다른 반점을 찾았는지 체크

					// 상하좌우
					for (int k = 0; k < 4; k++)
					{
						// 체크 할 위치
						int checkI = standardPos.first + checkDir[k].first;
						int checkJ = standardPos.second + checkDir[k].second;

						// 경계체크
						if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m) continue;

						// 자기보다 큰 라벨을 만나면 최단거리 갱신
						if (graph[checkI][checkJ] > curLabel)
						{
							isDot = true;
							minDis = min(minDis, dis[standardPos.first][standardPos.second]);

							break;
						}

						// 같은라벨체크
						if (graph[checkI][checkJ] == curLabel) continue;

						// 방문체크(거리로)
						if (dis[checkI][checkJ] > 0) continue;

						// 큐에저장 거리저장
						checkPos.push({ checkI, checkJ });
						dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;
					}

					// 다른 반점을 찾았으면 break
					if (isDot) break;
				}

				// 다음 반점도 다음 반점 보다 큰 라벨을 반점 체크하기 위해
				curLabel++;
			}
		}
	}

	// 1로 시작했으니 1 빼줌
	cout << minDis - 1 << '\n';

	return 0;
}