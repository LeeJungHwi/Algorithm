#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> operations)
{
    vector<int> answer;
    
    // operations : 연산
	// I 숫자 : 저장
	// D 1 : 우선순위가 가장 높은값 삭제
	// D -1 : 우선순위가 가장 낮은값 삭제
    
    map<long long, long long> m; // (숫자, 개수) 맵핑

    for (int i = 0; i < operations.size(); i++)
    {
        char op = operations[i][0];
        
        // (숫자, 개수) 맵핑
        if (op == 'I')
        {
            m[stoll(operations[i].substr(2, operations[i].size() - 2))]++;
            continue;
        }

        // 최솟값이면 맵 첫요소--
        // 최댓값이면 맵 막요소--
        
        if (operations[i][2] == '-')
        {
            if(!m.empty()) m.begin()->second--;
            else continue;
            if (m.begin()->second == 0) m.erase(m.begin());
            continue;
        }
        
        if (!m.empty())
        {
            auto it = m.end();
            it--;
            it->second--;
            if (it->second == 0) m.erase(it);
        }
    }
    
    // 비었으면 0 0
    if (m.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    
    // 비어있지않으면 최대 최소
    auto it = m.end();
    it--;
    answer.push_back(it->first);
    answer.push_back(m.begin()->first);
    
    return answer;
}