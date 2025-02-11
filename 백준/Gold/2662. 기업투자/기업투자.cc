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

// 기업투자
int main()
{
	init;

	// 한 기업에 돈을 나누어 투자할 수 없음
	// 이익 최댓값, 각 기업에 투자한 액수

	int n, m; cin >> n >> m; 
	mat(int, v, m + 1, n + 1); // v[i][j] => i번째 기업에 j원을 투자했을때 얻을 수 있는 이익
	int money;
	loop(i, 1, n + 1)
	{
		cin >> money;
		loop(j, 1, m + 1) cin >> v[j][money];
	}

	mat(int, dp, m + 1, n + 1); // dp[i][j] => i번 기업까지 투자했을때 j원이 남은 경우 얻을 수 있는 최대 이익
	mat(int, trace, m + 1, n + 1); // trace[i][j] => j원을 투자할 수 있을때 i번째 기업에 투자한 금액

	// i번째 기업
	loop(i, 1, m + 1)
	{
		// 남은 금액 j원
		loop(j, home, n + 1)
		{
			// i번째 기업에 투자 X
			dp[i][j] = dp[i - 1][j];

			// i번째 기업에 k원 투자
			loop(k, 1, j + 1)
			{
				// dp[i - 1][j - k] => 현재 기업 이전 기업까지 투자하고 j - k원 남았을때 최대 이익
				// v[i][k] => 현재 기업에 k원을 투자했을때 얻을 수 있는 이익
				if (dp[i][j] < dp[i - 1][j - k] + v[i][k])
				{
					dp[i][j] = dp[i - 1][j - k] + v[i][k];
					trace[i][j] = k;
				}
			}
		}
	}
	elp(dp[m][n]);

	// 각 기업에 투자한 금액
	vec(int, ans, m + 1);
	int remainMoney = n;

	// dp[m][n]부터 역추적 => m번째 기업까지 투자하고 남은 금액이 n일때 최대이익
	rloop(i, m, home)
	{
		ans[i] = trace[i][remainMoney];
		remainMoney -= trace[i][remainMoney];
	}
	loop(i, 1, m + 1) scp(ans[i]);

	return home;
}