#include <bits/stdc++.h>
using namespace std;

#define home 0

#define ll long long

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
#define dir vector<pii> checkDir = { {-1, 0}, {1, 0}, { 0, -1 }, { 0, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }

#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()

const int MAX = 2147000000;
const int MIN = 0;

// 바닥 장식
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
	mat(bool, vis, n, m);
	queue<pii> checkPos;
	loop(i, 0, n) loop(j, 0, m) cin >> graph[i][j];
	int cnt = 0;
	loop(i, 0, n) loop(j, 0, m)
	{
		if (!vis[i][j])
		{
			checkPos.push({ i, j });
			vis[i][j] = true;
			bool isH = cond(graph[i][j] == '-', true, false);
			cnt++;

			while (!checkPos.empty())
			{
				pii standard = checkPos.front();
				checkPos.pop();

				int ci = cond(isH, standard.lhs, standard.lhs + 1);
				int cj = cond(isH, standard.rhs + 1, standard.rhs);

				if (ci < 0 || cj < 0 || ci >= n || cj >= m) continue;
				if (vis[ci][cj]) continue;
				if (graph[ci][cj] != graph[standard.lhs][standard.rhs]) continue;

				checkPos.push({ ci, cj });
				vis[ci][cj] = true;
			}
		}
	}
	elp(cnt);

	return home;
}