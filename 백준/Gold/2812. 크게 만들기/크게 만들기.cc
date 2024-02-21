#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

// 크게 만들기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, k; // N, K
	cin >> n >> k;

	string inputString; // 입력 문자열
	cin >> inputString;

	string result; // 가장 큰 수

	// n = 4, k = 2
	// 1924
	// 덱에 1 push
	// 덱에서 1 pop k-- 덱에 9 push
	// 덱에 2 push
	// 덱에서 2 pop k-- 덱에 4 push
	// 94

	// n = 7, k = 3
	// 1231234
	// 덱에 1 push
	// 덱에서 1 pop k-- 덱에 2 push
	// 덱에서 2 pop k-- 덱에 3 push
	// 덱에 1 push
	// 덱에서 1 pop k-- 덱에 2 push
	// 덱에 3 push
	// 덱에 4 push
	// 3234

	// n = 10, k = 4
	// 4177252841
	// 덱에 4 push
	// 덱에 1 push
	// 덱에서 1 pop k-- 4 pop k-- 7 push
	// 덱에 7 push
	// 덱에 2 push
	// 덱에서 2 pop k-- 5 push
	// 덱에 2 push
	// 덱에서 2 pop k-- 8 push
	// 덱에 4 push
	// 덱에 1 push
	// 775841

	deque<char> selectNum; // 선택된 숫자 저장
	selectNum.push_back(inputString[0]);

	for (int i = 1; i < inputString.size(); i++)
	{
		// 조건 : 덱이 비어있지않고 현재숫자가 덱의마지막보다 크면서 아직 k번을 뽑은게 아니면
		// 반복 : 덱의 마지막 제거, k--
		while (!selectNum.empty() && selectNum.back() < inputString[i] && k > 0)
		{
			selectNum.pop_back();
			k--;
		}

		// 현재 숫자를 덱에 저장
		selectNum.push_back(inputString[i]);
	}

	// 만약 뽑을수있는 횟수 k가 남아있다면
	// 덱의 앞쪽은 이미 해당 자릿수의 최상의 수이므로
	// 덱의 뒤쪽부터 제거
	while (k--)
	{
		selectNum.pop_back();
	}

	// 가장 큰 수 출력
	while (!selectNum.empty())
	{
		result += selectNum.front();
		selectNum.pop_front();
	}

	cout << result << '\n';

	return 0;
}

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <string>
//#include <fstream>
//using namespace std;
//
//// 크게 만들기
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	ifstream cin;
//	cin.open("input.txt");
//
//	int n, k; // N, K
//	cin >> n >> k;
//
//	string inputString; // 1231234
//	cin >> inputString;
//
//	string result; // 가장 큰 수
//
//	// n = 4, k = 2
//	// 1924
//	// 192 -> 9 push
//	// 4 -> 4 push
//	// 94
//
//	// n = 7, k = 3
//	// 1231234
//	// 1231 -> 3 push
//	// 12 -> 2 push
//	// 3 -> 3 push
//	// 4 -> 4 push
//	// 3234
//
//	// n = 10, k = 4
//	// 4177252841
//	// 41772 -> 7 push
//	// 725 -> 7 push
//	// 252 -> 5 push
//	// 28 -> 8 push
//	// 4 -> 4 push
//	// 1 -> 1 push
//	// 775841
//
//	int coef = 1; // k + 계수까지 체크 -> 여기범위를 넘어서서 고르면 n - k 자리수를 만들수없어서
//	int prePushIndex = -1; // 이전에 push 했던 숫자의 인덱스
//	int backupPrePushIndex = -1; // 이전에 push 했던 숫자의 인덱스 백업
//	char maxNum = '0'; // 각 스텝에서 가장 큰 수 선택
//
//	for (int i = 0; i < n - k; i++) // n - k개 선택
//	{
//		maxNum = '0'; // 각 스텝에서 가장 큰 수 선택
//		backupPrePushIndex = -1; // 이전에 push 했던 숫자의 인덱스 백업
//
//		// 위에서 시뮬돌린 알고리즘
//		for (int j = prePushIndex + 1; j < k + coef; j++)
//		{
//			if (maxNum < inputString[j])
//			{
//				maxNum = inputString[j];
//				backupPrePushIndex = j;
//			}
//		}
//
//		// 각 스텝에서 가장 큰 수 push, 다음반복 인덱스 갱신, 계수증가
//		result += maxNum;
//		prePushIndex = backupPrePushIndex;
//		coef++;
//	}
//
//	// 가장 큰 수 출력
//	cout << stoi(result) << '\n';
//
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <string>
//#include <fstream>
//using namespace std;
//
//int n, k; // N, K 4, 2
//string inputString; // 1924
//vector<bool> vis(500000); // 방문체크
//string maxNum; // 가장 큰 수
//
//// DFS
//void DFS(int L, int cnt)
//{
//	if (L == n || cnt == k) // 종료조건 : n자리를 넘어가거나 k개를 뽑은경우
//	{
//		if (L == n) // n 자리를 넘긴경우
//		{
//			if (cnt != k) // k개를 뽑은경우가 아니면 리턴
//			{
//				return;
//			}
//		}
//
//		// 뽑은 k 개를 제외하여 얻은 문자열
//		string getNum = "";
//
//		for (int i = 0; i < n; i++)
//		{
//			if (!vis[i])
//			{
//				getNum.push_back(inputString[i]);
//			}
//		}
//
//		// 가장 큰 수 갱신
//		maxNum = max(maxNum, getNum);
//	}
//	else
//	{
//		vis[L] = true; // 제거할숫자 선택
//		DFS(L + 1, cnt += 1);
//		vis[L] = false; // 제거할숫자 미선택
//		DFS(L + 1, cnt -= 1);
//	}
//}
//
//// 크게 만들기
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	//ifstream cin;
//	//cin.open("input.txt");
//
//	cin >> n >> k;
//	cin >> inputString;
//
//	// DFS
//	DFS(0, 0);
//
//	// 가장 큰 수 출력
//	cout << stoi(maxNum) << '\n';
//
//	return 0;
//}