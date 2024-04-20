#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 정렬
// 합쳤을때 내림차순
bool compare(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers)
{
    vector<string> answer;
    
    // 문자열로
    for(int i = 0; i < numbers.size(); i++)
    {
        answer.push_back(to_string(numbers[i]));
    }
    
    // 정렬
    sort(answer.begin(), answer.end(), compare);
    
    // 0 체크
    if(answer[0] == "0") return "0";
    
    // 출력
    string result = "";
    
    for(int i = 0; i < answer.size(); i++)
    {
        result += answer[i];
    }
    
    return result;
}

// #include <string>
// #include <vector>
// #include <iostream>
// #include <algorithm>

// using namespace std;

// vector<bool> vis(100001); // 방문체크

// // DFS
// void DFS(string seq, vector<int> &nums, int cnt, vector<string> &ans)
// {
//     if(cnt == nums.size()) // 종료조건 : 숫자 개수를 넘긴경우
//     {
//         //cout << seq << '\n';
//         ans.push_back(seq);
//     }
//     else
//     {
//         for(int i = 0; i < nums.size(); i++)
//         {
//             if(!vis[i])
//             {
//                 vis[i] = true;
//                 DFS(seq + to_string(nums[i]), nums, cnt + 1, ans);
//                 vis[i] = false;
//             }
//         }
//     }
// }

// string solution(vector<int> numbers)
// {
//     vector<string> answer;
    
//     // DFS
//     DFS("", numbers, 0, answer);
    
//     sort(answer.begin(), answer.end());
    
//     return answer[answer.size() - 1];
// }