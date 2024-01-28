#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 인접행렬
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream cin;
	cin.open("input.txt");

	int n, m; // N, M
	cin >> n >> m;

	int vertex1; // 정점1
	int vertex2; // 정점2
	int cost; // 거리비용

	vector<vector<int> > adjacencyVec(n, vector<int>(n)); // 인접행렬

	// 인접행렬 초기화
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> vertex1 >> vertex2 >> cost;

			adjacencyVec[vertex1 - 1][vertex2 - 1] = cost;
		}
	}

	// 인접행렬 출력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << adjacencyVec[i][j] << ' ';
		}

		cout << '\n';
	}

	return 0;
}