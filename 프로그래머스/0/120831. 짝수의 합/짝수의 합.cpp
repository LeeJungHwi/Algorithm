#include <string>
#include <vector>

using namespace std;

int answer;

void Esum(int n, int cur)
{
    if(cur > n) return;
    
    if(cur % 2 == 0)
    {
        answer += cur++;
        Esum(n, cur);
        return;
    }
    
    Esum(n, ++cur);
}

int solution(int n)
{
    Esum(n, 2);
    return answer;
}