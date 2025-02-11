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

// 캡틴 이다솜
int main()
{
	init;

	int n; cin >> n;

	// 1 4 10 20 35 56 ...
	vec(int, v, 121);
	v[1] = 1;
	loop(i, 2, 121) v[i] = v[i - 1] + i;
	loop(i, 2, 121) v[i] = v[i - 1] + v[i];
	//loop(i, 1, 6) scp(v[i]);

	vec(int, dp, n + 1); // dp[i] => i개의 대포알로 만들 수 있는 사면체의 최소 개수
	loop(i, 1, n + 1) dp[i] = i; // 모두 1개 사면체로만 대포알을 가지고있을때
	loop(i, 1, 121)
	{
		loop(j, v[i], n + 1)
		{
			// 기존 dp값과 현재 정사면체를 사용하지않았을때의 최소개수 + 1(현재 정사면체 사용) 중 최솟값으로 업데이트
			dp[j] = min(dp[j], dp[j - v[i]] + 1);
		}
	}
	elp(dp[n]);

	return home;
}