#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 돌다리 건너기(bottomUp)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // 7
	cin >> n;

	vector<int> caseCnt(n + 2);

	// 돌다리 1개를 건너는 방법 : 1가지
	// 돌다리 2개를 건너는 방법 : 1 + 1, 2 -> 2가지
	// 돌다리 3개를 건너는 방법 : 돌다리 2개 + 돌다리 1개 -> 3가지
	// f(n) = f(n-2) + f(n-1)
	// 돌다리가 7개 이므로 도착지점은 n+1
	caseCnt[1] = 1;
	caseCnt[2] = 2;

	for (int i = 3; i < n + 2; i++)
	{
		caseCnt[i] = caseCnt[i - 2] + caseCnt[i - 1];
	}

	cout << caseCnt[n + 1] << '\n';

	return 0;
}