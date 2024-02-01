#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int n; // 8
vector<int> sequences(1001); // 수열
vector<int> length(1001); // 마지막 수에 따라 증가수열 길이 저장

// 최대 부분 증가수열(LIS)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> sequences[i]; // 5 3 7 8 6 2 9 4
	}

	// 만드려고 하는 부분 수열의 마지막 수가 5일때 -> 5 -> 길이 1
	// 만드려고 하는 부분 수열의 마지막 수가 3일때 -> 3 -> 길이 1
	// 만드려고 하는 부분 수열의 마지막 수가 7일때 -> 3 7, 5 7 -> 길이 2
	// 만드려고 하는 부분 수열의 마지막 수가 8일때 -> 3 7 8, 5 7 8, 3 8, 5 8 -> 길이 3
	// 만드려고 하는 부분 수열의 마지막 수가 6일때 -> 3 6, 5 6 -> 길이 2
	// 만드려고 하는 부분 수열의 마지막 수가 2일때 -> 2 -> 길이 1
	// 만드려고 하는 부분 수열의 마지막 수가 9일때 -> 2 9, 3 6 9, 5 6 9, 3 7 8 9, 5 7 8 9, 3 8 9, 5 8 9, 3 7 9, 5 7 9, 3 9, 5 9 -> 길이 4
	// 만드려고 하는 부분 수열의 마지막 수가 4일때 -> 2 4, 3 4 -> 길이 2
	length[1] = 1;
	int lis = 0;

	// 현재인덱스 이전인덱스를 돌면서 마지막 숫자보다 작은 수의 길이 중 최대값을 구해서 +1해서 저장
	for (int i = 2; i < n + 1; i++)
	{
		// 마지막 숫자보다 작은 수의 길이 중 최대값
		int maxLength = 0;
		int lastNum = sequences[i];

		for (int j = i - 1; j > 0; j--)
		{
			if (lastNum > sequences[j] && maxLength < length[j])
			{
				maxLength = length[j];
			}
		}

		// 구한 최대값에 + 1
		length[i] = maxLength + 1;

		// lis 갱신
		if (lis < length[i])
		{
			lis = length[i];
		}
	}

	cout << lis << '\n';

	return 0;
}

//#include <iostream>
//#include <vector>
//#include <fstream>
//using namespace std;
//
//int n; // 8
//vector<int> sequences(1000); // 수열
//vector<bool> vis(1000); // 방문체크
//int lis;
//
//void DFS(int L)
//{
//	if (L == n)
//	{
//		// 각 부분 수열에서 lis 갱신하기
//		int maxNum = 0;
//		int length = 0;
//
//		for (int i = 0; i < n; i++)
//		{
//			if (vis[i])
//			{
//				if (maxNum < sequences[i])
//				{
//					maxNum = sequences[i];
//					length++;
//				}
//			}
//		}
//
//		if (lis < length)
//		{
//			lis = length;
//		}
//	}
//	else
//	{
//		// 모든 부분 수열 만들기
//		if (!vis[L])
//		{
//			vis[L] = true;
//			DFS(L + 1);
//			vis[L] = false;
//			DFS(L + 1);
//		}
//	}
//}
//
//// 최대 부분 증가수열(LIS)
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	ifstream cin;
//	cin.open("input.txt");
//
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> sequences[i]; // 5 3 7 8 6 2 9 4
//	}
//
//	// 모든 수열 만들기
//	// 각 수열에서 lis 찾기
//	DFS(0);
//
//	cout << lis << '\n';
//
//	return 0;
//}