#include <string>
#include <vector>
using namespace std;

#define loop(v, s, e) for(int v = s; v < e; v++)

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> home(arr1.size(), vector<int>(arr1[0].size()));
    loop(i, 0, arr1.size()) loop(j, 0, arr1[i].size()) home[i][j] = arr1[i][j] + arr2[i][j];
    
    return home;
}