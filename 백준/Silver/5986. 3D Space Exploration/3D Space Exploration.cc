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
#define tiii tuple<int, int, int>

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

#define dir vector<tuple<int, int, int> > cd = { {-1, home, home}, {1, home, home}, { home, -1, home }, { home, 1, home }, { home, home, -1 }, { home, home, 1 } }
#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// 3D Space Exploration
int main()
{
	init;

	int n; cin >> n;
	vector<vector<vector<char> > > graph(n, vector<vector<char> >(n, vector<char>(n)));
	queue<tiii> cp; dir;
	tvec(tiii, sPos);
	loop(i, home, n) loop(j, home, n) loop(k, home, n)
	{
		cin >> graph[i][j][k];
		if (graph[i][j][k] == '*') sPos.push_back({ i, j, k });
	}
	int ans = home;
	loop(i, home, sPos.size())
	{
		if (graph[get<home>(sPos[i])][get<1>(sPos[i])][get<2>(sPos[i])] == '.') continue;
		cp.push({ get<home>(sPos[i]), get<1>(sPos[i]), get<2>(sPos[i]) });
		graph[get<home>(sPos[i])][get<1>(sPos[i])][get<2>(sPos[i])] = '.';
		++ans;
		while (!cp.empty())
		{
			tiii s = cp.front(); cp.pop();
			loop(j, home, 6)
			{
				int ci = get<home>(s) + get<home>(cd[j]);
				int cj = get<1>(s) + get<1>(cd[j]);
				int ck = get<2>(s) + get<2>(cd[j]);
				if (ci < home || cj < home || ck < home || ci >= n || cj >= n || ck >= n) continue;
				if (graph[ci][cj][ck] == '.') continue;
				cp.push({ ci, cj, ck });
				graph[ci][cj][ck] = '.';
			}
		}
	}
	elp(ans);

	return home;
}