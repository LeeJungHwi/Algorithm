#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// N!의 0의 개수
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	// 12! = 12 11 10 9 8 7 6 5 4 3 2 1
	// 2 * 5가 두쌍이므로 연속된 0의 개수는 2개
	// 2와 5의 개수 중에서 작은값을 구해야함
	// 5의 개수가 2의 개수보다 항상 작으므로 5의 개수를 구해야함
	// 5의 배수로 반복문 돌면서 5로 나누어 떨어지지 않을때까지 나눈 후 나눈 횟수 카운팅

	int divideCnt = 0;

	for (int i = 5; i < n + 1; i += 5)
	{
		int share = i; // 몫 초기화

		while (true)
		{
			if (share % 5 != 0) // 5로 나누어 떨어지지 않으면 종료
			{
				break;
			}

			share = share / 5; // 몫 갱신
			divideCnt++; // 나눈 횟수 카운팅
		}
	}

	cout << divideCnt << '\n';

	return 0;
}