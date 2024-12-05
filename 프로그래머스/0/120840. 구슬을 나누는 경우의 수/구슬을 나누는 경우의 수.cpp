#include <string>
#include <vector>
#include <iostream>

using namespace std;

// long long Facto(long long n)
// {
//     if(n == 1 || n == 0) return 1;
//     return n * Facto(n - 1);
// }

long long solution(int balls, int share)
{
    if (balls == share) return 1;

    long long ans = 1;
    for (int i = 1; i <= share; i++)
    {
        ans *= balls--;
        ans /= i;
    }
    return ans;
    //return Facto(balls) / (Facto(balls - share) * Facto(share));
}