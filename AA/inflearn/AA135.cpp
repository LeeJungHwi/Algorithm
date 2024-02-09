#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 유니온 파인드 집합
vector<int> unf(10001);

// 도로정보 구조체
struct Edge
{
	int vertex1; // 호텔1
	int vertex2; // 호텔2
	double distance; // 두 호텔을 연결하는 거리

	Edge(int v1, int v2, double dis) // 생성자
	{
		vertex1 = v1;
		vertex2 = v2;
		distance = dis;
	}

	bool operator<(Edge &edge) // 거리 기준 오름차순 정렬
	{
		return distance < edge.distance;
	}
};

// 파인드
// 호텔이 속한 집합 번호 반환 : 집합의 번호는 집합의 루트번호
int Find(int v)
{
	if (v == unf[v])
	{
		return v;
	}
	else
	{
		return unf[v] = Find(unf[v]);
	}
}

// 유니온
// 두 호텔이 속한 집합 번호가 다르면 하나로 합침
void Union(int v1, int v2)
{
	v1 = Find(v1);
	v2 = Find(v2);

	if (v1 != v2)
	{
		unf[v1] = v2;
	}
}

// 호텔연결
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 5, 2
	cin >> n >> m;

	vector<Edge> edge; // 도로정보

	int v1, v2; // 정점
	double minDis = 0; // 추가적인 도로의 최소길이

	vector<double> X, Y; // 호텔 좌표 저장
	int x, y; // 좌표

	// 도로정보 초기화
	//	2 1
	//	4 1
	//	5 1
	//	4 3
	//	1 2
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;

		X.push_back(x);
		Y.push_back(y);

		unf[i] = i; // 유니온파인드 집합 초기화
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			double dis = sqrt((X[j] - X[i]) * (X[j] - X[i]) + (Y[j] - Y[i]) * (Y[j] - Y[i])); // i번호텔에서 j개의 각 호텔 사이 거리를 구함
			edge.push_back(Edge(i, j, dis)); // 도로정보 저장
		}
	}

	// 이미 연결된 도로정보 초기화
	//	1 2
	//	2 3
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2;

		Union(v1 - 1, v2 - 1);
	}

	// 도로 거리기준 오름차순 정렬 : 가장 작은 거리부터 파인드하기위해
	sort(edge.begin(), edge.end());

	// 유니온 파인드로 호텔을 연결하면서 도로거리 누적
	for (int i = 0; i < edge.size(); i++)
	{
		int findVertex1 = Find(edge[i].vertex1);
		int findVertex2 = Find(edge[i].vertex2);

		if (findVertex1 != findVertex2) // 호텔이 서로 다른집합에 속하면 
		{
			minDis += edge[i].distance; // 거리 누적
			Union(edge[i].vertex1, edge[i].vertex2); // 집합 합침
		}
	}

	// 소수 셋째 자리에서 반올림 출력
	cout << fixed;
	cout.precision(2);
	cout << minDis;

	return 0;
}
