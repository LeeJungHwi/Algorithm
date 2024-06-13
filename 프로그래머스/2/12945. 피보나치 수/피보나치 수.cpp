#include <map>
using namespace std;

int home;
map<int, int> dp;

int Fib(int curN)
{
    if(dp[curN] > 0) return dp[curN];
    else if(curN == 0) return 0;
    else if(curN == 1) return 1;
    else return dp[curN] = (Fib(curN - 1) % 1234567 + Fib(curN - 2) % 1234567) % 1234567;
}

int solution(int n) { return home = Fib(n); }