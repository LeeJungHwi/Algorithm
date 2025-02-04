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

// 운동
int main()
{
	init;

	int n, m; cin >> n >> m;
	mat(int, dp, n + 1, n + 1);
	loop(i, home, n + 1) loop(j, home, n + 1) dp[i][j] = 2147000000;
	int v1, v2, c;
	loop(i, home, m)
	{
		cin >> v1 >> v2 >> c;
		dp[v1][v2] = c;
	}
	loop(i, home, n + 1) dp[i][i] = home;

	loop(k, 1, n + 1)
	{
		loop(i, 1, n + 1)
		{
			loop(j, 1, n + 1)
			{
				if (dp[i][k] == 2147000000 || dp[k][j] == 2147000000) continue;
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	//loop(i, home, n + 1)
	//{
	//	loop(j, home, n + 1)
	//	{
	//		scp(dp[i][j]);
	//	}
	//	cout << '\n';
	//}

	int ans = 2147000000;
	loop(i, 1, n + 1)
	{
		loop(j, 1, n + 1)
		{
			// 같은 마을인 경우 X
			if (i == j) continue;

			// 사이클이 아닌경우 X
			if (dp[i][j] == 2147000000 || dp[j][i] == 2147000000) continue;

			// 왕복 최단거리 업데이트
			ans = min(ans, dp[i][j] + dp[j][i]);
		}
	}
	elp(cond(ans == 2147000000, -1, ans));

	return home;
}