#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

map<int, long long> fib; // 메모 재사용

long long FibExtend(int curN)
{
	if (fib[curN] > 0) return fib[curN] % 1000000000;
	else if (curN == 0) return 0;
	else if (curN == 1) return 1;
	else return fib[curN] = FibExtend(curN - 1) % 1000000000 + FibExtend(curN - 2) % 1000000000;
}

// 피보나치 수의 확장
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 1.
	// 0 1 1 2 3 5
	// 0 1 -1 2 -3 5
	// f(1) = f(0) + f(-1) => f(-1) = f(1) - f(0) = 1
	// f(0) = f(-1) + f(-2) => f(-2) = f(0) - f(-1) = -1
	// f(-1) = f(-2) + f(-3) => f(-3) = f(-1) - f(-2) = 2
	// ...
	// n < 0
	// f(n) = f(n + 2) - f(n + 1)
	// f(-4) = f(-2) - f(-3) = -3
	// f(-5) = f(-3) - f(-4) = 5 <=> f(5) = f(4) + f(3)

	// n == 0 => 0
	// n == 1 => 1
	// n > 1 : f(n - 1) + f(n - 2)
	// n < 0 : f(n + 2) - f(n + 1)

	// 2.
	// n >= 0 : 0 1 1 2 3 5
	// n <= 0 : 0 1 -1 2 -3 5
	// n == 0 => 0
	// n == 1 => 1
	// n > 1 : f(n - 1) + f(n - 2)
	// n < 0 : 짝수 : 양수 피보나치의 음수, 홀수 : 양수 피보나치

	// 일단 양수 n에 대해 피보나치 수를 구하고
	// n이 음수면서 짝수면 -1

	int n; // N -2
	cin >> n;

	fib[0] = 0;
	fib[1] = 1;

	long long ans = FibExtend(abs(n)) % 1000000000;

	if (n == 0) cout << 0 << '\n' << 0 << '\n';
	else if (n < 0 && n % 2 == 0) cout << -1 << '\n' << ans << '\n';
	else cout << 1 << '\n' << ans << '\n';

	return 0;
}