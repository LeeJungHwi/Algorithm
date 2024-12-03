#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    while(b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

int solution(int a, int b)
{
    int g = gcd(a, b);
    b /= g;

    while (b % 2 == 0) b /= 2;
    while (b % 5 == 0) b /= 5;

    if (b == 1) return 1;
    else return 2;
}