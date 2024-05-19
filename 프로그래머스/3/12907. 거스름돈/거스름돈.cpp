#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money)
{
    int answer = 0;
    
    // money : 동전 종류
    // 각 동전을 사용하여 n원을 거슬러주는 경우의 수
    
    vector<int> dp(n + 1); // i원을 만드는 경우의 수
    dp[0] = 1; // 0원 : 동전을 모두 사용하지 않는 경우
    
    // 모든 동전을 돌면서
    for(int i = 1; i < money.size() + 1; i++)
    {
        // 각 동전을 사용 할 수 있는
        for(int j = money[i - 1]; j < n + 1; j++)
        {
            // 각 j원에 대해
            // money[i - 1]을 마지막으로 사용해서 i원을 만드는 경우의 수 누적
            // dp[j - money[i - 1]] : money[i - 1]을 사용하지 않은 상태
            dp[j] += dp[j - money[i - 1]];
        }
    }
    
    return answer = dp[n];
}