#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    
    // i행 j열을 전열 k에서 왔을때 최고점수
    vector<vector<vector<int> > > dp(land.size(), vector<vector<int> >(4, vector<int>(4)));
    for(int i = 0; i < land.size(); i++)
    {
        for(int j = 0; j < 4; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                dp[i][j][k] = -2147000000;
            }
        }
    }
    
    // 0행 이전열 없음
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            dp[0][i][j] = land[0][i];
        }
    }
    
    for (int i = 1; i < land.size(); i++)
    {
        for (int j = 0; j < 4; j++) // 현재열
        {
            for (int k = 0; k < 4; k++) // 이전열
            {
                // 같은열 체크
                if (j == k) continue;
                
                // l => 이전열의 이전열
                for (int l = 0; l < 4; l++)
                {
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][k][l] + land[i][j]);
                }
            }
        }
    }
    
    int maxScore = -2147000000;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            maxScore = max(maxScore, dp[land.size() - 1][i][j]);
        }
    }

    return maxScore;
}