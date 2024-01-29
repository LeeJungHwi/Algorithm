#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 경로탐색 (인접리스트)
void SearchGraph(int vertex, vector<int> graph[], int n, int &caseCnt, vector<bool> &vis)
{
	if (vertex == n - 1) // 종료조건 : N 정점에 도착한 경우
	{
		caseCnt++;
	}
	else
	{
		// out degree를 가지는 각 정점에서 갈수있는 정점들 재귀호출

		for (int i = 0; i < graph[vertex].size(); i++)
		{
			if (!vis[graph[vertex][i]]) // 인접리스트는 방문하지않은곳인지만 체크 : 갈수있는것을 연결해놓은 상태이므로
			{
				vis[graph[vertex][i]] = true;
				SearchGraph(graph[vertex][i], graph, n, caseCnt, vis);
				vis[graph[vertex][i]] = false; // 뒤로 되돌아갈때 방문체크 해제해줘야함
			}
		}
	}
}

// 경로탐색(인접리스트)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M
	cin >> n >> m;

	int v1, v2; // 정점

	int caseCnt = 0; // 가능한 경우 수

	vector<int> graph[20];
	vector<bool> vis(n); // 방문체크

	//	1 2
	//	1 3
	//	1 4
	//	2 1
	//	2 3
	//	2 5
	//	3 4
	//	4 2
	//	4 5
	//  0 -> 1 -> 2 -> 3
	//  1 -> 0 -> 2 -> 4
	//  2 -> 3
	//  3 -> 1 -> 4
	//  ....
	//  19
	// 인접리스트
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2;

		graph[v1 - 1].push_back(v2 - 1);
	}

	// 첫 정점 방문체크
	vis[0] = true;

	// DFS
	SearchGraph(0, graph, n, caseCnt, vis);

	cout << caseCnt << '\n';

	return 0;
}
// 핵심
// DFS 인접리스트 : 정점에서 갈수있는 정점이면서 방문하지않은곳 체크, 재귀호출 후 방문체크 해제
// 메모리공간 및 탐색시간 감소