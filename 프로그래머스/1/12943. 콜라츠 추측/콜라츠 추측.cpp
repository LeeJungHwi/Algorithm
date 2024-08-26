#include <string>
#include <vector>

using namespace std;

int solution(int num)
{
    int answer = 0;
    long long l = num;
    while(answer < 500)
    {
        if(l == 1) return answer;
        if(l % 2 == 0) l /= 2;
        else l = l * 3 + 1;
        answer++;
    }
    
    return -1;
}