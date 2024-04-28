#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
#include <stack>
using namespace std;

// 가장 긴 증가하는 부분 수열 4
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // 6
	cin >> n;

	// 만드려고 하는 부분 수열의 마지막 수가 10일때 -> 10 -> 길이 1
	// 만드려고 하는 부분 수열의 마지막 수가 20일때 -> 10 20 -> 길이 2
	// 만드려고 하는 부분 수열의 마지막 수가 10일때 -> 10 10 -> 길이 2
	// 만드려고 하는 부분 수열의 마지막 수가 30일때 -> 10 10 30, 10 20 30, 10 30 -> 길이 3
	// 만드려고 하는 부분 수열의 마지막 수가 20일때 -> 10 20, 10 20 20, 10 10 20 -> 길이 3
	// 만드려고 하는 부분 수열의 마지막 수가 50일때 -> 10 50, 10 20 50, 10 10 50, 10 10 30 50, 10 20 30 50, 10 30 50, 10 20 50, 10 20 20 50, 10 10 20 50 -> 길이 4

	vector<int> sequences(1001); // 수열
	for (int i = 1; i < n + 1; i++) cin >> sequences[i]; // 10 20 10 30 20 50
	vector<int> length(1001); // 마지막 수에 따라 증가수열 길이 저장
	vector<int> idx(1001); // 인덱스 추적

	int lis = 0; // 가장 긴 증가 부분수열 길이
	int lastIdx = 0; // 가장 긴 증가 부분수열의 마지막 인덱스

	// 현재인덱스 마지막 숫자로 했을때
	// 이전인덱스를 돌면서 현재 인덱스 숫자보다 작은 숫자들의 가장 긴 부분수열 + 1
	for (int i = 1; i < n + 1; i++)
	{
		length[i] = 1;
		int lastNum = sequences[i];

		for (int j = i - 1; j > 0; j--)
		{
			if (lastNum > sequences[j])
			{
				if (length[i] < length[j] + 1)
				{
					length[i] = length[j] + 1;
					idx[i] = j; // 이전 인덱스 갱신
				}
			}
		}

		if (lis < length[i])
		{
			lis = length[i];
			lastIdx = i; // lis 마지막 인덱스 갱신
		}
	}

	cout << lis << '\n';

	// 역추적해서 출력

	stack<int> lisSequence;

	while (true)
	{
		if (lastIdx == 0) break;

		lisSequence.push(sequences[lastIdx]); // sequences[6] == 50,sequences[4] == 30, sequences[2] == 20, sequences[1] == 10  

		lastIdx = idx[lastIdx]; // idx[6] == 4, idx[4] == 2, idx[2] == 1, idx[1] == 0
	}

	// 10 20 30 50
	while (!lisSequence.empty())
	{
		cout << lisSequence.top() << ' ';
		lisSequence.pop();
	}

	return 0;
}