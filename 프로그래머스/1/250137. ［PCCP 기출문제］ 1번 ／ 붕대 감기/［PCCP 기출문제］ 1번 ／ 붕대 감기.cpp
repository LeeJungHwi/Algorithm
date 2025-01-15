#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks)
{
    // bandage => 지속시간, 초당체회, 추가체회
    // health => 최대체력
    // attacks => 공격시간, 공격력
    // 모든 공격이 끝나고 남은체력 반환, 죽으면 -1 반환
    int answer = 0;
    
    // 마지막 공격시간 까지
    int cnt = 0, idx = 0, curHealth = health;
    cout << curHealth << '\n';
    for(int i = 1; i < attacks.back()[0] + 1; i++)
    {        
        // 공격시간이면
        // 연속성공 초기화
        // 체력 감소
        // 죽었는지 체크
        // 다음 공격으로
        if(attacks[idx][0] == i)
        {
            cnt = 0;
            curHealth -= attacks[idx++][1];
            if(curHealth <= 0) return -1;
            continue;
        }
        
        // 공격시간이 아니면
        // 연속성공 카운팅
        // 체력회복
        // 지속시간 모두 카운팅되면 추가회복
        cnt++;
        curHealth = curHealth + bandage[1] > health ? health : curHealth + bandage[1];
        if(cnt == bandage[0])
        {
            curHealth = curHealth + bandage[2] > health ? health : curHealth + bandage[2];
            cnt = 0;
        }
        
        cout << cnt << ' ' << curHealth << '\n';
    }
    
    return curHealth;
}