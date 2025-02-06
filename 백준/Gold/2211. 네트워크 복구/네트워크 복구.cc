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

// 네트워크 복구
int main()
{
	init;

	// 간선 최소화
	// 슈퍼컴퓨터(1번)에서 다른 정점까지 최단거리가 기존보다 길어지면 안됨
	// 연결한 간선 개수와 간선으로 연결된 두 정점 쌍을 모두 출력

	int n, m; cin >> n >> m;
	gmat(pii, graph, n);
	int v1, v2, c;
	loop(i, home, m)
	{
		cin >> v1 >> v2 >> c;
		graph[--v1].push_back({ --v2, c });
		graph[v2].push_back({ v1, c });
	}
	vector<int> dis(n, 2147000000);
	vec(int, parent, n);

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

	elp(n - 1);

	// 1번 정점은 부모가 없음
	// 2번 정점 부터 연결된 부모 정점 출력
	loop(i, 1, parent.size())
	{
		scp(i + 1);
		elp(++parent[i]);
	}

	return home;
}