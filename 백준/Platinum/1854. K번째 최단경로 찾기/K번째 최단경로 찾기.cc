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

// K번째 최단경로 찾기
int main()
{
	init;

	// 1번 도시부터 1~n번 도시까지의 k번째 최단경로
	// 각 도시에 대해 최대힙 유지

	int n, m, k; cin >> n >> m >> k;
	gmat(pii, graph, n);
	int v1, v2, c;
	loop(i, home, m)
	{
		cin >> v1 >> v2 >> c;
		graph[--v1].push_back({ --v2, c });
	}

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vec(priority_queue<int>, dis, n); // 각 도시에 대해 최대힙 유지

	pq.push({ home, home });
	dis[home].push(home);

	while (!pq.empty())
	{
		int sp = pq.top().rhs;
		int sc = pq.top().lhs;
		pq.pop();

		loop(i, home, graph[sp].size())
		{
			int cp = graph[sp][i].lhs;
			int cc = graph[sp][i].rhs;

			// k번째 최단거리가 없으면 그냥 저장
			if (dis[cp].size() < k)
			{
				dis[cp].push(sc + cc);
				pq.push({ sc + cc, cp });
				continue;
			}

			// k개가 있으면 더 작은값이 들어올 때 저장
			if (sc + cc < dis[cp].top())
			{
				dis[cp].pop();
				dis[cp].push(sc + cc);
				pq.push({ sc + cc, cp });
			}
		}
	}

	loop(i, home, n) elp(cond(dis[i].size() < k, -1, dis[i].top()));

	return home;
}