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

// 색상환
int main()
{
	init;

	// 현재 색을 선택하거나 안 하거나
	// 원형으로 연결 => 마지막 색 고려
	int n, k; cin >> n >> k;

	if (k > n / 2) { elp(home); return home; }

	mat(int, dp, n + 1, k + 1); // dp[i][j] => i개의 색 중에서 j개의 색을 선택하는 경우의 수

	loop(i, 1, n + 1)
	{
		dp[i][home] = 1; // 선택하지 않는 경우 1
		dp[i][1] = i; // i개의 색 중 하나를 선택하는 경우의 수
	}

	loop(i, 2, n + 1)
	{
		loop(j, 2, k + 1)
		{
			// dp[i - 1][j] => 현재 색을 선택하지 않고 남은 색 i - 1개에서 j개 선택하는 경우의 수
			// dp[i - 2][j - 1] => 현재 색을 선택한 경우 i - 1번 색은 사용할 수 없으므로 남은 i - 2개 색 중 j - 1개를 선택해야함
			dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % 1000000003;
		}
	}

	// dp[n - 1][k] => 마지막 색을 선택하지 않고 남은색 n - 1개에서 k개 선택하는 경우의 수
	// dp[n - 3][k - 1] => 마지막 색을 선택한 경우 처음 색과 n - 1번 색은 사용할 수 없으므로 남은 n - 3개 색 중 k - 1개를 선택해야함
	elp((dp[n - 1][k] + dp[n - 3][k - 1]) % 1000000003);

	return home;
}