#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k)
{
    bool isEven = k % 2 == 1 ? false : true;
    for(int i = 0; i < arr.size(); i++) arr[i] = isEven ? arr[i] + k : arr[i] * k;
    return arr;
}