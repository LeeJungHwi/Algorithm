#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int x, int y, int n)
{
    int answer = 0;
    
    vector<int> dis(y + 1);
    queue<int> checkPos;
    checkPos.push(x);
    dis[x] = 1;
    
    while(!checkPos.empty())
    {
        int standardPos = checkPos.front();
        checkPos.pop();
        
        vector<int> checkDir;
        checkDir.push_back(standardPos * 3);
        checkDir.push_back(standardPos * 2);
        checkDir.push_back(standardPos + n);
        
        for(int i = 0; i < checkDir.size(); i++)
        {
            if(checkDir[i] > y) continue;
            if(dis[checkDir[i]] > 0) continue;
            
            checkPos.push(checkDir[i]);
            dis[checkDir[i]] = dis[standardPos] + 1;
        }
    }
    
    if(!dis[y]) return -1;
    
    return answer = dis[y] - 1;
}