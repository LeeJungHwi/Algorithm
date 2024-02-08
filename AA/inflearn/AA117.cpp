#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 강 건너기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 4
	cin >> n;

	vector<int> times(n); // 각 사람이 강을 건너는 시간 저장 1 3 7 10

	for (int i = 0; i < n; i++)
	{
		cin >> times[i];
	}

	sort(times.begin(), times.end()); // 1 3 7 10

	// min(1 3이 7 10 옮기기, 1이 7 10 옮기기) 누적
	// 1 3이 7 10 옮기기 -> 1 3 이동(3) + 3 다시건너옴(3) + 7 10 이동(10) + 1 다시건너옴(1) -> 17
	// 1이 7 10 옮기기 -> 1 10 이동(10) + 1 다시건너옴(1) + 1 7 이동(7) + 1 다시건너옴(1) -> 19
	// 1 3이 7 10 옮기는게 더 최소이므로 값 누적
	// 사람이 홀수명이면 세번째 사람은 1이 옮기기 -> 1 세번째 이동(세번째사람시간) + 1 다시건너옴(1)
	// 마지막에 1 3 건너기

	int result = 0; // 모든 사람이 강 건너는 최소시간 누적

	for (int i = 0; i < n / 2 - 1; i++) // n / 2 - 1번 반복해야함
	{
		int duoTime = 0; // 1 3이 같이 옮기는데 걸리는 시간
		int soloTime = 0; // 1이 혼자 옮기는데 걸리는 시간

		// 1 3이 같이 옮기는데 걸리는 시간
		duoTime = times[1] * 2 + times[n - i * 2 - 1] + times[0]; // 1 3 이동(3) + 3 다시건너옴(3) + 7 10 이동(10) + 1 다시건너옴(1)

		// 1이 혼자 옮기는데 걸리는 시간
		soloTime = times[0] * 2 + times[n - i * 2 - 1] + times[n - i * 2 - 2]; // 1 10 이동(10) + 1 다시건너옴(1) + 1 7 이동(7) + 1 다시건너옴(1) -> 19

		// 최소시간 누적
		result += min(duoTime, soloTime);
	}

	//// 사람이 홀수명이면 세번째 사람은 1이 옮기기
	if (n % 2 != 0)
	{
		result += times[2] + times[0]; // 1 세번째사람 이동(세번째사람시간) + 1 다시건너옴(1)
	}

	// 마지막에 1 3 건너기
	result += times[1];

	cout << result << '\n';

	return 0;
}
// 핵심
// 처음 두 사람이 마지막 두 사람부터 옮기기
// 홀수명이면 세번째 사람은 첫번째 사람이 옮기기
// 마지막에 처음 두 사람 옮기기