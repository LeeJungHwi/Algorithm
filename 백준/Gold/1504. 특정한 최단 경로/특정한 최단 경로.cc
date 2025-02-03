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

// 특정한 최단 경로
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

	int a, b; cin >> a >> b;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<int> aDis(n, 2147000000);

	// a정점부터 지날때 => 1 ~ a 최단거리 + a ~ b 최단거리 + b ~ n 최단거리
	// b정점부터 지날때 => 1 ~ b 최단거리 + b ~ a 최단거리 + a ~ n 최단거리
	// 둘 중 최단경로, 둘다 2147000000이면 -1

	// a 다익스트라
	pq.push({ home, a - 1 });
	aDis[a - 1] = home;

	while (!pq.empty())
	{
		int sp = pq.top().rhs;
		int sc = pq.top().lhs;
		pq.pop();

		if (aDis[sp] < sc) continue;

		loop(i, home, graph[sp].size())
		{
			int cp = graph[sp][i].lhs;
			int cc = graph[sp][i].rhs;

			if (aDis[cp] <= aDis[sp] + cc) continue;

			aDis[cp] = aDis[sp] + cc;
			pq.push({ aDis[cp], cp });
		}
	}

	vector<int> bDis(n, 2147000000);

	// b 다익스트라
	pq.push({ home, b - 1 });
	bDis[b - 1] = home;

	while (!pq.empty())
	{
		int sp = pq.top().rhs;
		int sc = pq.top().lhs;
		pq.pop();

		if (bDis[sp] < sc) continue;

		loop(i, home, graph[sp].size())
		{
			int cp = graph[sp][i].lhs;
			int cc = graph[sp][i].rhs;

			if (bDis[cp] <= bDis[sp] + cc) continue;

			bDis[cp] = bDis[sp] + cc;
			pq.push({ bDis[cp], cp });
		}
	}

	// a정점부터 지날때 => 1 ~ a 최단거리 + a ~ b 최단거리 + b ~ n 최단거리
	// b정점부터 지날때 => 1 ~ b 최단거리 + b ~ a 최단거리 + a ~ n 최단거리
	// 둘 중 최단경로, 둘다 2147000000이면 -1
	int aFirst = cond((aDis[home] == 2147000000 || aDis[b - 1] == 2147000000 || bDis[n - 1] == 2147000000), 2147000000, aDis[home] + aDis[b - 1] + bDis[n - 1]);
	int bFirst = cond((bDis[home] == 2147000000 || bDis[a - 1] == 2147000000 || aDis[n - 1] == 2147000000), 2147000000, bDis[home] + bDis[a - 1] + aDis[n - 1]);

	elp(cond(min(aFirst, bFirst) == 2147000000, -1, min(aFirst, bFirst)));

	return home;
}