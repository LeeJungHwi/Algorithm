#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list)
{
    int answer = 0;
    string t1 = "", t2 = "";
    for(int i = 0; i < num_list.size(); i++) if(num_list[i] % 2 == 1) t1 += to_string(num_list[i]); else t2 += to_string(num_list[i]);
    answer = stoi(t1) + stoi(t2);
    return answer;
}