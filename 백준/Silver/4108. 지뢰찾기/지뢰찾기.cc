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

// 지뢰찾기
int main()
{
	init;

	int n, m; dir;
	while (true)
	{
		cin >> n >> m;
		if (n == home && m == home) return home;

		mat(char, graph, n, m);
		tvec(pii, bomb);
		loop(i, home, n)
		{
			loop(j, home, m)
			{
				cin >> graph[i][j]; 
				if (graph[i][j] == '*') bomb.push_back({ i, j });
				else graph[i][j] = '0';
			}
		}
		loop(i, home, bomb.size())
		{
			pii s = bomb[i];
			loop(j, home, 8)
			{
				int ci = s.lhs + cd[j].lhs;
				int cj = s.rhs + cd[j].rhs;
				if (ci < home || cj < home || ci >= n || cj >= m) continue;
				if (graph[ci][cj] == '*') continue;
				graph[ci][cj]++;
			}
		}

		for (auto a : graph)
		{
			for (auto b : a)
			{
				cout << b;
			}
			cout << '\n';
		}
	}

	return home;
}