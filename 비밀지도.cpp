#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
	vector<string> answer = {};
	for (int i = 0; i < n; i++)
	{
		string res = "";
		char ch;
		for (int j = n - 1; j >= 0; j--) // 맨 앞자리부터 계산해야 하기 때문에 이처럼 반복문 사용
		{
			ch = ((arr1[i] & (1 << j)) || (arr2[i] & (1 << j))) ? '#' : ' ';
			res.push_back(ch);
		}
		answer.push_back(res);
	}
	return (answer);
}

// 테스트 케이스
int main()
{
	vector<int> arr1 = { 9, 20, 28, 18, 11 };
	vector<int> arr2 = { 30, 1, 21, 17, 28 };
	vector<string> res = solution(5, arr1, arr2);
	for (auto x : res)
		cout << x << "\n";
	return (0);
}
