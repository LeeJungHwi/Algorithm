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

// Coast Length
int main()
{
	init;

	int n, m;
	cin >> n >> m;
	mat(char, graph, n, m);
	queue<pii> cp; dir;
	mat(bool, vis, n, m);

	loop(i, home, n) loop(j, home, m)
	{
		cin >> graph[i][j];
		if (i == home || i == n - 1 || (j == home && i > home && i < n - 1) || (j == m - 1 && i > home && i < n - 1))
		{
			if (graph[i][j] == '0')
			{
				cp.push({ i, j });
				vis[i][j] = true;
			}
		}
	}

	int ans = home;
	while (!cp.empty())
	{
		pii s = cp.front(); cp.pop();
		loop(i, home, 4)
		{
			int ci = s.lhs + cd[i].lhs;
			int cj = s.rhs + cd[i].rhs;
			if (ci < home || cj < home || ci >= n || cj >= m) continue;
			if (vis[ci][cj]) continue;
			if (graph[ci][cj] == '1')
			{
				ans++;
				continue;
			}
			cp.push({ ci, cj });
			vis[ci][cj] = true;
		}
	}
	loop(i, home, n)
	{
		if (graph[i][home] == '1') ans++;
		if (graph[i][m - 1] == '1') ans++;
	}
	loop(i, home, m)
	{
		if (graph[home][i] == '1') ans++;
		if (graph[n - 1][i] == '1') ans++;
	}
	elp(ans);

	return home;
}
