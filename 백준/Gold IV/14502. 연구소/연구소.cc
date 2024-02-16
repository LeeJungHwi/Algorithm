#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <fstream>
using namespace std;

vector<pair<int, int> > blankPos; // 전체 빈칸위치 저장
vector<pair<int, int> > idxWall; // 벽을 세울 빈칸위치 저장
vector<bool> blankVis(64); // 빈칸 3개 선택 방문체크

// DFS
void DFS(int L, int cnt)
{
	if (L == blankPos.size() || cnt == 3) // 종료조건 : 벽 위치 수를 넘긴경우나 3개의 위치를 선택했을때
	{
		if (L == blankPos.size()) // 벽 위치 수를 넘긴경우
		{
			if (cnt != 3) // 3개를 선택한게 아니면 리턴
			{
				return;
			}
		}

		// 벽을 세울 빈칸 위치 큐에 저장
		for (int i = 0; i < blankPos.size(); i++)
		{
			if (blankVis[i])
			{
				idxWall.push_back(blankPos[i]);
			}
		}
	}
	else
	{
		blankVis[L] = true; // 빈칸 선택
		DFS(L + 1, cnt += 1);
		blankVis[L] = false; // 빈칸 미 선택
		DFS(L + 1, cnt -= 1);
	}
}

// 연구소
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 7, 7
	cin >> n >> m;

	vector<vector<int> > graph(n, vector<int>(m)); // 그래프
	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });
	vector<pair<int, int> > virusPos; // 전체 바이러스위치 저장
	int wallCnt = 0; // 초기 벽의 개수
	int maxBlankCnt = 0; // 최대 빈칸 개수

	// 1. 벽을 세울 빈칸 3개 DFS로 선택하기
	// 2. 선택한 빈칸 3개에 벽 세우기
	// 3. 바이러스 BFS 돌리기
	// 4. 빈칸 개수 세기
	// 5. 최대 빈칸 개수 갱신
	// 6. 세운 벽 위치 다시 빈칸으로 돌리기

	//	2 0 0 0 1 1 0
	//	0 0 1 0 1 2 0
	//	0 1 1 0 1 0 0
	//	0 1 0 0 0 0 0
	//	0 0 0 0 0 1 1
	//	0 1 0 0 0 0 0
	//	0 1 0 0 0 0 0
	// 빈칸위치, 초기 벽 개수, 바이러스위치 저장
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];

			if (graph[i][j] == 0)
			{
				blankPos.push_back({ i, j });
			}
			else if (graph[i][j] == 1)
			{
				wallCnt++;
			}
			else if (graph[i][j] == 2)
			{
				virusPos.push_back({ i, j });
			}
		}
	}

	// 1. 벽을 세울 빈칸 3개 DFS로 선택하기
	DFS(0, 0);

	// 2. 큐에서 3개씩 꺼내서 벽세우기
	for (int i = 0; i < idxWall.size(); i += 3)
	{
		// 끝나고 다시 빈칸으로 돌려야함
		for (int j = i; j < i + 3; j++)
		{
			graph[idxWall[j].first][idxWall[j].second] = 1;
		}

		// 3. 바이러스 BFS 돌리기
		vector<vector<bool> > vis(n, vector<bool>(m)); // 방문체크
		int visCnt = 0; // 방문체크된 개수

		// 새로운 3개의 벽이 세워질때마다 큐에 바이러스 위치 저장하고 방문체크
		for (int j = 0; j < virusPos.size(); j++)
		{
			checkPos.push(virusPos[j]);
			vis[virusPos[j].first][virusPos[j].second] = true;
			visCnt++;
		}

		// BFS
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
				if (graph[checkI][checkJ] == 1)
				{
					continue;
				}

				// 빈칸을 만나면 큐에 저장 후 방문체크
				checkPos.push({ checkI, checkJ });
				vis[checkI][checkJ] = true;
				visCnt++;
			}
		}

		// 4. 빈칸 개수 세기
		// blankCnt = 격자크기 - 초기벽개수 - 세운벽개수 - 방문체크된 개수
		int blankCnt = n * m - wallCnt - 3 - visCnt;

		// 5. 최대 빈칸 개수 갱신
		maxBlankCnt = max(maxBlankCnt, blankCnt);

		// 끝나고 다시 빈칸으로 돌려야함
		for (int j = i; j < i + 3; j++)
		{
			graph[idxWall[j].first][idxWall[j].second] = 0;
		}
	}

	cout << maxBlankCnt << '\n';

	return 0;
}