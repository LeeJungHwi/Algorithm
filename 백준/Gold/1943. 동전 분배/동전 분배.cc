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

// 동전 분배
int main()
{
	init;

	int tc = 3;

	while (tc--)
	{
		int n; cin >> n;

		vec(pii, coin, n);
		int sum = home;

		loop(i, home, n)
		{
			cin >> coin[i].lhs >> coin[i].rhs;
			sum += coin[i].lhs * coin[i].rhs;
		}

		if (sum % 2 == 1) { elp(home); continue; }

		int s = sum / 2;
		vec(bool, dp, s + 1); // dp[i] => i원을 만들 수 있는지 체크
		dp[home] = true;

		loop(i, home, n)
		{
			int val = coin[i].lhs;
			int cnt = coin[i].rhs;

			// 역순 => 아이템의 개수가 제한되어있음
			rloop(j, s, -1)
			{
				// j원을 만들 수 없으면 X
				if (!dp[j]) continue;

				// 현재 가치의 동전을 1~최대 개수까지 사용
				loop(k, 1, cnt + 1)
				{
					// 현재금액 j에서 현재가치의 동전을 k개 사용했을때 금액
					int cVal = j + val * k;

					// s를 넘기면 X
					if (cVal > s) break;

					// cVal원은 만들 수 있음
					dp[cVal] = true;
				}
			}
		}

		elp(cond(dp[s], 1, home));
	}

	return home;
}