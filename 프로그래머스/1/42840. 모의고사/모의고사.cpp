#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    
    // answers : 문제 정답
    // 1번 : 1 2 3 4 5
    // 2번 : 2 1 2 3 2 4 2 5
    // 3번 : 3 3 1 1 2 2 4 4 5 5
    
    vector<int> first = {1, 2, 3, 4, 5}; // 1번
    vector<int> second = {2, 1, 2, 3, 2, 4, 2, 5}; // 2번
    vector<int> third = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}; // 3번
    vector<vector<int> > student = {first, second, third};
    int maxCnt = 0; // 최대 맞은 개수
    vector<int> cnts; // 각 사람이 맞은개수 저장
    
    for(int i = 0; i < student.size(); i++)
    {
        int curIdx = -1; // 현재인덱스
        int size = student[i].size(); // 5
        int cnt = 0; // 맞은 개수
        
        for(int j = 0; j < answers.size(); j++)
        {
            // 찍는 순서 조정
            curIdx++;
            if(curIdx == size) curIdx = 0;
            
            // 맞은개수 카운팅
            if(answers[j] == student[i][curIdx]) cnt++;
        }
        
        // 최대 맞은개수 갱신하면서 각 사람이 맞은 개수 저장
        maxCnt = max(maxCnt, cnt);
        cnts.push_back(cnt);
    }
    
    // 모든사람이 다 틀렸으면 answer return
    if(maxCnt == 0) return answer;
    
    // 최대 맞은개수인 사람만 answer에 push
    for(int i = 0; i < cnts.size(); i++)
    {
        if(cnts[i] == maxCnt) answer.push_back(i + 1);
    }
    
    return answer;
}