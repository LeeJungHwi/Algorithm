#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define elprint(a) cout << a << '\n'
#define mat(t, v, r, c, i) vector<vector<t> > v(r, vector<t>(c, i))

// 행렬 곱셈 순서
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n;
	cin >> n;

	// 각 행렬의 행과 열
	vector<int> r(n + 1), c(n + 1);
	loop(i, 1, n + 1) cin >> r[i] >> c[i];

	// dp[i][j] => i부터 j까지 행렬을 곱하는 데 필요한 최소연산
	mat(int, dp, n + 1, n + 1, 2147000000);
	
	// 단일행렬 처리 => 연산 0
	loop(i, 1, n + 1) dp[i][i] = 0;

	// l => 연속된 행렬 개수
	// i => 연속된 행렬 개수까지 각 행렬에 대해
	// j => 현재 연속된 행렬 개수에 대해 마지막 행렬
	// i부터 j까지 행렬의 곱을 i부터 k까지 행렬의 곱과 k + 1부터 j까지 행렬의 곱으로 분할
	// r[i] * c[k] * c[j] => 현재 두 행렬의 곱에 대한 연산 수
	// 더 최소연산이면 갱신
	loop(l, 1, n + 1) loop(i, 1, n - l + 2)
	{
		int j = i + l - 1;
		loop(k, i, j) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + r[i] * c[k] * c[j]);
	}

	// 첫 행렬 부터 마지막 행렬 까지 최소연산 수
	elprint(dp[1][n]);

	return home;
}