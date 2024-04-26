#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 연속합
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 길이가 n인 수열에서 연속된 몇개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합 구하기

	// 현재dp값 = max(이전dp값 + 자기자신, 자기자신)

	int n; // N 10
	cin >> n;

	vector<int> num(n + 1); // 10 -4 3 1 5 6 -35 12 21 -1
	for (int i = 1; i < n + 1; i++) cin >> num[i];
	vector<int> dp(n + 1); // dp[i] = max(dp[i - 1] + num[i], num[i])

	int maxSum = num[1];

	for (int i = 1; i < n + 1; i++)
	{
		dp[i] = max(dp[i - 1] + num[i], num[i]);
		maxSum = max(maxSum, dp[i]);
	}

	cout << maxSum << '\n';

	return 0;
}

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <string>
//#include <map>
//#include <fstream>
//using namespace std;
//
//// 연속합
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	ifstream cin;
//	cin.open("input.txt");
//
//	// 길이가 n인 수열에서 연속된 몇개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합 구하기
//
//	// 1. 2차원 dp 테이블 만들어서 1행 1열 누적합으로 채우기
//	// 2. (2,2) ~ (n,n)까지 max(위쪽,왼쪽) + 자기자신으로 채우기
//	// 3. 1,2 하면서 maxSum 갱신하기
//
//	int n; // N 10
//	cin >> n;
//
//	vector<int> num(n + 1);
//	for (int i = 1; i < n + 1; i++) cin >> num[i];
//	vector<vector<int> > dp(n + 1, vector<int>(n + 1));
//
//	// 3. 1,2 하면서 maxSum 갱신하기
//
//	// 1. 2차원 dp 테이블 만들어서 1행 1열 누적합으로 채우기
//	int maxSum = 0;
//	dp[1][1] = num[1];
//	maxSum = dp[1][1];
//	for (int i = 2; i < n + 1; i++)
//	{
//		dp[i][1] = dp[i - 1][1] + num[i];
//		dp[1][i] = dp[1][i - 1] + num[i];
//		maxSum = max(maxSum, dp[i][1]);
//	}
//
//	// 2. (2,2) ~ (n,n)까지 max(위쪽,왼쪽) + 자기자신으로 채우기
//	for (int i = 2; i < n + 1; i++)
//	{
//		for (int j = 2; j < n + 1; j++)
//		{
//			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + num[i];
//			maxSum = max(maxSum, dp[i][j]);
//		}
//	}
//
//	//for (auto a : dp)
//	//{
//	//	for (auto b : a)
//	//	{
//	//		cout << b << ' ';
//	//	}
//	//	cout << '\n';
//	//}
//
//	return 0;
//}