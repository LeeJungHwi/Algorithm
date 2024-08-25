#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr, int k)
{
    vector<int> answer;
    vector<bool> vis(100001);
    for(int i = 0; i < arr.size(); i++)
    {
        if(answer.size() == k) break;
        if(vis[arr[i]]) continue;
        answer.push_back(arr[i]);
        vis[arr[i]] = true;
    }
    if(answer.size() < k)
    {
        int backupSize = answer.size();
        for(int i = 0; i < k - backupSize; i++)
        {
            answer.push_back(-1);
        }
    }
    
    return answer;
}