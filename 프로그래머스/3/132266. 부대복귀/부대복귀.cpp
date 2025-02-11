#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination)
{
    vector<int> answer;

    vector<vector<int>> graph(n);
    for(int i = 0; i < roads.size(); i++)
    {
        graph[roads[i][0] - 1].push_back(roads[i][1] - 1);
        graph[roads[i][1] - 1].push_back(roads[i][0] - 1);
    }
    vector<int> dis(n);
    queue<int> cp;
    
    cp.push(destination - 1);
    dis[destination - 1] = 1;
    
    while(!cp.empty())
    {
        int s = cp.front(); cp.pop();
        
        for(int i = 0; i < graph[s].size(); i++)
        {
            int c = graph[s][i];
            
            if(dis[c] > 0) continue;
            
            dis[c] = dis[s] + 1;
            cp.push(c);
        }
    }
    
    for(int i = 0; i < sources.size(); i++) answer.push_back(dis[sources[i] - 1] > 0 ? dis[sources[i] - 1] - 1 : -1);
    
    return answer;
}