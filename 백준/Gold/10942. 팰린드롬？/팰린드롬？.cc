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

// 팰린드롬?
int main()
{
	init;

	int n; cin >> n;

	vec(int, v, n);
	loop(i, home, n) cin >> v[i];
	mat(int, dp, n, n); // dp[i][j] => i ~ j 구간이 팰린드롬인지 저장

	// base => 구간 길이가 1, 2인 경우
	loop(i, home, n)
	{
		dp[i][i] = 1;
		if (i < n - 1 && v[i] == v[i + 1]) dp[i][i + 1] = 1;
	}

	// 구간 길이 3 ~ n
	loop(i, 3, n + 1)
	{
		loop(j, home, n - i + 1)
		{
			// 양끝이 같고 중간이 팰린드롬인 경우
			// 내부 구간(j + 1 ~ k - 1)이 이미 검사된상태
			int k = i + j - 1;
			if (v[j] == v[k] && dp[j + 1][k - 1] == 1) dp[j][k] = 1;
		}
	}

	int m; cin >> m;
	int s, e;
	loop(i, home, m)
	{
		cin >> s >> e;
		elp(dp[--s][--e]);
	}

	return home;
}