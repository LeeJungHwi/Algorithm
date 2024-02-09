#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<int> dist(101, 2147000000); // 거리배열 초기화

// 도로정보 구조체
struct Edge
{
	int vertex1;
	int vertex2;
	int distance;

	Edge(int v1, int v2, int c)
	{
		vertex1 = v1;
		vertex2 = v2;
		distance = c;
	}
};

// 벨만포드
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream cin;
	cin.open("input.txt");

	vector<Edge> graph; // 그래프

	int n, m; // N, M 5, 7
	cin >> n >> m;

	int v1, v2, c; // 정정 및 비용

	// 연결정보 초기화
	//	1 2 5
	//	1 3 4
	//	2 3 - 3
	//	2 5 13
	//	3 4 5
	//	4 2 3
	//	4 5 7
	for (int i = 1; i < m + 1; i++)
	{
		cin >> v1 >> v2 >> c;
		graph.push_back(Edge(v1, v2, c));
	}

	int s, e; // S, E 1, 5
	cin >> s >> e;

	// 시작도시에서 시작도시까지 최소비용 0
	dist[s] = 0;

	// 벨만포드 : 그래프에 음의 가중치가 있을때, 만약 간선의 최대 개수를 넘어가는 경우 음의 사이클이 존재함
	// 시작정점에서 도착정점까지 간선의 개수를 늘려가면서 최소비용 갱신
	// 간선의 최대 개수 : 도착정점 - 시작정점 = 5 - 1 = 4
	/*
	 dist : 무한 무한 무한 무한 무한
	 i=1  : 0    5    4    무한 무한
	 i=2  : 0    5    2    9    18
	 i=3  : 0    5    2    7    16
	 i=4  : 0    5    2    7    14
	*/
	for (int i = 1; i < n; i++) // 간선의 개수를 늘려가면서 최소비용 갱신
	{
		for (int j = 0; j < graph.size(); j++) // 각 간선마다 갈수있는 정점 체크
		{
			int vertex1 = graph[j].vertex1;
			int vertex2 = graph[j].vertex2;
			int cost = graph[j].distance;

			if (dist[vertex1] != 2147000000 && dist[vertex1] + cost < dist[vertex2]) // 출발이 무한대면 더했을때 더 커지므로 갱신안됨, 갈수있는 정점에 가서 비용을 더했더니 기존 비용보다 작으면 갱신
			{
				dist[vertex2] = dist[vertex1] + cost;
			}
		}
	}

	// 한번더 해서 최소값이 갱신되면 간선의 최대 개수를 넘어가는 경우이므로 음의 사이클이 존재함
	for (int j = 0; j < graph.size(); j++)
	{
		int vertex1 = graph[j].vertex1;
		int vertex2 = graph[j].vertex2;
		int cost = graph[j].distance;

		if (dist[vertex1] != 2147000000 && dist[vertex1] + cost < dist[vertex2])
		{
			cout << "-1\n";
			return 0;
		}
	}

	// 시작도시에서 도착도시까지 최소비용 출력
	cout << dist[e] << '\n';

	return 0;
}
// 핵심
// 벨만포드
