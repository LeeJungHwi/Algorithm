#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

vector<int> dpZero(41); // 각 n에 대해 0 횟수 저장
vector<int> dpOne(41); // 각 n에 대해 1 횟수 저장

// 0, 1 횟수 리턴
pair<int, int> Fib(int n)
{
	if (dpZero[n] > 0 && dpOne[n] > 0) return { dpZero[n], dpOne[n] }; // 재사용
	else if (n == 0) return { 1, 0 };
	else if (n == 1) return { 0, 1 };
	else
	{
		// 메모
		dpZero[n] = Fib(n - 1).first + Fib(n - 2).first;
		dpOne[n] = Fib(n - 1).second + Fib(n - 2).second;

		return { dpZero[n], dpOne[n] };
	}
}

// 피보나치 함수
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int tc; // TC 3
	cin >> tc;

	int n;

	while (tc--)
	{
		cin >> n;

		pair<int, int> cnt = Fib(n);

		cout << cnt.first << ' ' << cnt.second << '\n';
	}

	return 0;
}