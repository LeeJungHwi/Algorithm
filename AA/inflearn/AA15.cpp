#include <iostream>
#include <fstream>
using namespace std;

// 소수의 개수
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	int cntPrime = 0; // 소수 개수
	bool isPrime = false; // 소수인지 체크

	// 소수인지 체크 후 소수 개수 증가
	// 36
	// = 1 * 36
	// = 2 * 18
	// = 3 * 12
	// = 4 * 9
	// = 6 * 6
	// 36의 제곱근 까지만 체크하면 됨
	for (int i = 2; i < n + 1; i++) // 2~N 까지
	{
		isPrime = true;

		for (int j = 2; j * j <= i; j++) // 1과 자기자신을 제외한 수로 나누었을때 나누어 떨어지면 소수 아님, 자연수의 제곱근 까지만 체크
		{
			if (i % j == 0) // i의 약수가 j이면 소수가 아님
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime)
		{
			cntPrime++;
		}
	}

	cout << cntPrime << '\n';

	return 0;
}

// 핵심
// 소수 체크 -> 자연수의 제곱근 까지만 체크