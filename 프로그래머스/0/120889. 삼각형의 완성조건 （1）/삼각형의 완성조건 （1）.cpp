#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides)
{
    int answer = 0;
    sort(sides.begin(), sides.end());
    return sides[2] < sides[0] + sides[1] ? 1 : 2;
}