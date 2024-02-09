#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// 유니온 파인드 집합
vector<int> unf(10001);

// 도로정보 구조체
struct Edge
{
	int vertex1;
	int vertex2;
	int distance;

	Edge(int v1, int v2, int c) // 생성자
	{
		vertex1 = v1;
		vertex2 = v2;
		distance = c;
	}

	bool operator<(Edge &edge) // 도로 유지비용 기준 오름차순 정렬
	{
		return distance < edge.distance;
	}
};

// 파인드
// 도시가 속한 집합 번호 반환 : 집합의 번호는 집합의 루트번호
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
// 두 도시가 속한 집합 번호가 다르면 하나로 합침
void Union(int v1, int v2)
{
	v1 = Find(v1);
	v2 = Find(v2);
	
	if (v1 != v2)
	{
		unf[v1] = v2;
	}
}

// 원더랜드(크루스칼)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	vector<Edge> edge; // 도로정보

	int v, e; // V, E 9, 12
	cin >> v >> e;

	int v1, v2, c; // 정점 및 비용
	int minCost = 0; // 최소비용

	// 도로정보 초기화
	/*	
			0 1 12
			0 8 25
			1 2 10
			1 7 17
			1 8 8
			2 3 18
			2 6 55
			3 4 44
			4 5 60
			4 6 38
			6 7 35
			7 8 15
	*/
	for (int i = 0; i < e; i++)
	{
		cin >> v1 >> v2 >> c;
		edge.push_back(Edge(v1 - 1, v2 - 1, c));
	}

	// 도로 유지비용 오름차순 정렬
	/*
			1 8 8
			1 2 10
			0 1 12
			7 8 15
			1 7 17
			2 3 18
			0 8 25
			6 7 35
			4 6 38
			3 4 44
			2 6 55
			4 5 60
	*/
	sort(edge.begin(), edge.end());

	// 유니온 파인드 집합 초기화
	// 0 1 2 3 4 5 6 7 8
	for (int i = 0; i < v; i++)
	{
		unf[i] = i;
	}

	// 유니온 파인드 진행하면서 도로유지비용 누적
	for (int i = 0; i < e; i++)
	{
		int findVertex1 = Find(edge[i].vertex1); // 1 1 0 7 1 2 0 6 4 3 2 4
		int findVertex2 = Find(edge[i].vertex2); // 8 2 1 8 7 3 8 7 6 4 6 5

		if (findVertex1 != findVertex2) // 도시가 서로 다른집합에 속하면
		{
			minCost += edge[i].distance; // 비용 누적
			Union(edge[i].vertex1, edge[i].vertex2); // 집합 합침
		}
	}

	// 최소비용 출력
	cout << minCost << '\n';

	return 0;
}
// 핵심
// 유니온 파인드
/*
유니온 : 공통원소가 있는 두 집합을 합침 -> A = {1, 2} + B = {2, 3} = {1, 2, 3}
disjoint Set : 공통원소가 없는 두 집합
*/
// 크루스칼
/*
간선을 가중치값에 따라 오름차순 정렬 후 회로가 발생하지 않는 조건하에 가충치가 낮은 간선부터 선택해 나가다가 간선을 n-1개 선택되면 최소비용
*/
