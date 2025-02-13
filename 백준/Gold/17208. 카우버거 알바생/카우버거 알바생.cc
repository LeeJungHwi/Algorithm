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

// 카우버거 알바생
int main()
{
	init;

	int n, m, k; cin >> n >> m >> k;

	vec(pii, order, n);
	loop(i, home, n) cin >> order[i].lhs >> order[i].rhs;
	mat(int, dp, m + 1, k + 1); // dp[i][j] => 주방에 치즈버거 i개 감자튀김 j개 있을때 처리할 수 있는 주문 개수 최댓값

	loop(i, home, n)
	{
		// 아이템 개수 제한 => 역순 냅색
		rloop(j, m, order[i].lhs - 1)
		{
			rloop(l, k, order[i].rhs - 1)
			{
				dp[j][l] = max(dp[j][l], dp[j - order[i].lhs][l - order[i].rhs] + 1);
			}
		}
	}
	elp(dp[m][k]);

	return home;
}