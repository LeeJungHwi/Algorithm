#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define print(a) cout << a

// 신촌 통폐합 계획
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n;
	cin >> n;

	vector<string> univ(n);
	vector<int> next(n);
	vector<int> last(n);

	// 통폐합 순서
	loop(i, 0, n)
	{
		cin >> univ[i];
		last[i] = i;
	}

	int u1, u2;
	loop(i, 0, n - 1)
	{
		cin >> u1 >> u2;
		u1 -= 1;
		u2 -= 1;
		next[last[u1]] = u2;
		last[u1] = last[u2];
	}

	// 순서대로
	loop(i, 0, n)
	{
		print(univ[u1]);
		u1 = next[u1];
	}

	return home;
}
