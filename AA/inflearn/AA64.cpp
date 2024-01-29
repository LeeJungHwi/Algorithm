#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 경로탐색(인접행렬)
void SearchGraph(int vertex, vector<vector<int> > &graph, int n, int &caseCnt, vector<bool> &vis)
{
	if (vertex == n - 1) // 종료조건 : N 정점에 도착한 경우
	{
		caseCnt++;
	}
	else
	{
		// out degree를 가지는 각 정점에서 갈수있는 정점들 재귀호출 
		// 함수 호출스택
		// DFS(0) i = 1
		// DFS(1) i = 2
		// DFS(2) i = 3
		// DFS(3) i = 4
		// DFS(4) cnt++ 후 스택에서 빠짐
		
		// DFS(0) i = 1
		// DFS(1) i = 2
		// DFS(2) i = 3
		// DFS(3) i = 4에서 vis[4] = false 후 스택에서 빠짐

		// DFS(0) i = 1
		// DFS(1) i = 2
		// DFS(2) i = 3에서 vis[3] = false 후 i = 4일때 못가므로 스택에서 빠짐

		// DFS(0) i = 1
		// DFS(1) i = 2에서 vis[2] = false 후 i = 3일때 못가고 i = 4일때 갈수있음 -> DFS(1) i = 4
		// DFS(4) cnt++ 후 스택에서 빠짐

		// DFS(0) i = 1
		// DFS(1) i = 4에서 vis[4] = false 후 스택에서 빠짐

		// DFS(0) i = 1에서 vis[1] = false 후 i = 2일때 갈수있음 -> DFS(1) i = 2
		// DFS(2) ....

		for (int i = 0; i < n; i++)
		{
			if (graph[vertex][i] == 1 && !vis[i]) // 갈수있으면서 방문하지않은곳이면
			{
				vis[i] = true;
				SearchGraph(i, graph, n, caseCnt, vis);
				vis[i] = false; // 뒤로 되돌아갈때 방문체크 해제해줘야함
			}
		}
	}
}

// 경로탐색(인접행렬)
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

	vector<vector<int> > graph(n, vector<int>(n)); // 그래프 저장
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
	// 0 1 1 1 0
	// 1 0 1 0 1
	// 0 0 0 1 0
	// 0 0 0 0 0
	// 0 1 0 0 1
	// 인접행렬
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2;

		graph[v1 - 1][v2 - 1] = 1;
	}

	// 첫 정점 방문체크
	vis[0] = true;

	// DFS
	SearchGraph(0, graph, n, caseCnt, vis);

	cout << caseCnt << '\n';

	return 0;
}
// 핵심
// DFS 인접행렬 : 정점에서 갈수있는 정점이면서 방문하지않은곳 체크, 재귀호출 후 방문체크 해제