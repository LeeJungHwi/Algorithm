#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n)
{
    int answer = 0;
    vector<int> v(n + 1);
    for(int i = 1; i < n + 1; i++)
    {
        for(int j = i; j < n + 1; j += i)
        {
            v[j]++;
        }
    }
    for(int i = 1; i < n + 1; i++) if(v[i] == 2) answer++;
    return answer;
}