#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 유니온 파인드 집합
vector<int> unf(10001);

// 파인드
// 회원이 속한 집합 번호 반환 : 집합의 번호는 집합의 루트번호
int Find(int v)
{
	if (v == unf[v])
	{
		return v;
	}
	else
	{
		return unf[v] = Find(unf[v]);
	}
}

// 유니온
// 두 회원이 속한 집합 번호가 다르면 하나로 합침
void Union(int v1, int v2)
{
	v1 = Find(v1);
	v2 = Find(v2);

	if (v1 != v2)
	{
		unf[v1] = v2;
	}
}

// 회의준비
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 8, 7
	cin >> n >> m;

	vector<vector<int> > graph(n + 1, vector<int>(n + 1, 100)); // 중간회원이 몇명인지에 따라 최소시간 갱신
	vector<int> result(n + 1); // 다이나믹 후 각 행의 최대점수 저장

	// Input
	//	1 2
	//	2 3
	//	4 5
	//	5 6
	//	4 6
	//	6 7
	//	7 4
	// graph
	// m 1 m m m m m m
	// 1 m 1 m m m m m
	// m 1 m m m m m m
	// m m m m 1 1 1 m
	// m m m 1 m 1 m m
	// m m m 1 1 m 1 m
	// m m m 1 m 1 m m
	// m m m m m m m m
	// 연결정보가 저장(중간회원 없이 아는사람), i == j는 0, 나머지는 max값으로 초기화
	// 유니온 파인드 집합 초기화
	for (int i = 1; i < n + 1; i++)
	{
		unf[i] = i; // 1 2 3 4 5 6 7 8
	}

	int v1, v2; // 정점 

	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2;

		// 양방향 연결
		graph[v1][v2] = 1;
		graph[v2][v1] = 1;

		// 각 회의 그룹화
		// (1 2 3)은 루트가 모두 3
		// (4 5 6 7)은 루트가 모두 7
		// (8)은 루트가 8
		Union(v1, v2);
	}

	for (int i = 1; i < n + 1; i++)
	{
		graph[i][i] = 0;
	}

	// 중간회원이 몇명인지에 따라 최소시간 갱신
	//	0 1 2 100 100 100 100 100
	//	1 0 1 100 100 100 100 100
	//	2 1 0 100 100 100 100 100
	//	100 100 100 0 1 1 1 100
	//	100 100 100 1 0 1 2 100
	//	100 100 100 1 1 0 1 100
	//	100 100 100 1 2 1 0 100
	//	100 100 100 100 100 100 100 0
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

	//	0 1 2 0 0 0 0 0
	//	1 0 1 0 0 0 0 0
	//	2 1 0 0 0 0 0 0
	//	0 0 0 0 1 1 1 0
	//	0 0 0 1 0 1 2 0
	//	0 0 0 1 1 0 1 0
	//	0 0 0 1 2 1 0 0
	//	0 0 0 0 0 0 0 0
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (graph[i][j] == 100)
			{
				graph[i][j] = 0;
			}
		}
	}

	// 의사전달시간 중 최대값 -> 각 행의 최대점수(각 회원이 의사전달할때 가장 늦게 전달되어지는 사람 시간) 저장
	for (int i = 1; i < n + 1; i++)
	{
		int maxScore = 0;

		for (int j = 1; j < n + 1; j++)
		{
			if (graph[i][j] > maxScore)
			{
				maxScore = graph[i][j];
			}
		}

		result[i] = maxScore; // 2 1 2 1 2 1 2 0
	}

	// 대표후보 조건 -> 같은회의팀 내 의사전달시간 최대값들 중 최소값 -> 가장 의사전달이 늦게되도 최소시간이되므로

	vector<int> minScore(n + 1, 100); // 각 회의팀 내 의사전달시간 최대값들 중 최소값 갱신
	vector<int> candidate(n + 1); // 각 회의팀 대표 저장
	int teamCnt = 0; // 회의팀 수

	for (int i = 1; i < n + 1; i++)
	{
		if (minScore[Find(i)] > result[i])
		{
			// 아직 갱신되지않았을때만 회의팀 수++
			if (minScore[Find(i)] == 100)
			{
				teamCnt++;
			}

			minScore[Find(i)] = result[i]; // 자기가 속한 회의팀 내 의사전달시간 최대값들 중 최소값 갱신
			candidate[Find(i)] = i; // 갱신될때 대표 저장 루트3팀은 2, 루트7팀은 4, 루트8팀은 8
		}
	}

	// 회의팀 수 출력
	cout << teamCnt << '\n';

	// 각 회의팀 대표 출력
	vector<int> test;

	for (int i = 1; i < n + 1; i++)
	{
		if (candidate[i] > 0)
		{
			test.push_back(candidate[i]);
			//cout << candidate[i] << '\n';
		}
	}	

	sort(test.begin(), test.end());

	for (auto a : test)
	{
		cout << a << '\n';
	}

	return 0;
}