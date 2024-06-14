#include <bits/stdc++.h>
using namespace std;

#define home 0
#define ll long long
#define loop(v, s, e) for(int v = s; v < e; v++)
#define elprint(a) cout << a << '\n'
#define mat(t, v) vector<t> v

// 집합 정보
vector<int> unf(100001);

// 간선 정보(가중치 오름차순)
struct Edge
{
	int vertex1;
	int vertex2;
	ll distance;

	Edge() {}
	Edge(int v1, int v2, ll c) : vertex1(v1), vertex2(v2), distance(c) {}
	bool operator<(Edge &edge) { return distance < edge.distance; }
};

// 정점이 속한 집합 번호 반환(루트)
int Find(int v)
{
	if (v == unf[v]) return v;
	return unf[v] = Find(unf[v]);
}

// 서로 다른 두 집합 결합
void Union(int v1, int v2) { unf[v1] = v2; }

// 도시 분할 계획
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m;
	cin >> n >> m;

	mat(Edge, graph);

	int v1, v2, c;
	loop(i, 0, m)
	{
		cin >> v1 >> v2 >> c;
		graph.push_back(Edge(v1 - 1, v2 - 1, c));
	}
	sort(graph.begin(), graph.end());
	loop(i, 0, n) unf[i] = i;

	ll minCost = 0;
	ll maxCost = 0;
	loop(i, 0, m)
	{
		int fV1 = Find(graph[i].vertex1);
		int fV2 = Find(graph[i].vertex2);

		// 서로 다른 집합인 정점 중 최소 가중치 => 비용 누적, 유니온
		// 최대 가중치 갱신
		if (fV1 != fV2)
		{
			minCost += graph[i].distance;
			Union(fV1, fV2);
			maxCost = max(maxCost, graph[i].distance);
		}
	}

	elprint(minCost - maxCost);

	return 0;
}