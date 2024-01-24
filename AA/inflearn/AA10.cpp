#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 자릿수 합
// 125 = 100 + 20 + 5 = ((num - num % 100) / 100) + (num % 100 - num % 10) + num % 10
int digit_sum(int x)
{
	int sum = 0; // 자릿수 합

	for (int j = 10000000; j > 0; j /= 10) // 자릿수 합 구하기
	{
		sum += ((x - x % j) / j);
		x %= j;
	}

	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	int num; // 자연수

	int maxSum = 0; // 자릿수 합 최대

	int maxNum = 0; // 자릿수 합 최대인 수

	vector<int> sums(101); // 각 자연수의 자릿수 합

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		int saveNum = num; // 자연수 백업

		sums[i] = digit_sum(num); // 자릿수 합

		if (maxSum < sums[i]) // 자릿수 합 최대보다 크면 자릿수 합 최대 갱신
		{
			maxSum = sums[i];
			maxNum = saveNum;
		}
		else if (maxSum == sums[i]) // 자릿수 합 최대랑 같으면 자릿수 합 최대인 수 갱신
		{
			if (maxNum < saveNum)
			{
				maxNum = saveNum;
			}
		}
	}

	cout << maxNum << '\n';

	return 0;
}