#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 키순서
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// n명의 학생 중 두 학생의 키를 비교하는 입력이 m번 주어짐
	// a < b : a -> b
	// 학생중에 자신의 키가 몇번째인지 정확히 알수있는 학생 수 계산하기

	int n, m; // N, M 6, 7
	cin >> n >> m;

	vector<vector<int> > graph(n + 1, vector<int>(n + 1, 500)); // 중간학생이 몇명인지에 따라 최단거리 갱신

	// Input
	//	1 3
	//	1 5
	//	3 4
	//	5 4
	//	4 2
	//	4 6
	//	5 2
	// graph
	// m m 1 m 1 m
	// m m m 1 1 m
	// 1 m m 1 m m
	// m 1 1 m 1 1
	// 1 1 m 1 m m
	// m m m 1 m m
	// 연결정보가 저장(중간학생 없이 바로 아는사람), i == j는 0, 나머지는 max값으로 초기화

	int v1, v2; // 정점 

	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2;

		// 키순서 연결
		graph[v1][v2] = 1;
	}

	for (int i = 1; i < n + 1; i++)
	{
		graph[i][i] = 0;
	}

	// 중간학생이 몇명인지에 따라 최단거리 갱신
	//	0 2 1 2 1 3
	//	500 0 500 500 500 500
	//	500 2 0 1 500 2
	//	500 1 500 0 500 1
	//	500 1 500 1 0 2
	//	500 500 500 500 500 0
	for (int k = 1; k < n + 1; k++)
	{
		for (int i = 1; i < n + 1; i++)
		{
			for (int j = 1; j < n + 1; j++)
			{
				if (graph[i][j] > graph[i][k] + graph[k][j])
				{
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}

	//	0 2 1 2 1 3
	//	0 0 0 0 0 0
	//	0 2 0 1 0 2
	//	0 1 0 0 0 1
	//	0 1 0 1 0 2
	//	0 0 0 0 0 0
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (graph[i][j] == 500)
			{
				graph[i][j] = 0;
			}
		}
	}

	// 처음 떠올린 아이디어 : indegree와 outdegree로 다른학생과 어떻게든 연결되어있어야함
	// 그래프 돌면서 대각선을 제외하고
	// 0을 만나면 graph[j][i]이 하나라도 0이면 자신의 키가 몇번째인지 모르는 학생
	// 자신의 키가 몇번째인지 아는 학생만 카운팅

	int knowCnt = 0; // 자신의 키가 몇번째인지 아는 학생 카운팅

	for (int i = 1; i < n + 1; i++)
	{
		bool isKnow = true; // 자신의 키가 몇번째인지 아는지 체크

		for (int j = 1; j < n + 1; j++)
		{
			if (j != i && graph[i][j] == 0) // 대각선이 아니면서 0을 만나면
			{
				if (graph[j][i] == 0) // graph[j][i]가 하나라도 0이면 자신의 키가 몇번째인지 모르는 학생
				{
					isKnow = false;
					break;
				}
			}

			// 자신의 키가 몇번째인지 모르면 탈출
			if (!isKnow)
			{
				break;
			}
		}

		// 만약 자신의 키가 몇번째인지 안다면 카운팅
		if (isKnow)
		{
			knowCnt++;
		}
	}

	// 자신의 키가 몇번째인지 아는 학생의 수 출력
	cout << knowCnt << '\n';

	return 0;
}