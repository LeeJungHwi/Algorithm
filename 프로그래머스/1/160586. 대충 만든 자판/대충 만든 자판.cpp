#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets)
{
    vector<int> answer;
    
    // keymap : 1번 키부터 차례대로 할당된 문자들이 순서대로 담긴 문자열배열
    // targets : 입력하려는 문자열들이 담긴 문자열배열
    // answer : 각 문자열을 작성하기위해 키를 최소 몇번눌러야하는지 저장
    
    // keymap 돌면서 (문자, 최소횟수) 맵핑
    // targets 돌면서 각 문자열의 최소횟수를 answer에 저장
    
    map<char, int> m;
    
    for(int i = 0; i < keymap.size(); i++)
    {
        for(int j = 0; j < keymap[i].size(); j++)
        {
            if(m[keymap[i][j]] == 0 || m[keymap[i][j]] > j + 1) // 횟수가 할당된적 없거나 기존값보다 작은값만 갱신
            {
                m[keymap[i][j]] = j + 1;
            }
        }
    }
    
    for(int i = 0; i < targets.size(); i++)
    {
        int pressCnt = 0; // 키를 누른 횟수
        bool cantPress = false; // 키를 누를수없는 문자가 있는지 체크
        
        for(int j = 0; j < targets[i].size(); j++)
        {
            if(m[targets[i][j]] == 0) // 횟수가 없다면 누를수없는 문자
            {
                cantPress = true;
                
                break;
            }
            
            pressCnt += m[targets[i][j]];
        }
        
        if(cantPress) // 키를 누를수없는 문자가 있다면 -1 저장
        {
            answer.push_back(-1);
            
            continue;
        }
        
        // 키를 누른 횟수 저장
        answer.push_back(pressCnt);
    }
    
    return answer;
}