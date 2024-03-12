#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper)
{
    vector<int> answer;
    
    // wallpaper : 바탕화면 그래프 .(빈칸) #(파일)
    // S(lux, luy) E(rdx, rdy)로 드래그해서 파일삭제 
    // 드래그 한 거리 : | rdx - lux | + | rdy - luy |
    
    // 그래프 돌면서
    // 최소 i, j 최대 i, j 구해서 answer에 저장
    // 최소는 좌상이므로 그대로, 최대는 우하이므로 +1
    
    int minI = 49, minJ = 49, maxI = 0, maxJ = 0;
    
    for(int i = 0; i < wallpaper.size(); i++)
    {
        for(int j = 0; j < wallpaper[i].size(); j++)
        {
            if(wallpaper[i][j] == '#')
            {
                minI = min(minI, i);
                minJ = min(minJ, j);
                maxI = max(maxI, i);
                maxJ = max(maxJ, j);
            }
        }
    }
    
    answer.push_back(minI);
    answer.push_back(minJ);
    answer.push_back(maxI + 1);
    answer.push_back(maxJ + 1);
    
    return answer;
}