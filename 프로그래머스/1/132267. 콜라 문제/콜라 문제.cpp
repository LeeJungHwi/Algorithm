#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b, int n)
{
    int answer = 0;
    int cur = n;

    while (cur >= a)
    {
        answer += (cur / a) * b;
        cur = (cur / a) * b + (cur % a);
    }

    return answer;
}