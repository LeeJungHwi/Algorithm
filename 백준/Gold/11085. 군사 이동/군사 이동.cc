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

// 군사 이동
int main()
{
	init;

	// 너비가 가장 넓은 길부터 유니온
	// 백준월드 수도 c와 큐브월드 v의 루트가 같아질때 종료
	int p, w, c, v; cin >> p >> w >> c >> v;
	loop(i, home, p) unf[i] = i;
	vector<pair<int, pii>> edge(w);
	loop(i, home, w) cin >> edge[i].rhs.lhs >> edge[i].rhs.rhs >> edge[i].lhs;
	sort(rall(edge));

	loop(i, home, edge.size())
	{
		int v1 = Find(edge[i].rhs.lhs);
		int v2 = Find(edge[i].rhs.rhs);

		if (v1 != v2)
		{
			Union(v1, v2);

			if (Find(c) == Find(v))
			{
				elp(edge[i].lhs);
				return home;
			}
		}
	}

	return home;
}