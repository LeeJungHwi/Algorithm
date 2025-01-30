#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int Col = -1;

bool comp(const vector<int> &v1, const vector<int> &v2)
{
    if(v1[Col] != v2[Col]) return v1[Col] < v2[Col];
    return v1[0] > v2[0];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end)
{
    int answer = 0;
    Col = --col;
    sort(data.begin(), data.end(), comp);
    // for(auto a : data)
    // {
    //     for(auto b : a)
    //     {
    //         cout << b << ' ';
    //     }
    //     cout << '\n';
    // }
    vector<int> Si;
    for(int i = row_begin - 1; i < row_end; i++)
    {
        int si = 0;
        for(int j = 0; j < data[i].size(); j++) si += data[i][j] % (i + 1);
        Si.push_back(si);
        //cout << si << '\n';
    }
    for(int i = 0; i < Si.size(); i++) answer ^= Si[i];
    
    return answer;
}