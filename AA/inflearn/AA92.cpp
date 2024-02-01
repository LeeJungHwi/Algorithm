#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int n;
vector<int> caseCnt(46);

int DFS(int n)
{
	if (caseCnt[n] > 0) // 재사용 : 이미 구해진 값 반환
	{
		return caseCnt[n];
	}
	else if (n == 2)
	{
		return caseCnt[2];
	}
	else if (n == 1)
	{
		return caseCnt[1];
	}
	else
	{
		return caseCnt[n] = DFS(n - 2) + DFS(n - 1); // 메모
	}
}

// 네트워크 선 자르기(topDown)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n;

	caseCnt[1] = 1;
	caseCnt[2] = 2;

	DFS(n);

	cout << caseCnt[n];

	return 0;
}
// 핵심
// DP
/*
topDown : DFS와 메모이제이션 이용
*/