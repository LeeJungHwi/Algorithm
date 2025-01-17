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

// 물건 팔기
int main()
{
	init;

	int n; cin >> n;
	vec(pii, buyer, n);
	loop(i, home, n) cin >> buyer[i].lhs >> buyer[i].rhs;
	sort(buyer.begin(), buyer.end());
	//loop(i, home, buyer.size()) cout << buyer[i].lhs << ' ' << buyer[i].rhs << '\n';

	// 최대 이익을 남길 수 있는 가격
	int ans = -1, maxSum = -1;
	
	loop(i, home, buyer.size())
	{
		// 전에 체크했던 가격
		if (ans == buyer[i].lhs) continue;

		// 현재 체크할 가격
		int curPrice = buyer[i].lhs;

		// 현재 가격으로 설정 시 이득 체크
		int sum = home;
		loop(j, home, buyer.size())
		{
			// 최대한도 체크
			if (buyer[j].lhs < curPrice) continue;

			sum += curPrice - buyer[j].rhs < 1 ? home : curPrice - buyer[j].rhs;
		}

		//cout << sum << '\n';

		// 최대 이익 업데이트
		if (sum > maxSum)
		{
			maxSum = sum;
			ans = curPrice;
		}
	}

	//cout << maxSum << '\n';
	cout << (maxSum == home ? maxSum : ans) << '\n';

	return home;
}