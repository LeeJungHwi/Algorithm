#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(int n)
{
    int lcm = (6 * n) / gcd(6, n);
    return lcm / 6;
}