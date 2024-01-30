#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 팩토리얼
//int factorial(int num)
//{
//	if (num == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return num * factorial(num - 1);
//	}
//}

// 이항계수
int BiCoef(int n, int r)
{
	if (r == 0 || n == r)
	{
		return 1;
	}
	else
	{
		return BiCoef(n - 1, r - 1) + BiCoef(n - 1, r);
	}
}

// 이항계수(메모이제이션)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, r; // N, N
	cin >> n >> r;

	//int divisor = 1, dividend = 1; // 제수, 피제수

	//// 5 * 4 * 3
	//for (int i = n; i > n - r; i--)
	//{
	//	dividend *= i;
	//}

	//// 3 * 2 * 1
	//for (int i = r; i > 0; i--)
	//{
	//	divisor *= i;
	//}

	//cout << dividend / divisor << '\n';

	cout << BiCoef(n, r) << '\n';

	return 0;
}
// 핵심
// 이항계수
// 5C3 = 4C2 + 4C3 -> nCr = n-1Cr-1 + n-1Cr
// 4C2 = 3C1 + 3C2
// 3C1 = 2C0 + 2C1 -> nCr에서 r이 0일때 종료
// 2C1 = 1C0 + 1C1 -> nCr에서 r이 0이거나 n == r일때 종료
