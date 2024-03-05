#include <string>
#include <map>
#include <vector>
using namespace std;

int solution(vector<int> array)
{
    int answer = 0;
    
    // array 돌면서 맵 카운팅
    // 카운팅된값에 따라 최대값 갱신, 최빈값 갱신
    
    map<int, int> m;
    int maxCount = 0;
    
    for(int i = 0; i < array.size(); i++)
    {
        m[array[i]]++;
        
        if(maxCount < m[array[i]])
        {
            maxCount = m[array[i]];
            answer = array[i];
        }
    }
    
    // 맵 돌면서 maxCount값을 가지는 키가 2개가되면
    // answer을 -1로하고 break
    
    int keyCnt = 0;
    
    for(auto it = m.begin(); it != m.end(); it++)
    {
        if(it->second == maxCount)
        {
            keyCnt++;
            
            if(keyCnt == 2)
            {
                answer = -1;
                
                break;
            }
        }
    }
    
    return answer;
}