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

// 주간 미팅
int main()
{
	init;

	int n, m, k; cin >> n >> m >> k;
	int a, b; cin >> a >> b; --a; --b;
	vec(int, team, n);
	loop(i, home, n) cin >> team[i];
	gmat(pii, graph, m);
	int v1, v2, c;
	loop(i, home, k)
	{
		cin >> v1 >> v2 >> c;
		graph[--v1].push_back({ --v2, c });
		graph[v2].push_back({ v1, c });
	}

	priority_queue<pii, vector<pii>, greater<pii>> pq;

	// 각 팀원에 대해 다익스트라
	int ans = home;
	loop(i, home, n)
	{
		int s = team[i] - 1;
		vector<int> dis(m, 2147000000);
		pq.push({ home, s });
		dis[s] = home;

		while (!pq.empty())
		{
			int sp = pq.top().rhs;
			int sc = pq.top().lhs;
			pq.pop();

			// 이미 더 적은비용으로 방문 가능하면 X
			if (dis[sp] < sc) continue;

			loop(j, home, graph[sp].size())
			{
				int cp = graph[sp][j].lhs;
				int cc = graph[sp][j].rhs;

				// 이미 더 적은비용으로 방문 가능하면 X
				if (dis[cp] <= dis[sp] + cc) continue;

				dis[cp] = dis[sp] + cc;
				pq.push({ dis[cp], cp });
			}
		}

		ans += cond(dis[a] == 2147000000, -1, dis[a]);
		ans += cond(dis[b] == 2147000000, -1, dis[b]);
	}
	elp(ans);

	return home;
}