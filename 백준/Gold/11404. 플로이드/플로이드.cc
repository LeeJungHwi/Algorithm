#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 플로이드와샬
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 5, 14
	cin >> n >> m;

	vector<vector<int> > minDis(n + 1, vector<int>(n + 1, 1000000000)); // 그래프 : 거쳐가는 중간노드를 몇개 사용하는지에 따라 최소비용 갱신

	int v1, v2, c; // 정점 및 비용

	// 연결정보가 저장(i에서 j로 직행했을때 거리), i == j는 0, 나머지는 max값으로 초기화
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2 >> c;

		// 같은 시작도시 -> 도착도시가 들어올수있으므로 최단거리 직행거리를 저장
		if (minDis[v1][v2] == 0)
		{
			minDis[v1][v2] = c;

			continue;
		}
		else
		{
			minDis[v1][v2] = min(minDis[v1][v2], c);
		}
	}

	for (int i = 1; i < n + 1; i++)
	{
		minDis[i][i] = 0;
	}

	// 거쳐가는 중간노드를 몇개 사용하는지에 따라 최소비용 갱신 -> k는 거쳐가는 중간노드로 1개부터 노드개수만큼 늘려가면서 다이나믹
	for (int k = 1; k < n + 1; k++)
	{
		for (int i = 1; i < n + 1; i++)
		{
			for (int j = 1; j < n + 1; j++)
			{
				if (minDis[i][j] > minDis[i][k] + minDis[k][j])
				{
					minDis[i][j] = minDis[i][k] + minDis[k][j];
				}
			}
		}
	}

	// 정점 i 에서 정점 j 로 가는 최단거리 출력
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (minDis[i][j] == 1000000000) // 갈수없다면 0 출력
			{
				cout << 0 << ' ';

				continue;
			}

			cout << minDis[i][j] << ' ';
		}

		cout << '\n';
	}

	return 0;
}