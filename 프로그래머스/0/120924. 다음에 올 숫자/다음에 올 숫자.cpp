#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common)
{
    if(common[1] - common[0] == common[2] - common[1]) return common[common.size() - 1] + common[1] - common[0];
    else return common[common.size() - 1] * common[1] / common[0];
}