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

vector<int> unf(201);

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
	bool operator<(const Edge& e)const { return c < e.c; }
};

// 고속철도 설계하기
int main()
{
	init;

	// 이미 고속도로가 설치된 정점은 미리 Union 후 크루스칼
	int n; cin >> n;
	loop(i, home, n) unf[i] = i;
	tvec(Edge, graph);
	int c, v1, v2, minCost = home;
	loop(i, home, n)
	{
		loop(j, home, n)
		{
			cin >> c;
			if (i == j) continue;
			
			// 이미 고속도로로 연결된 두 정점
			if (c < home)
			{
				v1 = Find(i);
				v2 = Find(j);
				minCost -= c;
				if (v1 != v2) Union(i, j);
			}
			else graph.push_back(Edge(i, j, c));
		}
	}
	sort(all(graph));
	minCost /= 2;

	// 연결최소비용, 연결된 간선 수, 설치된 두 정점 번호
	int cnt = home;
	tvec(pii, connectVertex);
	loop(i, home, graph.size())
	{
		v1 = Find(graph[i].v1);
		v2 = Find(graph[i].v2);

		if (v1 != v2)
		{
			Union(v1, v2);
			minCost += graph[i].c;
			cnt++;
			connectVertex.push_back({ graph[i].v1, graph[i].v2 });
		}
	}

	scp(minCost); elp(cnt);
	loop(i, home, cnt)
	{
		scp(connectVertex[i].lhs + 1);
		elp(connectVertex[i].rhs + 1);
	}

	return home;
}