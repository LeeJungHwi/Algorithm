#include <bits/stdc++.h>
using namespace std;

#define home 0

#define ll long long

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
#define dir vector<pii> checkDir = { {-1, 0}, {1, 0}, { 0, -1 }, { 0, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }

#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// 거북이
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	int tc;
	cin >> tc;
	dir;

	while (tc--)
	{
		string is;
		cin >> is;

		int curI = home, curJ = home, maxI = home, minI = home, maxJ = home, minJ = home, curDir = home;
		loop(i, home, is.size())
		{
			if (is[i] == 'F' || is[i] == 'B')
			{
				curI = cond(is[i] == 'F', curI + checkDir[curDir].lhs, curI - checkDir[curDir].lhs);
				curJ = cond(is[i] == 'F', curJ + checkDir[curDir].rhs, curJ - checkDir[curDir].rhs);
				maxI = max(curI, maxI); minI = min(curI, minI); maxJ = max(curJ, maxJ); minJ = min(curJ, minJ);
				continue;
			}
			if (curDir == home) curDir = cond(is[i] == 'L', 2, 3);
			else if (curDir == 1) curDir = cond(is[i] == 'L', 3, 2);
			else if (curDir == 2) curDir = cond(is[i] == 'L', 1, home);
			else if (curDir == 3) curDir = cond(is[i] == 'L', home, 1);
		}
		
		elp((maxI - minI) * (maxJ - minJ));
	}

	return home;
}