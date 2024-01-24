#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

// 졸리 점퍼
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	vector<int> cntSubSequences(101, 0); // 인접한 두 수의 차 카운트

	int num; // 숫자
	int preNum = 0; // 이전 숫자
	int subNum = 0; // 인접한 두 수의 차

	// 처음 숫자 저장 -> 0번
	cin >> num;
	preNum = num;

	for (int i = 1; i < n; i++) // -> 1 ~ n-1번
	{
		cin >> num;

		// 인접한 두 수의 차 저장
		subNum = abs(preNum - num);

		if (subNum > 0 && subNum < 101)
		{
			cntSubSequences[subNum]++;
		}

		// 이전 숫자 갱신
		preNum = num;
	}

	// 졸리점퍼인지 체크
	// 4
	// -2 1 2 4
	// 3 1 2
	for (int i = 1; i < n; i++)
	{
		if (cntSubSequences[i] == 0) // 하나라도 0이면 NO
		{
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n"; // 모두 가지면 YES
	return 0;
}

// 핵심
// 졸리 점퍼 -> 1부터 N-1 까지 수를 인접한 두 수의 차가 모두 가져야함