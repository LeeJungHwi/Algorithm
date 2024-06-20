#include <bits/stdc++.h>
using namespace std;

#define home 0

#define ll long long

#define pii pair<int, int>
#define pll pair<ll, ll>

#define loop(v, s, e) for(int v = (s); v < (e); v++)
#define rloop(v, s, e) for(int v = (s); v > (e); v--)
#define mloop(v, a) for(auto v = (a).begin(); v != (a).end(); v++)
#define mrloop(v, a) for(auto v = (a).rbegin(); v != (a).rend(); v++)
#define aloop(t, v, s, c, e, i) for(t v = (s); v c (e); i)

#define p(a) cout << (a)
#define elp(a) cout << (a) << '\n'
#define scp(a) cout << (a) << ' '

#define vec(t, v, r) vector<t> v((r))
#define mat(t, v, r, c) vector<vector<t> > v((r), vector<t>((c)))
#define dir vector<pii> checkDir = { {-1, 0}, {1, 0}, { 0, -1 }, { 0, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }

#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()

const int MAX = 2147000000;
const int MIN = -2147000000;

struct Person
{
	int lhs, rhs;

	Person() {}
	Person(int l, int r) : lhs(l), rhs(r) {}

	bool operator<(const Person &person)const
	{
		return lhs < person.lhs;
	}
};

// 신입 사원
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	int tc;
	cin >> tc;

	while (tc--)
	{
		int n;
		cin >> n;

		vec(Person, person, n);
		loop(i, 0, n) cin >> person[i].lhs >> person[i].rhs;
		sort(all(person)); // 1 4  2 3  3 2  4 1  5 5
		int cnt = 1;
		int minRhs = person[0].rhs;
		loop(i, 1, n) if (person[i].rhs < minRhs)
		{
			cnt++;
			minRhs = person[i].rhs;
		}
		elp(cnt);
	}

	return home;
}