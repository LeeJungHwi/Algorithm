#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void IsFriend(int v1, int v2, vector<int> graph[], bool &isFriend, vector<bool> &vis)
{
	if (v1 == v2) // 종료조건 : 연결되어있으면 친구
	{
		isFriend = true;
	}
	else
	{
		for (int i = 0; i < graph[v1].size(); i++) // 갈수있는곳 양방향으로 연결 하고 방문체크만
		{
			if (!vis[graph[v1][i]])
			{
				vis[graph[v1][i]] = true; // 방문 체크
				IsFriend(graph[v1][i], v2, graph, isFriend, vis);
				vis[graph[v1][i]] = false; // 방문 해제
			}
		}
	}
}

// 친구인가?
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 20, 22
	cin >> n >> m;

	int v1, v2; // 정점

	vector<int> graph[1000]; // 그래프
	vector<bool> vis(1000); // 방문체크

	bool isFriend = false; // 친구인지 체크

	//	17 -> 8
	//	3 -> 14
	//	11 -> 15
	//	8 -> 9
	//	9 -> 6
	//	13 -> 8
	//	12 -> 2
	//	16 -> 4
	//	5 -> 0
	//	0 -> 13
	//	11 -> 3
	//	8 -> 10
	//	6 -> 4
	//	16 -> 3
	//	5 -> 16
	//	11 -> 8
	//	17 -> 9
	//	16 -> 7
	//	10 -> 17
	//	6 -> 18
	//	3 -> 2
	//	2 -> 3

	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2;

		// 양방향으로 연결
		graph[v1 - 1].push_back(v2 - 1);
		graph[v2 - 1].push_back(v1 - 1);
	}

	cin >> v1 >> v2; // 10, 15

	IsFriend(v1 - 1, v2 - 1, graph, isFriend, vis);

	if (isFriend) // 친구
	{
		cout << "YES\n";

		return 0;
	}

	cout << "NO\n"; // 친구 아님

	return 0;
}
// 핵심
// 양방향으로 연결