#include <bits/stdc++.h>
using namespace std;

#define home 0

#define ll long long
#define ld long double

#define pii pair<int, int>
#define pll pair<ll, ll>

#define loop(v, s, e) for(int v = (s); v < (e); v++)
#define rloop(v, s, e) for(int v = (s); v > (e); v--)
#define mloop(v, a) for(auto v = (a).begin(); v != (a).end(); v++)
#define mrloop(v, a) for(auto v = (a).rbegin(); v != (a).rend(); v++)
#define aloop(t, v, s, c, e, i) for(t v = (s); v c (e); i)

#define p(a) cout << (a)
#define elp(a) cout << (a) << '\n'
#define scp(a) cout << (a) << ' '

#define vec(t, v, r) vector<t> v((r))
#define mat(t, v, r, c) vector<vector<t> > v((r), vector<t>((c)))
#define gmat(t, v, r) vector<vector<t> > v((r))
#define dir vector<pii> cd = { {-1, 0}, {1, 0}, { 0, -1 }, { 0, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }

#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// Binary Counting
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	int n, m;
	cin >> n >> m;
	vector<int> v;
	v.push_back(home);
	v.push_back(1);
	int cur = 2;
	while(v.size() < n * 4 + m)
	{
		int tc = cur++;
		vector<int> tv;
		while (true)
		{
			if(tc / 2 > 1) tv.push_back(tc % 2);
			else { tv.push_back(tc % 2); tv.push_back(1); break; }
			tc /= 2;
		}
		reverse(all(tv));
		loop(j, home, tv.size()) v.push_back(tv[j]);
	}
	loop(i, home, 5) scp(v[m + n * i - 1]);


	return home;
}