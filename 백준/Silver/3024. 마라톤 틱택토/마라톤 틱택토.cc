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

// 마라톤 틱택토
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	int n;
	cin >> n;
	mat(char, graph, n, n);
	dir;
	loop(i, home, n) loop(j, home, n) cin >> graph[i][j];
	loop(i, home, n) loop(j, home, n)
	{
		if (graph[i][j] == '.') continue;
		loop(k, home, 8)
		{
			bool isWin = true;
			loop(l, 1, 3)
			{
				int ci = i + cd[k].lhs * l;
				int cj = j + cd[k].rhs * l;
				if (ci < home || cj < home || ci >= n || cj >= n) { isWin = false;	break; }
				if (graph[ci][cj] != graph[i][j]) { isWin = false;	break; }
			}

			if (isWin) { elp(graph[i][j]); return home; }

			if (k == home || k == 2 || k == 4 || k == 5)
			{
				isWin = true;
				loop(l, home, 2)
				{
					int ci = cond(!l, i + cd[k].lhs, i - cd[k].lhs);
					int cj = cond(!l, j + cd[k].rhs, j - cd[k].rhs);
					if (ci < home || cj < home || ci >= n || cj >= n) { isWin = false;	break; }
					if (graph[ci][cj] != graph[i][j]) { isWin = false;	break; }
				}
			}

			if (isWin) { elp(graph[i][j]); return home; }
		}
	}
	elp("ongoing");

	return home;
}