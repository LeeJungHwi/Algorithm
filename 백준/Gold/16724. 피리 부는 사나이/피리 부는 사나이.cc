#include <bits/stdc++.h>
using namespace std;

#define home 0
#define pii pair<int, int>
#define loop(v, s, e) for(int v = s; v < e; v++)
#define elprint(a) cout << a << '\n'
#define mat(t, v, r, c) vector<vector<t> > v(r, vector<t>(c))
#define X first
#define Y second

// 피리 부는 사나이
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m;
	cin >> n >> m;

	mat(char, graph, n, m);
	mat(int, label, n, m);
	map<char, pii> checkDir = { {'U', {-1, 0}}, {'D', {1, 0}}, {'L', {0, -1}}, {'R', {0, 1}} };
	string inputString;
	loop(i, 0, n)
	{
		cin >> inputString;
		loop(j, 0, m) graph[i][j] = inputString[j];
	}

	int cnt = 0;
	int curLabel = 0;
	loop(i, 0, n) loop(j, 0, m)
	{
		if (label[i][j]) continue;

		pii standardPos = { i, j };
		curLabel++;

		while (true)
		{
			// 같은 사이클을 만나면 카운팅
			if (label[standardPos.X][standardPos.Y] == curLabel)
			{
				cnt++;
				break;
			}

			// 다른 사이클을 만나면 종료
			if (label[standardPos.X][standardPos.Y]) break;

			// 라벨링
			label[standardPos.X][standardPos.Y] = curLabel;

			// 이동
			int checkI = standardPos.X + checkDir[graph[standardPos.X][standardPos.Y]].X;
			int checkJ = standardPos.Y + checkDir[graph[standardPos.X][standardPos.Y]].Y;
			standardPos.X = checkI;
			standardPos.Y = checkJ;
		}
	}

	elprint(cnt);

	return home;
}