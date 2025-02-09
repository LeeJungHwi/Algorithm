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
#define pld pair<ld, ld>

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
	int v1, v2;
	double c;
	Edge() {}
	Edge(int v1, int v2, double c) : v1(v1), v2(v2), c(c) {}
	bool operator<(const Edge& e)const { return c < e.c; }
};

// 우주신과의 교감
int main()
{
	init;

	// 이미 연결된 통로는 미리 Union
	int n, m; cin >> n >> m;
	loop(i, home, n) unf[i] = i;
	tvec(Edge, graph);
	vec(pld, v, n);
	loop(i, home, n) cin >> v[i].lhs >> v[i].rhs;
	vec(pld, connectPos, m);
	loop(i, home, m)
	{
		cin >> connectPos[i].lhs >> connectPos[i].rhs;
		Union(--connectPos[i].lhs, --connectPos[i].rhs);
	}

	// 그래프에 간선 추가
	loop(i, home, n)
	{
		loop(j, i + 1, n)
		{
			ld c = sqrt((v[i].lhs - v[j].lhs) * (v[i].lhs - v[j].lhs) + (v[i].rhs - v[j].rhs) * (v[i].rhs - v[j].rhs));
			graph.push_back(Edge(i, j, c));
		}
	}
	sort(all(graph));

	ld minCost = home;
	int v1, v2;
	loop(i, home, graph.size())
	{
		v1 = Find(graph[i].v1);
		v2 = Find(graph[i].v2);

		if (v1 != v2)
		{
			minCost += graph[i].c;
			Union(v1, v2);
		}
	}
	cout << fixed << setprecision(2);
	elp(minCost);

	return home;
}