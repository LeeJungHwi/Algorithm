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

int n, m, h;
pii sPos;
vector<pii> milkPos;
map<pair<pii, pii>, int> dis;
int ans = home;

void DFS(pii curPos, int curHp, int curMilkCnt, vector<bool> &ch)
{
    loop(i, home, milkPos.size())
    {
        if (!ch[i])
        {
            // 현재 위치에서 다음 방문할 우유까지 거리
            pii cp = milkPos[i];
            int disToMilk = dis[{curPos, cp}];

            // 현재체력으로 방문할 수 있는지 확인
            if (curHp >= disToMilk)
            {
                // i번쨰 우유 방문
                ch[i] = true;

                // 다음 우유 방문 후 체력 상태
                int cHp = curHp - disToMilk + h;

                // 다음 방문 우유 위치에서 집까지 거리
                int disToHome = dis[{cp, sPos}];

                // 다음 우유 재귀
                DFS(cp, cHp, curMilkCnt + 1, ch);

                // 백트래킹
                ch[i] = false;
            }
        }
    }

    // 집으로 돌아갈 수 없으면 X
    if (curHp < dis[{curPos, sPos}]) return;
    
    // 최대 우유 업데이트
    ans = max(ans, curMilkCnt);
}

// 진우의 민트초코우유
int main()
{
	init;

	cin >> n >> m >> h;
	mat(int, graph, n, n);
	loop(i, home, n) loop(j, home, n)
	{
		cin >> graph[i][j];
		if (graph[i][j] == 1) sPos = { i, j };
		else if (graph[i][j] == 2) milkPos.push_back({ i, j });
	}

	// 집 <-> 우유 까지 거리
	// 우유 <-> 우유 까지 거리
    milkPos.push_back(sPos);
    loop(i, home, milkPos.size())
    {
        loop(j, i + 1, milkPos.size())
        {
            int d = abs(milkPos[i].lhs - milkPos[j].lhs) + abs(milkPos[i].rhs - milkPos[j].rhs);
            dis[{{milkPos[i].lhs, milkPos[i].rhs}, { milkPos[j].lhs, milkPos[j].rhs }}] = d;
            dis[{{milkPos[j].lhs, milkPos[j].rhs}, { milkPos[i].lhs, milkPos[i].rhs }}] = d;
        }
    }
    milkPos.pop_back();

    //mloop(it, dis)
    //{
    //    scp(it->lhs.lhs.lhs);
    //    scp(it->lhs.lhs.rhs);
    //    scp(it->lhs.rhs.lhs);
    //    scp(it->lhs.rhs.rhs);
    //    elp(it->rhs);
    //}

    vector<bool> ch(milkPos.size()); // 중복 X
    DFS(sPos, m, home, ch);
    elp(ans);

	return home;
}