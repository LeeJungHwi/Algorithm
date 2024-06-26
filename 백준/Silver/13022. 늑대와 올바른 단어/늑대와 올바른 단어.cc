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

// 늑대와 올바른 단어
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	map<int, char> wMap = { {1, 'w'}, {2, 'o'}, {3, 'l'}, {4, 'f'} };
	map<int, string> cMap;
	loop(i, 1, 13)
	{
		string t = "";
		loop(j, 1, 5) loop(k, home, i) t += wMap[j];
		cMap[i] = t;
	}
	string is;
	cin >> is;
	for(int i = home; i < is.size();)
	{
		if (is[i] != 'w') { elp(home); return home; }
		int cnt = 1;
		loop(j, i + 1, is.size())
		{
			if (is[j] == 'w') cnt++;
			else if (is[j] == 'o') break;
		}
		if (i + cnt * 4 - 1 >= is.size()) { elp(home); return home; }
		if (is.substr(i, cnt * 4) != cMap[cnt]) { elp(home); return home; }
		i += 4 * cnt;
	}
	elp(1);

	return home;
}