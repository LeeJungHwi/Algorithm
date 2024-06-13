#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define elprint(a) cout << a << '\n'
#define mat(t, v, r, c) vector<vector<t> > v(r, vector<t>(c))

// 케빈 베이컨의 6단계 법칙
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m;
	cin >> n >> m;
	mat(int, graph, n, n);
	vector<int> dis(n);
	queue<int> checkPos;

	int v1, v2;
	loop(i, 0, m)
	{
		cin >> v1 >> v2;
		graph[v1 - 1][v2 - 1] = 1;
		graph[v2 - 1][v1 - 1] = 1;
	}

	int minDis = 2147000000;
	int ans = 1;
	loop(i, 0, n)
	{
		checkPos.push(i);
		dis[i] = 1;
		int sumDis = 0;

		// i => 각 j 까지 거리
		while (!checkPos.empty())
		{
			int standardPos = checkPos.front();
			checkPos.pop();

			loop(j, 0, n)
			{
				if (!graph[standardPos][j]) continue;
				if (dis[j] > 0) continue;

				checkPos.push(j);
				dis[j] = dis[standardPos] + 1;
			}
		}

		// 누적
		loop(j, 0, n)
		{
			sumDis += dis[j];
			dis[j] = 0;
		}

		// 갱신
		if (minDis > sumDis)
		{
			minDis = sumDis;
			ans = i + 1;
		}
	}

	elprint(ans);

	return home;
}