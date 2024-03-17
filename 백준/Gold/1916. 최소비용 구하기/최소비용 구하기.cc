#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

vector<pair<int, int>> graph[1001]; // 그래프
vector<int> dist(1001, 2147000000); // 거리배열 초기화 : dist[i] -> 1번정점에서 i번정점으로 가는데 최소비용
vector<bool> vis1(1001); // 방문체크

// 최소비용 구하기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 5, 8
	int v1, v2, c; // 정점 및 비용
	int minIdx; // 가장 가까운 정점 인덱스

	cin >> n >> m;

	// 연결정보 초기화
	//	1 2 2
	//	1 3 3
	//	1 4 1
	//	1 5 10
	//	2 4 2
	//	3 4 1
	//	3 5 1
	//	4 5 3
	for (int i = 1; i < m + 1; i++)
	{
		cin >> v1 >> v2 >> c;

		// 이미 입력된 간선이 입력으로 들어올수있음
		// 이미 입력된 간선이면 최단거리 저장

		bool isExist = false; // 이미 입력된 간선인지 체크

		// v1과 연결된 간선을 돌면서
		for (int j = 0; j < graph[v1].size(); j++)
		{
			if (graph[v1][j].first == v2) // v2와 연결된 간선이 이미 존재하면
			{
				isExist = true; // 이미 존재함
				graph[v1][j].second = min(graph[v1][j].second, c); // 최단거리 저장
				break;	
			}
		}

		// 이미 입력된 간선이면 continue
		if (isExist)
		{
			continue;
		}

		// 이미 입력된 간선이 아니면 그냥 저장
		graph[v1].push_back({ v2, c });
	}

	int start, end; // 출발도시, 도착도시 1, 5
	cin >> start >> end;

	// start번정점에서 start번정점으로 가는데 최소비용 0
	dist[start] = 0;

	// 다익스트라 : 간선값이 모두 양수일때
	// 각 정점에서 갈수있는 정점에 대해 거리배열 최소값 갱신
	// 각 정점 구하는법 : dist 배열의 최소값
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

	// start번정점에서 end번정점으로 가는데 최소비용 출력
	cout << dist[end] << '\n';

	return 0;
}
