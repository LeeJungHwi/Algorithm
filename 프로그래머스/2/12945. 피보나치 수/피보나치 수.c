#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int dp[100001];

int Fib(int curN)
{
    if(dp[curN] > 0) return dp[curN];
    else if(curN == 0) return 0;
    else if(curN == 1) return 1;
    else return dp[curN] = (Fib(curN - 1) % 1234567 + Fib(curN - 2) % 1234567) % 1234567;
}

int solution(int n)
{
    int answer = 0;
    
    answer = Fib(n);
    
    return answer;
}