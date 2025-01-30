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

// 최소비용 구하기 2
int main()
{
	init;

	int n, m; cin >> n >> m;
	gmat(pii, graph, n);
	int v1, v2, c;
	loop(i, home, m)
	{
		cin >> v1 >> v2 >> c;
		graph[--v1].push_back({ --v2, c });
	}

	int s, e; cin >> s >> e; s--; e--;

	vector<int> dis(n, 2147000000);
	vector<int> parent(n, -1); // 경로 트랰
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	dis[s] = home;
	pq.push({ home, s }); // rhs번 도시까지 가는 최소비용 lhs
	while (!pq.empty())
	{
		pii st = pq.top();
		pq.pop();

		// 이미 더 적은비용으로 방문 가능하면 X
		if (st.lhs > dis[st.rhs]) continue;

		// 현재도시에서 갈수있는 도시를 보면서
		loop(i, home, graph[st.rhs].size())
		{
			// 갈수있는 도시 번호, 비용
			int ch = graph[st.rhs][i].lhs;
			int co = graph[st.rhs][i].rhs;

			// 이미 더 적은비용으로 방문 가능하면 X
			if (dis[st.rhs] + co >= dis[ch]) continue;

			// 더 적은비용으로 갈수있는 도시 방문
			dis[ch] = dis[st.rhs] + co;
			parent[ch] = st.rhs;
			pq.push({ dis[ch], ch });
		}
	}

	// 최소비용
	elp(dis[e]);

	// 경로 트랰
	tvec(int, path);
	for (int i = e; i != -1; i = parent[i]) path.push_back(i + 1);
	reverse(path.begin(), path.end());

	// 방문한 도시 수
	elp(path.size());

	// 경로
	loop(i, home, path.size()) scp(path[i]);
	cout << '\n';

	return home;
}
