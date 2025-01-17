#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n)
{
    int answer = 0;
    for(int i = 4; i < n + 1; i++)
    {
        int cnt = 0;
        for(int j = 1; j <= sqrt(i); j++)
        {
            if(i % j == 0)
            {
                cnt += i / j == j ? 1 : 2;
                if(cnt >= 3)
                {
                    answer++;
                    break;
                }
            }
        }
    }
    
    return answer;
}