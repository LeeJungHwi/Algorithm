#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

vector<bool> vis1(30); // 방문체크

// 도로정보 구조체
struct Edge
{
	int vertex;
	int distance;

	Edge(int v, int c) // 생성자
	{
		vertex = v;
		distance = c;
	}

	bool operator<(const Edge &edge)const // 최소힙 정렬
	{
		return distance > edge.distance;
	}
};

// 원더랜드(프림)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	priority_queue<Edge> minHeap; // 최소힙
	vector<pair<int, int> > graph[30]; // 양방향 그래프

	int v, e; // V, E 9, 12
	cin >> v >> e;

	int v1, v2, c; // 정점 및 비용
	int minCost = 0; // 최소비용

	// 도로정보 초기화
	for (int i = 0; i < e; i++)
	{
		cin >> v1 >> v2 >> c;

		// 양방향 그래프 초기화
		graph[v1 - 1].push_back({ v2 - 1, c });
		graph[v2 - 1].push_back({ v1 - 1, c });
	}

	// 최소힙 사용
	// 최소힙에 (임의정점, 비용) 저장
	// 최소힙에서 최소비용 꺼낸뒤 비용 누적 후 트리에 저장, 꺼낸 정점으로부터 갈수있는 정점 최소힙에 저장
	// 큐가 비었으면 종료
	/*
	(0, 0) heap push
	(0, 0) heap pop (0, 0) tree push (1, 12),(8,25) heap push 0 cost
	(1, 12) heap pop (1, 12) tree push (8, 8),(7, 17),(2,10) heap push 12 cost
	(8, 8) heap pop (8, 8) tree push (7, 15) heap push 20 cost
	(2, 10) heap pop (2, 10) tree push (3, 18),(6, 55) heap push 30 cost
	(7, 15) heap pop (7, 15) tree push (6, 35) heap push 45 cost
	(3, 18) heap pop (3, 18) tree push (4, 44) heap push 63 cost
	(8, 25) heap pop 트리에 존재하므로 pop만하고 지나감
	(6, 35) heap pop (6, 35) tree push (4, 38) heap push 98 cost
	(4, 38) heap pop (4, 38) tree push (5, 60) heap push 136 cost
	(4, 44) heap pop 트리에 존재하므로 pop만하고 지나감
	(6, 55) heap pop 트리에 존재하므로 pop만하고 지나감
	(5, 60) heap pop (5, 60) tree push 196 cost
	*/

	minHeap.push(Edge(0, 0)); // (임의정점, 비용) 저장
	while (!minHeap.empty()) // 큐가 비었으면 종료
	{
		Edge tmpEdge = minHeap.top(); // 최소비용 꺼낸 뒤
		minHeap.pop();

		int vertex = tmpEdge.vertex; // 해당 도시로가는
		int cost = tmpEdge.distance; // 비용

		if (!vis1[vertex]) // 아직 방문하지 않았으면
		{
			minCost += cost; // 비용 누적
			vis1[vertex] = true; // 방문 체크

			for (int i = 0; i < graph[vertex].size(); i++) // 해당 도시로부터 갈수있는 도시정보 최소힙에 추가
			{
				minHeap.push(Edge(graph[vertex][i].first, graph[vertex][i].second));
			}
		}
	}

	// 최소비용 출력
	cout << minCost << '\n';

	return 0;
}
// 핵심
// 프림
/*
임의의 시작 정점을 선택하고 선택한 정점부터 연결관계를 보면서 정점을 추가해 나가다가 정점이 n개가 되면 최소비용 -> 최소힙 사용
*/
