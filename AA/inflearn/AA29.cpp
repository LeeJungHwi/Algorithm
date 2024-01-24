#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int threeCnt; // 3의 개수

// 자릿수 얻는 함수
int GetPos(int n)
{
	int pos = 0;

	if (n < 10)
	{
		return pos = 1;
	}
	else if (n < 100)
	{
		return pos = 2;
	}
	else if (n < 1000)
	{
		return pos = 3;
	}
	else if (n < 10000)
	{
		return pos = 4;
	}
	else if (n < 100000)
	{
		return pos = 5;
	}
}

// 3의 개수는?(small)
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	for (int i = 1; i < n + 1; i++)
	{
		int tempNum = i; // 카운팅하기위해 임시숫자 초기화 353

		for (int j = 0; j < GetPos(i); j++)
		{
			if (tempNum % 10 == 3) // 10으로 나눈 나머지가 3이면 카운팅
			{
				threeCnt++;
			}

			tempNum /= 10; // 1의 자리 갱신 35
		}
	}
	cout << threeCnt;

	return 0;
}

// 핵심
// 일의 자리 체크