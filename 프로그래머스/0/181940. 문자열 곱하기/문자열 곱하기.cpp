#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

string solution(string my_string, int k)
{
    string answer = my_string;
    int cnt = 1;
    while(pow(2, cnt) < k) cnt++;
    cnt--; k -= pow(2, cnt);
    for(int i = 0; i < cnt; i++) answer += answer;
    for(int i = 0; i < k; i++) answer += my_string;
    return answer;
}