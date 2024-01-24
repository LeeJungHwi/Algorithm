#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <fstream>
using namespace std;

// 연속 부분 증가수열
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");
	//freopen("input.txt", "rt", stdin);

	int n; // N
	scanf_s("%d", &n);

	int num; // 숫자

	int preNum = 0; // 수열 숫자
	int length = 0; // 증가수열 길이
	int maxLength = 0; // 증가수열 최대길이

	// 증가수열 최대길이 구하기
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &num);

		if (preNum <= num) // 증가수열
		{
			length++;

			if (maxLength < length)
			{
				maxLength = length;
			}
		}
		else
		{
			length = 1; // 전값보다 작아 초기화 되었지만 새롭게 시작하므로 첫 증가 부분
		}

		preNum = num;
	}

	printf("%d\n", maxLength);

	return 0;
}

// 핵심
// 시간초과 -> printf scanf가 cout cin보다 빠름