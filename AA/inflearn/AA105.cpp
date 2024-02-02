#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 위상정렬
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 6, 6
	cin >> n >> m;

	int v1, v2; // 정점 

	vector<vector<int> > graph(n + 1, vector<int>(n + 1)); // 선후관계 그래프
	vector<int> inDegree(n + 1); // 들어오는 차수
	queue<int> curWorks; // 선진행해야하는 일 저장

	// 일의 순서정보
	/*
		input : 1 4 -> 1번일을 하고나서 4번일을 해야함
				5 4
				4 3
				2 5
				2 3
				6 2

		graph : 0 0 0 1 0 0
				0 0 1 0 1 0
				0 0 0 0 0 0
				0 0 1 0 0 0
				0 0 0 1 0 0
				0 1 0 0 0 0
	*/
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2;

		graph[v1][v2] = 1;

		inDegree[v2]++; // 들어오는 차수 저장 -> 0 1 2 2 1 0
	}

	// 들어오는 차수가 0이면 큐에 저장
	for (int i = 1; i < n + 1; i++)
	{
		if (inDegree[i] == 0)
		{
			curWorks.push(i);
		}
	}

	// 큐가 빌때까지 BFS
	while (!curWorks.empty())
	{
		// 선진행해야하는 일 꺼냄
		int curWork = curWorks.front();
		curWorks.pop();

		cout << curWork << " ";

		// 선진행 하는 일의 outDegree로 가는 일의 inDegree 제거하고 만약 inDegree가 하나도 남지않으면 큐에 저장 -> inDegree가 0인것은 선진행해야할 작업이 없는 작업이므로 큐에 저장
		for (int i = 1; i < n + 1; i++)
		{
			if (graph[curWork][i] == 1)
			{
				inDegree[i]--;

				if (inDegree[i] == 0)
				{
					curWorks.push(i);
				}
			}
		}
	}

	return 0;
}
// 핵심
// 위상정렬
/*
각각의 일의 선후관계가 복잡할때 선후관계를 유지하면서 전체 일의 순서를 짬
*/