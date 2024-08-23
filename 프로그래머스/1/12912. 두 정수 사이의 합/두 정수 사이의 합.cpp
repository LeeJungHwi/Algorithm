#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int a, int b)
{
    long long answer = 0, s = min(a, b), e = max(a, b);
    for(int i = s; i <= e; i++) answer += i;
    return answer;
}