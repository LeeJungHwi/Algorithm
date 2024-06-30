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

vector<pii> deserterPos;
vec(bool, vis, 5);
map<pii, int> aMap;
int tollGateCost, deserterCnt;
int ans = MAX;

struct TollGate
{
	int lhs, rhs, cost;

	TollGate() {}
	TollGate(int l, int r, int c) : lhs(l), rhs(r), cost(c) {}

	bool operator<(const TollGate &tollGate)const { return cost > tollGate.cost; }
};

void DFS(int L)
{
	// 마지막 탈영병 잡고 부대로 복귀
	if (deserterCnt == deserterPos.size()) { ans = min(ans, tollGateCost + aMap[{home, L}]); return; }

	loop(i, 1, deserterPos.size() + 1)
	{
		if (vis[i - 1]) continue;

		vis[i - 1] = true;
		tollGateCost += aMap[{L, i}];
		deserterCnt += 1;
		DFS(i);
		deserterCnt -= 1;
		tollGateCost -= aMap[{L, i}];
		vis[i - 1] = false;
	}
}

// 군탈체포조
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	int n;
	cin >> n;
	mat(int, graph, n, n);
	mat(int, dis, n, n);
	priority_queue<TollGate> cp;
	dir;
	loop(i, home, n) loop(j, home, n)
	{
		cin >> graph[i][j];
		dis[i][j] = MAX;

		// 부대 비용 0으로
		if (graph[i][j] == home) deserterPos.push_back({ i, j });
		else if (graph[i][j] == -1) { cp.push(TollGate(i, j, home)); graph[i][j] = dis[i][j] = home; }
	}

	// 부대 <-> 탈영병 메모
	while (!cp.empty())
	{
		TollGate s = cp.top(); cp.pop();
		if (s.cost > dis[s.lhs][s.rhs]) continue;
		loop(i, home, 4)
		{
			int ci = s.lhs + cd[i].lhs;
			int cj = s.rhs + cd[i].rhs;
			if (ci < home || cj < home || ci >= n || cj >= n) continue;
			if (dis[ci][cj] <= dis[s.lhs][s.rhs] + graph[ci][cj]) continue;
			dis[ci][cj] = dis[s.lhs][s.rhs] + graph[ci][cj];
			cp.push(TollGate(ci, cj, dis[ci][cj]));
		}
	}
	loop(i, home, deserterPos.size()) aMap[{home, i + 1}] = dis[deserterPos[i].lhs][deserterPos[i].rhs];

	// 탈영병 <-> 탈영병 메모
	loop(i, home, deserterPos.size())
	{
		loop(j, home, n) loop(k, home, n) dis[j][k] = MAX;
		cp.push(TollGate(deserterPos[i].lhs, deserterPos[i].rhs, home));
		dis[deserterPos[i].lhs][deserterPos[i].rhs] = home;
		while (!cp.empty())
		{
			TollGate s = cp.top(); cp.pop();
			if (s.cost > dis[s.lhs][s.rhs]) continue;
			loop(j, home, 4)
			{
				int ci = s.lhs + cd[j].lhs;
				int cj = s.rhs + cd[j].rhs;
				if (ci < home || cj < home || ci >= n || cj >= n) continue;
				if (dis[ci][cj] <= dis[s.lhs][s.rhs] + graph[ci][cj]) continue;
				dis[ci][cj] = dis[s.lhs][s.rhs] + graph[ci][cj];
				cp.push(TollGate(ci, cj, dis[ci][cj]));
			}
		}
		loop(j, home, deserterPos.size()) aMap[{i + 1, j + 1}] = dis[deserterPos[j].lhs][deserterPos[j].rhs];
	}

	// 탈영병 없을 때
	if (deserterPos.empty()) { elp(home); return home; }

	// 재사용
	DFS(home);
	elp(ans);

	return home;
}