#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

// 갈 수 있는 정점 중 아직 set에 저장 안 된 정점
int DFS(int L, map<int, map<int, int> > &netMap, set<int> &netSet)
{
    netSet.insert(L);
    
    for(auto it = netMap[L].begin(); it != netMap[L].end(); it++) if(it->second > 0 && netSet.find(it->first) == netSet.end()) DFS(it->first, netMap, netSet);
    
    return netSet.size();
}

int solution(int n, vector<vector<int>> wires)
{
    int answer = 2147000000;
    
    map<int, map<int, int> > netMap;
    
    // 양방향 맵핑
    for(int i = 0; i < wires.size(); i++)
    {
        netMap[wires[i][0]][wires[i][1]]++;
        netMap[wires[i][1]][wires[i][0]]++;
    }
    
    // 두 전력망 개수 차이 최소
    for(int i = 0; i < wires.size(); i++)
    {
        // 각 전선 끊고
        netMap[wires[i][0]][wires[i][1]] = 0;
        netMap[wires[i][1]][wires[i][0]] = 0;
        
        // 최솟값 갱신
        set<int> netSet;
        int netCnt = DFS(1, netMap, netSet);
        answer = min(answer, abs(netCnt * 2 - n));
        
        // 끊은 전선 다시 맵핑
        netMap[wires[i][0]][wires[i][1]]++;
        netMap[wires[i][1]][wires[i][0]]++;
    }
    
    return answer;
}