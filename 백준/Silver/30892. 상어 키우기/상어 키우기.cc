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

// 상어 키우기
int main()
{
	init;

	int n, k; cin >> n >> k;
	ll t; cin >> t;
	vec(int, sz, n);
	loop(i, home, n) cin >> sz[i];
	sort(all(sz));

	// 1 5 10 15 24 => 15
	// 1 10 15 24 => 25
	// 1 15 24 => 49
	ll curSz = t;
	stack<int> s;
	queue<int> q;
	int cnt = home;
	loop(i, home, n)
	{
		if (sz[i] < curSz) s.push(sz[i]);
		else q.push(sz[i]);
	}

	// 1 5 : 10 15 24 => 15
	// 1 10 : 15 24 => 25
	// 1 15 24 : empty => 49
	loop(i, home, k)
	{
		if (!s.empty())
		{
			curSz += s.top();
			s.pop();

			while (curSz > q.front())
			{
				if (q.empty()) break;

				s.push(q.front());
				q.pop();
			}
		}
	}
	elp(curSz);

	return home;
}