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

vector<int> unf(100001);

int Find(int v)
{
	if (unf[v] == v) return v;
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
	bool operator<(const Edge& e) const { return c > e.c; }
};

// 세부
int main()
{
	init;

	// 가중치가 큰 간선부터 연결하다가 s, e가 연결되면 해당 간선의 비용 출력
	int n, m, s, e; cin >> n >> m >> s >> e;
	loop(i, home, n) unf[i] = i;
	tvec(Edge, graph);
	int v1, v2, c;
	loop(i, home, m)
	{
		cin >> v1 >> v2 >> c;
		graph.push_back(Edge(--v1, --v2, c));
	}
	sort(all(graph));

	loop(i, home, graph.size())
	{
		v1 = Find(graph[i].v1);
		v2 = Find(graph[i].v2);

		if (v1 != v2)
		{
			Union(v1, v2);

			if (Find(s - 1) == Find(e - 1))
			{
				elp(graph[i].c);
				return home;
			}
		}
	}
	elp(home);

	return home;
}