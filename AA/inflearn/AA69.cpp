#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

// 이진트리 탐색
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int v1, v2; // 정점

	vector<int> graph[7]; // 그래프
	queue<int> checkVertex; // 체크할 정점

	// 인접리스트
	// 0 -> 1 -> 2
	// 1 -> 3 -> 4
	// 2 -> 5 -> 6
	for (int i = 0; i < 6; i++)
	{
		cin >> v1 >> v2;

		graph[v1 - 1].push_back(v2 - 1);
	}

	checkVertex.push(0);
	cout << 1 << ' '; // 1

	// BFS
	while (checkVertex.back() != 6)
	{
		int curVertex = checkVertex.front(); // 현재 체크할 정점
		checkVertex.pop(); // 꺼냈으니 pop

		for (int i = 0; i < graph[curVertex].size(); i++)
		{
			cout << graph[curVertex][i] + 1 << ' '; // 정점번호 출력 : 2 3 -> 4 5 -> 6 7
			checkVertex.push(graph[curVertex][i]); // 정점번호 큐에 push
		}
	}

	return 0;
}
// 핵심
// DFS는 재귀로 BFS는 반복문으로 구현