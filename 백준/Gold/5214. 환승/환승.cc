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

// 환승
int main()
{
	init;

	int n, k, m; cin >> n >> k >> m;
	gmat(int, station, n); // 각 역에서 연결된 하이퍼튜브
	gmat(int, hyper, m); // 각 하이퍼튜브에서 연결된 역
	vec(int, dis, n);
	int v;
	loop(i, home, m)
	{
		loop(j, home, k)
		{
			cin >> v;
			station[--v].push_back(i);
			hyper[i].push_back(v);
		}
	}

	queue<int> q;
	q.push(home);
	dis[home] = 1;

	while (!q.empty())
	{
		int sp = q.front();
		q.pop();

		// 현재 역과 연결된 하이퍼튜브
		loop(i, home, station[sp].size())
		{
			// 해당 하이퍼튜브와 연결된 역
			loop(j, home, hyper[station[sp][i]].size())
			{
				int cp = hyper[station[sp][i]][j];

				if (dis[cp] > home) continue;

				dis[cp] = dis[sp] + 1;
				q.push(cp);
			}
		}
	}
	elp(cond(dis[n - 1] == home, -1, dis[n - 1]));

	return home;
}