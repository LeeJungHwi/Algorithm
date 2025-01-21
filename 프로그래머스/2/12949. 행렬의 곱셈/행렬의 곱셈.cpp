#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    int n = arr1[0].size();
    int m = arr1.size();
    int arr2N = arr2[0].size();
    vector<vector<int> > answer(m, vector<int>(arr2N));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < arr2N; j++)
        {
            for (int k = 0; k < n; k++)
            {
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    
    return answer;
}