#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define scprint(a) cout << a << ' '
#define mat(t, v, r, c) vector<vector<t> > v(r, vector<t>(c))

// 누울 자리를 찾아라
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n;
	cin >> n;
	mat(char, graph, n, n);
	loop(i, 0, n) loop(j, 0, n) cin >> graph[i][j];
	int hAns = 0, vAns = 0;
	loop(i, 0, n)
	{
		char pre = 'X';
		loop(j, 0, n)
		{
			if (graph[i][j] == '.' && pre == '.')
			{
				hAns++;
				pre = 'X';

				loop(k, j, n)
				{
					if (graph[i][k] == 'X')
					{
						pre = 'X';
						break;
					}

					j = k;
				}
			}

			pre = graph[i][j];
		}
		
		pre = 'X';
		loop(j, 0, n)
		{
			if (graph[j][i] == '.' && pre == '.')
			{
				vAns++;
				pre = 'X';

				loop(k, j, n)
				{
					if (graph[k][i] == 'X')
					{
						pre = 'X';
						break;
					}

					j = k;
				}
			}

			pre = graph[j][i];
		}
	}

	scprint(hAns);
	scprint(vAns);

	return home;
}