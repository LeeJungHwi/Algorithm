#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = n / 7;
    n -= 7 * answer;
    if(n > 0) answer++;
    return answer;
}