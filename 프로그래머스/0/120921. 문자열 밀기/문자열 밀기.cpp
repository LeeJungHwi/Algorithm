#include <string>
#include <vector>

using namespace std;

int solution(string A, string B)
{
    int answer = 0;
    for(int i = 0; i < A.size(); i++)
    {
        if(A == B) return answer;
        A = A.back() + A;
        A.pop_back();
        answer++;
    }
    return -1;
}