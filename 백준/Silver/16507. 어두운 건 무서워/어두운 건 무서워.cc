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

// 어두운 건 무서워
int main()
{
	init;

	int n, m, q; cin >> n >> m >> q;
	mat(int, graph, n + 1, m + 1);
	mat(int, prefixSum, n + 1, m + 1);
	loop(i, 1, n + 1) loop(j, 1, m + 1)
	{
		cin >> graph[i][j];
		prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + graph[i][j];
	}
	int n1, m1, n2, m2;
	loop(i, home, q)
	{
		cin >> n1 >> m1 >> n2 >> m2;
		cout << (prefixSum[n2][m2] - prefixSum[n2][m1 - 1] - prefixSum[n1 - 1][m2] + prefixSum[n1 - 1][m1 - 1]) / ((n2 - n1 + 1) * (m2 - m1 + 1)) << '\n';
	}

	return home;
}