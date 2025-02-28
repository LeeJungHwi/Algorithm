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

// 구슬 탈출
int main()
{
	init;

	// 빨간구슬만 떨어뜨리기 위한 최단거리 => 기울이는 횟수를 10회 넘기면 X
	// 구멍을 만나면 떨어짐 => 파란구슬이 떨어지면 X
	// 두 구슬이 겹칠 수 없음 => 기울였을 때 더 많이 이동한 구슬을 한칸 뒤로 빼야함
	// 벽이면 이동할 수 없음 => 제자리

	int n, m; cin >> n >> m;
	mat(char, graph, n, m);
	ssmat(int, dis, n, m, n, m); // dis[i][j][k][l] => 빨간구슬 i,j 파란구슬 k,l일 때 최단거리
	queue<pair<pii, pii>> cp; dir; // (빨간구슬 위치, 파란구슬 위치)
	pii redPos, bluePos;
	loop(i, home, n) loop(j, home, m)
	{
		cin >> graph[i][j];
		
		// 두 구슬 위치 저장
		if (graph[i][j] == 'R') redPos = { i, j };
		else if(graph[i][j] == 'B') bluePos = {i, j};
	}

	cp.push({ redPos, bluePos });
	dis[redPos.lhs][redPos.rhs][bluePos.lhs][bluePos.rhs] = 1;

	while (!cp.empty())
	{
		int rsi = cp.front().lhs.lhs;
		int rsj = cp.front().lhs.rhs;
		int bsi = cp.front().rhs.lhs;
		int bsj = cp.front().rhs.rhs;
		cp.pop();

		// 기울이는 횟수를 10회 넘기면 X
		if (dis[rsi][rsj][bsi][bsj] > 10)
		{
			elp(home);
			return home;
		}

		loop(i, home, 4)
		{
			int rci = rsi;
			int rcj = rsj;
			int bci = bsi;
			int bcj = bsj;

			// 벽을 만날 때 까지 두 구슬 기울이기
			
			// 빨간 구슬 기울이기
			int rMoveCnt = home;
			while (true)
			{
				// 한칸 이동
				rci += cd[i].lhs;
				rcj += cd[i].rhs;
				rMoveCnt++;

				// 벽이면 한칸 뒤로 뺌
				if (graph[rci][rcj] == '#')
				{
					rci -= cd[i].lhs;
					rcj -= cd[i].rhs;
					rMoveCnt--;

					break;
				}

				// 구멍이면 떨어짐
				if (graph[rci][rcj] == 'O') { rMoveCnt = -1; break; }
			}

			// 파란 구슬 기울이기
			int bMoveCnt = home;
			while (true)
			{
				// 한칸 이동
				bci += cd[i].lhs;
				bcj += cd[i].rhs;
				bMoveCnt++;

				// 벽이면 한칸 뒤로 뺌
				if (graph[bci][bcj] == '#')
				{
					bci -= cd[i].lhs;
					bcj -= cd[i].rhs;
					bMoveCnt--;

					break;
				}

				// 구멍이면 떨어짐
				if (graph[bci][bcj] == 'O') { bMoveCnt = -1; break; }
			}

			// 파란 구슬이 떨어지면 X
			if (bMoveCnt == -1) continue;

			// 빨간 구슬이 떨어지면 종료
			if (rMoveCnt == -1) { elp(1); return home; }

			// 두 구슬이 겹쳐지면 더 많이 이동한 구슬을 한칸 뒤로 뺌
			if (rci == bci && rcj == bcj)
			{
				if (rMoveCnt > bMoveCnt) { rci -= cd[i].lhs; rcj -= cd[i].rhs; }
				else { bci -= cd[i].lhs; bcj -= cd[i].rhs; }
			}

			if (dis[rci][rcj][bci][bcj] > home) continue;

			cp.push({ {rci, rcj}, {bci, bcj} });
			dis[rci][rcj][bci][bcj] = dis[rsi][rsj][bsi][bsj] + 1;
		}
	}
	elp(home);

	return home;
}