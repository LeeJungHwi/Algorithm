#include <bits/stdc++.h>
using namespace std;

#define home 0

#define ll long long

#define pii pair<int, int>
#define pll pair<ll, ll>

#define loop(v, s, e) for(int v = (s); v < (e); v++)
#define rloop(v, s, e) for(int v = (s); v > (e); v--)
#define mloop(v, a) for(auto v = (a).begin(); v != (a).end(); v++)
#define mrloop(v, a) for(auto v = (a).rbegin(); v != (a).rend(); v++)
#define aloop(t, v, s, c, e, i) for(t v = (s); v c (e); i)

#define p(a) cout << (a)
#define elp(a) cout << (a) << '\n'
#define scp(a) cout << (a) << ' '

#define vec(t, v, r) vector<t> v((r))
#define mat(t, v, r, c) vector<vector<t> > v((r), vector<t>((c)))
#define gmat(t, v, r) vector<vector<t> > v((r))
#define dir vector<pii> cd = { {-1, 0}, {1, 0}, { 0, -1 }, { 0, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }

#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// 쿠키의 신체 측정
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	int n;
	cin >> n;
	mat(char, graph, n, n);
	bool isHead = false;
	pii heartPos = { -1, -1 };
	loop(i, home, n) loop(j, home, n)
	{
		cin >> graph[i][j];
		if (graph[i][j] == '*' && !isHead) { isHead = true; heartPos = { i + 1, j };}
	}

	int lArm = home, rArm = home;
	rloop(i, heartPos.rhs - 1, -1) if (graph[heartPos.lhs][i] == '*') lArm++; else break;
	loop(i, heartPos.rhs + 1, n) if (graph[heartPos.lhs][i] == '*') rArm++; else break;

	int hurry = home, hurryI = heartPos.lhs + 1;
	loop(i, heartPos.lhs + 1, n) if (graph[i][heartPos.rhs] == '*') hurry++; else { hurryI = i; break; }

	int lLeg = home, rLeg = home;
	loop(i, hurryI, n)
	{
		if (graph[i][heartPos.rhs - 1] == '*') lLeg++;
		if (graph[i][heartPos.rhs + 1] == '*') rLeg++;
	}

	scp(heartPos.lhs + 1);
	elp(heartPos.rhs + 1);
	scp(lArm); scp(rArm); scp(hurry); scp(lLeg); scp(rLeg);

	return home;
}