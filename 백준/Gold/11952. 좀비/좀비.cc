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

// 좀비
int main()
{
	init;

	int n, m, k, s, p, q; cin >> n >> m >> k >> s >> p >> q;
	gmat(pii, graph, n);
	map<ll, ll> zPos;
	int v1, v2;
	loop(i, home, k)
	{
		cin >> v1;
		zPos[--v1]++;
	}
	loop(i, home, m)
	{
		cin >> v1 >> v2;
		graph[--v1].push_back({--v2, 1 });
		graph[v2].push_back({ v1, 1 });
	}

	// 멀티 소스 다익 => 모든 좀비 도시 부터 다익스트라
	// 최단거리가 s 이하면 q원 아니면 p원
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	vector<ll> dis(n, LLONG_MAX);

	mloop(it, zPos)
	{
		pq.push({ home, it->lhs });
		dis[it->lhs] = home;
	}

	while (!pq.empty())
	{
		int sp = pq.top().rhs;
		ll sc = pq.top().lhs;
		pq.pop();

		if (dis[sp] < sc) continue;

		loop(i, home, graph[sp].size())
		{
			int cp = graph[sp][i].lhs;
			ll cc = graph[sp][i].rhs;

			if (dis[cp] <= dis[sp] + cc) continue;

			dis[cp] = dis[sp] + cc;
			pq.push({ dis[cp], cp });
		}
	}
	loop(i, home, n)
	{
		dis[i] = cond(dis[i] <= s, q, p);
		if (zPos[i] > home) dis[i] = home;
		//scp(dis[i]);
	}

	loop(i, home, graph.size()) loop(j, home, graph[i].size()) graph[i][j] = { graph[i][j].lhs, dis[i] };
	loop(i, home, n) dis[i] = LLONG_MAX;

	// 0번 도시부터 다익스트라
	pq.push({ home, home });
	dis[home] = home;

	while (!pq.empty())
	{
		int sp = pq.top().rhs;
		ll sc = pq.top().lhs;
		pq.pop();

		if (dis[sp] < sc) continue;

		loop(i, home, graph[sp].size())
		{
			int cp = graph[sp][i].lhs;
			ll cc = graph[sp][i].rhs;

			if (zPos[cp] > home) continue;
			if (dis[cp] <= dis[sp] + cc) continue;

			dis[cp] = dis[sp] + cc;
			pq.push({ dis[cp], cp });
		}
	}

	// 첫 도시와 마지막 도시는 숙박할 필요 없음
	elp(dis[n - 1] - graph[home][home].rhs);
	

	return home;
}