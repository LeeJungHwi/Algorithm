#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<bool> vis(7);
string selectedNum;
set<int> numSet;
int primeCnt;

// 소수 체크
void CheckPrime(int num)
{
    if(num <= 1) return;
    
    bool isPrime = true;
    for(int i = 2; i * i <= num; i++)
    {
        if(num % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    if(isPrime) primeCnt++;
}

// DFS
void DFS(int L, string &nums)
{
    if(L == nums.size()) return;
    
    for(int i = 0; i < nums.size(); i++)
    {
        if(!vis[i])
        {
            vis[i] = true;
            selectedNum += nums[i];
            //cout << selectedNum << '\n';
            //CheckPrime(selectedNum);
            numSet.insert(stoi(selectedNum));
            DFS(L + 1, nums);
            vis[i] = false;
            selectedNum.pop_back();
        }
    }
}

int solution(string numbers)
{
    int answer = 0;
    
    // 0. DFS 로 모든 숫자 조합
    // 1. 모든 숫자 조합에 대해 소수 체크
    DFS(0, numbers);
    //for(auto it = numSet.begin(); it != numSet.end(); it++) cout << *it << '\n';
    for(auto it = numSet.begin(); it != numSet.end(); it++) CheckPrime(*it);
    
    return answer = primeCnt;
}