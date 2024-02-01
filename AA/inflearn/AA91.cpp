#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 네트워크 선 자르기(BottomUp)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 7
	cin >> n;

	vector<int> caseCnt(n + 1); // 각 길이를 가지는 선을 자르는 경우의 수 기록

	// 1m 선을 자르는방법 : 1 -> 1가지
	// 2m 선을 자르는방법 : 1+1, 2 -> 2가지
	caseCnt[1] = 1;
	caseCnt[2] = 2;

	// 3m 선을 자르는방법 : 마지막 선의 길이가 1m 일때 앞의 2m를 자르는 방법은 2가지 + 마지막 선의 길이가 2m 일때 앞의 1m를 자르는 방법은 1가지 -> caseCnt[3] = caseCnt[2] + caseCnt[1] -> 3가지
	// 4m 선을 자르는방법 : 마지막 선의 길이가 1m 일때 앞의 3m를 자르는 방법은 3가지 + 마지막 선의 길이가 2m 일때 앞의 2m를 자르는 방법은 2가지 -> caseCnt[4] = caseCnt[3] + caseCnt[2] -> 5가지
	// f(n) = f(n-2) + f(n-1)
	for (int i = 3; i < n + 1; i++)
	{
		caseCnt[i] = caseCnt[i - 2] + caseCnt[i - 1];
	}

	cout << caseCnt[n] << '\n';

	return 0;
}
// 핵심
// DP
/*
bottomUp : 작은문제 해로부터 점화식을 통해 큰문제로 확장
*/