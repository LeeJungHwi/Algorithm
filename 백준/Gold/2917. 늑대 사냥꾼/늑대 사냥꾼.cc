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

struct Hyun
{
	int lhs, rhs, cost;

	Hyun() {}
	Hyun(int l, int r, int c) : lhs(l), rhs(r), cost(c) {}

	bool operator<(const Hyun &hyun)const { return cost < hyun.cost; }
};

// 늑대 사냥꾼
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	int n, m;
	cin >> n >> m;
	mat(char, graph, n, m);
	mat(int, dis, n, m);
	queue<pii> cp;
	dir;
	pii sPos, ePos;
	vector<pii> tPos;
	loop(i, home, n) loop(j, home, m)
	{
		cin >> graph[i][j];
		dis[i][j] = MAX;
		if (graph[i][j] == 'V') sPos = { i, j };
		else if (graph[i][j] == 'J') ePos = { i, j };
		else if (graph[i][j] == '+') tPos.push_back({ i, j });
	}
	loop(i, home, tPos.size())
	{
		cp.push(tPos[i]);
		dis[tPos[i].lhs][tPos[i].rhs] = 1;
		while (!cp.empty())
		{
			pii s = cp.front(); cp.pop();
			loop(j, home, 4)
			{
				int ci = s.lhs + cd[j].lhs;
				int cj = s.rhs + cd[j].rhs;
				if (ci < home || cj < home || ci >= n || cj >= m) continue;
				if (dis[ci][cj] <= dis[s.lhs][s.rhs] + 1) continue;
				cp.push({ ci, cj });
				dis[ci][cj] = dis[s.lhs][s.rhs] + 1;
			}
		}
	}
	//for (auto a : dis)
	//{
	//	for (auto b : a)
	//	{
	//		scp(b);
	//	}
	//	elp("");
	//}

	mat(int, hDis, n, m);
	loop(i, home, n) loop(j, home, m) hDis[i][j] = MAX;
	priority_queue<Hyun> cpq;
	cpq.push(Hyun(sPos.lhs, sPos.rhs, dis[sPos.lhs][sPos.rhs]));
	hDis[sPos.lhs][sPos.rhs] = dis[sPos.lhs][sPos.rhs];
	int ans = min(dis[sPos.lhs][sPos.rhs], dis[ePos.lhs][ePos.rhs]);
	while (!cpq.empty())
	{
		Hyun s = cpq.top(); cpq.pop();
		if (s.cost > hDis[s.lhs][s.rhs]) continue;
		ans = min(ans, dis[s.lhs][s.rhs]);
		if (s.lhs == ePos.lhs && s.rhs == ePos.rhs) break;
		loop(i, home, 4)
		{
			int ci = s.lhs + cd[i].lhs;
			int cj = s.rhs + cd[i].rhs;
			if (ci < home || cj < home || ci >= n || cj >= m) continue;
			if (hDis[ci][cj] <= dis[s.lhs][s.rhs] + dis[ci][cj]) continue;
			hDis[ci][cj] = dis[s.lhs][s.rhs] + dis[ci][cj];
			cpq.push(Hyun(ci, cj, hDis[ci][cj]));
		}
	}
	elp(ans - 1);

	return home;
}