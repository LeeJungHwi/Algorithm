#include <string>
#include <map>
#include <vector>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo)
{
    vector<int> answer;
    
    // name : 그리워하는 사람의 이름을 담은 문자열 배열
    // yearning : 각 사람별 그리움 점수를 담은 정수 배열
    // photo : 각 사진에 찍힌 인물의 이름을 담은 2차원 문자열 배열
    // answer : 각 사진의 추억점수 저장
    
    // (이름, 점수) 맵핑
    // 사진 돌면서 추억점수 구하고 answer에 저장
    
    // (이름, 점수) 맵핑 
    map<string, int> nameScore;
    
    for(int i = 0; i < name.size(); i++)
    {
        nameScore[name[i]] = yearning[i];
    }
    
    // 사진 돌면서 추억점수 구하고 answer에 저장
    for(int i = 0; i < photo.size(); i++) // 전체 사진 수를 돌면서
    {
        int score = 0; // 각 사진 추억점수
        
        for(int j = 0; j < photo[i].size(); j++) // 각 사진을 돌면서
        {
            if(nameScore[photo[i][j]] > 0) // 추억이있는 사람의 이름이 있으면
            {
                score += nameScore[photo[i][j]]; // 해당 사람의 추억점수 누적
            }
        }
        
        // answer에 각 사진 추억점수 저장
        answer.push_back(score);
    }
    
    return answer;
}