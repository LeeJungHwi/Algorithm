#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define elprint(a) cout << a << '\n'

// 청기 백기
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n;
	cin >> n;

	int ans = 0;

	// 초기 => 청(위) 백(아래)
	// 약수 개수 홀수 => 백(위)
	loop(i, 1, sqrt(n) + 1) if (i * i < n + 1) ans++;

	elprint(ans);

	return home;
}