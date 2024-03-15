#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

int k; // K 7
vector<int> nums(12); // k개의 수 저장 1 2 3 4 5 6 7
vector<int> sequence; // 수열 저장

// DFS
void DFS(int L, int cnt)
{
	if (L == k || cnt == 6) // 종료조건 : 선택가능한 수를 넘기거나 6개의 수를 선택했을때
	{
		if (L == k) // 선택가능한 수를 넘긴경우
		{
			if (cnt != 6) // 6개의 수를 선택한경우가 아니면 리턴
			{
				return;
			}
		}

		// 선택한 수열 출력
		for (int i = 0; i < sequence.size(); i++)
		{
			cout << sequence[i] << ' ';
		}

		cout << '\n';
	}
	else
	{
		sequence.push_back(nums[L]); // 선택
		DFS(L + 1, cnt += 1);
		sequence.pop_back(); // 미선택
		DFS(L + 1, cnt -= 1);
	}
}

// 로또
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	while (true)
	{
		cin >> k;

		if (k == 0) // 입력이 0이면 종료
		{
			break;
		}

		// 1 2 3 4 5 6 7
		for (int i = 0; i < k; i++)
		{
			cin >> nums[i];
		}

		// DFS
		DFS(0, 0);

		cout << '\n';
	}

	return 0;
}