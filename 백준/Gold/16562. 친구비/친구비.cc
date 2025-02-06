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

vector<int> unf(10001);

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

// 친구비
int main()
{
	init;

	// 유파
	// unf 돌면서 루트를 키로 가지는 맵에 최솟값 저장
	// 맵 돌면서 가지고 있는 돈으로 모두 친구로 만들 수 있으면 비용의 총합을, 아니면 Oh no 출력

	int n, m, k; cin >> n >> m >> k;
	loop(i, home, n) unf[i] = i;
	vec(int, cost, n);
	loop(i, home, n) cin >> cost[i];
	int v1, v2;
	loop(i, home, m)
	{
		cin >> v1 >> v2;
		Union(--v1, --v2);
	}
	map<int, int> root;
	loop(i, home, n) if (root[Find(i)] == home || root[Find(i)] > cost[i]) root[Find(i)] = cost[i];
	int ans = home;
	mloop(it, root) ans += it->rhs;
	if (ans > k) { elp("Oh no"); return home; }
	elp(ans);

	return home;
}