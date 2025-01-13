#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int left, int right)
{
    int answer = 0;
    
    for(int i = left; i < right + 1; i++)
    {
        int cnt = 0;
        for(int j = 1; j <= sqrt(i); j++)
        {
            if(i % j == 0)
            {
                cnt += 2;
                if(j == i / j)
                {
                    cnt = 0;
                    break;
                }
            }
        }
        answer = cnt > 0 ? answer + i : answer - i;
    }
    
    return answer;
}