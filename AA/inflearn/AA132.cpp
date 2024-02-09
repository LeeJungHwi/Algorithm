#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 공통원소 최대값
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 10
	cin >> n;

	vector<vector<int> > sets(3, vector<int>(n)); // 세 집합 숫자 저장
	vector<vector<bool> > vis(3, vector<bool>(100001)); // 세 집합 요소 체크

	//	39 31 32 75 75 7 89 21 7 67
	//	4 19 52 75 35 100 4 26 24 69
	//	82 53 22 64 58 80 94 75 51 69

	int num; // 숫자

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> num;

			sets[i][j] = num; // 각 집합에 숫자 저장
			vis[i][num] = true; // 각 집합에 들어있는 요소 체크
		}
	}

	// 세 집합 오름차순 정렬
	//	7 7 21 31 32 39 67 75 75 89
	//	4 4 19 24 26 35 52 69 75 100
	//	22 51 53 58 64 69 75 80 82 94
	for (int i = 0; i < 3; i++)
	{
		sort(sets[i].begin(), sets[i].end());
	}

	// 첫번째 집합에서 큰수부터 두, 세번째 집합에 공통원소를 가지는지 체크

	int maxCommonEle = 0; // 공통원소 최대값

	for (int i = n - 1; i > -1; i--)
	{
		int checkNum = sets[0][i]; // 체크할 숫자

		if (vis[1][checkNum] && vis[2][checkNum]) // 체크 할 숫자가 두, 세번째 집합에도 있다면
		{
			maxCommonEle = checkNum; // 공통원소 최대값 저장 후 종료
			
			break;
		}
	}

	if (maxCommonEle == 0) // 갱신 안됐으면 찾지못했음
	{
		cout << -1 << '\n';

		return 0;
	}

	cout << maxCommonEle << '\n';

	return 0;
}