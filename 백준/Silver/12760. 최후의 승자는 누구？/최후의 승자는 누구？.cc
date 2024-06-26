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

// 최후의 승자는 누구?
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	int n, m;
	cin >> n >> m;
	mat(int, graph, n, m);
	loop(i, home, n) loop(j, home, m) cin >> graph[i][j];
	loop(i, home, n) sort(rall(graph[i]));
	map<int, int> pMap;
	int ansP = MIN;
	loop(i, home, m)
	{
		vector<int> maxP;
		int maxN = MIN;
		loop(j, home, n)
		{
			if (maxN < graph[j][i])
			{
				maxP.clear();
				maxP.push_back(j + 1);
				maxN = graph[j][i];
			}
			else if (maxN == graph[j][i]) maxP.push_back(j + 1);
		}
		loop(j, home, maxP.size()) ansP = max(ansP, ++pMap[maxP[j]]);
	}
	mloop(it, pMap) if (it->second == ansP) scp(it->first);

	return home;
}