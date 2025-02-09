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

// 연예인은 힘들어
int main()
{
	init;

	// 지헌 다익스트라
	// 성하 다익스트라
	// 약속장소
	// 1.지헌과 성하의 최단거리의 합이 최소가되는 정점
	// 2.지헌이 최단시간 > 성하 최단시간인 경우 X
	// 3.약속장소가 여러 곳이면 지헌이 최단시간 중 최소가되는 정점
	// 4.3번도 여러 곳이면 번호가 가장 작은 정점

	int n, m; cin >> n >> m;
	gmat(pii, graph, n);
	int v1, v2, c;
	loop(i, home, m)
	{
		cin >> v1 >> v2 >> c;
		graph[--v1].push_back({ --v2, c });
		graph[v2].push_back({ v1, c });
	}

	cin >> v1 >> v2; --v1; --v2;

	vector<int> jDis(n, 2147000000), sDis(n, 2147000000);
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	// 지헌 다익스트라
	pq.push({ home, v1 });
	jDis[v1] = home;

	while (!pq.empty())
	{
		int sp = pq.top().rhs;
		int sc = pq.top().lhs;
		pq.pop();

		if (jDis[sp] < sc) continue;

		loop(i, home, graph[sp].size())
		{
			int cp = graph[sp][i].lhs;
			int cc = graph[sp][i].rhs;

			if (jDis[cp] <= jDis[sp] + cc) continue;

			jDis[cp] = jDis[sp] + cc;
			pq.push({ jDis[cp], cp });
		}
	}

	// 성하 다익스트라
	pq.push({ home, v2 });
	sDis[v2] = home;

	while (!pq.empty())
	{
		int sp = pq.top().rhs;
		int sc = pq.top().lhs;
		pq.pop();

		if (sDis[sp] < sc) continue;

		loop(i, home, graph[sp].size())
		{
			int cp = graph[sp][i].lhs;
			int cc = graph[sp][i].rhs;

			if (sDis[cp] <= sDis[sp] + cc) continue;

			sDis[cp] = sDis[sp] + cc;
			pq.push({ sDis[cp], cp });
		}
	}

	// 약속장소
	// 1.지헌이와 성하의 출발위치는 약속장소가 될 수 없음
	// 2.지헌과 성하의 최단거리의 합이 최소가되는 정점
	// 3.지헌이 최단시간 > 성하 최단시간인 경우 X
	// 4.지헌이 최단시간 중 최소가되는 정점
	// 5.번호가 가장 작은 정점

	int minDis = 2147000000;
	tvec(int, ans);
	loop(i, home, n)
	{
		// 1.지헌이와 성하의 출발위치는 약속장소가 될 수 없음
		if (i == v1 || i == v2) continue;

		// 2.지헌과 성하의 최단거리의 합이 최소가되는 정점
		int sumDis = jDis[i] + sDis[i];
		if (sumDis < minDis)
		{
			ans.clear();
			ans.push_back(i);
			minDis = sumDis;
		}
		else if (sumDis == minDis) ans.push_back(i);
	}

	// 3.지헌이 최단시간 > 성하 최단시간인 경우 X
	tvec(int, ans2);
	loop(i, home, ans.size())
	{
		if (jDis[ans[i]] > sDis[ans[i]]) continue;
		ans2.push_back(ans[i]);
	}

	// 약속장소가 없으면 -1
	if (ans2.empty()) { elp(-1); return home; }

	// 4.지헌이 최단시간 중 최소가되는 정점
	minDis = 2147000000;
	tvec(int, ans3);
	loop(i, home, ans2.size())
	{
		if (jDis[ans2[i]] < minDis)
		{
			ans3.clear();
			ans3.push_back(ans2[i]);
			minDis = jDis[ans2[i]];
		}
		else if (jDis[ans2[i]] == minDis) ans3.push_back(ans2[i]);
	}
	
	// 5.번호가 가장 작은 정점
	sort(all(ans3));
	elp(++ans3[home]);

	return home;
}