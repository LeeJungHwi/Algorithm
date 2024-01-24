#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

// 3의 개수는?(large)
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	// 0001
	// 0002
	// ....
	// 0130
	// 0131
	// 0132
	// ....
	// 0130
	// 0131
	// ....
	// 5367

	// 십의자리에서 3이 나오는 경우의 수
	// lt cur rt k(구할 자릿수)
	// 53  6  7  10
	// 003(0~9) : 10개
	// 013(0~9) : 10개
	// 023(0~9) : 10게
	// ....
	// 533(0~9) : 10개
	// cur > 3 경우 (left + 1) * k = 54 * 10 = 540개
	// cur == 3 경우 (left) * k + (right + 1) = 53 * 10 + 8 = 538개
	// cur < 3 경우 (left) * k = 53 * 10 = 530개

	// 천의자리에서 3이 나오는 경우의 수
	// lt cur rt k(구할 자릿수)
	// 0  5  367 1000
	// 3(0~999) : 1000개
	// cur > 3 경우 (left + 1) * k = (0 + 1) * 1000 = 1000개
	// cur == 3 경우 (left) * k + (right + 1) =  0 * 1000 + 368 = 368개
	// cur < 3 경우 (left) * k = 0 * 1000 = 0개

	int left; // cur 왼쪽
	int cur; // 현재 구할 자릿수의 숫자
	int right; // cur 오른쪽
	int k = 1; // 1의 자리부터 구함
	int threeCnt = 0; // 3의 개수 총합

	do
	{
		left = n / (k * 10); // left 갱신 5367 / 10 = 536 -> 53 -> 5 -> 0
		cur = (n / k) % 10; // cur 갱신 5367 % 10 = 7 -> 6 -> 3 -> 5
		right = n % k; // right 갱신 5367 % 1 = 0 -> 7 -> 67 -> 367

		if (cur > 3) // cur > 3 경우 (left + 1) * k
		{
			threeCnt += (left + 1) * k;
		}
		else if (cur == 3) // cur == 3 경우 (left) * k + (right + 1)
		{
			threeCnt += left * k + (right + 1);
		}
		else if (cur < 3) // cur < 3 경우 (left) * k
		{
			threeCnt += left * k;
		}

		k *= 10; // 구할 자릿수 갱신 1 -> 10 -> 100 -> 1000
	} while (left != 0);

	cout << threeCnt << '\n';

	return 0;
}

// 핵심
// 각 자리별로 3의 개수 체크