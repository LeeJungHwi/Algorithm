#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// DNA
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 뉴클레오티드 : Adenine, Thymine, Guanine, Cytosine
	// 각 DNA 표현 : DNA를 이루는 뉴클레오티드의 앞글자만 따서 표현함
	// 해밍거리 : 두 DNA가 있을때 각 위치의 뉴클오티드 문자가 다른것의 개수
	// 즉, AGCAT와 GGAAT는 1,3 번째 글자가 다르므로 해밍거리는 2임
	// N개의 길이 M인 DNA가 여러개가 주어져있을때 다른 모든 DNA와의 해밍거리의 합이 가장 작은 DNA와 해밍거리 합을 구해야함
	// 여러개면 사전순으로 앞서는 DNA를 구해야함 

	int n, m; // N, M 5, 8
	cin >> n >> m;

	vector<string> dna(n); // 각 DNA 저장

	//	TATGATAC
	//	TAAGCTAC
	//	AAAGATCC
	//	TGAGATAC
	//	TAAGATGT
	for (int i = 0; i < n; i++)
	{
		cin >> dna[i];
	}

	string minHamingDNA; // 최소 해밍거리 DNA
	int minHamingDis = 0; // 최소 해밍거리

	// 모든 DNA를 인덱스 0부터 (알파벳, 나온횟수) 맵핑
	// 나온횟수가 최대인 알파벳 최소 해밍거리 DNA에 추가

	for (int i = 0; i < m; i++) // 모든 DNA를 인덱스 0부터
	{
		map<char, int> alphaCnt; // (알파벳, 나온횟수) 맵핑

		for (int j = 0; j < dna.size(); j++)
		{
			alphaCnt[dna[j][i]]++;
		}

		// 맵 돌면서 나온횟수가 최대인 알파벳 최소 해밍거리 DNA에 추가

		int maxCnt = 0; // 최대 나온횟수, 해밍거리는 n - maxCnt
		char maxCntAlpha = 'a'; // 최대 나온횟수 알파벳

		for (auto it = alphaCnt.begin(); it != alphaCnt.end(); it++)
		{
			if (it->second > maxCnt)
			{
				maxCnt = it->second;
				maxCntAlpha = it->first;
			}
		}

		minHamingDNA += maxCntAlpha;
		minHamingDis += n - maxCnt;
	}

	cout << minHamingDNA << '\n' << minHamingDis << '\n';

	return 0;
}