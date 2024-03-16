#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
#include <tuple>
using namespace std;

int n, m, g, r; // N, M, G, R 3, 3, 2, 1
vector<vector<int>> graph(50, vector<int>(50)); // 그래프
vector<pair<int, int>> soilPos; // 황토색 땅 위치 (0, 0) (2, 0) (2, 2)
vector<pair<pair<int, int>, int> > selected; // (황토색 땅 위치, 뿌려잰 배양액의 색)
int maxFlowerCnt; // 피울수있는 꽃의 최대 개수

vector<pair<int, int> > checkDir = { {-1,0}, {1, 0}, {0, -1}, {0, 1} }; // 상하좌우
queue<pair<int, int> > checkPos; // 체크 할 위치

// BFS
// 각 경우의 수에 대해 배양액이 퍼져나가면서 피울수있는 꽃의 최대개수 갱신하기
void BFS()
{
	int flowerCnt = 0; // 각 경우의 수에 대한 꽃이 피는 수
	vector<vector<int>> dis(n, vector<int>(m)); // 거리체크
	vector<vector<int>> vis(n, vector<int>(m)); // 방문체크
	vector<pair<int, int> > flowerPos; // 꽃이 핀 위치 저장

	// 모든 배양액부터 BFS
	for (int i = 0; i < selected.size(); i++)
	{
		checkPos.push(selected[i].first);
		dis[selected[i].first.first][selected[i].first.second] = 1;
		vis[selected[i].first.first][selected[i].first.second] = selected[i].second;
	}

	// 큐가 빌때까지
	while (!checkPos.empty())
	{
		// 기준위치 꺼냄
		pair<int, int> standardPos = checkPos.front();
		checkPos.pop();

		// 꽃이 핀 위치는 퍼질수 없으므로 continue
		bool cantSpread = false;

		for (int i = 0; i < flowerPos.size(); i++)
		{
			if (standardPos.first == flowerPos[i].first && standardPos.second == flowerPos[i].second)
			{
				cantSpread = true;

				break;
			}
		}

		if (cantSpread)
		{
			continue;
		}

		// 상하좌우
		for (int i = 0; i < 4; i++)
		{
			// 체크 할 위치
			int checkI = standardPos.first + checkDir[i].first;
			int checkJ = standardPos.second + checkDir[i].second;

			// 경계체크
			if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m)
			{
				continue;
			}

			// 호수체크
			if (graph[checkI][checkJ] == 0)
			{
				continue;
			}

			// 아직 어떤 배양액도 없는 땅이면 배양액 저장, 거리 증가, 큐에 추가
			if (vis[checkI][checkJ] == 0)
			{
				vis[checkI][checkJ] = vis[standardPos.first][standardPos.second];
				dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;
				checkPos.push({ checkI, checkJ });
			} 
			else // 이미 배양액이 있는 땅이면
			{
				// 서로 다른 배양색이면서
				if (vis[checkI][checkJ] != vis[standardPos.first][standardPos.second])
				{
					// 동일한 시간에 도달하고 아직 꽃을 피운상태가 아니면 꽃을 피움
					if (dis[checkI][checkJ] == dis[standardPos.first][standardPos.second] + 1 && vis[checkI][checkJ] != 3)
					{
						flowerCnt++; // 핀 꽃 수 카운팅
						vis[checkI][checkJ] = 3; // 꽃을 피운 상태
						flowerPos.push_back({ checkI, checkJ }); // 꽃이 핀 위치 저장
					}
				}
			}
		}
	}

	// 디버깅용
	//for (auto a : vis)
	//{
	//	for (auto b : a)
	//	{
	//		cout << b << ' ';
	//	}
	//	cout << '\n';
	//}
	//cout << '\n';

	maxFlowerCnt = max(maxFlowerCnt, flowerCnt);
}

// DFS
// 황토색 땅에 배양액을 놓는 경우의 수 구하기
void DFS(int L, int cntG, int cntR)
{
	if (L == soilPos.size() || cntG == g && cntR == r) // 종료조건 : 황토색 땅 위치 수를 넘겼거나 모든 배양액을 뿌린경우
	{
		// 황토색 땅 위치수를 넘긴경우
		if (L == soilPos.size())
		{
			// 모든 배양액을 뿌린경우가 아니면 리턴
			if (cntG != g || cntR != r)
			{
				return;
			}
		}

		// 디버깅용
		//for (int i = 0; i < selected.size(); i++)
		//{
		//	cout << "(" << selected[i].first.first << "," << selected[i].first.second << ")" << selected[i].second;
		//}
		//cout << '\n';

		// 모든 배양액을 뿌렸으면
		// BFS 돌려서 꽃을 피울수있는 최대개수 갱신
		BFS();

		return;
	}

	// 초록색 배양액 처리
	if (cntG < g)
	{
		selected.push_back({ soilPos[L], 1 });
		DFS(L + 1, cntG + 1, cntR);
		selected.pop_back();
	}

	// 빨간색 배양액 처리
	if (cntR < r)
	{
		selected.push_back({ soilPos[L], 2 });
		DFS(L + 1, cntG, cntR + 1);
		selected.pop_back();
	}

	// 해당 황토색 땅 건너뜀
	DFS(L + 1, cntG, cntR);
}

// Gaaaaaaaaaarden
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 하얀색 1 : 배양액 뿌릴수없음
	// 황토색 2 : 배양액 뿌릴수있음
	// 하늘색 0 : 호수

	// 초록색 배양액과 빨간색 배양액이 동일한 시간에 땅에 도달시 두 배양액이 합쳐져 꽃이 핀다
	// 꽃이 핀 땅에서는 배양액이 사라지고 더이상 인접한 땅으로 배양액이 퍼지지않는다
	// 주어진 배양액은 서로 다른곳에 모두 뿌려져야한다

	// 정원과 두 배양액의 개수가 주어지면 피울수있는 꽃의 최대 개수 구하기

	// 1. DFS로 g와 r을 놓을수있는 경우의 수 구하기(황토색 땅의 서로다른곳에 뿌림)
	// 2. BFS로 각 경우의 수에 대해 꽃을 피울수있는 최대 개수 갱신

	cin >> n >> m >> g >> r;

	//	2 1 0
	//	1 0 1
	//	2 1 2
	// 황토색 땅 위치 저장해둠
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];

			if (graph[i][j] == 2)
			{
				soilPos.push_back({ i, j });
			}
		}
	}

	// DFS
	DFS(0, 0, 0);

	cout << maxFlowerCnt << '\n';

	return 0;
}
