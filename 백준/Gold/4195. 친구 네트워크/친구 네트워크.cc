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

#include <unordered_map>

vector<int> unf(200002), cnt(200002);

int Find(int v)
{
	if (v == unf[v]) return v;
	return unf[v] = Find(unf[v]);
}

void Union(int v1, int v2)
{
	v1 = Find(v1);
	v2 = Find(v2);

	if (v1 != v2)
	{
		unf[v1] = v2;

		// 친구 관계
		cnt[v2] += cnt[v1];
		cnt[v1] = home;
	}
}

// 친구 네트워크
int main()
{
	init;

	int tc; cin >> tc;

	while (tc--)
	{
		int n; cin >> n;
		unordered_map<string, int> m;
		vector<pair<string, string>> ship(n);
		tvec(string, v);
		string s1, s2;
		loop(i, home, n)
		{
			cin >> s1 >> s2;
			if (m[s1] == home)
			{
				v.push_back(s1);
				m[s1]++;
			}
			if (m[s2] == home)
			{
				v.push_back(s2);
				m[s2]++;
			}
			
			ship[i] = {s1, s2};
		}

		loop(i, home, v.size())
		{
			m[v[i]] = unf[i] = i;
			cnt[i] = 1;
		}

		loop(i, home, ship.size())
		{
			Union(Find(m[ship[i].lhs]), Find(m[ship[i].rhs]));
			elp(cnt[Find(m[ship[i].lhs])]);
		}
	}

	return home;
}