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

// 암호해독기
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	map<int, char> fMap;
	map<char, int> sMap;
	fMap[0] = ' ';
	fMap[1] = 'A';
	loop(i, 2, 27) fMap[i] = fMap[1] + i - 1;
	fMap[27] = 'a';
	loop(i, 28, 53) fMap[i] = fMap[27] + i - 27;
	//mloop(it, fMap) scp(it->second);
	int n;
	cin >> n;
	int num;
	loop(i, home, n)
	{
		cin >> num;
		sMap[fMap[num]]++;
	}
	cin.ignore();
	string is;
	getline(cin, is);
	map<char, int> tMap;
	loop(i, home, is.size()) tMap[is[i]]++;
	mloop(it, tMap) if (it->second > sMap[it->first]) { elp('n'); return home; }
	elp('y');

	return home;
}