#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

// 자연수 자리수 체크
int NumPosCheck(int num)
{
	int pos = 0;

	if (num < 10)
	{
		return pos = 1;
	}
	else if (num >= 10 && num < 100)
	{
		return pos = 2;
	}
	else if (num >= 100 && num < 1000)
	{
		return pos = 3;
	}
	else if (num >= 1000 && num < 10000)
	{
		return pos = 4;
	}
	else if (num >= 10000 && num < 100000)
	{
		return pos = 5;
	}
}

// 숫자를 뒤집는 함수
// 3700
// 37
// 73
int reverse(int num)
{
	int reverseNum = 0; // 뒤집힌 자연수
	int pos = 0; // 자연수 자릿수

	// 3700
	// 370
	// 37
	while (num % 10 == 0) // 10으로 나눈 나머지가 0일때 반복
	{
		num /= 10; // 1의자리 제거
	}

	// 자연수 뒤집기
	// 37
	// 7 * 10^1 + 3 * 10^0
	// 73
	pos = NumPosCheck(num); // 자연수 자릿수 체크

	for (int i = pos; i > 0; i--)
	{
		reverseNum += (num % 10) * pow(10, i - 1); // 70 + 3
		num /= 10; // 1의자리 제거
	}

	return reverseNum;
}

// 소수인지 체크
// 1보다 큰 자연수 중 약수로 1과 자기자신만 가져야함
bool isPrime(int num)
{
	if (num == 1) // 뒤집은 자연수가 1이면 소수 아님
	{
		return false;
	}

	for (int i = 2; i < num; i++) // 1과 자기자신을 제외한 수로 나누었을때 나누어 떨어지면 소수 아님
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}

// 뒤집은 소수
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	int num; // 자연수

	for (int i = 0; i < n; i++)
	{
		cin >> num;

		num = reverse(num); // 자연수 뒤집기
		
		if (isPrime(num)) // 뒤집은 수가 소수면 출력
		{
			cout << num << ' ';
		}
	}

	return 0;
}

// 핵심
// 소수 -> 1보다 큰 자연수 중 1과 자기자신만 약수로 가지는 수 