#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total)
{
    vector<int> answer;
    for (int i = 0; i < num; i++) answer.push_back(total / num - (num - 1) / 2 + i);
    return answer;
}