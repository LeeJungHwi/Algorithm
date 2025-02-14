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

// 두 배 더하기
int main()
{
	init;

	// 최종 상태에서 원본 상태로 변환

	int n; cin >> n;
	vec(int, v, n);
	loop(i, home, n) cin >> v[i];

	int ans = home, zeroCnt = home;
	while (true)
	{
		zeroCnt = home;
		loop(i, home, v.size())
		{
			// 홀수값 -1
			if (v[i] % 2 == 1)
			{
				ans++;
				v[i]--;
			}

			if (v[i] == home) zeroCnt++;
		}

		// B를 A로 만든경우
		if (zeroCnt == n) { elp(ans); return home; }

		// 아직 A로 만들지 못 한 경우 /2
		loop(i, home, v.size()) v[i] /= 2;

		ans++;
	}

	return home;
}