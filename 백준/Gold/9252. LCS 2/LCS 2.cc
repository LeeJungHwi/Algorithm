#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define elprint(a) cout << a << '\n'
#define cond(c, t, f) ((c) ? (t) : (f))

// LCS 2
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	string first, second;
	cin >> first >> second;
	
	// 두 부분문자열의 마지막 문자가 같다면 => 두 부분문자열의 마지막 문자를 뺀 최대길이 + 1
	// 두 부분문자열의 마지막 문자가 다르다면 => 첫문자열의 마지막문자 뺀 최대길이, 두번째문자열의 마지막문자 뺀 최대길이 둘 중 최대
	vector<vector<int> > dp(first.size() + 1, vector<int>(second.size() + 1));
	loop(i, 1, first.size() + 1) loop(j, 1, second.size() + 1)
		dp[i][j] = cond(first[i - 1] == second[j - 1], dp[i - 1][j - 1] + 1, max(dp[i - 1][j], dp[i][j - 1]));

	int len = dp[first.size()][second.size()];
	elprint(len);
	string lcs;
	int i = first.size(), j = second.size();
	while (i > 0 && j > 0)
	{
		// 두 부분문자열의 마지막 문자가 같다면 => lcs에 추가
		if (first[i - 1] == second[j - 1])
		{
			lcs.push_back(first[i - 1]);
			i--;
			j--;
			continue;
		}

		// 두 부분문자열의 마지막 문자가 다르다면
		// 첫문자열의 마지막문자 뺀 최대길이가 두번째문자열의 마지막문자 뺀 최대길이보다 길면
		// 첫문자열의 마지막문자 뺌 아니면 두번째문자열의 마지막문자 뺌
		cond(dp[i - 1][j] > dp[i][j - 1], i--, j--);
	}

	reverse(lcs.begin(), lcs.end());
	cond(!len, elprint('\n'), elprint(lcs));

	return home;
}