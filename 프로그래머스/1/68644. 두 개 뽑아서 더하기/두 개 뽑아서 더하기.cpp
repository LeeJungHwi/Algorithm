#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> home;
#define loop(t, v, s, e, c) for(t v = s; v c e; v++)
set<int> homeSet;

vector<int> solution(vector<int> numbers)
{
    loop(int, i, 0, numbers.size() - 1, <) loop(int, j, i + 1, numbers.size(), <) homeSet.insert(numbers[i] + numbers[j]);
    loop(auto, it, homeSet.begin(), homeSet.end(), !=) home.push_back(*it);
    
    return home;
}