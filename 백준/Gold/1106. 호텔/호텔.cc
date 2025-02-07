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

// 호텔
int main()
{
	init;

	// 아이템 사용 무제한 => 정방향 냅색
	// 적어도 c명 => c명보다 고객을 더 유치해도됨 비용이 더 적게든다면

	int c, n; cin >> c >> n;
	vec(pii, hotel, n);
	loop(i, home, n) cin >> hotel[i].lhs >> hotel[i].rhs;
	vec(int, dp, c + 101); // dp[i] => i명의 고객을 유치하는데 드는 최소비용
	loop(i, home, c + 101) dp[i] = 2147000000;
	dp[home] = home;

	loop(i, home, n)
	{
		int cc = hotel[i].lhs;
		int cp = hotel[i].rhs;

		loop(j, cp, c + 101)
		{
			// 기존 dp와 현재 아이템을 사용하지않았을때의 고객 수를 유치하는 최소비용 + 현재 아이템을 하나 사용했을때 드는비용 중 최솟값으로 업데이트
			dp[j] = min(dp[j], dp[j - cp] + cc);
		}
	}

	int ans = 2147000000;
	loop(i, c, c + 101) ans = min(ans, dp[i]);
	elp(ans);

	return home;
}