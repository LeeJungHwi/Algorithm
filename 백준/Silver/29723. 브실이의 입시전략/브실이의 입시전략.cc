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

// 브실이의 입시전략
int main()
{
	init;

	int n, m, k; cin >> n >> m >> k;
	map<string, int> nsMap;
	map<int, vector<string> > snMap;
	string name; int score;
	loop(i, home, n)
	{
		cin >> name >> score;
		nsMap[name] = score;
		snMap[score].push_back(name);
	}
	map<string, int> pMap;
	int publicScore = home;
	loop(i, home, k)
	{
		cin >> name;
		pMap[name]++;
		publicScore += nsMap[name];
	}
	m -= k;
	int cnt = home;
	score = home;
	mloop(it, snMap)
	{
		loop(i, home, it->second.size())
		{
			if (cnt == m) break;
			if (pMap[it->second[i]]) continue;
			score += it->first;
			++cnt;
		}
		if (cnt == m) break;
	}
	scp(publicScore + score);
	cnt = score = home;
	mrloop(it, snMap)
	{
		loop(i, home, it->second.size())
		{
			if (cnt == m) break;
			if (pMap[it->second[i]]) continue;
			score += it->first;
			++cnt;
		}
		if (cnt == m) break;
	}
	elp(publicScore + score);

	return home;
}