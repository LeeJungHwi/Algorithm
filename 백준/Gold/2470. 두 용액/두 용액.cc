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

int ans = 2147000000;

bool Check(int &s, vector<int> &v)
{
	// 두 용액 합의 절대값이 더 작으면 가능한경우
	return abs(s) < abs(ans);
}

// 두 용액
int main()
{
	init;

	int n; cin >> n;
	vec(int, v, n);
	loop(i, home, n) cin >> v[i];
	sort(all(v));

	// lo => 0
	// hi => n - 1
	// 두 용액 합의 절대값의 최솟값

	int l = home, h = n - 1;
	int lValue, rValue;

	while (l < h)
	{
		int s = v[l] + v[h];

		if (Check(s, v))
		{
			ans = s;
			lValue = v[l];
			rValue = v[h];
		}
		
		// 두 용액 합이 음수면 lhs를 증가시켰을때 0에 더 가까워지는지 탐색
		if (s < home) l++;
		else h--;
	}
	scp(lValue);
	elp(rValue);

	return home;
}