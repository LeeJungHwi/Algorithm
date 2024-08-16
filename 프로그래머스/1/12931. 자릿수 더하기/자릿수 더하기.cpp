#include <string>
using namespace std;

int solution(int n)
{
    int answer = 0;
    string temp = to_string(n);
    for(int i = 0; i < temp.size(); i++) answer += temp[i] - '0';

    return answer;
}