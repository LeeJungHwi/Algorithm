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

// 벽 타기
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	int n, m; cin >> n >> m;
	mat(char, graph, n, m);
	mat(int, dis, n, m);
	deque<pii> cp;
	dir;
	pii ePos;
	vector<pii> wPos;
	loop(i, home, n) loop(j, home, m)
	{
		cin >> graph[i][j];
		dis[i][j] = MAX;
		if (graph[i][j] == 'S') { cp.push_back({ i, j }); dis[i][j] = 1; }
		else if (graph[i][j] == 'E') ePos = { i, j };
		else if (graph[i][j] == '#') { wPos.push_back({ i, j }); }
	}
	map<pii, int> zeroMap;
	loop(i, home, wPos.size())
	{
		loop(j, home, 4)
		{
			int ci = wPos[i].lhs + cd[j].lhs;
			int cj = wPos[i].rhs + cd[j].rhs;
			if (ci < home || cj < home || ci >= n || cj >= m) continue;
			if (graph[ci][cj] == '#') continue;
			if (zeroMap[{ci, cj}]) continue;
			zeroMap[{ci, cj}]++;
		}
	}
	while (!cp.empty())
	{
		pii s = cp.front(); cp.pop_front();
		if(s == ePos) { elp(dis[s.lhs][s.rhs] - 1); return home; }
		loop(i, home, 4)
		{
			pii c = { s.lhs + cd[i].lhs, s.rhs + cd[i].rhs };
			if (graph[c.lhs][c.rhs] == '#') continue;
			if (dis[c.lhs][c.rhs] <= cond(zeroMap[s] && zeroMap[c], dis[s.lhs][s.rhs], dis[s.lhs][s.rhs] + 1)) continue;
			dis[c.lhs][c.rhs] = cond(zeroMap[s] && zeroMap[c], dis[s.lhs][s.rhs], dis[s.lhs][s.rhs] + 1);
			cond(zeroMap[s] && zeroMap[c], cp.push_front(c), cp.push_back(c));
		}
	}

	return home;
}