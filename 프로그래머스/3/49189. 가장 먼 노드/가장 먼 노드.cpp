#include <string>
#include <queue>
#include <vector>

using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)

int solution(int n, vector<vector<int>> edge)
{
    vector<vector<int> > graph(n);
    vector<int> dis(n);
    queue<int> cp;
    loop(i, home, edge.size()) { graph[edge[i][home] - 1].push_back(edge[i][1] - 1); graph[edge[i][1] - 1].push_back(edge[i][home] - 1); }
    cp.push(home);
    dis[home] = 1;
    int maxCnt = home, maxDis = home;
    while(!cp.empty())
    {
        int s = cp.front(); cp.pop();
        loop(i, home, graph[s].size())
        {
            if(dis[graph[s][i]] > home) continue;
            dis[graph[s][i]] = dis[s] + 1;
            if(dis[graph[s][i]] > maxDis) { maxCnt = 1; maxDis = dis[graph[s][i]]; }
            else if(dis[graph[s][i]] == maxDis) ++maxCnt; 
            cp.push(graph[s][i]);
        }
    }
    
    return maxCnt;
}