#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 최대 선 연결하기(LIS)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 10
	cin >> n;

	vector<int> leftVec(n + 1); // 왼쪽 번호
	vector<int> rightVec(n + 1); // 오른쪽 번호
	vector<int> length(n + 1); // 오른쪽 번호 연결 길이

	for (int i = 1; i < n + 1; i++)
	{
		leftVec[i] = i; // 1 2 3 4 5 6 7 8 9 10
		cin >> rightVec[i]; // 4 1 2 3 9 7 5 6 10 8
	}

	// rightVec 인덱스 1까지 연결할때 -> 4 -> 1개
	// rightVec 인덱스 2까지 연결할때 -> 1 -> 1개
	// rightVec 인덱스 3까지 연결할때 -> 작은값 1 -> 최대길이 1 + 1 -> 1 2 -> 2개
	// rightVec 인덱스 4까지 연결할때 -> 작은값 2, 1 -> 최대길이 2 + 1 -> 1 2 3 -> 3개
	// rightVec 인덱스 5까지 연결할때 -> 작은값 3, 2, 1, 4 -> 최대길이 3 + 1 -> 1 2 3 9 -> 4개
	// rightVec 인덱스 6까지 연결할때 -> 작은값 3, 2, 1, 4 -> 최대길이 3 + 1 -> 1 2 3 7 -> 4개
	// rightVec 인덱스 7까지 연결할때 -> 작은값 3, 2, 1, 4 -> 최대길이 3 + 1 -> 1 2 3 5 -> 4개
	// rightVec 인덱스 8까지 연결할때 -> 작은값 5, 3, 2, 1, 4 -> 최대길이 4 + 1 -> 1 2 3 5 6 -> 5개
	// rightVec 인덱스 9까지 연결할때 -> 작은값 6, 5, 7, 9, 3, 2, 1, 4 -> 최대길이 5 + 1 -> 1 2 3 5 6 10 -> 6개
	// rightVec 인덱스 10까지 연결할때 -> 작은값 6, 5, 7, 3, 2, 1, 4 -> 최대길이 5 + 1 -> 1 2 3 5 6 8 -> 6개
	length[1] = 1;
	int result = 1;

	// rightVec[인덱스] 이전을 돌면서 rightVec[인덱스]보다 작은값들 중 최대길이에 + 1 후 저장
	for (int i = 2; i < n + 1; i++)
	{
		// rightVec[인덱스] 이전을 돌면서 rightVec[인덱스]보다 작은값들 중 최대길이
		int maxLength = 0;

		for (int j = i - 1; j > 0; j--)
		{
			if (rightVec[i] > rightVec[j])
			{
				if (maxLength < length[j])
				{
					maxLength = length[j];
				}
			}
		}

		// 구한 최대길이에 + 1
		length[i] = maxLength + 1;

		// 최대 선 연결 갱신
		if (result < length[i])
		{
			result = length[i];
		}
	}

	cout << result << '\n';

	return 0;
}