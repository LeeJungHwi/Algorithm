#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

// 그래프 최단거리
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M
	cin >> n >> m;

	int v1, v2; // 정점

	vector<int> graph[20];
	vector<int> vertexCnt(n); // 각 정점으로 가는 최소간선 수
	queue<int> vertexCheck; // 체크할 정점
	int cntEdge = 0; // 간선 수
	int storeCnt = 0; // 저장한 횟수
	bool isFinish = false; // 모두 저장이 끝났는지 체크

	// 인접리스트
	// 0 -> 2 -> 3
	// 1 -> 0 -> 4
	// 2 -> 3
	// 3 -> 4 -> 5
	// 5 -> 1 -> 4
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2;

		graph[v1 - 1].push_back(v2 - 1);
	}

	vertexCheck.push(0);

	// BFS
	while (!isFinish)
	{
		// 체크할 정점 꺼내기
		int curVertex = vertexCheck.front();
		vertexCheck.pop();

		// 간선의 수는 꺼낸정점 간선의 수에 1개 증가
		cntEdge = vertexCnt[curVertex] + 1;

		// 꺼낸 정점에서 갈수있는 정점 최소간선 수 저장 후 큐에 추가
		for (int i = 0; i < graph[curVertex].size(); i++)
		{
			if (vertexCnt[graph[curVertex][i]] == 0) // 아직 간선 수가 저장되지 않은경우만 
			{
				vertexCnt[graph[curVertex][i]] = cntEdge; // 간선 수 저장
				storeCnt++;

				if (storeCnt == n - 1) // 각 정점별로 최소거리를 모두 저장했으면 종료
				{
					isFinish = true;

					break;
				}
			}

			vertexCheck.push(graph[curVertex][i]); // 큐에 추가
		}
	}

	for (int i = 1; i < n; i++)
	{
		cout << i + 1 << " : " << vertexCnt[i] << '\n';
	}

	return 0;
}
// 핵심
// BFS 할때마다 간선 수 증가 X -> 체크할 정점의 간선 수 + 1