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

// 수들의 합 2
int main()
{
	init;

	// 누적합 + 투포인터
	int n, m; cin >> n >> m;
	vec(int, pV, n); cin >> pV[home];
	int num;
	loop(i, 1, n)
	{
		cin >> num;
		pV[i] = pV[i - 1] + num;
	}
	// pV => 1 2 3 4

	int ans = home;
	loop(i, home, n)
	{
		if (pV[i] == m) ans++;

		loop(j, i + 1, n)
		{
			if (pV[j] - pV[i] == m) ans++;
		}
	}
	// 0 => 1 1 2 3
	// 1 => 2 1 2
	// 2 => 3 1
	// 3 => 4
	elp(ans);

	return home;
}