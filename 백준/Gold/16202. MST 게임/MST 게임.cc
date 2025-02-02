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

vector<int> unf(1001);

int Find(int v)
{
	if (unf[v] == v) return v;
	return unf[v] = Find(unf[v]);
}

void Union(int v1, int v2)
{
	v1 = Find(v1);
	v2 = Find(v2);
	if (v1 != v2) unf[v1] = v2;
}

struct Edge
{
	int v1, v2, c;
	Edge() {}
	Edge(int v1, int v2, int c) : v1(v1), v2(v2), c(c) {}
	// 정렬 X => 이미 가중치가 정렬된 상태로 들어옴
};

// MST 게임
int main()
{
	init;

	int n, m, k; cin >> n >> m >> k;
	tvec(Edge, graph);
	int v1, v2;
	loop(i, home, m)
	{
		cin >> v1 >> v2;
		graph.push_back(Edge(--v1, --v2, i + 1));
	}

	// T => 제거된 간선, F => 다음턴에 사용할 수 있는 간선
	vec(bool, ch, graph.size());

	// 진행한 턴 횟수
	int coutCnt = home;
	while (true)
	{
		// 진행한 턴 횟수 체크
		if (coutCnt == k) return home;

		int connectCnt = home, minCost = home;
		loop(i, home, n) unf[i] = i;

		// 제거될 간선 => 처음으로 연결된 간선
		bool isEdge = false;
		loop(i, home, graph.size())
		{
			// 제거된 간선 체크
			if (ch[i]) continue;

			v1 = Find(graph[i].v1);
			v2 = Find(graph[i].v2);

			if (v1 != v2)
			{
				minCost += graph[i].c;
				Union(v1, v2);
				connectCnt++;

				// 처음 연결된 간선 제거
				if (!isEdge)
				{
					isEdge = true;
					ch[i] = true;
				}
			}
		}

		// MST를 만들 수 없으면 남은 턴 0 출력하고 종료
		if (connectCnt != n - 1)
		{
			loop(i, home, k - coutCnt) scp(home);
			return home;
		}

		// 모두 연결된 경우 MST 비용 출력 
		scp(minCost);
		coutCnt++;
	}

	return home;
}