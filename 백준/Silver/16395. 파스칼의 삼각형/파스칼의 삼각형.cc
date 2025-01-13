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

// 파스칼의 삼각형
int main()
{
	init;

	// 1
	// 11
	// 121 (2, 1)
	// 1331 (3, 1) (3, 2)
	// 14641 (4, 1) (4, 2) (4, 3)
	int n, k; cin >> n >> k;
	mat(int, graph, 30, 30);
	mat(int, dp, 30, 30);
	loop(i, home, 30)
	{
		graph[i][home] = dp[i][home] = 1;
		graph[i][i] = dp[i][i] = 1;
	}
	int coef = 2;
	loop(i, 2, 30)
	{
		loop(j, 1, coef)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
		coef++;
	}

	cout << dp[--n][--k] << '\n';

	return home;
}