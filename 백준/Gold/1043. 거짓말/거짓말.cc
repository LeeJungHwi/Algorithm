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

vector<int> unf(51);

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

// 거짓말
int main()
{
	init;

	int n, m, k; cin >> n >> m >> k;

	// 유파 초기화
	loop(i, home, n) unf[i] = i;

	// 진실을 알고있는 사람
	map<int, int> know;
	int v1, v2;
	loop(i, home, k)
	{
		cin >> v1;
		know[--v1]++;
	}
	
	// 파티에서 만나는 사람들 Union
	// 모두 Union한 상태에서 거짓말을 할 수 있는 파티를 알아내야하므로 그래프에 저장
	gmat(int, graph, m);
	loop(i, home, m)
	{
		cin >> k >> v1;
		graph[i].push_back(v1 - 1);

		loop(j, 1, k)
		{
			cin >> v2;
			graph[i].push_back(v2 - 1);
			Union(v1 - 1, v2 - 1);
		}
	}

	// 경로압축
	loop(i, home, n) Find(i);

	// 그래프 돌면서 진실을 알고있는 사람이 있는 파티면 카운팅 X
	int ans = home;
	loop(i, home, m)
	{
		bool isParty = true;
		loop(j, home, graph[i].size())
		{
			int cur = Find(graph[i][j]);

			mloop(it, know)
			{
				if (Find(it->lhs) == cur)
				{
					isParty = false;
					break;
				}
			}

			if (!isParty) break;
		}

		if (isParty) ans++;
	}
	elp(ans);

	return home;
}