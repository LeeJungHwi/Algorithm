#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long solution(long long n)
{
    long long answer = sqrt(n) == (long long)sqrt(n) ? pow(sqrt(n) + 1, 2) : -1;
    return answer;
}