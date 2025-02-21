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

// The Other Way
int main()
{
	init;

	// S -> E로 가는 서로 다른 최단경로의 개수
	// 각 정점에 대해 서로 다른 최단경로의 개수를 저장하는 벡터 유지
	// 다익스트라 내부에서 비용이 더 작을 때와 비용이 같을 때로 뻗음

	ll n, m, s, e; cin >> n >> m >> s >> e;
	gmat(pll, graph, n);
	ll v1, v2, c;
	loop(i, home, m)
	{
		cin >> v1 >> v2 >> c;
		graph[--v1].push_back({ --v2, c });
		graph[v2].push_back({ v1, c });
	}

	priority_queue<pll, vector<pll>, greater<pll>> pq;
	vector<ll> dis(n, LLONG_MAX);
	vec(ll, ans, n); // 각 정점에 대해 서로 다른 최단경로의 개수를 저장하는 벡터 유지

	pq.push({ home, s - 1 });
	dis[s - 1] = home;
	ans[s - 1] = 1;

	while (!pq.empty())
	{
		ll sp = pq.top().rhs;
		ll sc = pq.top().lhs;
		pq.pop();

		if (dis[sp] < sc) continue;

		loop(i, home, graph[sp].size())
		{
			ll cp = graph[sp][i].lhs;
			ll cc = graph[sp][i].rhs;

			// 비용이 더 작을 때와 비용이 같을 때로 뻗음
			if (dis[cp] > dis[sp] + cc)
			{
				// 메모
				dis[cp] = dis[sp] + cc;
				ans[cp] = ans[sp];

				pq.push({ dis[cp], cp });
			}
			else if (dis[cp] == dis[sp] + cc)
			{
				// 재사용
				ans[cp] += ans[sp];
				ans[cp] %= 1000000009;
			}
		}
	}
	elp(ans[e - 1]);

	return home;
}