#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 최소비용
void SearchGraph(int vertex, int n, int &minDis, int sumDis, vector<vector<int> > &graph, vector<bool> &vis, vector<vector<int> > &dis)
{
	if (vertex == n - 1) // 종료조건 : 마지막 정점 도착
	{
		if (minDis > sumDis) // 최소비용 갱신
		{
			minDis = sumDis;
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (graph[vertex][i] == 1 && !vis[i]) // 갈수있으면서 아직 방문하지않은곳이면
			{
				vis[i] = true; // 방문체크
				sumDis += dis[vertex][i]; // 거리 증가
				SearchGraph(i, n, minDis, sumDis, graph, vis, dis);
				vis[i] = false; // 방문해제
				sumDis -= dis[vertex][i]; // 거리 감소
			}
		}
	}
}

// 최소비용(인접행렬)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M
	cin >> n >> m;

	int v1, v2, d; // 정점, 거리
	int minDis = 0; // 최소비용
	int sumDis = 0; // 거리 총합

	vector<vector<int> > graph(n, vector<int>(n)); // 그래프
	vector<bool> vis(n); // 방문체크
	vector<vector<int> > dis(n, vector<int>(n)); // 거리

	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2 >> d;

		graph[v1 - 1][v2 - 1] = 1;
		dis[v1 - 1][v2 - 1] = d;
		minDis += d;
	}

	// 첫 정점 방문체크
	vis[0] = true;

	// DFS
	SearchGraph(0, n, minDis, sumDis, graph, vis, dis);

	cout << minDis << '\n';

	return 0;
}
// 핵심
// 거리행렬 추가