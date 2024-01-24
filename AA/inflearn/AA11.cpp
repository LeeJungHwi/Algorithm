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

// 자연수 자릿수에 따른 숫자 개수
// 1~9 : 1 * 9 * 10^0
// 10~99 : 2 * 9 * 10^1
// 100~999 : 3 * 9 * 10^2
// 1000~9999 : 4 * 9 * 10^3
// ....
// 재귀
// 세자리 수 : 한자리 수 + 두자리 수 + num관련
// 네자리 수 : 한자리 수 + 두자리 수 + 세자리 수 + num관련
// ....
int PosCount(int pos)
{
	int cnt = pos * 9 * pow(10, pos - 1); // 숫자 개수

	if (pos == 1)
	{
		return cnt;
	}
	else
	{
		return cnt += PosCount(pos - 1);
	}
}

// 자연수에 따른 숫자 개수
// num이 한자리 수 : num
// num이 두자리 수 : PosCount(1) + (num - 9) * 2
// num이 세자리 수 : PosCount(1) + PosCount(2) + (num - 99) * 3
// num이 네자리 수 : PosCount(1) + PosCount(2) + PosCount(3) + (num - 999) * 4
// ....
// 9 99 999 9999 : (10 - 1) (100 - 1) (1000 - 1) (10000 - 1)
int NumCount(int num)
{
	int pos = NumPosCheck(num); // 자연수 자리수 체크

	if (pos == 1)
	{
		return num;
	}
	else
	{
		return PosCount(pos - 1) + (num - (pow(10, pos - 1) - 1)) * pos;
	}
}

// 숫자의 총 개수(small)
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	cout << NumCount(n) << "\n";

	return 0;
}

// 핵심
// pow(n, m) -> n의 m제곱 리턴