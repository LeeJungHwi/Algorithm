#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int n; // 7
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

// 계단오르기(topDown)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n;

	// 계단 1개 : 1가지
	// 계단 2개 : 1 + 1, 2 -> 2가지
	// 계단 3개 : 마지막에 계단을 1개 올라갈때 앞에 계단 2개를 올라가는 방법 2가지 + 마지막에 계단을 2개 올라갈때 앞에 계단 1개를 올라가는 방법 1가지 -> 3가지
	caseCnt[1] = 1;
	caseCnt[2] = 2;
	DFS(n);

	cout << caseCnt[n] << '\n';

	return 0;
}