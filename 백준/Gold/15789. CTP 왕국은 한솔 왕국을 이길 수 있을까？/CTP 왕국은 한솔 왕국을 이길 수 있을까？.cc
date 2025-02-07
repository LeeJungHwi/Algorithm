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

vector<int> unf(100001), power(100001);

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

// CTP 왕국은 한솔 왕국을 이길 수 있을까?
int main()
{
	init;

	int n, m; cin >> n >> m;
	loop(i, home, n) { unf[i] = i; power[i] = 1; }
	int v1, v2;
	loop(i, home, m)
	{
		cin >> v1 >> v2;
		Union(--v1, --v2);
	}

	map<int, int> root;
	loop(i, home, n) root[Find(i)]++;

	int c, h, k; cin >> c >> h >> k;

	tvec(int, power);
	mloop(it, root)
	{
		if (it->lhs == Find(c - 1) || it->lhs == Find(h - 1)) continue;
		power.push_back(it->rhs);
	}
	sort(rall(power));
	
	int ans = root[Find(c - 1)];
	loop(i, home, power.size())
	{
		if (k-- <= home) continue;
		ans += power[i];
	}
	elp(ans);

	return home;
}