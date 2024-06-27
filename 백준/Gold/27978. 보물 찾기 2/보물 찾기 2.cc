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

// 보물 찾기 2
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
	loop(i, home, n) loop(j, home, m) dis[i][j] = MAX;
	deque<pii> cp;
	dir;
	pii sPos, ePos;
	loop(i, home, n) loop(j, home, m)
	{
		cin >> graph[i][j];
		if (graph[i][j] == 'K') sPos = { i, j };
		else if (graph[i][j] == '*') ePos = { i, j };
		else if (graph[i][j] == '#') dis[i][j] = 1;
	}
	cp.push_back(sPos);
	dis[sPos.lhs][sPos.rhs] = 1;
	while (!cp.empty())
	{
		pii s = cp.front(); cp.pop_front();
		if (s == ePos) { elp(dis[s.lhs][s.rhs] - 1); return home; }
		loop(i, home, 8)
		{
			int ci = s.lhs + cd[i].lhs;
			int cj = s.rhs + cd[i].rhs;
			if (ci < home || cj < home || ci >= n || cj >= m) continue;
			if (dis[ci][cj] <= cond(i == 5 || i == 3 || i == 7, dis[s.lhs][s.rhs], dis[s.lhs][s.rhs] + 1)) continue;
			dis[ci][cj] = cond(i == 5 || i == 3 || i == 7, dis[s.lhs][s.rhs], dis[s.lhs][s.rhs] + 1);
			cond(i == 5 || i == 3 || i == 7, cp.push_front({ ci, cj }), cp.push_back({ ci, cj }));
		}
	}
	elp(-1);

	return home;
}