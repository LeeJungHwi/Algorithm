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

// 미로 만들기
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	int n; cin >> n; dir;
	int curI, curJ, minI, minJ, maxI, maxJ, curDir = 1;
	map<pii, int> p; p[{49, 49}]++;
	curI = curJ = minI = minJ = maxI = maxJ = 49;
	char o;
	loop(i, home, n)
	{
		cin >> o;
		if (o == 'F')
		{
			p[{curI += cd[curDir].lhs, curJ += cd[curDir].rhs}]++;
			minI = min(minI, curI); minJ = min(minJ, curJ);
			maxI = max(maxI, curI); maxJ = max(maxJ, curJ);
			continue;
		}
		if (curDir == home) curDir = cond(o == 'L', 2, 3);
		else if (curDir == 1) curDir = cond(o == 'L', 3, 2);
		else if (curDir == 2) curDir = cond(o == 'L', 1, home);
		else if (curDir == 3) curDir = cond(o == 'L', home, 1);
	}
	mat(char, graph, 100, 100);
	loop(i, minI, maxI + 1)
	{
		loop(j, minJ, maxJ + 1)
		{
			if (p[{i, j}]) p('.');
			else p('#');
		}
		elp("");
	}

	return home;
}