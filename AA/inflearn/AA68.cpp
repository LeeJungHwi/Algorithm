#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 최소비용
void SearchGraph(int vertex, int n, vector<pair<int, int> > graph[], vector<bool> &vis, int &minDis, int sumDis)
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
		for (int i = 0; i < graph[vertex].size(); i++)
		{
			if (!vis[graph[vertex][i].first]) // 아직 방문하지않은곳만 체크 : 인접리스트는 갈수있는곳만 연결하므로
			{
				vis[graph[vertex][i].first] = true; // 방문체크
				sumDis += graph[vertex][i].second; // 거리 증가
				SearchGraph(graph[vertex][i].first, n, graph, vis, minDis, sumDis);
				vis[graph[vertex][i].first] = false; // 방문체크 해제
				sumDis -= graph[vertex][i].second; // 거리 감소
			}
		}
	}
}

// 최소비용 (인접리스트)
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

	vector<pair<int, int> > graph[20]; // 그래프
	vector<bool> vis(n); // 방문체크

	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2 >> d;

		graph[v1 - 1].push_back({ v2 - 1, d });
		minDis += d;
	}

	// 첫 정점 방문체크
	vis[0] = true;

	// DFS
	SearchGraph(0, n, graph, vis, minDis, sumDis);

	cout << minDis << '\n';

	return 0;
}
// 핵심
// 거리행렬 추가