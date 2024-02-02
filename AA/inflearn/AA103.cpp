#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 플로이드와샬
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 5 8
	cin >> n >> m;

	vector<vector<int> > minDis(n + 1, vector<int>(n + 1, 5000)); // 그래프 : 거쳐가는 중간노드를 몇개 사용하는지에 따라 최소비용 갱신

	int v1, v2, c; // 정점 및 비용

	// 연결정보가 저장(i에서 j로 직행했을때 거리), i == j는 0, 나머지는 max값으로 초기화
	/*
	Input =
			1 2 6
			1 3 3
			3 2 2
			2 4 1
			2 5 13
			3 4 5
			4 2 3
			4 5 7

	graph = 0 6 3 M M
			M 0 M 1 13
			M 2 0 5 M
			M 3 M 0 7
			M M M M 0
	*/
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2 >> c;

		minDis[v1][v2] = c;
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
			if (minDis[i][j] == 5000) // 갈수없다면 M 출력
			{
				cout << 'M' << ' ';
				continue;
			}

			cout << minDis[i][j] << ' ';
		}

		cout << '\n';
	}

	return 0;
}
// 핵심
// 플로이드와샬
/*
모든 정점에서 모든 정점으로 가는 최단거리를 구함
minDis[i][j] = min(minDis[i][j], minDis[i][k] + minDis[k][j]) -> 정점 i 에서 정점 j 로 가는 최단거리, k는 거쳐가는 중간노드
*/