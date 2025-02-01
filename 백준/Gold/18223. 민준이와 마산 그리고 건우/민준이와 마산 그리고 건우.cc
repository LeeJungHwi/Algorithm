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

// 민준이와 마산 그리고 건우
int main()
{
	init;

	// 1 -> 마산(V)과 1 -> 건우(P) -> 마산(V) 최단거리가 같아야함
	// 1번 정점부터 다익스트라로 마산(V)까지 최단거리
	// 건우(P) 정점부터 다익스트라로 P -> 1, P -> V 최단거리의 합
	// 위 두개가 같으면 SAVE HIM 아니면 GOOD BYE

	int v, e, p; cin >> v >> e >> p; --p;
	gmat(pii, graph, v);
	int v1, v2, c;
	loop(i, home, e)
	{
		cin >> v1 >> v2 >> c;
		graph[--v1].push_back({--v2, c});
		graph[v2].push_back({ v1, c });
	}

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<int> sDis(v, 2147000000);

	// 1부터 다익스트라
	pq.push({ home, home });
	sDis[home] = home;
	while (!pq.empty())
	{
		pii s = pq.top();
		pq.pop();

		if (s.lhs > sDis[s.rhs]) continue;

		loop(i, home, graph[s.rhs].size())
		{
			if (sDis[graph[s.rhs][i].lhs] <= s.lhs + graph[s.rhs][i].rhs) continue;

			sDis[graph[s.rhs][i].lhs] = s.lhs + graph[s.rhs][i].rhs;
			pq.push({ sDis[graph[s.rhs][i].lhs] , graph[s.rhs][i].lhs });
		}
	}
	//elp(sDis[v - 1]);

	vector<int> pDis(v, 2147000000);

	// p부터 다익스트라
	pq.push({ home, p });
	pDis[p] = home;
	while (!pq.empty())
	{
		pii s = pq.top();
		pq.pop();

		if (s.lhs > pDis[s.rhs]) continue;

		loop(i, home, graph[s.rhs].size())
		{
			if (pDis[graph[s.rhs][i].lhs] <= s.lhs + graph[s.rhs][i].rhs) continue;

			pDis[graph[s.rhs][i].lhs] = s.lhs + graph[s.rhs][i].rhs;
			pq.push({ pDis[graph[s.rhs][i].lhs] , graph[s.rhs][i].lhs });
		}
	}
	//scp(pDis[home]); elp(pDis[v - 1]);

	elp(sDis[v - 1] == pDis[home] + pDis[v - 1] ? "SAVE HIM" : "GOOD BYE");

	return home;
}