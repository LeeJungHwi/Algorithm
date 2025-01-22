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

// 두라무리 휴지
int main()
{
	init;

	int n; cin >> n;
	string is1, is2, aeiouIs1 = "", aeiouIs2 = ""; cin >> is1 >> is2;
	map<char, int> m;
	loop(i, home, n)
	{
		m[is1[i]]++;
		m[is2[i]]--;

		if (i == home || i == n - 1)
		{
			if (is1[i] != is2[i])
			{
				cout << "NO\n";
				return home;
			}
		}

		if (is1[i] != 'a' && is1[i] != 'e' && is1[i] != 'i' && is1[i] != 'o' && is1[i] != 'u') aeiouIs1 += is1[i];
		if (is2[i] != 'a' && is2[i] != 'e' && is2[i] != 'i' && is2[i] != 'o' && is2[i] != 'u') aeiouIs2 += is2[i];
	}
	mloop(it, m) if (it->second != home) { cout << "NO\n"; return home; }
	if (aeiouIs1 != aeiouIs2) { cout << "NO\n"; return home; }
	cout << "YES\n";

	return home;
}