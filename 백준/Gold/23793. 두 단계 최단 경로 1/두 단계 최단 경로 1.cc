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

int x, y, z;
priority_queue<pii, vector<pii>, greater<pii>> pq;

void Dijk(int s, vector<int> &d, vector<vector<pii> > &g, bool isY = true)
{
	pq.push({ home, s });
	d[s] = home;

	while (!pq.empty())
	{
		int sp = pq.top().rhs;
		int sc = pq.top().lhs;
		pq.pop();

		if (d[sp] < sc) continue;

		loop(i, home, g[sp].size())
		{
			int cp = g[sp][i].lhs;
			int cc = g[sp][i].rhs;

			// 다음 방문할 정점이 y면 X
			if (!isY && cp == y - 1) continue;

			if (d[cp] <= d[sp] + cc) continue;

			d[cp] = d[sp] + cc;
			pq.push({ d[cp], cp });
		}
	}
}

// 두 단계 최단 경로 1
int main()
{
	init;

	// Y를 거치는 최단거리 => X -> Y 최단거리 + Y -> Z 최단거리
	// Y를 거치지 않는 최단거리 => X부터 다익스트라 진행하면서 Y 정점 방문 X
	// 최단거리가 갱신되지 않았으면 -1

	int n, m; cin >> n >> m;
	gmat(pii, graph, n);
	int v1, v2, c;
	loop(i, home, m)
	{
		cin >> v1 >> v2 >> c;
		graph[--v1].push_back({ --v2, c });
	}
	cin >> x >> y >> z;

	vector<int> xDis(n, 2147000000), yDis(n, 2147000000), nyDis(n, 2147000000);
	Dijk(x - 1, xDis, graph);
	Dijk(y - 1, yDis, graph);
	Dijk(x - 1, nyDis, graph, false);

	// X -> Y 최단거리 + Y -> Z 최단거리
	scp(cond(xDis[y - 1] == 2147000000 || yDis[z - 1] == 2147000000, -1, xDis[y - 1] + yDis[z - 1]));

	// X -> Z 까지 Y를 거치지않는 최단거리
	elp(cond(nyDis[z - 1] == 2147000000, -1, nyDis[z - 1]));

	return home;
}