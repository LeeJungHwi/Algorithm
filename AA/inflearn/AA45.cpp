#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// 공주구하기(조세퍼스)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, k; // N, K
	cin >> n >> k;

	vector<int> princes(n); // 나이순으로 n명의 왕자
	vector<bool> cantGo(n); // 갈수없는 왕자 체크

	for (int i = 0; i < n; i++)
	{
		princes[i] = i; // 0 1 2 3 4 5 6 7
	}

	// 공주를 구하러 갈 왕자 구하기
	// 1 2 3 -> 3 제외
	// 4 5 6 -> 6 제외
	// 7 8 1 -> 1 제외
	// 2 4 5 -> 5 제외
	// 7 8 2 -> 2 제외
	// 4 7 8 -> 8 제외
	// 4 7 4 -> 4 제외
	// 7번 왕자가 공주 구하기

	int shoutNum = 0; // 외치는 숫자
	int canGoCnt = n; // 구하러 갈수있는 왕자 수
	int preShout = 0; // 이전에 번호를 외친 왕자

	for (int i = 0; i < n; i++)
	{
		if (!cantGo[i]) // 제외된 왕자가 아닐때만
		{
			shoutNum++; // 번호 외치기

			if (shoutNum == k) // 외친 번호가 k면 제외
			{
				cantGo[i] = true;
				canGoCnt--;
				shoutNum = 0;

				if (canGoCnt == 1) // 갈 수 있는 왕자가 한명이면 종료
				{
					break;
				}
			}

			preShout = princes[i]; // 이전에 번호를 외친 왕자
		}

		if (i == n - 1) // 마지막 왕자까지 가면 처음 왕자로 반복
		{
			i = -1;
		}
	}

	cout << preShout + 1 << '\n';

	return 0;
}
// 핵심
// 이전에 번호를 외친 왕자 갱신 타이밍