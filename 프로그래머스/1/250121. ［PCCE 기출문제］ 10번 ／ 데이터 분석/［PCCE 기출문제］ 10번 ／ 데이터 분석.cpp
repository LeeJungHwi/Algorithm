#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

map<string, int> sortMap;
string sortBy;

bool comp(const vector<int> &v1, const vector<int> &v2) { return v1[sortMap[sortBy] - 1] < v2[sortMap[sortBy] - 1]; }

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by)
{
    vector<vector<int>> answer;
    sortBy = sort_by;
    
    // data : code date max rem
    // ext : 데이터 뽑는 기준
    // val_ext : 뽑은 정보 기준값
    // sort_by : 정보 정렬 기준
    
    // 정렬 기준 맵핑
    sortMap["code"] = 1;
    sortMap["date"] = 2;
    sortMap["maximum"] = 3;
    sortMap["remain"] = 4;
    
    // 1. sort_by 로 정렬
    // 2. ext 보면서 val_ext 초과 데이터 삭제
    // 3. answer에 데이터 저장
    
    sort(data.begin(), data.end(), comp);
    for(int i = 0; i < data.size(); i++) if(data[i][sortMap[ext] - 1] <= val_ext) answer.push_back(data[i]);
    
    return answer;
}