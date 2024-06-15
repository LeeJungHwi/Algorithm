#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define elprint(a) cout << a << '\n'

// But can you do it in 0.5x A presses?
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n;
	cin >> n;
	double num;
	bool isFirst = false;
	int cnt = 0;
	loop(i, 0, n)
	{
		cin >> num;

		// 처음 만나면 => 누른 상태로
		if (!isFirst && num > 0)
		{
			isFirst = true;
			cnt += round(num);
			continue;
		}

		// 그 이후는 정수값 만큼
		cnt += (int)num;
	}

	elprint(cnt);

	return home;
}