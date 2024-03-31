#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 정렬기준
// 폭격미사일 끝지점 오름차순
bool compare(const vector<int> &v1, const vector<int> &v2)
{
    return v1[1] < v2[1];
}

int solution(vector<vector<int>> targets)
{
    int answer = 0;
    
    // targets : 각 폭격 미사일의 x좌표 범위
    // answer : 모든 폭격 미사일을 요격하기위해 필요한 요격 미사일 수의 최솟값
    
    // 1.x끝 기준 정렬
    // 2.요격할 폭격미사일의 시작지점이 현재 요격미사일의 끝지점보다 이상이면 새로운 요격미사일이 필요함
    
    // 1.x끝 기준 정렬
    sort(targets.begin(), targets.end(), compare);
    
    // 2.요격할 폭격미사일의 시작지점이 현재 요격미사일의 끝지점보다 이상이면 새로운 요격미사일이 필요함
    int endPos = -1; // 현재 요격미사일의 끝지점
    
    for(int i = 0; i < targets.size(); i++) // 폭격미사일 돌면서
    {
        if (targets[i][0] >= endPos) // 요격할 폭격미사일의 시작지점이 현재 요격미사일의 끝지점 이상이면
        {
            answer++; // 새로운 요격미사일이 필요함
            endPos = targets[i][1]; // 현재 요격미사일의 끝지점 갱신
        }
    }
    
    return answer;
}