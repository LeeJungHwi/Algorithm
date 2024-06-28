#include <bits/stdc++.h>
using namespace std;

#define home 0

#define ll long long
#define ld long double

#define pii pair<int, int>
#define pll pair<ll, ll>

#define loop(v, s, e) for(int v = (s); v < (e); v++)
#define rloop(v, s, e) for(int v = (s); v > (e); v--)
#define mloop(v, a) for(auto v = (a).begin(); v != (a).end(); v++)
#define mrloop(v, a) for(auto v = (a).rbegin(); v != (a).rend(); v++)
#define aloop(t, v, s, c, e, i) for(t v = (s); v c (e); i)

#define p(a) cout << (a)
#define elp(a) cout << (a) << '\n'
#define scp(a) cout << (a) << ' '

#define vec(t, v, r) vector<t> v((r))
#define mat(t, v, r, c) vector<vector<t> > v((r), vector<t>((c)))
#define gmat(t, v, r) vector<vector<t> > v((r))
#define dir vector<pii> cd = { {-1, 0}, {1, 0}, { 0, -1 }, { 0, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }

#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

struct Road
{
	int lhs, rhs, cost;

	Road() {}
	Road(int l, int r, int c) : lhs(l), rhs(r), cost(c) {}

	bool operator<(const Road &road)const { return cost > road.cost; }
};

// Road Reconstruction
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	int n, m;
	cin >> n >> m;
	mat(int, graph, n, m);
	mat(int, dis, n, m);
	priority_queue<Road> cp;
	dir;
	loop(i, home, n) loop(j, home, m) { cin >> graph[i][j]; dis[i][j] = MAX;}
	if (graph[home][home] == -1) { elp(-1); return home; }
	cp.push(Road(home, home, graph[home][home]));
	dis[home][home] = graph[home][home];
	while (!cp.empty())
	{
		Road s = cp.top(); cp.pop();
		if (s.cost > dis[s.lhs][s.rhs]) continue;
		loop(i, home, 4)
		{
			int ci = s.lhs + cd[i].lhs;
			int cj = s.rhs + cd[i].rhs;
			if (ci < home || cj < home || ci >= n || cj >= m) continue;
			if (graph[ci][cj] == -1) continue;
			if (dis[ci][cj] <= dis[s.lhs][s.rhs] + graph[ci][cj]) continue;
			dis[ci][cj] = dis[s.lhs][s.rhs] + graph[ci][cj];
			cp.push(Road(ci, cj, dis[ci][cj]));
		}
	}
	elp(cond(dis[n - 1][m - 1] == MAX, -1, dis[n - 1][m - 1]));

	return home;
}