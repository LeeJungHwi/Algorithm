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

// 유성
int main()
{
	init;

	int n, m; cin >> n >> m;
	mat(char, graph, n, m);
	tvec(pii, xPos);
	pii d = { 1, home };
	map<int, int> xI, gI;
	loop(i, home, n)
	{
		loop(j, home, m)
		{
			cin >> graph[i][j];

			if (graph[i][j] == 'X')
			{
				xPos.push_back({ i, j });
				xI[j] = i;
			}
			else if (gI[j] == home && graph[i][j] == '#') gI[j] = i;
		}
	}

	// 각 j열에 대해 유성과 땅 사이 최소거리
	int cnt = 2147000000;
	mloop(it, xI) cnt = min(cnt, gI[it->lhs] - it->rhs - 1);
	loop(i, home, xPos.size())
	{
		graph[xPos[i].lhs][xPos[i].rhs] = '.';
		xPos[i].lhs += d.lhs * cnt;
	}
	loop(i, home, xPos.size()) graph[xPos[i].lhs][xPos[i].rhs] = 'X';

	for (auto a : graph)
	{
		for (auto b : a)
		{
			cout << b;
		}
		cout << '\n';
	}
	//cout << cnt << '\n';

	//mloop(it, xI) cout << it->lhs << ' ' << it->rhs << '\n';
	//cout << '\n';
	//mloop(it, gI) cout << it->lhs << ' ' << it->rhs << '\n';

	return home;
}