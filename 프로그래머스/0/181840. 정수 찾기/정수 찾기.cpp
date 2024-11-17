#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> num_list, int n)
{
    sort(num_list.begin(), num_list.end());
    int first = 0, last = num_list.size();
    while(first <= last)
    {
        int standard = (first + last) / 2;
        if(num_list[standard] == n) return 1;
        else if(num_list[standard] > n) last = --standard;
        else first = ++standard;
    }
    return 0;
}