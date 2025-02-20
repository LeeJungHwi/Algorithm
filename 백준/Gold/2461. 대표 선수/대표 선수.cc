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

// 대표 선수
int main()
{
	init;

	// 각 학급 오름차순
	// 현재까지 선택된 학생들 중 최솟값과 최댓값 유지하고 ans에 현재까지 최댓값 - 최솟값 업데이트
	// 현재까지 선택된 학생들 중 최솟값 제거하고 해당 학급의 다음학생 추가
	int n, m; cin >> n >> m;

	mat(int, graph, n, m);
	loop(i, home, n) loop(j, home, m) cin >> graph[i][j];
	loop(i, home, n) sort(all(graph[i]));

	priority_queue<int> maxHeap;
	priority_queue<pii, vector<pii>, greater<pii>> minHeap; // (능력치, 학급번호)

	// 가장 능력치가 작은 학생으로 초기화
	loop(i, home, n)
	{
		maxHeap.push(graph[i][home]);
		minHeap.push({ graph[i][home], i });
	}

	int ans = 2147000000;
	vec(int, cnt, n); // 각 학급에서 선택된 학생 수
	while (true)
	{
		// 현재까지 선택된 학생들 중 최솟값인 학생의 학급번호
		int curIdx = minHeap.top().rhs;

		// 현재까지 최댓값 - 최솟값 업데이트
		ans = min(ans, maxHeap.top() - minHeap.top().lhs);

		// 해당 학급에서 더 이상 선택할 학생이 없으면 X
		if (++cnt[curIdx] == m) break;

		// 현재까지 선택된 학생들 중 최솟값 제거하고 해당 학급의 다음학생 추가
		minHeap.pop();
		minHeap.push({ graph[curIdx][cnt[curIdx]], curIdx });
		maxHeap.push(graph[curIdx][cnt[curIdx]]);
	}
	elp(ans);

	return home;
}