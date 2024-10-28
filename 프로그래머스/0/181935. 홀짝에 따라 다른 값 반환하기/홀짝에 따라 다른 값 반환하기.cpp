#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;
    for(int i = n % 2 == 1 ? 1 : 2; i < n + 1; i += 2) answer = n % 2 == 1 ? answer + i : answer + i * i;
    return answer;
}