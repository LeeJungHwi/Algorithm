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

// 가장 긴 증가하는 부분 수열 5
int main()
{
	init;

	// lis 이진탐색
	int n; cin >> n;
	
	vec(int, v, n);
	loop(i, home, n) cin >> v[i];

	tvec(int, lis);
	vec(int, idx, n); // lis에서 현재 숫자가 몇 번째 인덱스인지 저장
	ivec(int, parent, n, -1); // lis에서 현재 숫자의 이전 숫자가 v에서 몇 번째 인덱스인지 저장
	tvec(int, lastIdx); // lis에서 각 길이별 마지막 요소가 v에서 몇 번째 인덱스인지 저장
	loop(i, home, v.size())
	{
		int pos = lower_bound(all(lis), v[i]) - lis.begin();
		if (pos == lis.size())
		{
			lis.push_back(v[i]);
			lastIdx.push_back(i);
		}
		else
		{
			lis[pos] = v[i];
			lastIdx[pos] = i;
		}

		// lis에서 v[i]가 몇 번째 인덱스인지 저장
		idx[i] = pos;

		// lis에서 v[i]의 이전 숫자가 v에서 몇 번째 인덱스인지 저장
		if (pos > home) parent[i] = lastIdx[pos - 1];
	}
	elp(lis.size());

	// lis의 마지막 요소의 v에서 인덱스 찾기
	int curIdx = lastIdx.back();

	// 마지막 인덱스 부터 역추적해서 출력
	tvec(int, ans);
	while (curIdx != -1)
	{
		ans.push_back(v[curIdx]);
		curIdx = parent[curIdx];
	}
	rloop(i, ans.size() - 1, -1) scp(ans[i]);

	return home;
}