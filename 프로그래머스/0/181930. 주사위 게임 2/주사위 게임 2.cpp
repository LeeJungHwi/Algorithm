#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int a, int b, int c)
{
    int equal = 0;
    if(a == b) ++equal;
    if(b == c) ++equal;
    if(c == a) ++equal;
    switch(equal)
    {
        case 3: return (a + b + c) * (pow(a, 2) + pow(b, 2) + pow(c, 2)) * (pow(a, 3) + pow(b, 3) + pow(c, 3)); break;
        case 1: return (a + b + c) * (pow(a, 2) + pow(b, 2) + pow(c, 2)); break;
        case 0: return a + b + c; break;
        default: break;
    }
}