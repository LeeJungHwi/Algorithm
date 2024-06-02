#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

// 갈 수 있는 정점 중 아직 set에 저장 안 된 정점
void DFS(int L, map<int, map<int, int> > &netMap, set<int> &netSet)
{
    netSet.insert(L);
    for(auto it = netMap[L].begin(); it != netMap[L].end(); it++) if(it->second > 0 && netSet.find(it->first) == netSet.end()) DFS(it->first, netMap, netSet);
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    
    map<int, map<int, int> > netMap;
    set<int> netSet;
    
    // 연결된 네트워크 정점 맵핑
    for(int i = 0 ; i < computers.size(); i++)
    {
        for(int j = 0; j < computers[i].size(); j++)
        {
            if(i == j) continue;
            if(!computers[i][j]) continue;
            netMap[i][j]++;
        }
    }
    
    // 모든 정점을 체크하면 종료
    while(netSet.size() != computers.size())
    {
        for(int i = 0; i < computers.size(); i++)
        {
            // 이미 체크한 정점 continue
            if(netSet.find(i) != netSet.end()) continue;
            
            // 아직 체크하지 않은 정점 체크
            DFS(i, netMap, netSet);
            
            // 한 스텝 끝나면 하나의 네트워크 형성
            answer++;
        }
    }
    
    return answer;
}