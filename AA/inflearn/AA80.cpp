#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

vector<pair<int, int>> graph[30]; // 그래프
vector<int> dist(30, 2147000000); // 거리배열 초기화 : dist[i] -> 1번정점에서 i번정점으로 가는데 최소비용
vector<bool> vis1(30); // 방문체크

// 다익스트라
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 6, 9
	int v1, v2, c; // 정점 및 비용
	int minIdx; // 가장 가까운 정점 인덱스

	cin >> n >> m;

	// 연결정보 초기화
	//	1 2 12
	//	1 3 4
	//	2 1 2
	//	2 3 5
	//	2 5 5
	//	3 4 5
	//	4 2 2
	//	4 5 5
	//	6 4 5
	for (int i = 1; i < m + 1; i++)
	{
		cin >> v1 >> v2 >> c;
		graph[v1].push_back({ v2, c });
	}

	// 1번정점에서 1번정점으로 가는데 최소비용 0
	dist[1] = 0;

	// 다익스트라 : 간선값이 모두 양수일때
	// 각 정점에서 갈수있는 정점에 대해 거리배열 최소값 갱신
	// 각 정점 구하는법 : dist 배열의 최소값
	// dist : 무한 무한 무한 무한 무한 무한
	// v1   : 0(vis) 12 4 무한 무한 무한
	// v3   : 0(vis) 12 4(vis) 9 무한 무한
	// v4   : 0(vis) 11 4(vis) 9(vis) 14 무한
	// v2   : 0(vis) 11(vis) 4(vis) 9(vis) 14 무한
	// v5   : 0(vis) 11(vis) 4(vis) 9(vis) 14(vis) 무한
	for (int i = 1; i < n + 1; i++)
	{
		minIdx = 0;

		// 갈수있는 정점 중 아직 방문하지않은 정점중에 거리가 가장 가까운 정점 찾기
		for (int j = 1; j < n + 1; j++)
		{
			if (!vis1[j] && dist[j] < dist[minIdx])
			{
				minIdx = j;
			}
		}

		vis1[minIdx] = true; // 가장 가까운 정점 방문체크

		for (int j = 0; j < graph[minIdx].size(); j++) // 가장 가까운 정점에서 갈수있는 정점의 최소값 갱신
		{
			int vertex = graph[minIdx][j].first;
			int cost = graph[minIdx][j].second;

			if (dist[vertex] > dist[minIdx] + cost)
			{
				dist[vertex] = dist[minIdx] + cost;
			}
		}
	}

	// 2번 정점부터 각 정점으로 가는 최소비용 출력
	for (int i = 2; i < n + 1; i++)
	{
		if (dist[i] != 2147000000)
		{
			cout << i << " : " << dist[i] << '\n';
		}
		else // 갈수없는 정점
		{
			cout << i << " : impossible\n";
		}
	}

	return 0;
}
// 핵심
// 다익스트라
