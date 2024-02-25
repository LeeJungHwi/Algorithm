#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// 유니온 파인드 집합
vector<int> unf(1000001);

// 연결정보 구조체
struct Edge
{
	int vertex1; // 행성1
	int vertex2; // 행성2
	int distance; // 관리비용

	Edge(int v1, int v2, int c) // 생성자
	{
		vertex1 = v1;
		vertex2 = v2;
		distance = c;
	}

	bool operator<(Edge &edge) // 관리비용 기준 오름차순 정렬
	{
		return distance < edge.distance;
	}
};

// 파인드
// 행성이 속한 집합 번호 반환 : 집합의 번호는 집합의 루트번호
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
// 두 행성이 속한 집합 번호가 다르면 하나로 합침
void Union(int v1, int v2)
{
	v1 = Find(v1);
	v2 = Find(v2);

	if (v1 != v2)
	{
		unf[v1] = v2;
	}
}

// 행성연결
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	vector<Edge> edge; // 관리비용 정보

	int n; // N 5
	cin >> n;

	// 연결정보 초기화
	/*
	Input
	0 6 8 1 3
	6 0 5 7 3
	8 5 0 9 4
	1 7 9 0 6
	3 3 4 6 0

	edge
	(1,1,0), (1,2,6) .... (5,5,0)
	*/

	int c; // 관리비용

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			cin >> c;
			edge.push_back(Edge(i, j, c));
		}
	}

	// 연결정보 관리비용 기준 오름차순 정렬
	sort(edge.begin(), edge.end());

	// 유니온 파인드 집합 초기화

	int e = (n - 1) * n; // 간선개수 20

	for (int i = 1; i < e + 1; i++)
	{
		unf[i] = i;
	}
	
	// 유니온 파인드 진행하면서 도로유지비용 누적

	long long minCost = 0; // 관리최소비용

	for (int i = 1; i < e + 1; i++)
	{
		// 두 행성의 루트번호를 가져옴
		int findVertex1 = Find(edge[i].vertex1);
		int findVertex2 = Find(edge[i].vertex2);
	
		// 두 행성이 서로 다른 집합에 속하면 비용누적 및 유니온
		if (findVertex1 != findVertex2) 
		{
			minCost += edge[i].distance; // 비용 누적
			Union(edge[i].vertex1, edge[i].vertex2); // 집합 합침
		}
	}
	
	// 최소관리비용 출력
	cout << minCost << '\n';
	
	return 0;
}
