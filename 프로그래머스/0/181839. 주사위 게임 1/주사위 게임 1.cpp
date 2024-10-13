#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int a, int b)
{
    int temp = 0;
    if(a % 2 == 1) temp++;
    if(b % 2 == 1) temp++;
    if(temp == 2) return pow(a, 2) + pow(b, 2);
    return temp == 1 ? 2 * (a + b) : abs(a - b);
}