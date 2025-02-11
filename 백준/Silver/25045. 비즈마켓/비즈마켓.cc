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

// 비즈마켓
int main()
{
	init;

	// 각 기업은 하나의 물품만 렌탈 가능
	// Ai의 만족도를 가지는 물품을 Bj의 비용으로 렌탈하면  Ai - Bj 만큼의 고객만족도를 얻음
	// 기업은 만족도가 0보다 작다면 거래하지않음 
	// 만족도 합의 최댓값

	ll n, m; cin >> n >> m;
	vec(ll, A, n);
	loop(i, home, n) cin >> A[i];
	vec(ll, B, m);
	loop(i, home, m) cin >> B[i];
	sort(rall(A)); sort(all(B));
	n = min(n, m);

	// 10 9 8 7 6
	// 2 3 4 5 6
	// 8 + 6 + 4 + 2

	ll ans = home;
	loop(i, home, n) if(A[i] - B[i] > home) ans += A[i] - B[i];
	elp(ans);

	return home;
}