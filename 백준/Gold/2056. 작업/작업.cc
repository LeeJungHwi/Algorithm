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

// 작업
int main()
{
	init;

	int n; cin >> n;
	gmat(int, graph, n);
	vec(int, directPre, n);
	vec(int, time, n);
	loop(i, home, n)
	{
		int preCnt;
		cin >> time[i] >> preCnt;
		loop(j, home, preCnt)
		{
			int v;
			cin >> v;
			graph[i].push_back(--v);
			directPre[v]++; // v번 작업의 inDegree 카운팅
		}
	}

	queue<int> noPre;
	loop(i, home, n) if (directPre[i] == home) noPre.push(i);

	vec(int, dp, n);
	loop(i, home, n) dp[i] = time[i];
	int ans = time[home];
	while (!noPre.empty())
	{
		int s = noPre.front();
		noPre.pop();

		loop(i, home, graph[s].size())
		{
			int c = graph[s][i];

			dp[c] = max(dp[c], dp[s] + time[c]);

			if (--directPre[c] == home) noPre.push(c);
		}
	}
	loop(i, home, n) ans = max(ans, dp[i]);
	elp(ans);

	return home;
}