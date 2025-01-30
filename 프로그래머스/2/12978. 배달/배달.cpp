#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int> > road, int K)
{
    int answer = 0;
    
    vector<vector<pair<int, int> > > graph(N);
    for(int i = 0; i < road.size(); i++)
    {
        // 양방향
        graph[road[i][0] - 1].push_back({road[i][1] - 1, road[i][2]});
        graph[road[i][1] - 1].push_back({road[i][0] - 1, road[i][2]});
    }
    
    // 각 도시까지 최단거리
    vector<int> dis(N, 2147000000);
    
    // rhs까지가는 최소비용 lhs
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > pq;
    
    // 1번 도시부터
    dis[0] = 0;
    pq.push({0, 0});
    
    while(!pq.empty())
    {
        pair<int, int> s = pq.top();
        pq.pop();
        
        // 이미 더 적은비용으로 갈수있으면 X
        if(s.first > dis[s.second]) continue;
        
        // 갈수있는 도시 돌면서
        for(int i = 0; i < graph[s.second].size(); i++)
        {
            // 갈수있는 도시와 비용
            int ch = graph[s.second][i].first;
            int co = graph[s.second][i].second;
            
            // 이미 더 적은비용으로 갈수있으면 X
            if(dis[s.second] + co >= dis[ch]) continue;
            
            // 더 적은비용으로 다음도시 방문
            dis[ch] = dis[s.second] + co;
            pq.push({dis[ch], ch});
        }
    }
    
    // 1번 도시에서 각 도시까지의 최단거리 중 K이하로 갈수있으면 카운팅
    int cnt = 1;
    for(int i = 1; i < N; i++) if(dis[i] <= K) cnt++;
    
    return answer = cnt;
}