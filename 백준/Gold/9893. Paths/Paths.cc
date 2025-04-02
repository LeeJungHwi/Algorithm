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
#define piii pair<int, pii>
#define pll pair<ll, ll>
#define plll pair<ll, pll>

#define loop(v, s, e) for(int v = (s); v < (e); v++)
#define rloop(v, s, e) for(int v = (s); v > (e); v--)
#define mloop(v, a) for(auto v = (a).begin(); v != (a).end(); v++)
#define mrloop(v, a) for(auto v = (a).rbegin(); v != (a).rend(); v++)

#define p(a) cout << (a)
#define elp(a) cout << (a) << '\n'
#define scp(a) cout << (a) << ' '

#define tvec(t, v) vector<t> v
#define vec(t, v, r) vector<t> v((r))
#define ivec(t, v, r, i) vector<t> v((r), i)
#define gmat(t, v, r) vector<vector<t> > v((r))
#define mat(t, v, r, c) vector<vector<t> > v((r), vector<t>((c)))
#define imat(t, v, r, c, i) vector<vector<t> > v((r), vector<t>((c), i))
#define smat(t, v, r, c, s) vector<vector<vector<t> > > v((r), vector<vector<t>>((c), vector<t>((s))))
#define ismat(t, v, r, c, s, i) vector<vector<vector<t> > > v((r), vector<vector<t>>((c), vector<t>((s), i)))
#define ssmat(t, v, r, c, s1, s2) vector<vector<vector<vector<t> > > > v((r), vector<vector<vector<t>>>((c), vector<vector<t>>((s1), vector<t>((s2)))))
#define issmat(t, v, r, c, s1, s2, i) vector<vector<vector<vector<t> > > > v((r), vector<vector<vector<t>>>((c), vector<vector<t>>((s1), vector<t>((s2), i))))
#define sssmat(t, v, r, c, s1, s2, s3) vector<vector<vector<vector<vector<t> > > > > v((r), vector<vector<vector<vector<t>>>>((c), vector<vector<vector<t>>>((s1), vector<vector<t>>((s2), vector<t>((s3))))))
#define isssmat(t, v, r, c, s1, s2, s3, i) vector<vector<vector<vector<vector<t> > > > > v((r), vector<vector<vector<vector<t>>>>((c), vector<vector<vector<t>>>((s1), vector<vector<t>>((s2), vector<t>((s3), i)))))

#define dir vector<pii> cd = { {-1, home}, {1, home}, { home, -1 }, { home, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }
#define kdir vector<pii> kcd = { {-1, -2}, {-2, -1}, { -2, 1 }, { -1, 2 }, { 1, -2 }, { 2, -1 }, { 1, 2 }, { 2, 1 } }
#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// Paths
int main()
{
	init;

	// 다익스트라 기준
	// 1.거리 
	// 2.비용
	// 0번 정점에서 1번 정점으로 가는 최단거리 최소비용

	int n, m; cin >> n >> m;
	gmat(pii, graph, n);
	int v1, v2, c;
	loop(i, home, m)
	{
		cin >> v1 >> v2 >> c;
		graph[v1].push_back({ v2, c });
	}
	vector<pii> dis(n,{MAX, MAX}); // 거리, 비용

	priority_queue<piii, vector<piii>, greater<piii>> pq; // 거리, 비용, 정점
	pq.push({ home, {home, home} });
	dis[home] = { home, home };

	while (!pq.empty())
	{
		int sp = pq.top().rhs.rhs;
		int sc = pq.top().rhs.lhs;
		int sd = pq.top().lhs;
		pq.pop();

		// 기존 거리가 더 짧은 경우 X
		if (sd > dis[sp].lhs) continue;

		// 기존 거리는 같은데 기존 비용이 더 적은 경우 X
		if (sd == dis[sp].lhs && sc < dis[sp].rhs) continue;

		loop(i, home, graph[sp].size())
		{
			int cp = graph[sp][i].lhs;
			int cc = graph[sp][i].rhs;
			int cd = sd + 1;

			// 거리가 더 짧거나 거리가 같으면 비용이 더 적은 경우 분기
			if (cd < dis[cp].lhs || (cd == dis[cp].lhs && dis[sp].rhs + cc < dis[cp].rhs))
			{
				dis[cp] = { cd, dis[sp].rhs + cc };
				pq.push({ cd, {dis[cp].rhs, cp} });
			}
		}
	}
	elp(dis[1].rhs);

	return home;
}