#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 1. 온도 최대 합을 구하는 함수
// n 10 k 3 일때
// 012 123 234 345 456 567 678 789
// 처음 온도 합을 구하고 인덱스0 이후 값들의 합 저장
// 뒤에 2개 합 저장 -> 뒤에 k - 1개 합 저장
// 다음 인덱스 -> 저장된값 + (k + i)인덱스의값
// n 10 k 4 일때
// 0123 1234 2345 3456 4567 5678 6789
// 처음 온도 합을 구하고 인덱스0 이후 값들의 합 저장
// 뒤에 3개 합 저장 -> 뒤에 k - 1개 합 저장
// 다음 인덱스 -> 저장된값 + (k + i)인덱스의값
void GetMaxTemp(vector<int> &tempVec, int &max, int sum, int n, int k)
{
	int reuseTemp = 0; // 재사용할 온도 합

	for (int i = 0; i < k; i++) // 처음 온도 합 및 재사용 온도
	{
		sum += tempVec[i]; // 0 + 1 + 2
		reuseTemp = sum - tempVec[0]; // 1 + 2
	}

	if (max < sum) // 최대 온도 합 갱신
	{
		max = sum;
	}

	sum = 0; // 온도 합 초기화

	for (int i = 0; i < n - k; i++) // 1부터 n-k 까지 온도 재사용
	{
		sum = reuseTemp + tempVec[k + i]; // 0 : 1 + 2 + 3 -> 1 : 2 + 3 + 4 -> ... -> 6 : 7 + 8 + 9
		reuseTemp = sum - tempVec[i + 1]; // 0 : 1 + 2 - 1 + 3 = 2 + 3 -> 1 : 2 + 3 - 2 + 4 = 3 + 4 -> ... -> 6 : 7 + 8 - 7 + 9 = 8 + 9

		if (max < sum) // 최대 온도 합 갱신
		{
			max = sum; // 1 + 2 + 3
		}

		sum = 0; // 온도 합 초기화
	}

	cout << max << '\n';
}

// 온도의 최대값
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n, k; // N, K
	cin >> n >> k;

	vector<int> temperatures(100000, 0); // 온도 저장

	int temp; // 온도

	int sumTemp = 0; // 온도 합
	int maxTempSum = -10000000; // 최대 온도 합 : 100000 * (-100) = 10000000

	// 온도 저장
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		temperatures[i] = temp;
	}

	// 1. 온도 최대 합을 구하는 함수
	GetMaxTemp(temperatures, maxTempSum, sumTemp, n, k);

	return 0;
}

// 핵심
// 이전값 재사용