#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    int answer = -1;
    
    // skill : 선행스킬순서
    // skill_trees : 유저가 만든 스킬트리
    
    // answer : 가능한 스킬트리 개수
    
    // skill 돌면서 (스킬순서, 스킬문자) 맵핑
    // skill_trees 돌면서 skill에 있는 문자를 만나면
    // 현재스킬인덱스에 해당하는 스킬이 아니면 continue
    // 마지막까지 내려왔으면 가능한 스킬트리 카운팅
    
    // skill 돌면서 (스킬순서, 스킬문자) 맵핑
    // 1 C
    // 2 B
    // 3 D
    map<int, char> orderSkill;
    
    for(int i = 0; i < skill.size(); i++)
    {
        orderSkill[i + 1] = skill[i];
    }
    
    // skill_trees 돌면서
    for(int i = 0; i < skill_trees.size(); i++)
    {
        bool isSkill = true; // 가능한 스킬트리인지 체크
        int curSkillIdx = 1; // 현재스킬인덱스
        
        for(int j = 0; j < skill_trees[i].size(); j++) // 각 스킬트리 돌면서
        {
            for(auto it = orderSkill.begin(); it != orderSkill.end(); it++) // 맵 돌면서
            {
                if(it->second == skill_trees[i][j]) // skill에 있는 문자를 만나면
                {   
                    if(orderSkill[curSkillIdx] != skill_trees[i][j]) // 현재스킬인덱스에 해당하는 스킬이 아니면 불가능한스킬
                    {
                        isSkill = false;
                    }
                    else // 현재스킬인덱스에 해당하는 스킬이면 curSkillIdx 증가
                    {
                        curSkillIdx++;
                    }
                }
                
                // 불가능한 스킬트리면 break
                if(!isSkill)
                {
                    break;
                }
            }
            
            // 불가능한 스킬트리면 break
            if(!isSkill)
            {
                break;
            }
        }
        
        // 가능한 스킬트리면 카운팅
        if(isSkill)
        {
            //cout << skill_trees[i] << '\n';
            answer++;
        }
    }
    
    // 가능한스킬트리가 있다면 -1부터 시작했으므로 1증가
    if(answer != -1)
    {
        answer++;
    }
    else // 가능한 스킬트리가 없다면 0
    {
        answer = 0;
    }
    
    return answer;
}