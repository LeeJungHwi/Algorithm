#include <string>
#include <vector>
#include <map>

using namespace std;

long long solution(int n)
{
    long long answer = 0;
    
    // n = 1 : 1
    // n = 2 : 11 2
    // n = 3 : 111 12 21
    // n = 4 : 1111 121 112 211 22
    // n = k : dp[k - 1] + dp[k - 2]
    map<int ,long long> dp;
    dp[1] = 1; dp[2] = 2;
    for(int i = 3; i < n + 1; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
    answer = dp[n] % 1234567;
    
    return answer;
}