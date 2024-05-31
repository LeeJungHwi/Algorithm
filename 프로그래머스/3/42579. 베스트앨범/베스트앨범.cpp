#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    
    // genres : 노래의 장르
    // plays : 노래별 재생 횟수
    
    // 0.장르, (재생 횟수, 고유 번호) 맵핑
    // 1.0맵 돌면서 총 재생 횟수, 장르 맵핑
    // 2.1맵 돌면서 장르에 대한 0번 맵의 고유 번호 2개 씩 뽑기
    
    map<string, map<int, vector<int> > > zeroMap;
    map<int, string> oneMap;
    
    for(int i = 0; i < genres.size(); i++) zeroMap[genres[i]][plays[i]].push_back(i + 1);
    for(auto it = zeroMap.begin(); it != zeroMap.end(); it++)
    {
        int totalPlay = 0;
        for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++) totalPlay += it2->first * it2->second.size();
        oneMap[totalPlay] = it->first;
    }
    for(auto it = oneMap.rbegin(); it != oneMap.rend(); it++)
    {
        int pickCnt = 0;
        for(auto it2 = zeroMap[it->second].rbegin(); it2 != zeroMap[it->second].rend(); it2++)
        {
            for(int i = 0; i < it2->second.size(); i++)
            {
                if(pickCnt < 2)
                {
                    answer.push_back(it2->second[i] - 1);
                    pickCnt++;
                }
            }
        }
    }
    
    return answer;
}