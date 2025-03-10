#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> info, int n, int m)
{
    // A 도둑이 i번째 물건을 훔치면 info[i][0]개의 흔적을 남기고 n개 이상이되면 경찰에 붙잡힘
    // B 도둑이 i번째 물건을 훔치면 info[i][1]개의 흔적을 남기고 m개 이상이되면 경찰에 붙잡힘
    // 두 도둑 모두 경찰에 붙잡히지 않도록 모든 물건을 훔칠 때 A도둑이 남긴 흔적 개수 최솟값
    // 어떤 방법으로도 두 도둑 모두 붙잡히지 않는 방법이 없다면 -1
    // 현재 물건을 A가 챙기는 경우와 B가 챙기는 경우로 A가 남긴 흔적의 최솟값 업데이트
    
    // dp[i][j][k] => i번째 물건 까지 고려했을 때 A와 B가 남긴 흔적의 개수가 각각 j, k일 때 A가 남긴 흔적 횟수의 최솟값
    vector<vector<vector<int>>> dp(info.size() + 1, vector<vector<int>>(n + 1, vector<int>(m + 1, 2147000000)));

    // base => 두 도둑 모두 아무 흔적도 남기지 않음
    dp[0][0][0] = 0;

    for (int i = 0; i < info.size(); i++) for (int j = 0; j < n; j++) for (int k = 0; k < m; k++)
    {
        // 불가능한 상태 X
        if (dp[i][j][k] == 2147000000) continue;

        // A가 i번째 물건을 챙기는 경우 다음 물건에 대한 디피 업데이트
        if (j + info[i][0] < n) dp[i + 1][j + info[i][0]][k] = min(dp[i + 1][j + info[i][0]][k], dp[i][j][k] + info[i][0]);

        // B가 i번째 물건을 챙기는 경우 다음 물건에 대한 디피 업데이트
        if (k + info[i][1] < m) dp[i + 1][j][k + info[i][1]] = min(dp[i + 1][j][k + info[i][1]], dp[i][j][k]);
    }

    // 마지막 물건 까지 고려했을 때 A가 남긴 흔적의 최솟값
    int answer = 2147000000;
    for (int j = 0; j < n; j++) for (int k = 0; k < m; k++) answer = min(answer, dp[info.size()][j][k]);
    return (answer == 2147000000) ? -1 : answer;
}