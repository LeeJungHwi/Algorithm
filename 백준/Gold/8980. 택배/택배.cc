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

// 택배
int main()
{
	init;

	// 각 마을에 도착하면 받는 마을이 작은 마을부터 최대용량까지 채움
	// 받는 마을이 현재마을인 택배를 현재용량에서 뺌

	int n, c, m; cin >> n >> c >> m;
	map<int, map<int, int>> m1;
	int s, e, cc;
	loop(i, home, m)
	{
		cin >> s >> e >> cc;
		m1[s][e] = cc;
	}

	// m1 => 키 보내는 마을 값 (받는 마을, 박스 개수) 쌍
	// 1 => (2, 10) (3, 20) (4, 30)
	// 2 => (3, 10) (4, 20)
	// 3 => (4, 20)

	// m2 => 키 받는마을 값 받는마을에서 내릴 박스 개수
	map<int, int> m2;
	int curCapacity = home, ans = home;
	mloop(it, m1)
	{
		// 각 마을에서
		mloop(it2, it->rhs)
		{
			// 내릴 박스가 있으면 내림
			if (m2[it->lhs] > home)
			{
				curCapacity -= m2[it->lhs];
				m2[it->lhs] = home;
			}

			// 최대용량까지 채움
			if (curCapacity + it2->rhs > c)
			{
				ans += c - curCapacity;
				m2[it2->lhs] += c - curCapacity;
				curCapacity = c;
			}
			else
			{
				ans += it2->rhs;
				m2[it2->lhs] += it2->rhs;
				curCapacity += it2->rhs;
			}
		}
	}
	elp(ans);

	return home;
}