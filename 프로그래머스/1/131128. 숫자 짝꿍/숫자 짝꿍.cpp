#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string X, string Y)
{
    string answer = "";
    
    // (X의 수, 개수) 맵핑
    // (Y의 수, 개수) 맵핑
    // X맵을 돌면서
    // Y맵도 개수가 있으면 (공통수, 최소개수) 맵핑
    // 공통맵핑된게 없으면 -1 출력 
    // 공통맵핑된게 크기가 1이고 그게 0이면 0 출력
    // 그외는 짝꿍이 존재하므로 큰수부터 answer에 추가
    
    map<char, int> xMap;
    map<char, int> yMap;
    map<char, int> commonMap;
    
    for(int i = 0; i < X.size(); i++)
    {
        xMap[X[i]]++;
    }
    
    for(int i = 0; i < Y.size(); i++)
    {
        yMap[Y[i]]++;
    }
    
    for(auto it = xMap.begin(); it != xMap.end(); it++)
    {
        if(yMap[it->first] > 0)
        {
            commonMap[it->first] = min(it->second, yMap[it->first]);
        }
    }
    
    if(commonMap.size() == 0)
    {
        return answer += "-1";
    }
    
    if(commonMap.size() == 1 && commonMap['0'] > 0)
    {
        return answer += "0";
    }
    
    // 그외는 작은수부터 개수만큼 추가하고 뒤집어줌
    for(auto it = commonMap.begin(); it != commonMap.end(); it++)
    {
        while(it->second--)
        {
            answer += it->first;
        }
    }
    
    reverse(answer.begin(), answer.end());
    
    // 디버깅용
    // for(auto it = commonMap.begin(); it != commonMap.end(); it++)
    // {
    //     cout << it->first << ' ' << it->second << '\n';
    // }
    
    return answer;
}