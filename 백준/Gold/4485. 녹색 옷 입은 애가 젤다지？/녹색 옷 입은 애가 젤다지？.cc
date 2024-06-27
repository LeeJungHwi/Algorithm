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

struct Rupee
{
	int lhs, rhs, cost;
	
	Rupee() {}
	Rupee(int l, int r, int c) : lhs(l), rhs(r), cost(c) {}

	bool operator<(const Rupee &rupee)const { return cost > rupee.cost; }
};

// 녹색 옷 입은 애가 젤다지?
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	int cur = home;
	dir;
	while (true)
	{
		int n;
		cin >> n;
		if (!n) return home;
		mat(int, graph, n, n);
		mat(int, dis, n, n);
		loop(i, home, n) loop(j, home, n) { cin >> graph[i][j]; dis[i][j] = MAX;}
		priority_queue<Rupee> cp;

		cp.push(Rupee(home, home, graph[home][home]));
		dis[home][home] = graph[home][home];

		while (!cp.empty())
		{
			Rupee s = cp.top(); cp.pop();
			if (s.cost > dis[s.lhs][s.rhs]) continue;
			loop(i, home, 4)
			{
				int ci = s.lhs + cd[i].lhs;
				int cj = s.rhs + cd[i].rhs;
				if (ci < home || cj < home || ci >= n || cj >= n) continue;
				if (dis[ci][cj] <= dis[s.lhs][s.rhs] + graph[ci][cj]) continue;
				dis[ci][cj] = dis[s.lhs][s.rhs] + graph[ci][cj];
				cp.push(Rupee(ci, cj, dis[ci][cj]));
			}
		}
		scp("Problem"); p(++cur); scp(":"); elp(dis[n - 1][n - 1]);
	}

	return home;
}
