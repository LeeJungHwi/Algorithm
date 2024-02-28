#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 등수 기준 오름차순 정렬
bool compare(const pair<int, int> &r1, const pair<int, int> &r2)
{
    return r1.second < r2.second;
}

int solution(vector<int> rank, vector<bool> attendance)
{
    int answer = 0;
    
    // n명 학생 중 참여학생 중 등수가 높은 3명을 선발
    // rank -> 각 학생의 선발고사 등수
    // attendance -> 각 학생이 참여가능한지
    // 10000 * a + 100 * b + c 구하기
    
    // 각 학생의 (번호, 등수) 쌍 저장
    vector<pair<int, int> > student(rank.size());
    
    for(int i = 0; i < rank.size(); i++)
    {
        student[i] = {i, rank[i]};
    }
    
    // 등수 기준 오름차순 정렬
    sort(student.begin(), student.end(), compare);
    
    // 결과 구하기
    
    int curRank = 1; // 현재 선발하는 등수
    
    for(int i = 0; i < rank.size(); i++) // 학생 수만큼 돌면서
    {
        if(attendance[student[i].first]) // 해당학생이 참여가능하다면
        {
            if(curRank == 1) // 1등
            {
                answer += student[i].first * 10000;
                curRank++;
            }
            else if(curRank == 2) // 2등
            {
                answer += student[i].first * 100;
                curRank++;
            }
            else if(curRank == 3) // 3등
            {
                answer += student[i].first;
                break;
            }
        }
    }

    return answer;
}