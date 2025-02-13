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

// 암호코드
int main()
{
	init;

	string is; cin >> is;

	// 해석 X
	if (is[home] == '0') { elp(home); return home; }

	vec(ll, dp, is.size() + 1); // dp[i] => i번째 자리까지 해석 수
	dp[home] = dp[1] = 1;

	loop(i, 2, is.size() + 1)
	{
		int n1 = is[i - 1] - '0';
		int n2 = stoi(is.substr(i - 2, 2));

		// 한 자리 숫자가 1~9인 경우 이전 해석 숫자 누적
		if (n1 >= 1) dp[i] = (dp[i] + dp[i - 1]) % 1000000;
		
		// 두 자리 숫자가 10~26인 경우 두 단계전 해석 숫자 누적
		if (10 <= n2 && 26 >= n2) dp[i] = (dp[i] + dp[i - 2]) % 1000000;
	}
	elp(dp[is.size()]);

	return home;
}