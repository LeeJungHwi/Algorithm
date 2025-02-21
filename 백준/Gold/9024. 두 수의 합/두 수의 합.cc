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

int n, k;
int ans = 2147000000;

int Check(int s)
{
	// -1 => 절댓값이 더 작은 경우
	// 0 => 같은 경우
	// 1 => 큰 경우 X
	if (s < ans) return -1;
	else if (s == ans) return home;
	return 1;
}

// 두 수의 합 
int main()
{
	init;

	int tc; cin >> tc;
	while (tc--)
	{
		cin >> n >> k;
		vec(int, v, n);
		loop(i, home, n) cin >> v[i];
		sort(all(v));

		int l = home, h = n - 1, cnt = home;
		ans = 2147000000;

		while (l < h)
		{
			int sum = v[l] + v[h];
			int s = abs(sum - k);

			int res = Check(s);
			if (res == -1)
			{
				// 더 작은 경우
				ans = s;
				cnt = 1;
			}
			else if (res == home)
			{
				// 같은 경우
				cnt++;
			}

			// 두 수의 합이 k보다 작으면 lhs를 증가시켜 더 작은 절댓값이 가능한지 탐색
			if (sum < k) l++;
			else h--;
		}

		elp(cnt);
	}

	return home;
}