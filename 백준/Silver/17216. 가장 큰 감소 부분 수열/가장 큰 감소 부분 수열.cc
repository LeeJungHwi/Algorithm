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

// 가장 큰 감소 부분 수열
int main()
{
	init;

	int n; cin >> n;
	vec(int, v, n);
	loop(i, home, n) cin >> v[i];
	vec(int, dp, n);

	// base => 자기 자신만 포함하는 부분수열
	loop(i, home, n) dp[i] = v[i];

	// dp[i] => i가 마지막 인덱스일때 감소 부분 수열 합의 최댓값
	// i 0 => 1
	// i 1 => 100
	// i 2 => 100 2
	// i 3 => 100 50
	// i 4 => 100 60
	// i 5 => 100 60 8
	// i 6 => 100 60 8 7
	// i 7 => 100 60 8 7 3
	// i 8 => 100 60 8 7 6
	// i 9 => 100 60 8 7 6 5

	int ans = -2147000000;
	loop(i, 1, n)
	{
		// i번째 이전값을 보면서
		loop(j, home, i)
		{
			// 감소하는 수열인경우 dp 업데이트
			if (v[i] < v[j]) dp[i] = max(dp[i], dp[j] + v[i]);
			ans = max(ans, dp[i]);
		}
	}
	elp(ans);

	return home;
}