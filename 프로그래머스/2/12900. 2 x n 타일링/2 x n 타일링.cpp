#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;
    
    // n : 직사각형 가로길이
    // 직사각형을 1b2 2by1 타일로 채우는 방법의 수
    
    // n 1 : 1
    // n 2 : 2
    // n 3 : 3
    // n 4 : 5
    // 피보나치
    
    vector<long long> dp(n + 1);
    
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i = 2; i < n + 1; i++) dp[i] = (dp[i - 1] % 1000000007 + dp[i - 2] % 1000000007) % 1000000007;
    
    return answer = dp[n];
}