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

// 무엇을 아느냐가 아니라 누구를 아느냐가 문제다
int main()
{
	init;

	// 0(한신이) -> m-1(최고의원)까지 다익스트라 경로 추적
	// 갈 수 없으면 -1

	int tc; cin >> tc;

	int cur = 1;
	while (tc--)
	{
		int n, m; cin >> n >> m;
		gmat(pii, graph, m);
		vector<int> parent(m, -1);
		int v1, v2, c;
		loop(i, home, n)
		{
			cin >> v1 >> v2 >> c;
			graph[v1].push_back({ v2, c });
			graph[v2].push_back({ v1, c });
		}
		vector<int> dis(m, 2147000000);

		priority_queue<pii, vector<pii>, greater<pii>> pq;
		pq.push({ home, home });
		dis[home] = home;

		while (!pq.empty())
		{
			int sp = pq.top().rhs;
			int sc = pq.top().lhs;
			pq.pop();

			if (dis[sp] < sc) continue;

			loop(i, home, graph[sp].size())
			{
				int cp = graph[sp][i].lhs;
				int cc = graph[sp][i].rhs;

				if (dis[cp] <= dis[sp] + cc) continue;

				dis[cp] = dis[sp] + cc;
				pq.push({ dis[cp], cp });
				parent[cp] = sp;
			}
		}

		p("Case #"); p(cur++); scp(':');

		// 갈 수 없으면 -1
		if (dis[m - 1] == 2147000000) { elp(-1); return home; }

		// 갈 수 있으면 경로 출력
		tvec(int, path);
		int cur = m - 1;
		while (cur != home)
		{
			path.push_back(cur);
			cur = parent[cur];
		}
		path.push_back(home);
		reverse(all(path));
		loop(i, home, path.size()) scp(path[i]);
		elp(' ');
	}

	return home;
}