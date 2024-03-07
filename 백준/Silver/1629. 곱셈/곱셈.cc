#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// A^B % C
long long ApowerBmodC(long long A, long long B, long long C)
{
	// 0승
	if (B == 0)
	{
		return 1 % C;
	}
	
	// 짝수
	// A^4 = (A^2)^2
	if (B % 2 == 0)
	{
		long long half_power = ApowerBmodC(A, B / 2, C); // A^2
		return (half_power * half_power) % C; // (A^2)^2
	}

	// 홀수
	// A^5 = A * 4^4 = A * (A^2)^2
	return (A * ApowerBmodC(A, B - 1, C)) % C; // A * (A^2)^2
}

// 곱셈
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	long long A, B, C; // A, B, C 10, 11, 12
	cin >> A >> B >> C;

	long long result = ApowerBmodC(A, B, C); // 4
	cout << result << '\n';

	return 0;
}
