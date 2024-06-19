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
const int MIN = -2147000000;

// 모래성
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	int n, m;
	cin >> n >> m;
	mat(int, graph, n, m);
	mat(bool, vis, n, m);
	queue<pii> checkPos;
	dir;
	string is;
	loop(i, 0, n)
	{
		cin >> is;
		loop(j, 0, is.size())
		{
			if (is[j] == '.')
			{
				graph[i][j] = -1;
				checkPos.push({ i, j });
				vis[i][j] = true;
				continue;
			}
			graph[i][j] = is[j] - '0';
		}
	}

	int cur = 0;
	while (!checkPos.empty())
	{
		int sz = checkPos.size();
		loop(i, 0, sz)
		{
			pii standard = checkPos.front();
			checkPos.pop();

			loop(j, 0, 8)
			{
				int ci = standard.lhs + checkDir[j].lhs;
				int cj = standard.rhs + checkDir[j].rhs;

				if (ci < 0 || cj < 0 || ci >= n || cj >= m) continue;
				if (vis[ci][cj]) continue;
				if (--graph[ci][cj]) continue;

				checkPos.push({ ci, cj });
				vis[ci][cj] = true;
			}
		}
		//for (auto a : graph)
		//{
		//	for (auto b : a)
		//	{
		//		scp(b);
		//	}
		//	elp("");
		//}
		cur++;
	}
	elp(--cur);

	return home;
}