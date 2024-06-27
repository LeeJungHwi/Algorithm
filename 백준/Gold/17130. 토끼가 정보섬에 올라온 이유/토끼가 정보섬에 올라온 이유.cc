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
#define dir vector<pii> cd = { {-1, 1}, {0, 1}, {1, 1} }

#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// 토끼가 정보섬에 올라온 이유
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	int n, m;
	cin >> n >> m;
	mat(char, graph, n, m);
	mat(int, dis, n, m);
	deque<pii> cp;
	dir;
	loop(i, home, n) loop(j, home, m)
	{
		cin >> graph[i][j];
		dis[i][j] = MIN;
		if (graph[i][j] == 'R') { cp.push_back({ i, j }); dis[i][j] = 1; }
	}
	int ans = MIN;
	while (!cp.empty())
	{
		pii s = cp.front();
		cp.pop_front();
		loop(i, home, 3)
		{
			int ci = s.lhs + cd[i].lhs;
			int cj = s.rhs + cd[i].rhs;
			if (ci < home || cj < home || ci >= n || cj >= m) continue;
			if (graph[ci][cj] == '#') continue;
			cond(graph[ci][cj] == 'C', dis[s.lhs][s.rhs] + 1, dis[s.lhs][s.rhs]);
			if (dis[ci][cj] >= cond(graph[ci][cj] == 'C', dis[s.lhs][s.rhs] + 1, dis[s.lhs][s.rhs])) continue;
			dis[ci][cj] = cond(graph[ci][cj] == 'C', dis[s.lhs][s.rhs] + 1, dis[s.lhs][s.rhs]);
			cond(graph[ci][cj] == 'C', cp.push_back({ ci, cj }), cp.push_front({ ci, cj }));
			if (graph[ci][cj] == 'O') ans = max(ans, dis[ci][cj] - 1);
		}
	}
	elp(cond(ans == MIN, -1, ans));

	return home;
}
