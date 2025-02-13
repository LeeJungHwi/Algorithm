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

priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

void Dijk(int s, vector<ll>& d, vector<vector<pii> >& g)
{
	pq.push({ home, s });
	d[s] = home;

	while (!pq.empty())
	{
		int sp = pq.top().rhs;
		ll sc = pq.top().lhs;
		pq.pop();

		if (d[sp] < sc) continue;

		loop(i, home, g[sp].size())
		{
			int cp = g[sp][i].lhs;
			int cc = g[sp][i].rhs;

			if (d[cp] <= d[sp] + cc) continue;

			d[cp] = d[sp] + cc;
			pq.push({ d[cp], cp });
		}
	}
}

// 두 단계 최단 경로 2
int main()
{
	init;

	// x -> pi + pi -> z 최단경로

	int n, m; cin >> n >> m;
	gmat(pii, graph, n);
	int v1, v2, c;
	loop(i, home, m)
	{
		cin >> v1 >> v2 >> c;
		graph[--v1].push_back({ --v2, c });
		graph[v2].push_back({ v1, c });
	}

	int x, z, p; cin >> x >> z >> p;
	vector<ll> xDis(n, LLONG_MAX), zDis(n, LLONG_MAX);
	Dijk(x - 1, xDis, graph);
	Dijk(z - 1, zDis, graph);

	ll ans = LLONG_MAX;
	loop(i, home, p)
	{
		cin >> v1;

		if (xDis[v1 - 1] == LLONG_MAX || zDis[v1 - 1] == LLONG_MAX) continue;

		ans = min(ans, xDis[v1 - 1] + zDis[v1 - 1]);
	}
	elp(cond(ans != LLONG_MAX, ans, -1));

	return home;
}