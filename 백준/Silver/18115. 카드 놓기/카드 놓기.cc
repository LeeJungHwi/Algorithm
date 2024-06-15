#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define rloop(v, s, e) for(int v = s; v > e; v--)
#define scprint(a) cout << a << ' '

// 카드 놓기
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n;
	cin >> n;
	vector<int> A(n);
	loop(i, 0, n) cin >> A[i];
	
	deque<int> d;
	rloop(i, n - 1, -1)
	{
		// 현재카드 위로
		if (A[i] == 1)
		{
			d.push_front(n - i - 1);
			continue;
		}

		if (A[i] == 2)
		{
			// 카드 1장 => 그냥 내려놓음
			if (d.empty())
			{
				d.push_back(n - i - 1);
				continue;
			}

			// 덱 뒤로 백업
			d.push_back(d.front());
			d.pop_front();

			// 현재카드 위로
			d.push_front(n - i - 1);

			// 백업한 카드 원래대로
			d.push_front(d.back());
			d.pop_back();
			continue;
		}
		
		// 현재카드 아래로
		d.push_back(n - i - 1);
	}

	while (!d.empty())
	{
		scprint(d.front() + 1);
		d.pop_front();
	}

	return home;
}