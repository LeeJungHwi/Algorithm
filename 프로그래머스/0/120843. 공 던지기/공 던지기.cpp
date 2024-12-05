#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k)
{
    int answer = 1; k--;
    while(k--)
    {
        answer += 2;
        if(answer > numbers.size()) answer %= numbers.size();
    }
    return answer;
}