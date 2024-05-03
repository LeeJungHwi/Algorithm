#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 스티커
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 스티커 2n개를 구매하고 2행 n열로 배치함
	// 스티커 한 장을 떼면 해당 스티커의 변을 공유하는 상하좌우 스티커는 모두 찢어져 사용 할 수 없음
	// 서로 변을 공유하는 스티커는 동시에 뗄 수 없음
	// 각 스티커가 점수를 갖고 있을 때 점수의 합이 최대가 되도록 스티커를 뗄 때 최대점수 구하기
	
	int tc; // TC 2
	cin >> tc;

	int col; // 열 5

	while (tc--)
	{
		cin >> col;

		vector<vector<long long> > score(3, vector<long long>(col + 1)); // (i, j) 번 째 스티커의 점수 저장
		//	50 10 100 20 40
		//	30 50 70 10 60
		for (int i = 1; i < 3; i++)
		{
			for (int j = 1; j < col + 1; j++)
			{
				cin >> score[i][j];
			}
		}
		vector<vector<long long> > dp(3, vector<long long>(col + 1)); // (i, j) 번 째 스티커를 뗄 때 최대점수 저장
		dp[1][1] = score[1][1];
		dp[2][1] = score[2][1];
		long long maxScore = max(dp[1][1], dp[2][1]); // dp값 중 최대값으로 갱신

		// dp[i][j]
		// 현재 스티커 이전 열에 있는 스티커를 떼지 않았을때 dp값
		// 현재 스티커 두 칸 이전 열에 있는 스티커를 떼지 않았을때 dp값 중 최댓값 + 현재 스티커 점수
		for (int j = 2; j < col + 1; j++)
		{
			for (int i = 1; i < 3; i++)
			{
				dp[i][j] = max(dp[3 - i][j - 1], dp[3 - i][j - 2]) + score[i][j];
				maxScore = max(maxScore, dp[i][j]);
			}
		}

		cout << maxScore << '\n';
	}

	return 0;
}