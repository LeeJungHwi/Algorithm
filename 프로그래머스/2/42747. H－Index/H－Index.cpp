#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations)
{
    int answer = 0;
    
    // citations : 논문의 인용 횟수
    
    // 0.인용 횟수 오름차순 정렬
    // 1.citations 돌면서 현재 논문의 인용 횟수가 현재 논문을 포함해 남은 논문들의 수 이상이 되면 hIdx 리턴
    
    sort(citations.begin(), citations.end());
    for(int i = 0; i < citations.size(); i++) if(citations[i] >= citations.size() - i) return citations.size() - i;
    
    return answer;
}