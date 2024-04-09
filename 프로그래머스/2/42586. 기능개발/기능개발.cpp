#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    
    // 각 기능은 100% 일때 서비스 가능함
    // 각 기능의 개발속도는 모두 달라서 뒤에있는 기능이 앞에있는 기능보다 먼저 개발될수있음
    // 뒤에있는기능은 앞에있는 기능이 배포될때 함께 배포됨
    
    // progresses : 먼저 배포되어야하는 기능의 작업진도가 순서대로 저장
    // speeds : 각 작업의 개발속도 저장
    // answer : 각 배포마다 몇개의 기능이 배포되는지 저장
    
    // progresses 돌면서 (각 기능의 배포순서, {각 기능의 작업진도, 각 기능의 작업속도} ) 맵핑
    // 맵 돌면서
    // 각 요소 값의 first가 >= 100 이 될때까지 각 기능 작업진도에 각 기능 작업속도를 더해나감
    // 각 요소 값의 first가 >= 100 이 되면 작업진도가 < 100 인 작업을 만날때까지 개수를 카운팅하고 키값 삭제하고 구한개수를 answer에 push
    
    // progresses 돌면서 (각 기능의 배포순서, {각 기능의 작업진도, 각 기능의 작업속도} ) 맵핑
    map<int, pair<int, int> > progress;
    
    for(int i = 0; i < progresses.size(); i++)
    {
        progress[i + 1] = {progresses[i], speeds[i]};
    }
    
    // 맵 돌면서
    // 각 요소 값의 first가 >= 100 이 될때까지 각 기능 작업진도에 각 기능 작업속도를 더해나감
    // 각 요소 값의 first가 >= 100 이 되면 작업진도가 < 100 인 작업을 만날때까지 개수를 카운팅하고 구한개수를 answer에 push
    
    int completeCnt = 0;
    
    // 맵 돌면서
    for(auto it = progress.begin(); it != progress.end(); it++)
    {
        // 이미 개발된 기능이면 continue
        if(it->second.first >= 100)
        {
            continue;
        }
        
        int releaseCnt = 0; // 각 기능이 개발될때 배포하는 기능 개수
        
        // 각 요소 값의 first가 >= 100 이 될때까지
        while(it->second.first < 100)
        {
            //  각 기능 작업진도에 각 기능 작업속도를 더해나감
            for(auto it2 = it; it2 != progress.end(); it2++)
            {
                it2->second.first += it2->second.second;
            }
        }
        
        // 각 요소 값의 first가 >= 100 이 되면
        for(auto it2 = it; it2 != progress.end(); it2++)
        {
            if(it2->second.first < 100)
            {
                break;
            }
            
            releaseCnt++;
        }
        
        completeCnt += releaseCnt;
        answer.push_back(releaseCnt);
        
        // 모든 기능을 작업했으면 종료
        if(completeCnt == progresses.size())
        {
            break;
        }
    }
    
    return answer;
}