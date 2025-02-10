#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Check(int n, long long s, vector<int> &t)
{
    long long cnt = 0;
    
    for(int i = 0; i < t.size(); i++) cnt += s / (long long)t[i];
    
    return cnt >= n;
}

long long solution(int n, vector<int> times)
{
    long long answer = 0;
    
    // 기준 => 심사를 받는 시간
    // lo => 1
    // hi => 가장 오래 걸리는 심사대에서 모든 사람이 심사를 받는 경우 => maxTime * n
    // s시간에 n명 이상 심사를 받을 수 있으면 가능한 경우
    
    long long l = 1, h = -1;
    for(int i = 0; i < times.size(); i++) h = max((long long)h, (long long)times[i]);
    h *= (long long)n;
    
    while(l <= h)
    {
        long long s = (l + h) / 2;
        
        if(Check(n, s, times))
        {
            answer = s;
            h = s - 1;
        }
        else l = s + 1;
    }
    
    return answer;
}