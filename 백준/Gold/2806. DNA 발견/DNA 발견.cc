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
#define piii pair<int, pii>
#define pll pair<ll, ll>
#define plll pair<ll, pll>

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
#define smat(t, v, r, c, s) vector<vector<vector<t> > > v((r), vector<vector<t>>((c), vector<t>((s))))

#define dir vector<pii> cd = { {-1, home}, {1, home}, { home, -1 }, { home, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }
#define kdir vector<pii> kcd = { {-1, -2}, {-2, -1}, { -2, 1 }, { -1, 2 }, { 1, -2 }, { 2, -1 }, { 1, 2 }, { 2, 1 } }
#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// DNA 발견
int main()
{
	init;

	// 한 글자 변환, 첫 k개 글자 변환
	// 모두 A로 만드는 최소 횟수

	int n; cin >> n;
	string is; cin >> is;
	mat(int, dp, 2, n); // dp[0][j] => j번째 분자까지 전부 A로 만드는 최소 횟수, dp[1][j] => j번째 분자까지 전부 B로 만드는 최소 횟수
	loop(i, home, 2) loop(j, home, n) dp[i][j] = 2147000000;

	// base => 0번째 분자까지 A 또는 B로 만드는 최소 횟수
	dp[home][home] = cond(is[home] == 'A', home, 1);
	dp[1][home] = cond(is[home] == 'B', home, 1);

	// dp[0][i] => i번째 분자까지 전부 A로 만드는 최소 횟수
	// 1.i - 1번째 분자까지 전부 A로 만드는 최소 횟수 + i번째 분자가 A면 0 B면 1
	// 2.i - 1번째 분자까지 전부 B로 만드는 최소 횟수 + 1
	// 1, 2 둘중 최솟값으로 업데이트
	loop(i, 1, n)
	{
		dp[home][i] = min(dp[home][i - 1] + cond(is[i] == 'A', home, 1), dp[1][i - 1] + 1);
		dp[1][i] = min(dp[1][i - 1] + cond(is[i] == 'B', home, 1), dp[home][i - 1] + 1);
	}
	elp(dp[home][n - 1]);

	return home;
}