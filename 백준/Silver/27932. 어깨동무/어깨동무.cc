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
#define ivec(t, v, r, i) vector<t> v((r), i)
#define gmat(t, v, r) vector<vector<t> > v((r))
#define mat(t, v, r, c) vector<vector<t> > v((r), vector<t>((c)))
#define imat(t, v, r, c, i) vector<vector<t> > v((r), vector<t>((c), i))
#define smat(t, v, r, c, s) vector<vector<vector<t> > > v((r), vector<vector<t>>((c), vector<t>((s))))
#define ismat(t, v, r, c, s, i) vector<vector<vector<t> > > v((r), vector<vector<t>>((c), vector<t>((s), i)))
#define ssmat(t, v, r, c, s1, s2) vector<vector<vector<vector<t> > > > v((r), vector<vector<vector<t>>>((c), vector<vector<t>>((s1), vector<t>((s2)))))
#define issmat(t, v, r, c, s1, s2, i) vector<vector<vector<vector<t> > > > v((r), vector<vector<vector<t>>>((c), vector<vector<t>>((s1), vector<t>((s2), i))))
#define sssmat(t, v, r, c, s1, s2, s3) vector<vector<vector<vector<vector<t> > > > > v((r), vector<vector<vector<vector<t>>>>((c), vector<vector<vector<t>>>((s1), vector<vector<t>>((s2), vector<t>((s3))))))
#define isssmat(t, v, r, c, s1, s2, s3, i) vector<vector<vector<vector<vector<t> > > > > v((r), vector<vector<vector<vector<t>>>>((c), vector<vector<vector<t>>>((s1), vector<vector<t>>((s2), vector<t>((s3), i)))))

#define dir vector<pii> cd = { {-1, home}, {1, home}, { home, -1 }, { home, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }
#define kdir vector<pii> kcd = { {-1, -2}, {-2, -1}, { -2, 1 }, { -1, 2 }, { 1, -2 }, { 2, -1 }, { 1, 2 }, { 2, 1 } }
#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

int n, k;

bool Check(int s, vector<int> &v)
{
	// 지친 학생의 수
	int tiredCnt = home;

	// 첫 학생과 마지막 학생이 지치는지 확인
	if (v.size() >= 2)
	{
		if (abs(v[home] - v[1]) > s) tiredCnt++;
		if (abs(v[v.size() - 1] - v[v.size() - 2]) > s) tiredCnt++;
	}

	// 두번째 학생 부터 마지막 학생 전 까지 지치는지 확인
	loop(i, 1, v.size() - 1)
	{
		if (abs(v[i] - v[i - 1]) > s || abs(v[i] - v[i + 1]) > s)
		{
			tiredCnt++;
		}
	}

	// 지친 학생이 k명 이하면 가능한 경우
	return tiredCnt <= k;
}

// 어깨동무
int main()
{
	init;

	// lo => 0
	// hi => maxH - minH
	// s 점수 차이로 k명 이하가 지치면 가능한 경우
	cin >> n >> k;
	vec(int, v, n);
	int maxH = MIN, minH = MAX;
	loop(i, home, n)
	{
		cin >> v[i];
		maxH = max(maxH, v[i]);
		minH = min(minH, v[i]);
	}

	int l = home, h = maxH - minH, ans = home;
	while (l <= h)
	{
		int s = (l + h) / 2;

		if (Check(s, v))
		{
			ans = s;
			h = s - 1;
		}
		else l = s + 1;
	}
	elp(ans);

	return home;
}