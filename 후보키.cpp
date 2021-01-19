#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

bool ft_check(vector<int> ans, int ind) {
	for (int i = 0; i < ans.size(); i++) {
		if ((ans[i] & ind) == ans[i])		// 최소성 만족 여부 확인
			return false;
	}
	return true;
}

int solution(vector<vector<string>> relation) {
	int n = relation.size();
	int m = relation[0].size();
	vector<int> ans;

	for (int i = 0; i < (1 << m); i++) {
		set<string> s;
		for (int j = 0; j < n; j++) {
			string str = "";
			for (int k = 0; k < m; k++) {
				if (i & (1 << k))		// 추출하고자 하는 속성이 i에 속하는지 확인, 예를 들어 i가 5(0101)일 때 k가 0(1<<0) 또는 2(1<<2)이어야 추출한다.
					str += relation[j][k];
			}
			s.insert(str);
		}
		if (s.size() == n && ft_check(ans, i))
			ans.push_back(i);
	}
	return ans.size();
}
