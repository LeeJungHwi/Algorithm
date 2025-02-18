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

// 멀티탭 스케줄링
int main()
{
	init;

	int n, k; cin >> n >> k;
	vec(int, order, k);
	map<int, int> m;
	int s = home;
	loop(i, home, k)
	{
		cin >> order[i];

		// 처음 멀티탭 상태 초기화
		if (m.size() < n)
		{
			m[order[i]]++;
			s = i + 1;
		}
	}

	// 1 1 2 1 1 1 3 1 1 1
	int ans = home;
	loop(i, s, k)
	{
		// 현재 멀티탭에 있는상태
		if (m[order[i]] > home) continue;
		// 현재 멀티탭에 없는상태
		else
		{
			// 멀티탭에 사용중인 전자용품 중
			// 가장 나중에 사용되는 전자용품 찾기
			int obj = -1, latestJ = -2147000000;
			mloop(it, m)
			{
				int lateJ = 2147000000;
				if (it->rhs > home)
				{
					loop(j, i + 1, k)
					{
						if (order[j] == it->lhs)
						{
							lateJ = j;
							break;
						}
					}

					if (lateJ > latestJ)
					{
						latestJ = lateJ;
						obj = it->lhs;
					}
				}
			}

			// 가장 나중에 사용되는 전자용품 제거
			if (obj != -1)
			{
				m[obj] = home;
				ans++;
			}

			// 새로운 전자용품을 꽂음
			m[order[i]]++;
		}
	}
	elp(ans);

	return home;
}