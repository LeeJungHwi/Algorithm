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
#define piii pair<int, pii>
#define pll pair<ll, ll>
#define plll pair<ll, pll>

#define loop(v, s, e) for(int v = (s); v < (e); v++)
#define rloop(v, s, e) for(int v = (s); v > (e); v--)
#define mloop(v, a) for(auto v = (a).begin(); v != (a).end(); v++)
#define mrloop(v, a) for(auto v = (a).rbegin(); v != (a).rend(); v++)

#define p(a) cout << (a)
#define elp(a) cout << (a) << '\n'
#define scp(a) cout << (a) << ' '

#define tvec(t, v) vector<t> v
#define vec(t, v, r) vector<t> v((r))
#define ivec(t, v, r, i) vector<t> v((r), i)
#define gmat(t, v, r) vector<vector<t> > v((r))
#define mat(t, v, r, c) vector<vector<t> > v((r), vector<t>((c)))
#define imat(t, v, r, c, i) vector<vector<t> > v((r), vector<t>((c), i))
#define smat(t, v, r, c, s) vector<vector<vector<t> > > v((r), vector<vector<t>>((c), vector<t>((s))))
#define ismat(t, v, r, c, s, i) vector<vector<vector<t> > > v((r), vector<vector<t>>((c), vector<t>((s), i)))
#define ssmat(t, v, r, c, s1, s2) vector<vector<vector<vector<t> > > > v((r), vector<vector<vector<t>>>((c), vector<vector<t>>((s1), vector<t>((s2)))))
#define issmat(t, v, r, c, s1, s2, i) vector<vector<vector<vector<t> > > > v((r), vector<vector<vector<t>>>((c), vector<vector<t>>((s1), vector<t>((s2), i))))
#define sssmat(t, v, r, c, s1, s2, s3) vector<vector<vector<vector<vector<t> > > > > v((r), vector<vector<vector<vector<t>>>>((c), vector<vector<vector<t>>>((s1), vector<vector<t>>((s2), vector<t>((s3))))))
#define isssmat(t, v, r, c, s1, s2, s3, i) vector<vector<vector<vector<vector<t> > > > > v((r), vector<vector<vector<vector<t>>>>((c), vector<vector<vector<t>>>((s1), vector<vector<t>>((s2), vector<t>((s3), i)))))

#define dir vector<pii> cd = { {-1, home}, {1, home}, { home, -1 }, { home, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }
#define kdir vector<pii> kcd = { {-1, -2}, {-2, -1}, { -2, 1 }, { -1, 2 }, { 1, -2 }, { 2, -1 }, { 1, 2 }, { 2, 1 } }
#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// 파스칼 삼각형
int main()
{
	init;

	/*
	1 
	1 1
	1 2 1
	1 3 3 1
	1 4 6 4 1
	1 5 10 10 5 1
	1 6 15 20 15 6 1
	1 7 21 35 35 21 7 1
	*/
	mat(int, graph, 30, 30);
	loop(i, home, 30)
	{
		graph[i][home] = 1;
		graph[i][i] = 1;
	}
	loop(i, 2, 30) loop(j, 1, i) graph[i][j] = graph[i - 1][j - 1] + graph[i - 1][j];

	int r, c, w; cin >> r >> c >> w; r--; c--;

	int ans = home;
	loop(i, r, r + w) loop(j, c, c + (i - r) + 1) ans += graph[i][j];
	elp(ans);

	return home;
}