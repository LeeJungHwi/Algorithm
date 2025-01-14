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

bool comp(const pii & p1, const pii & p2)
{
	if (p1.second != p2.second) return p1.second > p2.second;
	return p1.first < p2.first;
}

//  중간고사 채점
int main()
{
	init;

	int n, m; cin >> n >> m;
	vec(int, test, n);
	loop(i, home, n) cin >> test[i];
	vec(pii, tester, m);

	loop(i, home, m)
	{
		cin >> tester[i].first;
		int score = home;
		char c;
		loop(j, home, n)
		{
			cin >> c;
			if (c == 'O') score += test[j];
		}
		tester[i].second = score;
	}
	sort(tester.begin(), tester.end(), comp);

	cout << tester[home].first << ' ' << tester[home].second << '\n';

	return home;
}