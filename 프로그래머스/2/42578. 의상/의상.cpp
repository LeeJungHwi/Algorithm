#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    
    // clothes : 코니가 가진 의상
    
    // 0.의상 종류, 의상 이름들 맵핑
    // 1.의상 종류에 해당하는 각 의상을 선택하거나 모두 선택하지 않은 경우
    // 2.아무것도 입지 않은 경우 제외
    
    map<string, vector<string> > clothMap;
    for(int i = 0; i < clothes.size(); i++) clothMap[clothes[i][1]].push_back(clothes[i][0]);
    for(auto it = clothMap.begin(); it != clothMap.end(); it++) answer *= (it->second.size() + 1);
    
    return answer - 1;
}