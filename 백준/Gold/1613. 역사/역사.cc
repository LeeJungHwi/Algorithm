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

// 역사
int main()
{
	init;

	int n, m; cin >> n >> m;
	mat(int, dp, n + 1, n + 1); // dp[i][j] == 1 => i가 j보다 선행됨
	int v1, v2;
	loop(i, home, m)
	{
		cin >> v1 >> v2;
		dp[v1][v2] = 1;
	}

	loop(k, 1, n + 1)
	{
		loop(i, 1, n + 1)
		{
			loop(j, 1, n + 1)
			{
				// i -> k -> j로 갈 수 있는 경로가 존재하면 i가 j보다 선행됨
				if (dp[i][k] == 1 && dp[k][j] == 1)
				{
					dp[i][j] = 1;
				}
			}
		}
	}

	int s; cin >> s;
	loop(i, home, s)
	{
		cin >> v1 >> v2;
		if (dp[v1][v2] == 1) elp(-1);
		else if (dp[v2][v1] == 1) elp(1);
		else elp(home);
	}

	return home;
}