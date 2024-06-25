#include <bits/stdc++.h>
using namespace std;

#define home 0

#define ll long long

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

// Best Grass
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
	queue<pii> cp;
	dir;
	loop(i, home, n) loop(j, home, m) cin >> graph[i][j];
	int ans = home;
	loop(i, home, n) loop(j, home, m) if (graph[i][j] == '#')
	{
		cp.push({ i, j });
		graph[i][j] = '.';
		++ans;
		while (!cp.empty())
		{
			pii s = cp.front();
			cp.pop();
			loop(k, home, 4)
			{
				int ci = s.lhs + cd[k].lhs;
				int cj = s.rhs + cd[k].rhs;
				if (ci < home || cj < home || ci >= n || cj >= m) continue;
				if (graph[ci][cj] == '.') continue;
				cp.push({ ci, cj });
				graph[ci][cj] = '.';
			}
		}
	}
	elp(ans);

	return home;
}