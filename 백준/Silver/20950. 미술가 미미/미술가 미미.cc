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

int n;
piii gomduri;
int ans = MAX, rSum, gSum, bSum, useCnt;

void DFS(int L, vector<piii>&v)
{
    // 혼합한 물감이 2개 이상인 경우만 업데이트
    if (useCnt >= 2)
    {
        int rAvg = rSum / useCnt;
        int gAvg = gSum / useCnt;
        int bAvg = bSum / useCnt;
        int gap = abs(gomduri.lhs - rAvg) + abs(gomduri.rhs.lhs - gAvg) + abs(gomduri.rhs.rhs - bAvg);
        ans = min(ans, gap);
    }

    // 물감 범위를 넘어가거나 사용한 물감의 개수가 7개를 초과하면 X
    if (L == n || useCnt >= 7) return;

    // 선택
    rSum += v[L].lhs;
    gSum += v[L].rhs.lhs;
    bSum += v[L].rhs.rhs;
    useCnt++;
    DFS(L + 1, v);

    // 선택 X
    useCnt--;
    rSum -= v[L].lhs;
    gSum -= v[L].rhs.lhs;
    bSum -= v[L].rhs.rhs;
    DFS(L + 1, v);
}


// 미술가 미미
int main()
{
	init;

	// 새로운 물감 => R합 / 개수, G합 / 개수, B합 / 개수
	// 물감 색 차이 => abs(R 차이) + abs(G 차이) + abs(B 차이)
	// 문두리 색 => 최대 7개의 물감을 혼합해 곰두리 색과 차이가 최소인 색

	// 현재 물감을 선택하거나 선택 하지 않거나로 분기
	// 물감 범위를 넘어가거나 사용한 물감의 개수가 7개를 초과하면 X
    // 혼합한 물감의 개수가 2개 이상인 경우만 업데이트

	cin >> n;
	vec(piii, v, n);
	loop(i, home, n) cin >> v[i].lhs >> v[i].rhs.lhs >> v[i].rhs.rhs;
	cin >> gomduri.lhs >> gomduri.rhs.lhs >> gomduri.rhs.rhs;

    DFS(home, v);
	elp(ans);

	return home;
}