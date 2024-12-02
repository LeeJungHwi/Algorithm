#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2)
{
    if(arr1.size() != arr2.size()) return arr1.size() > arr2.size() ? 1 : -1;
    int n = 0, m = 0;
    for(int i = 0; i < arr1.size(); i++)
    {
        n += arr1[i];
        m += arr2[i];
    }
    if(n == m) return 0;
    return n > m ? 1 : -1;
}