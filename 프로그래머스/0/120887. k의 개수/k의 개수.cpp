#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k)
{
    int answer = 0;
    for(int s = i; s < j + 1; s++)
    {
        string temp = to_string(s);
        for(int l = 0; l < temp.size(); l++)
        {
            if(temp[l] - '0' == k) answer++;
        }
    }
    return answer;
}