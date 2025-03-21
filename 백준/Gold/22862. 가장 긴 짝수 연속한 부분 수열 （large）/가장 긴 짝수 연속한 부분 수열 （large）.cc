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

// 가장 긴 짝수 연속한 부분 수열 (large)
int main()
{
	init;

	// 최대 k개의 홀수를 갖는 배열 찾기
	int n, k; cin >> n >> k;
	vec(int, v, n);
	loop(i, home, n) cin >> v[i];

	int ans = home, l = home, h = home, cnt = home;
	while (h <= n - 1)
	{
		// 홀수 개수가 k개 초과
		if (cnt > k)
		{
			if (v[l] % 2 == 1) cnt--;
			l++;
		}
		// 홀수 개수가 k개 이하
		else
		{
			if (v[h] % 2 == 1) cnt++;
			h++;

			// 짝수 개수 = 구간 길이 - 홀수 개수
			ans = max(ans, h - l - cnt);
		}
	}
	elp(ans);

	return home;
}