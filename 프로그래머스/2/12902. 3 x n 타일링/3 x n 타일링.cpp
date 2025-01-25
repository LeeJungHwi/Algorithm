#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n)
{
    int answer = 0;
    
    vector<long long> dp(n + 1);
    dp[0] = 1; // 아무것도 놓지 않은 경우
    dp[2] = 3; // 3 by 2
    
    for(int i = 4; i < n + 1; i += 2)
    {
        // 3 by 2
        dp[i] = 3 * dp[i - 2];
        
        // 3 by 4에서 가로타일이 2, 3열을 차지하는 패턴
        for(int j = i - 4; j > -1; j -= 2)
        {
            dp[i] += 2 * dp[j];
        }
        
        dp[i] %= 1000000007;
    }
    
    return dp[n];
}