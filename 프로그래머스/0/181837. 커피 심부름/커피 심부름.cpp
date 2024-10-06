#include <string>
#include <vector>

using namespace std;

int solution(vector<string> order)
{
    int answer = 0;
    for(int i = 0; i < order.size(); i++) answer += order[i][3] == 'a' || order[i][3] == 'r' || order[i][3] == 't' ? 4500 : 5000;
    return answer;
}