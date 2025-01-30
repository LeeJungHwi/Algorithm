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

// 파티
int main()
{
	init;

	int n, m, x; cin >> n >> m >> x; --x;
	gmat(pii, graph, n);
	gmat(pii, rGraph, n);
	int v1, v2, t;
	loop(i, home, m)
	{
		cin >> v1 >> v2 >> t;
		graph[--v1].push_back({ --v2, t });
		rGraph[v2].push_back({ v1, t });
	}

	vec(int, roundDis, n);

	// 각 마을 => X번 마을 최단거리
	vec(int, dis, n);
	loop(i, home, n) dis[i] = 2147000000;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dis[x] = home;
	pq.push({ home, x });

	while (!pq.empty())
	{
		pii s = pq.top();
		pq.pop();

		if (s.lhs > dis[s.rhs]) continue;

		loop(j, home, graph[s.rhs].size())
		{
			if (dis[graph[s.rhs][j].lhs] <= s.lhs + graph[s.rhs][j].rhs) continue;

			dis[graph[s.rhs][j].lhs] = s.lhs + graph[s.rhs][j].rhs;
			pq.push({ dis[graph[s.rhs][j].lhs], graph[s.rhs][j].lhs });
		}
	}

	// X번 마을 => 각 마을 최단거리
	vec(int, rdis, n);
	loop(i, home, n) rdis[i] = 2147000000;
	rdis[x] = home;
	pq.push({ home, x });

	while (!pq.empty())
	{
		pii s = pq.top();
		pq.pop();

		if (s.lhs > rdis[s.rhs]) continue;

		loop(j, home, rGraph[s.rhs].size())
		{
			if (rdis[rGraph[s.rhs][j].lhs] <= s.lhs + rGraph[s.rhs][j].rhs) continue;

			rdis[rGraph[s.rhs][j].lhs] = s.lhs + rGraph[s.rhs][j].rhs;
			pq.push({ rdis[rGraph[s.rhs][j].lhs], rGraph[s.rhs][j].lhs });
		}
	}

	//loop(i, home, n) cout << dis[i] << ' ' << rdis[i] << '\n';
	
	// 왕복 최대거리
	int maxDis = -2147000000;
	loop(i, home, n) maxDis = max(maxDis, dis[i] + rdis[i]);

	elp(maxDis);

	return home;
}