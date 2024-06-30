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

vector<pii> storePos;
vec(bool, vis, 20);
map<pii, int> sMap;
int moveCnt, storeCnt;
int ans = MAX;

void DFS(int L)
{
	if (storeCnt == 5) { ans = min(ans, moveCnt); return; }

	loop(i, 1, storePos.size() + 1)
	{
		if (vis[i - 1]) continue;
		if (sMap[{L, i}] == -1) continue;

		vis[i - 1] = true;
		moveCnt += sMap[{L, i}];
		storeCnt += 1;
		DFS(i);
		storeCnt -= 1;
		moveCnt -= sMap[{L, i}];
		vis[i - 1] = false;
	}
}

// 포항항
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
	loop(i, home, n) loop(j, home, m)
	{
		cin >> graph[i][j];
		if (graph[i][j] == 'S') { cp.push({ i, j }); dis[i][j] = 1; }
		else if (graph[i][j] == 'K') storePos.push_back({ i, j });
	}

	// 현재 위치 <-> 식당 메모
	while (!cp.empty())
	{
		pii s = cp.front(); cp.pop();
		loop(i, home, 4)
		{
			int ci = s.lhs + cd[i].lhs;
			int cj = s.rhs + cd[i].rhs;
			if (ci < home || cj < home || ci >= n || cj >= m) continue;
			if (dis[ci][cj] > home) continue;
			if (graph[ci][cj] == 'X') continue;
			cp.push({ ci, cj });
			dis[ci][cj] = dis[s.lhs][s.rhs] + 1;
		}
	}
	int cnt = home;
	loop(i, home, storePos.size())
	{
		sMap[{home, i + 1}] = dis[storePos[i].lhs][storePos[i].rhs] - 1;
		if (sMap[{home, i + 1}] == -1) cnt++;
	}

	// 5개 이상 방문 할 수 없으면
	if (storePos.size() - cnt < 5) { elp(-1); return home; }

	// 식당 <-> 식당 메모
	loop(i, home, storePos.size())
	{
		loop(j, home, n) loop(k, home, m) dis[j][k] = home;
		cp.push(storePos[i]);
		dis[storePos[i].lhs][storePos[i].rhs] = 1;
		while (!cp.empty())
		{
			pii s = cp.front(); cp.pop();
			loop(j, home, 4)
			{
				int ci = s.lhs + cd[j].lhs;
				int cj = s.rhs + cd[j].rhs;
				if (ci < home || cj < home || ci >= n || cj >= m) continue;
				if (dis[ci][cj] > home) continue;
				if (graph[ci][cj] == 'X') continue;
				cp.push({ ci, cj });
				dis[ci][cj] = dis[s.lhs][s.rhs] + 1;
			}
		}
		loop(j, home, storePos.size()) sMap[{i + 1, j + 1}] = dis[storePos[j].lhs][storePos[j].rhs] - 1;
	}

	// 재사용
	DFS(home);
	elp(ans);

	return home;
}