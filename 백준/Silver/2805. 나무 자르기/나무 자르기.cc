#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 나무 자르기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	long long n, m; // N, M 4, 7
	cin >> n >> m;

	// 나무 길이 20 15 10 17
	vector<long long> trees(n);

	for (int i = 0; i < n; i++)
	{
		cin >> trees[i];
	}

	sort(trees.begin(), trees.end());

	// 이진탐색

	long long first = 0; // 처음
	long long last = trees.back(); // 마지막
	long long maxHeight = 0; // 최대높이

	while (first <= last) // 역전되면 종료
	{
		long long standard = (first + last) / 2; // 기준값

		bool isHeight = false; // 기준값 길이로 잘랐을때 m길이 이상의 나무를 가져갈수있는지 체크

		long long len = 0; // 가져갈수있는 길이

		// 각 나무길이 돌면서 m길이 이상의 나무를 가져갈수있는지 체크
		for (int i = 0; i < trees.size(); i++)
		{
			// 잘랐을때 음수면 0으로 처리
			len += max(trees[i] - standard, (long long)0);

			// m길이 이상 가져갈수있다면 break
			if (len >= m)
			{
				isHeight = true;

				break;
			}
		}

		// m길이 이상의 나무를 가져갈수있다면
		if (isHeight)
		{
			maxHeight = standard; // 최대높이 갱신
			first = standard + 1; // 처음 갱신
		}
		else // m길이 이상의 나무를 가져갈수없다면
		{
			last = standard - 1; // 마지막 갱신
		}
	}

	cout << maxHeight << '\n'; // 최대높이 출력

	return 0;
}