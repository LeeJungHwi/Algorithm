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

vector<int> dog, order;

// 도시번호를 페널티값 기준으로 오름차순
bool comp(const int& v1, const int& v2)
{
	return dog[v1] < dog[v2];
}

// 도망자 원숭이
int main()
{
	init;

	// 경로에서 가장 오래 괴롭힐 수 있는 도시 하나에서만 괴롭힘

	int n, m, q; cin >> n >> m >> q;
	dog.resize(n + 1); // 각 도시에서 괴롭히는 시간
	order.resize(n + 1); // 각 도시 번호
	loop(i, 1, n + 1)
	{
		cin >> dog[i];
		order[i] = i;
	}
	sort(all(order), comp);
	mat(int, graph, n + 1, n + 1);
	loop(i, home, n + 1) loop(j, home, n + 1) graph[i][j] = 1000000000;
	mat(int, penalty, n + 1, n + 1); // penalty[i][j] => i -> j로 가는 경로 내 최대 패널티 저장
	int v1, v2, c;
	loop(i, home, m)
	{
		cin >> v1 >> v2 >> c;
		graph[v1][v2] = min(graph[v1][v2], c);
		graph[v2][v1] = min(graph[v1][v2], c);
		penalty[v1][v2] = max(dog[v1], dog[v2]);
		penalty[v2][v1] = max(dog[v1], dog[v2]);
	}
	loop(i, home, n + 1) graph[i][i] = home;

	loop(k, 1, n + 1)
	{
		loop(i, 1, n + 1)
		{
			loop(j, 1, n + 1)
			{
				// 페널티가 작은 k부터 사용
				// 기존 경로 + 기존 경로 최대패널티 > k 경유 경로 + k 경유 경로 최대패널티인 경우 업데이트
				if (graph[i][j] + penalty[i][j] > graph[i][order[k]] + graph[order[k]][j] + max({ penalty[i][order[k]], penalty[order[k]][j], dog[order[k]] }))
				{
					graph[i][j] = graph[i][order[k]] + graph[order[k]][j];
					penalty[i][j] = max({ penalty[i][order[k]], penalty[order[k]][j], dog[order[k]] });
				}
			}
		}
	}

	loop(i, home, q)
	{
		cin >> v1 >> v2;
		elp(cond(graph[v1][v2] == 1000000000, -1, graph[v1][v2] + penalty[v1][v2]));
	}

	return home;
}