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
	bool operator<(const Edge& e)const { return c < e.c; }
};

int DFS(int sp, int ep, const vector<vector<pair<int, int>>>& edge, vector<bool>& vis)
{
	// base => X -> Y로 가는 경로를 찾았으면 0
	if (sp == ep) return home;

	vis[sp] = true;

	loop(i, home, edge[sp].size())
	{
		int cp = edge[sp][i].first;
		int cc = edge[sp][i].second;

		if (!vis[cp])
		{
			int maxEdge = DFS(cp, ep, edge, vis);

			// 경로를 찾았으면 최대 간선 비용
			if (maxEdge != -1) return max(maxEdge, cc);
		}
	}

	// 경로를 찾지 못 함
	return -1;
}

// 조별과제 멈춰!
int main()
{
	init;

	// X와 Y가 각 집합의 팀장
	// X조와 Y조는 서로 다른 조, 각 팀장은 자기 조 학생에게만 공지를 전달하는 최소비용
	// 크루스칼 => X와 Y를 포함하는 최소비용으로 연결
	// X와 Y를 연결하는 경로에서 가장 큰 간선 제거 => X와 Y조를 서로 다른 조로 분리

	int n, m; cin >> n >> m;
	loop(i, home, n) unf[i] = i;
	tvec(Edge, graph);
	int v1, v2, c;
	loop(i, home, m)
	{
		cin >> v1 >> v2 >> c;
		graph.push_back(Edge(--v1, --v2, c));
	}
	sort(all(graph));

	gmat(pii, edge, n);
	int minCost = home;
	loop(i, home, graph.size())
	{
		v1 = Find(graph[i].v1);
		v2 = Find(graph[i].v2);

		if (v1 != v2)
		{
			Union(v1, v2);
			edge[graph[i].v1].push_back({ graph[i].v2, graph[i].c });
			edge[graph[i].v2].push_back({ graph[i].v1, graph[i].c });
			minCost += graph[i].c;
		}
	}

	int q; cin >> q;
	loop(i, home, q)
	{
		cin >> v1 >> v2;
		vec(bool, vis, n);
		int maxEdge = DFS(--v1, --v2, edge, vis);
		elp(minCost - maxEdge);
	}

	return home;
}