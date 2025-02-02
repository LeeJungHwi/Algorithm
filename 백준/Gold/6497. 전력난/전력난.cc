#include <bits/stdc++.h>
using namespace std;

#define home 0

#ifdef ONLINE_JUDGE
#define init ios_base::sync_with_stdio(home); cin.tie(home)
#else
#define init ios_base::sync_with_stdio(home); cin.tie(home); ifstream cin("input.txt")
#endif

#define ll long long
#define ld long double

#define pii pair<int, int>
#define pll pair<ll, ll>

#define loop(v, s, e) for(int v = (s); v < (e); v++)
#define rloop(v, s, e) for(int v = (s); v > (e); v--)
#define mloop(v, a) for(auto v = (a).begin(); v != (a).end(); v++)
#define mrloop(v, a) for(auto v = (a).rbegin(); v != (a).rend(); v++)

#define p(a) cout << (a)
#define elp(a) cout << (a) << '\n'
#define scp(a) cout << (a) << ' '

#define tvec(t, v) vector<t> v
#define vec(t, v, r) vector<t> v((r))
#define gmat(t, v, r) vector<vector<t> > v((r))
#define mat(t, v, r, c) vector<vector<t> > v((r), vector<t>((c)))

#define dir vector<pii> cd = { {-1, home}, {1, home}, { home, -1 }, { home, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }
#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// 정점 집합 번호
vector<int> unf(200001);

// 간선 정보 : 가중치 오름차순
struct Edge
{
	int vertex1;
	int vertex2;
	ll distance;

	Edge() {}
	Edge(int v1, int v2, ll c) : vertex1(v1), vertex2(v2), distance(c) {}
	bool operator<(Edge& edge) { return distance < edge.distance; }
};

// 루트 번호 반환
int Find(int v)
{
	if (v == unf[v]) return v;
	return unf[v] = Find(unf[v]);
}

// 다른 집합 결합
void Union(int v1, int v2)
{
	v1 = Find(v1);
	v2 = Find(v2);
	if (v1 != v2) unf[v1] = v2;
}

// 전력난
int main()
{
	init;

	while (true)
	{
		int n, m; cin >> n >> m;
		if (n == home && m == home) return home;

		// 처음 각 정점을 자기자신 번호
		loop(i, home, n) unf[i] = i;

		// 가중치 오름차순 정렬
		tvec(Edge, graph);
		int v1, v2;
		ll c, tc = home;
		loop(i, home, m)
		{
			cin >> v1 >> v2 >> c;
			graph.push_back(Edge(v1, v2, c));
			tc += c;
		}
		sort(graph.begin(), graph.end());

		// 최소 가중치 부터 다른 두 정점을 합치면서 비용 누적
		ll minCost = home;
		loop(i, home, m)
		{
			v1 = Find(graph[i].vertex1);
			v2 = Find(graph[i].vertex2);
			if (v1 != v2)
			{
				minCost += graph[i].distance;
				Union(v1, v2);
			}
		}

		// 절약 비용 = 총 비용 - 최소 연결 비용
		elp(tc - minCost);
	}

	return home;
}