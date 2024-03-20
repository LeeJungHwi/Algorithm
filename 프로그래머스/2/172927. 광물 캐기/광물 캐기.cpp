#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> nums; // 처음 자연수 저장 1 2 2 2 3 3
vector<int> combination; // 선택된 수열
vector<bool> vis(15); // 방문체크
map<string, int> diamond; // 다이아몬드로 캐짐을 당하는 광물의 피로도
map<string, int> iron; // 철로 캐짐을 당하는 광물의 피로도
map<string, int> stone; // 돌로 캐짐을 당하는 광물의 피로도
int minStamina = 2147000000; // 최소피로도

// DFS
void DFS(int L, vector<string> &minerals)
{
	if (L == nums.size()) // 종료조건 : 6개 뽑은경우
	{
        int stamina = 0; // 현재 수열로 캤을때 피로도
        int curMineral = 0; // 현재 캐야 할 처음 광물인덱스
        
        // 현재 순열 돌면서 minerals 돌면서 광물 캐면서 피로도 누적 후 최소피로도 갱신
        for(int i = 0; i < combination.size(); i++)
        {
            for(int j = curMineral; j < curMineral + 5; j++)
            {
                // 더이상 캘 광물이 없으면 최소피로도 갱신하고 리턴
                if(j == minerals.size())
                {
                    minStamina = min(minStamina, stamina);
                    
                    return;
                }
                
                if(combination[i] == 1) // 다이아 곡괭이로 캐면
                {
                    stamina += diamond[minerals[j]];
                }
                else if(combination[i] == 2) // 철 곡괭이로 캐면
                {
                    stamina += iron[minerals[j]];
                }
                else if(combination[i] == 3) // 돌 곡괭이로 캐면
                {
                    stamina += stone[minerals[j]];
                }
            }
            
            // 캐야 할 광물 인덱스 갱신
            curMineral += 5;
        }
        
        // 최소피로도 갱신
        minStamina = min(minStamina, stamina);
	}
	else
	{
		for (int i = 0; i < nums.size(); i++)
		{
            // 중복없이 조합 생성
            if (!vis[i] && (i == 0 || nums[i] != nums[i - 1] || vis[i - 1]))
            {
                vis[i] = true; // 선택
                combination.push_back(nums[i]);
                DFS(L + 1, minerals);
                combination.pop_back();
                vis[i] = false; // 미선택
            }
		}
	}
}


int solution(vector<int> picks, vector<string> minerals)
{
    int answer = 0;
    
    // 다이아 곡괭이 : 0 ~ 5개
    // 철 곡괭이 : 0 ~ 5개
    // 돌 곡괭이 : 0 ~ 5개
    // 곡괭이로 광물을 캘때마다 피로도가 소모되며 각 곡괭이는 광물 5개를 캐면 더이상 사용할수없음 
    // 다이아 -> 다이아(1) 철(1) 돌(1)
    // 철 -> 다이아(5) 철(1) 돌(1)
    // 돌 -> 다이아(25) 철(5) 돌(1)
    // 아래 규칙을 지키면서 최소한의 피로도로 광물을 캐야함
    // 1. 사용할수있는 곡괭이중 아무거나 하나를 선택해 광물을 캠
    // 2. 한번 사용하기 시작한 곡괭이는 사용할수없을때까지 사용함
    // 3. 광물은 주어진 순서대로만 캘수있음
    // 4. 광산에 있는 모든 광물을 캐거나 더 사용할 곡괭이가 없을때까지 광물을 캠
    // 요약 -> 곡괭이 하나를 선택해서 광물 5개를 연속으로 캐고 다음 곡괭이를 선택하고 캐는것을 더이상 남은 곡괭이가 없거나 더이상 남은 광물이 없을때까지 반복함
    // picks : 갖고있는 곡괭이의 개수를 나타내는 정수 배열 
    // minerals : 광물들의 순서를 나타내는 문자열 배열
    // answer : 작업을 끝내기까지 필요한 최소한의 피로도 
    
    // picks 돌면서 각 곡괭이 개수 및 곡괭이 총 개수 구하기
    
    for(int i = 0; i < picks.size(); i++)
    {
        for(int j = 0; j < picks[i]; j++)
        {
            nums.push_back(i + 1);
        }
    }
    
    // 디버깅용
    // for(auto a : nums)
    // {
    //     cout << a << ' ';
    // }
    
    // 각 곡괭이 종류로 캘때 피로도 맵핑
    
    diamond["diamond"] = 1;
    diamond["iron"] = 1;
    diamond["stone"] = 1;
    iron["diamond"] = 5;
    iron["iron"] = 1;
    iron["stone"] = 1;
    stone["diamond"] = 25;
    stone["iron"] = 5;
    stone["stone"] = 1;
    
    // DFS 1 2 2 2 3 3 각 곡괭이로 캘 순서 선택하기
    // 선택된 순서대로 캐보면서 최소피로도 갱신하기
    DFS(0, minerals);
    
    answer = minStamina;
    
    return answer;
}