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

// 간선 이어가기 2
int main()
{
	init;

	int n, m; cin >> n >> m;
	gmat(pii, graph, n);
	int v1, v2, c;
	loop(i, home, m)
	{
		cin >> v1 >> v2 >> c;
		graph[--v1].push_back({ --v2, c });
		graph[v2].push_back({ v1, c });
	}

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<int> dis(n, 2147000000);

	int s, t; cin >> s >> t;

	// s부터 다익스트라
	pq.push({ home, --s });
	dis[s] = home;
	while (!pq.empty())
	{
		pii s = pq.top(); pq.pop();

		// 이미 더 적은비용으로 가능하면 X
		if (s.lhs > dis[s.rhs]) continue;

		loop(i, home, graph[s.rhs].size())
		{
			int cp = graph[s.rhs][i].lhs;
			int cc = graph[s.rhs][i].rhs;

			// 이미 더 적은비용이거나 같은비용이면 업데이트 X
			if (dis[cp] <= s.lhs + cc) continue;

			dis[cp] = s.lhs + cc;
			pq.push({ dis[cp], cp });
		}
	}
	elp(dis[--t]);

	return home;
}