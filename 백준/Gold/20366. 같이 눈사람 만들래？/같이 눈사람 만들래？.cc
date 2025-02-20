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

// 같이 눈사람 만들래?
int main()
{
	init;

	int n; cin >> n;
	vec(int, v, n);
	loop(i, home, n) cin >> v[i];

	// 두 눈덩이 합을 저장하고 정렬하면 인접한 두 눈덩이의 합만 비교하면됨
	// 인접한 두 눈덩이 합의 차이가 최솟값이 될 확률이 높음
	// 최솟값 업데이트 과정에서 사용된 인덱스가 같은 눈덩이가 있으면 안됨
	vector<pair<int, pii>> pV; // (합, (사용된 인덱스 쌍))
	loop(i, home, n)
	{
		loop(j, i + 1, n)
		{
			pV.push_back({ v[i] + v[j], {i, j} });
		}
	}
	sort(all(pV));

	int ans = 2147000000;
	loop(i, home, pV.size() - 1)
	{
		// 인접한 두 눈덩이 합 차이
		int gap = abs(pV[i].lhs - pV[i + 1].lhs);
		
		// 같은 눈덩이를 사용한 경우 X
		int i1 = pV[i].rhs.lhs, i2 = pV[i + 1].rhs.lhs, j1 = pV[i].rhs.rhs, j2 = pV[i + 1].rhs.rhs;
		if (i1 == i2 || i1 == j2 || j1 == i2 || j1 == j2) continue;

		// 최솟값 업데이트
		ans = min(ans, gap);
	}
	elp(ans);

	return home;
}