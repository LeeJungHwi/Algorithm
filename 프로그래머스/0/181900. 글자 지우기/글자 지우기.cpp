#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = "";
    if(indices.empty()) return my_string;
    sort(indices.begin(), indices.end());
    int cur = 0;
    for(int i = 0; i < my_string.size(); i++)
    {
        if(i != indices[cur]) answer.push_back(my_string[i]);
        else ++cur;
    }
    return answer;
}