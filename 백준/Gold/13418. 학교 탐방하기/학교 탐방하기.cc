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

vector<int> unf(1001);

int Find(int v)
{
	if (v == unf[v]) return v;
	return unf[v] = Find(unf[v]);
}

void Union(int v1, int v2)
{
	v1 = Find(v1);
	v2 = Find(v2);
	if (v1 != v2) unf[v1] = v2;
}

struct Edge
{
	int v1, v2, c;
	Edge() {}
	Edge(int v1, int v2, int c) : v1(v1), v2(v2), c(c) {}
};

bool compMax(const Edge& e1, const Edge& e2)
{
	return e1.c > e2.c;
}

bool compMin(const Edge& e1, const Edge& e2)
{
	return e1.c < e2.c;
}

// 학교 탐방하기
int main()
{
	init;

	// 피로도 최대비용 연결 - 피로도 최소비용 연결
	// 0 ~ n번 건물 연결
	// 오르막길(c == 0) 내리막길(c == 1)
	int n, m; cin >> n >> m;
	tvec(Edge, graph);
	
	int v1, v2, c;
	loop(i, home, m + 1)
	{
		cin >> v1 >> v2 >> c;
		graph.push_back(Edge(v1, v2, !c));
	}

	// 최대비용
	loop(i, home, n + 1) unf[i] = i;
	sort(all(graph), compMax);

	int maxCost = home;
	loop(i, home, graph.size())
	{
		v1 = Find(graph[i].v1);
		v2 = Find(graph[i].v2);

		if (v1 != v2)
		{
			Union(graph[i].v1, graph[i].v2);
			maxCost += graph[i].c;
		}
	}
	maxCost = pow(maxCost, 2);

	// 최소비용
	loop(i, home, n + 1) unf[i] = i;
	sort(all(graph), compMin);

	int minCost = home;
	loop(i, home, graph.size())
	{
		v1 = Find(graph[i].v1);
		v2 = Find(graph[i].v2);

		if (v1 != v2)
		{
			Union(graph[i].v1, graph[i].v2);
			minCost += graph[i].c;
		}
	}
	minCost = pow(minCost, 2);

	elp(maxCost - minCost);

	return home;
}