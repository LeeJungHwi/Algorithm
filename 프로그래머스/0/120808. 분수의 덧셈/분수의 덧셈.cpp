#include <string>
#include <vector>
#include <numeric>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2)
{
    int numer = numer1 * denom2 + numer2 * denom1;
    int denom = denom1 * denom2;
    int ggcd = gcd(numer, denom);
    numer /= ggcd;
    denom /= ggcd;
    return {numer, denom};
}