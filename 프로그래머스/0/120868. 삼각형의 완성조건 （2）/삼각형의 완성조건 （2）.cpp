#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> sides)
{
    int answer = 0;
    int mmin = 2147000000, mmax = -2147000000;
    mmin = sides[0] < sides[1] ? sides[0] : sides[1];
    mmax = sides[0] < sides[1] ? sides[1] : sides[0];
    // mmax - mmin + 1 ~ mmax
    // mmax + 1 ~ mmin + mmax - 1
    return mmin + mmin - 1;
}