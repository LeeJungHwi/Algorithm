#include <string>
#include <vector>
#include <cctype>
#include <map>

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;
    
    // LRU 캐시 구현
    
    // cities 돌면서
    // 맵핑된 도시가 아니면
    // 캐시가 가득 찼으면 맵 첫키 삭제하고 (들어온순서, 들어온도시) 맵핑하고 CPU 시간 += 5
    // 캐시가 가득차지않았으면 (들어온순서, 들어온도시) 맵핑하고 CPU 시간 += 5
    // 맵핑된 도시면
    // 기존에 맵핑된 키 삭제하고 (들어온순서, 들어온도시) 맵핑하고 CPU 시간 += 1
    
    // cacheSize : 캐시 크기
    // cities : 도시 이름, 대소문자 구분 X
    
    map<int, string> cache; // (들어온순서, 들어온도시) 맵핑
    int cpuTime = 0; // CPU시간
    
    // 캐시크기가 0이면 모두 캐시 미스
    if(cacheSize == 0)
    {
        cpuTime += cities.size() * 5;
        
        return cpuTime;
    }
    
    // cities 돌면서
    for(int i = 0; i < cities.size(); i++)
    {   
        bool isCache = false; // 맵핑된 도시인지 체크
        int order = 0; // 맵핑된 키
        
        // 도시이름 소문자는 대문자로 변환하고
        for(int j = 0; j < cities[i].size(); j++)
        {
            if(islower(cities[i][j]))
            {
                cities[i][j] = toupper(cities[i][j]);
            }
        }
        
        // 맵핑된 도시면 체크
        for(auto it = cache.begin(); it != cache.end(); it++)
        {
            if(it->second == cities[i])
            {
                isCache = true;
                order = it->first;
                
                break;
            }
        }
        
        // 맵핑된 도시면
        if(isCache)
        {
            // 기존에 맵핑된 키 삭제하고 (들어온순서, 들어온도시) 맵핑하고 CPU 시간 += 1
            cache.erase(order);
            cache[i + 1] = cities[i];
            cpuTime += 1;
            
            continue;
        }
        
        // 맵핑된 도시가 아니면
        
        // 캐시가 가득 찼으면 맵 첫키 삭제하고 (들어온순서, 들어온도시) 맵핑하고 CPU 시간 += 5
        if(cache.size() == cacheSize)
        {
            cache.erase(cache.begin());
            cache[i + 1] = cities[i];
            cpuTime += 5;
            
            continue;
        }
        
        // 캐시가 가득차지않았으면 (들어온순서, 들어온도시) 맵핑하고 CPU 시간 += 5
        cache[i + 1] = cities[i];
        cpuTime += 5;
    }
    
    answer = cpuTime;
    
    return answer;
}