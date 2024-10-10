#include <string>
#include <vector>

using namespace std;

int ans;

void Rec(vector<int> &numList, int s)
{
    if(s >= numList.size()) return;
    ans = numList.size() >= 11 ? ans + numList[s++] : ans * numList[s++];
    Rec(numList, s);
}

int solution(vector<int> num_list)
{
    ans = num_list.size() >= 11 ? 0 : 1;
    Rec(num_list, 0);
    return ans;
}