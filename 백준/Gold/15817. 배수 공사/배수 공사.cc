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

// 배수 공사
int main()
{
	init;

	int n, m; cin >> n >> m;

	vec(pii, pipe, n);
	loop(i, home, n) cin >> pipe[i].lhs >> pipe[i].rhs;

	vec(int, dp, m + 1); // dp[i] => 길이 i를 만들 수 있는 방법의 수
	dp[home] = 1;

	loop(i, home, n)
	{
		int len = pipe[i].lhs;
		int cnt = pipe[i].rhs;

		// 아이템 개수 제한 => 역순 냅색
		rloop(j, m, -1)
		{
			// j원을 만드는 방법이 없으면 X
			if (dp[j] == home) continue;

			// 1~최대 개수까지 사용
			loop(k, 1, cnt + 1)
			{
				// k개 사용했을때 길이
				int cLen = j + len * k;

				// m을 넘기면 X
				if (cLen > m) break;

				// 길이 j를 만드는 방법의 수 누적
				dp[cLen] += dp[j];
			}
		}
	}
	elp(dp[m]);

	return home;
}