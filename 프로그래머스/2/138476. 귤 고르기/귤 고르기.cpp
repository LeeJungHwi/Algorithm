#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(int k, vector<int> tangerine)
{
    int answer = 0;
    
    // k : 수확한 귤 중 고를 귤의 개수
    // tangerine : 각 귤의 크기
    // 수확한 귤의 크기가 일정하지않아 보기에좋지않아 귤을 크기별로 분류했을때 서로다른종류의 수를 최소화하고싶음
    // answer : 귤 k 개를 고를때 크기가 서로다른 종류 수의 최솟값
    
    // tangerine 돌면서 (귤크기, 귤개수) 맵핑하고 귤 총 개수와 맵 크기를 구해놓음
    // 맵 돌면서 (귤개수, 귤크기) 맵핑
    // 맵 돌면서 각 키의 값 개수만큼 하나씩 빼보면서 체크
    
    map<int, int> sizeCnt; // (귤크기, 귤개수)
    int totalCnt = tangerine.size(); // 귤 총 개수 8
    
    for(int i = 0; i < tangerine.size(); i++)
    {
        sizeCnt[tangerine[i]]++; // 1 1, 2 2, 3 2, 4 1, 5 2
    }
    
    int mapSize = sizeCnt.size(); // 맵 크기 5
    
    // 디버깅용
    // for(auto it = sizeCnt.begin(); it != sizeCnt.end(); it++)
    // {
    //     cout << it->first << ' ' << it->second << '\n';
    // }
    // cout << '\n';
    
    map<int, int> cntSize; // (귤개수, 귤크기)
    
    for(auto it = sizeCnt.begin(); it != sizeCnt.end(); it++)
    {
        cntSize[it->second]++; // 1 2, 2 3
    }
    
    // 디버깅용
    // for(auto it = cntSize.begin(); it != cntSize.end(); it++)
    // {
    //     cout << it->first << ' ' << it->second << '\n';
    // }
    
    // 맵 돌면서 각 키의 값 개수만큼 하나씩 빼보면서 체크
    // 귤 총 개수 - 키 > k 면 귤 총 개수와 맵 크기 실제로 빼줌 : 아직 k보다 크므로 현재키값을 빼주고 다음키값을 체크해야함
    // 귤 총 개수 - 키 == k 면 answer = 맵 크기 - 1 : 현재키값을 제외했을때 k개와 같아지므로 현재키값을 제외해서 맵크기에서 1빼줌
    // 귤 총 개수 - 키 < k 면 answer = 맵 크기 : k보다 작아지지않게 제외하므로 현재키값은 서로다른종류로 포함됨
    for(auto it = cntSize.begin(); it != cntSize.end(); it++)
    {
        for(int i = 0; i < it->second; i++)
        {
            if(totalCnt - it->first > k)
            {
                totalCnt -= it->first;
                mapSize--;
            }
            else if(totalCnt - it->first == k)
            {
                return answer = --mapSize;
            }
            else if(totalCnt - it->first < k)
            {
                return answer = mapSize;
            }
        }
    }
    
    return answer;
}