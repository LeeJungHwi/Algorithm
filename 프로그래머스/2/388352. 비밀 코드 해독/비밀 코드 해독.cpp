#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer;
vector<int> order;

void DFS(int L, int s, int bitmask, vector<vector<int>> &q, vector<int> &ans, int &n)
{
    if(L == 5)
    {
        //for(int i = 0; i < 5; i++) cout << order[i] << ' ';
        //cout << '\n';
        
        bool is = true; // 가능한 비밀번호인지 체크
        for(int i = 0; i < q.size(); i++)
        {
            int cnt = 0; // 일치하는 개수
            int p1 = 0, p2 = 0; // 선택한 숫자 포인터, q 숫자 포인터
            
            // p1 또는 p2가 5가 될 때 까지
            // p1이 작으면 p1++
            // p2가 작으면 p2++
            // p1과 p2가 같으면 둘다++
            while(p1 < 5 && p2 < 5)
            {
                if(order[p1] < q[i][p2]) p1++;
                else if(order[p1] > q[i][p2]) p2++;
                else
                {
                    cnt++;
                    p1++;
                    p2++;
                }
            }
            
            // 만약 일치하는 개수가 다르면 불가능한 비밀번호
            if(cnt != ans[i]) return;
        }
        
        // 비밀번호로 가능한 경우만 카운팅
        answer++;
    }
    else
    {
        for(int i = s; i < n + 1; i++)
        {
            if((bitmask & (1 << i)) > 0) continue;
            
            order.push_back(i);
            DFS(L + 1, i, bitmask | (1 << i), q, ans, n);
            order.pop_back();
        }
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans)
{
    // 비중복조합으로 5개 숫자 선택
    // q돌면서 일치하는 개수가 전부 맞는지 확인하고 카운팅
    DFS(0, 1, 0, q, ans, n);
    
    return answer;
}