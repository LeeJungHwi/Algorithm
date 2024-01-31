#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<pair<int, int> > consulting; // T, P 쌍 저장
int n; // N 7
int maxPay; // 최대 급여

void GetMaxPay(int i, int sumPay)
{
	if (i == n) // 종료조건 : n일 일때 종료
	{
		if (sumPay > maxPay)
		{
			maxPay = sumPay;
		}
	}
	else
	{
		if (i + consulting[i].first < n + 1) // 상담날짜를 더했을때 휴가날까지만 가능
		{
			GetMaxPay(i + consulting[i].first, sumPay + consulting[i].second); // 상담을 한다
		}

		GetMaxPay(i + 1, sumPay); // 상담을 안 한다
	}
}

// 휴가
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n;

	int t, p; // T, P

	//  T P
	//	4 20
	//	2 10
	//	3 15
	//	3 20
	//	2 30
	//	2 20
	//	1 10
	for (int i = 0; i < n; i++)
	{
		cin >> t >> p;
		consulting.push_back({ t, p });
	}

	// 스케쥴링
	// 종료조건 : n일 일때 종료
	// 상담을 한다 안한다로 구분
	GetMaxPay(0, 0);

	cout << maxPay << '\n';

	return 0;
}