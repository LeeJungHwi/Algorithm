#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int answer = 0;
    
    priority_queue<int> mHeap;
    priority_queue<int> nHeap;
    
    // 가로에 길이가 긴 변 몰빵
    for(int i = 0; i < sizes.size(); i++)
    {
        mHeap.push(sizes[i][0] >= sizes[i][1] ? sizes[i][0] : sizes[i][1]);
        nHeap.push(sizes[i][0] >= sizes[i][1] ? sizes[i][1] : sizes[i][0]);
    }
    
    return answer = mHeap.top() * nHeap.top();
}