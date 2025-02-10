#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Check(int s, vector<int> &r, int n, int distance)
{
    int cnt = 0, prePos = 0;

    for(int i = 0; i < r.size(); i++)
    {
        if (r[i] - prePos < s) cnt++;
        else prePos = r[i];
    }

    return distance - prePos < s ? ++cnt <= n : cnt <= n;
}

int solution(int distance, vector<int> rocks, int n)
{
    int answer = 0;
    
    // 기준 => 각 바위 사이 거리
    // lo => 1
    // hi => distance
    // s 만큼 간격이 유지되도록 배치된 바위를 제거할때 제거한 횟수가 n이하면 가능한경우
    
    sort(rocks.begin(), rocks.end());
    int l = 1, h = distance;
    
    while(l <= h)
    {
        int s = (l + h) / 2;
        
        if(Check(s, rocks, n, distance))
        {
            answer = s;
            l = s + 1;
        }
        else h = s - 1;
    }
    
    return answer;
}
