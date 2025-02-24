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
#define piii pair<int, pii>
#define pll pair<ll, ll>
#define plll pair<ll, pll>

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
#define smat(t, v, r, c, s) vector<vector<vector<t> > > v((r), vector<vector<t>>((c), vector<t>((s))))

#define dir vector<pii> cd = { {-1, home}, {1, home}, { home, -1 }, { home, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }
#define kdir vector<pii> kcd = { {-1, -2}, {-2, -1}, { -2, 1 }, { -1, 2 }, { 1, -2 }, { 2, -1 }, { 1, 2 }, { 2, 1 } }
#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

#include <unordered_map>

// 가로등
int main()
{
	init;

	// 1차원 BFS
	// l + 1개의 가로등 부터 멀티 소스 BFS
	// 방향은 좌우
	// 어두운 정도를 작은값부터 k개 출력

	ll l, n, k; cin >> l >> n >> k;
	unordered_map<ll, ll> dis;
	queue<ll> cp;
	vector<ll> d = { -1, 1 };
	ll sPos;
	loop(i, home, n)
	{
		cin >> sPos;
		cp.push(sPos);
		dis[sPos] = 1;
	}

	while (!cp.empty())
	{
		ll s = cp.front();
		cp.pop();

		// BFS => 최단거리가 보장되므로 k개 출력 후 종료
		if (k > home)
		{
			elp(dis[s] - 1);
			k--;
		}
		else break;

		loop(i, home, d.size())
		{
			ll c = s + d[i];

			if (c < home || c >= l + 1) continue;
			if (dis.count(c) > home) continue;

			cp.push(c);
			dis[c] = dis[s] + 1;
		}
	}

	return home;
}